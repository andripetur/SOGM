#pragma once

#include <iostream>

using namespace std;

class Amplifier
{
public:
    Amplifier(); // constructor for the class
    void setLevel(long level);
    void showLevel();
    
    long getLevel();
    virtual void process(float* buffer, int bufferframes);
    
    float clip(float input);
    
    virtual void printInfo();
    
    virtual void setFreq(float freq){};
    virtual void setOutputGain(float og){};
    virtual void setDepth(float d){};
    
private:
    long level;
}; // Amplifier{}

