#include "tremolo.h"
#include <math.h>

Tremolo::Tremolo()
{
    setLevel(2);
    playBar = 0;
    
    for(int i = 0; i < 44100; i++) {
        oneCycle[i] = 0;
    }
    this->modDepth = 100;
    this->setFreq(400);
}

void Tremolo::setDepth(float modDepth)
{
    this->modDepth = modDepth;
}

void Tremolo::setFreq(float frequency)
{
    this->frequency = frequency;
    fillSineBuffer();
    
}

void Tremolo::process(float* buffer, int bufferFrames)
{
    long gain = getLevel();
    
    for( int i = 0; i < bufferFrames; ++i)
    {
        buffer[i] *= gain * (oneCycle[playBar] * modDepth);
        buffer[i] = clip(buffer[i]);
        ++playBar;
        
        if(playBar == onePeriod)
        {
            playBar = 0;
        }
    }
    
} // process

void Tremolo::printInfo()
{
    cout << "I'm a Tremolo " << endl;
    cout << "With a depth of: " << modDepth << endl;
    cout << "And a frequency of: " << frequency << endl;
    cout << endl;
    
}

void Tremolo::fillSineBuffer()
{
    onePeriod = 44100 / frequency;
    
    //Put dat shit in a for loop
    for(int i = 0; i < onePeriod; ++i) {
        
        //Calculate step size in radians
        radian = (float)i / (float)onePeriod * 2*M_PI;
        
        oneCycle[i] = fabs(sin(radian));
    }
    
}