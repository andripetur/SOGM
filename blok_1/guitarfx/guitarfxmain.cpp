#include <iostream>
#include "audio_io.h"
#include "amplifier.h"
#include "tremolo.h"
#include "distortion.h"

#define SAMPLERATE 44100
#define NROFCHANNELS 1
#define FRAMESPERBUFFER 1024

enum {NOINPUT = 0, AMPLIFIER, TREMOLO, DISTORTION, DEFAULT };
enum {ARG_NAME = 0, ARG_WHICH_EFFECT, ARG_LEVEL, ARG_FREQ, ARG_DEPTH};

Amplifier* effect;

void printInfo(int chosenEffect);

using namespace std;

int main(int argc, char** argv)
{
    // Make Audiostream variables. 
    Audio_IO audiostream;
    
    int chosenEffect = 0;
    int inputDevice = -1;
    int outputDevice = -1;

    float samplebuffer[FRAMESPERBUFFER];
    float* bufptr = samplebuffer;

    for ( int i = 0; i < FRAMESPERBUFFER; ++i){
        samplebuffer[i] = 0;
    }
    
    // Set up audiostream
    audiostream.set_mode(AUDIO_IO_READWRITE);
    audiostream.set_samplerate(SAMPLERATE);
    audiostream.set_nrofchannels(NROFCHANNELS);
    audiostream.set_framesperbuffer(FRAMESPERBUFFER);
    
    // Get user input
    if (argc == 1) {
        printInfo(NOINPUT);
        return -1;
    }
    // Parameter 0 : Select effect
    else if (argc > 1)
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
        // Get user input parameters
        
        // Parameter1
        if ( argc >= 3 ) {
            // -l level
            if ( strcmp(argv[2], "-l") == 0)
            {
                long uilevel = atoi(argv[3]);
                effect->setLevel(uilevel);
            }
        }
        // Parameter2
        if ( argc >= 5 ) {
            // -f freq
            if ( strcmp(argv[4], "-f") == 0 && chosenEffect == TREMOLO)
            {
                float uiFreq = atof(argv[5]);
                effect->setFreq(uiFreq);
            }
            
            // -o outputGain
            if ( strcmp(argv[4], "-o") == 0 && chosenEffect == DISTORTION)
            {
                float uiOutGain = atof(argv[5]);
                effect->setOutputGain(uiOutGain);
            }
        }
        // Parameter3
        if ( argc >= 7) {
            // -d depth
            if ( strcmp(argv[6], "-d") == 0 && chosenEffect == TREMOLO)
            {
                float uiDepth = atof(argv[7]);
                effect->setDepth(uiDepth);
            }

        }

    } // User Input
    
    if (argc == 2) {
        printInfo(chosenEffect);
        printInfo(DEFAULT);
    } else {
        printInfo(chosenEffect);
    }
    
        effect->printInfo();
    
        // Set in and output devices
        audiostream.initialise();
        audiostream.list_devices();
        cout << endl;
        
        cout << "Give input device number: ";
        cin >> inputDevice;
        
        if(audiostream.set_input_device(inputDevice) == -1)
        {
            cout << "Input device does not exist" << endl;
            return -1;
        }
        
        cout << "Give output device number: ";
        cin >> outputDevice;
        cout << endl;
    
        if(audiostream.set_output_device(outputDevice) == -1)
        {
            cout << "Output device does not exist" << endl;
            return -1;
        }
        audiostream.start_server();
    
        cout << "Press ctrl c to stop program" << endl;
    
        //Do processing
        while(true) {
            audiostream.read(samplebuffer);
            effect->process(bufptr, FRAMESPERBUFFER);
            audiostream.write(samplebuffer);
        }
        
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
            std::cout << "This effect has 2 parameters." << std::endl;
            std::cout << "Usage: guitarfx -a [-l LEVEL]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case TREMOLO:
            std::cout << " " << std::endl;
            std::cout << "This effect has 3 parameters." << std::endl;
            std::cout << "Usage: guitarfx -t [-l LEVEL] [-f FREQUENCY] [-d DEPTH]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case DISTORTION:
            std::cout << " " << std::endl;
            std::cout << "This effect has 2 parameters." << std::endl;
            std::cout << "Usage: guitarfx -d [-l LEVEL] [-o OUTPOUTGAIN]" << std::endl;
            std::cout << " " << std::endl;
            break;
            
        case DEFAULT:
            std::cout << "The effect now runs with the default settings" << std::endl;
            std::cout << " " << std::endl;
            break;
            
    }
    
} //printInfo

