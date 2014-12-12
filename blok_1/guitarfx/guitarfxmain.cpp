#include <iostream>
#include <unistd.h>
#include "amplifier.h"
#include "tremolo.h"
#include "distortion.h"

#define BUFFERSIZE 10
#define SAMPLERATE 44100
#define NROFCHANNELS 2

enum {NOINPUT = 0, AMPLIFIER, TREMOLO, DISTORTION};
enum {ARG_NAME = 0, ARG_WHICH_EFFECT, ARG_LEVEL, ARG_FREQ, ARG_DEPTH};

void printInfo(int chosenEffect) {
    
    switch (chosenEffect) {
        
        case NOINPUT:
            std::cout << "This program needs arguments to run." << std::endl;
            std::cout << "1. Type of effect" << std::endl;
            std::cout << "You can choose from: " << std::endl;
            std::cout << "  AMPLIFIER: -a " << std::endl;
            std::cout << "  TREMOLO: -t " << std::endl;
            std::cout << "  DISTORTION: -d " << std::endl;
            std::cout << "Try again, with fx to get further usage info  " << std::endl;
            break;
            
        case AMPLIFIER:
            std::cout << "This program needs 2 arguments to run." << std::endl;
            std::cout << "1.Type effect: AMPLIFIER, TREMOLO or DISTORTION" << std::endl;
            std::cout << "2. Level" << std::endl;
            break;
            
        case TREMOLO:
            std::cout << "This program needs 4 arguments to run." << std::endl;
            std::cout << "1.Type effect: AMPLIFIER, TREMOLO or DISTORTION" << std::endl;
            std::cout << "2. Level" << std::endl;
            std::cout << "3. Frequency" << std::endl;
            std::cout << "4. Depth" << std::endl;
            break;
            
        case DISTORTION:
            std::cout << "This program needs at least 2 arguments to run." << std::endl;
            std::cout << "1.Type effect: AMPLIFIER, TREMOLO or DISTORTION" << std::endl;
            std::cout << "2. Level" << std::endl;
            std::cout << "3. OutputGain" << std::endl;
            break;
            
    }
} //printInfo

using namespace std;

int main(int argc, char** argv)
{
    int chosenEffect = 0;
    
    if (argc == 1) {
        printInfo(NOINPUT);
    }
    else if (argc > 1)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            chosenEffect = AMPLIFIER;
        }
        else if (strcmp(argv[1], "-t") == 0)
        {
            chosenEffect = TREMOLO;
        }
        else if (strcmp(argv[1], "-d") == 0)
        {
            chosenEffect = DISTORTION;
        }
        
    }
    
    printInfo(chosenEffect);
    

    
    /*
    Amplifier amp;
    Tremolo trem;
    Distortion dist;

    amp.showLevel();
    trem.process();
    dist.process(0.5);
     */
    
    return 0;
} // main()

