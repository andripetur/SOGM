#pragma once

#include "amplifier.h"

class Tremolo : public Amplifier
{
public:
    Tremolo();
    void setDepth(float modDepth);
    void setFreq(float frequency);
    void process(float* buffer, int framesperbuffer);
    
    void printInfo();
    
private:
    float modDepth;
    float frequency;
    
    void fillSineBuffer();
    
    int onePeriod;
    float radian;
    
    float oneCycle[44100];
    int playBar; 
}; //tremolo