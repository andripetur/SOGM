#pragma once

#include "amplifier.h"

class Tremolo : public Amplifier
{
public:
    Tremolo();
    void setDepth(float modDepth);
    void setFreq(float frequency);
    void process();
    
private:
    float modDepth;
    float frequency;
}; //tremolo