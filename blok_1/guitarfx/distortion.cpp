#include "distortion.h"

Distortion::Distortion()
{
    setLevel(90);
    this->outputGain = 1;
}

void Distortion::setOutputGain(float outputGain)
{
    this->outputGain = outputGain;
}

void Distortion::process(float* buffer, int bufferFrames)
{
    long inputGain = getLevel();
    
    for ( int i = 0; i < bufferFrames; ++i) {
        
        buffer[i]= tanh(buffer[i]*inputGain);
        
    }

}

void Distortion::printInfo()
{
    cout << "I'm a Distortion " << endl;
    cout << "Input gain is: " << getLevel() << endl;
    cout << "Output gain is: " << outputGain << endl;
    cout << endl;

}