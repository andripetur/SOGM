#pragma once

#include "amplifier.h"
#include <math.h>

class Distortion : public Amplifier
{
public:
    Distortion();
    void setOutputGain(float outputGain);
    void process(float input);
    void printInfo();
    
private:
    float outputGain;
};