#include <sndfile.h>
#include <stdio.h>
#include <libgen.h>
#include <string>
#include <math.h>
#include <iostream>

enum {ARG_NAME = 0, ARG_PATH, ARG_OUT_NAME, ARG_GAIN, NUM_ARGS};

SF_INFO sfInfo;
SNDFILE* inFile;
SNDFILE* outFile;

char* pathToInFile;
char* pathToOutFile;
char* nameOfOutFile;
char* nameOfInFile;
char* fileExtension;

float maxGain = 0;
float multiplier;
float destinationGain;

int channels;
int frames;
int vectorSize;
int samplerate;

// Get extension
char* get_ext(char* file){
    for(int i = strlen(file)-1; i >= 0; i-- ) if( file[i] == '.' ) return file+i;
    return file;
}

void notEnoughArgumentsError() {
    std::cout << std::endl;
    std::cout << "This program has performed an illegal operation and will be shut down! " << std::endl;
    std::cout << std::endl;
    std::cout << "Just kidding... but seriously. " << std::endl;
    std::cout << "This program needs 3 parameters to run: " << std::endl;
    std::cout << "1: Filepath" << std::endl;
    std::cout << "2: New filename" << std::endl;
    std::cout << "3: Gain" << std::endl;
    std::cout << std::endl;
}

void gainError() {
    std::cout << std::endl;
    std::cout << "The computer says no. " << std::endl;
    std::cout << std::endl;
    std::cout << "Gain needs to be higher than 0.00000000001 and not higher than 1." << std::endl;
    std::cout << std::endl;
    
}

void sameFileNameError() {
    std::cout << std::endl;
    std::cout << "The normalization could not be completed " << std::endl;
    std::cout << std::endl;
    std::cout << "New filename can't be the same as old name " << std::endl;
    std::cout << "Please try again, with another name." << std::endl;
    std::cout << std::endl;
}

void loadFileError() {
    std::cout << std::endl;
    std::cout << "An error occured loading the file. " << std::endl;
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    //----------Check if there are enough arguments --------------------
    if (argc != NUM_ARGS) {
        notEnoughArgumentsError();
        return -1;
    }
    
    //----------Get User Variables----------------------------------
    pathToInFile = argv[ARG_PATH]; //path to inFile
    nameOfOutFile= argv[ARG_OUT_NAME]; //name of outFile.
    destinationGain = atof(argv[ARG_GAIN]); //gain to normalize to.
    
    
    //----------Check if gain format is right---------------------
    if ( destinationGain == 0 || destinationGain > 1 ) {
        gainError();
        return -1;
    }

    //----------Make Path to out file-------------------------------
    pathToOutFile = dirname(pathToInFile);
    strcat(pathToOutFile, "/");
    strcat(pathToOutFile, nameOfOutFile);
    
    nameOfInFile = basename(pathToInFile);
    
    //----------Load Read File------------------------------------------
    inFile = sf_open(pathToInFile, SFM_READ, &sfInfo);
    
    //- check for file load error
    if(inFile == NULL) {
        loadFileError();
        return -1;
    }
    
    //-------------Get some info on the file----------------------------
    channels = sfInfo.channels;
    frames = sfInfo.frames;
    samplerate = sfInfo.samplerate;
    vectorSize = 1024;
    
    fileExtension = get_ext(pathToInFile);
    
    //-------------Create a buffer-------------------------------------
    int bufferSize = vectorSize*channels;
    float buffer[bufferSize];
    float writeBuffer[bufferSize];
    
    //-------------Find max gain-------------------------------------
    for (int i = 0; i < frames; i+=vectorSize)
    {
        sf_readf_float(inFile, buffer, vectorSize);
        
        for (int b = 0; b < bufferSize; b++)
        {
            if(fabs(buffer[b]) > maxGain)
            {
                maxGain = fabs(buffer[b]);
            }
        }
    }// for
    
    //std::cout << "Max Gain " << maxGain << std::endl;
    
    //------------Rewind and get multiplier----------------------------
    sf_seek(inFile, 0, SEEK_SET);
    multiplier = destinationGain/maxGain;
    
    
    //------------Add File extension ------------------------------------
    strcat(pathToOutFile, fileExtension); // add file extension
    strcat(nameOfOutFile, fileExtension); // add to out file name
    
    //----------Check if file has another name ------------------------
    if (strcmp (nameOfInFile,nameOfOutFile) == 0) {
        sameFileNameError();
        sf_close(inFile);
        
        return -1;
    }
    
    //------------Make the outFile--------------------------------------
    outFile= sf_open(pathToOutFile, SFM_WRITE, &sfInfo);

    //------------Write to new file------------------------------------
    for(int i = 0; i < frames; i+=vectorSize) {
        
        sf_readf_float(inFile, buffer, vectorSize); //filll the buffer
        
        for (int b = 0; b < bufferSize; b++)
        {
            writeBuffer[b] = buffer[b]*multiplier;
        }//fill the readBuffer;
        
        sf_writef_float(outFile, writeBuffer, vectorSize); //WriteBuffer to file
    
    }// for
    
    //std::cout << "Multiplier " << multiplier << std::endl;

    
    //------------Print Some Info To Terminal--------------------------
    int lengthInSeconds = frames/samplerate;
    int minutes = lengthInSeconds / 60;
    int seconds = lengthInSeconds - (minutes*60);
    
    std::cout << std::endl;
    std::cout << "Orginal Name: "<< nameOfInFile << std::endl;
    std::cout << "Normalized Name: "<< nameOfOutFile << std::endl;
    std::cout << std::endl;
    std::cout << "Length: "<< minutes << "."<< seconds << std::endl;
    std::cout << "Channels: "<< channels << std::endl;
    std::cout << "Samplerate: "<< samplerate << std::endl;
    
    //-------------Clean up your mess----------------------------------
    sf_close(inFile);
    sf_close(outFile);
    
    return 0;

} // main