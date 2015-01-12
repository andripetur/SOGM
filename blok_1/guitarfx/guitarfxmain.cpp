#include <iostream>
#include "audio_io.h"
#include <unistd.h>
#include "amplifier.h"
#include "tremolo.h"
#include "distortion.h"

#define BUFFERSIZE 10
#define SAMPLERATE 44100
#define NROFCHANNELS 2
#define FRAMESPERBUFFER 1024

enum {NOINPUT = 0, AMPLIFIER, TREMOLO, DISTORTION};
enum {ARG_NAME = 0, ARG_WHICH_EFFECT, ARG_LEVEL, ARG_FREQ, ARG_DEPTH};

Amplifier* effect;

void printInfo(int chosenEffect);

using namespace std;

int main(int argc, char** argv)
{
    Audio_IO audiostream;
    
    int chosenEffect = 0;
    int inputDevice = 0;
    int outputDevice = 0;

    float sampleBufferSize = FRAMESPERBUFFER * NROFCHANNELS;
    
    // Set up audiostream
    audiostream.set_samplerate(SAMPLERATE);
    audiostream.set_nrofchannels(NROFCHANNELS);
    audiostream.set_framesperbuffer(FRAMESPERBUFFER);
    
    // Select audio effect.
    if (argc == 1) {
        printInfo(NOINPUT);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            chosenEffect = AMPLIFIER;
            effect = new Amplifier();
        }
        else if (strcmp(argv[1], "-t") == 0)
        {
            chosenEffect = TREMOLO;
            effect = new Tremolo();
        }
        else if (strcmp(argv[1], "-d") == 0)
        {
            chosenEffect = DISTORTION;
            effect = new Distortion();
        }
        
        printInfo(chosenEffect);
    }
    
    // Set in and output devices
    audiostream.initialise();
    audiostream.list_devices();
    
    cout << "Give input device number: ";
    cin >> inputDevice;
    
    if(audiostream.set_input_device(inputDevice) == -1){
        cout << "Output device does not exist" << endl;
        return -1;
    }
    
    cout << "Give output device number: ";
    cin >> outputDevice;
    
    if(audiostream.set_output_device(outputDevice) == -1){
        cout << "Output device does not exist" << endl;
        return -1;
    }
    audiostream.start_server();
    
    effect->printInfo();
    
    //Do processing
    
    
    // Clean up
    audiostream.finalise();
    return 0;
    
} // main()

void printInfo(int chosenEffect) {
    
    switch (chosenEffect) {
            
        case NOINPUT:
            std::cout << " " << std::endl;
            std::cout << "This program needs arguments to run." << std::endl;
            std::cout << "  Usage: guitarfx [-effect]" << std::endl;
            std::cout << "  Choose fx for more info" << std::endl;
            std::cout << " " << std::endl;
            
            std::cout << "Available fx are: " << std::endl;
            std::cout << "  AMPLIFIER: -a " << std::endl;
            std::cout << "  TREMOLO: -t " << std::endl;
            std::cout << "  DISTORTION: -d " << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case AMPLIFIER:
            std::cout << " " << std::endl;
            std::cout << "This program needs 2 arguments to run." << std::endl;
            std::cout << "Usage: guitarfx [-effect] [-l LEVEL]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case TREMOLO:
            std::cout << " " << std::endl;
            std::cout << "This program needs 4 arguments to run." << std::endl;
            std::cout << "Usage: guitarfx [-effect] [-l LEVEL] [-f FREQUENCY] [-d DEPTH]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case DISTORTION:
            std::cout << " " << std::endl;
            std::cout << "This program needs 2 arguments to run." << std::endl;
            std::cout << "Usage: guitarfx [-effect] [-l LEVEL] [-o OUTPOUTGAIN]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
    }
    
} //printInfo

