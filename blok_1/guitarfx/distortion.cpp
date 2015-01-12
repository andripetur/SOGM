#include "distortion.h"

Distortion::Distortion()
{
    Amplifier();
    this->outputGain = 1;
}

void Distortion::setOutputGain(float outputGain)
{
    this->outputGain = outputGain;
}

void Distortion::process(float* buffer, int bufferFrames)
{
    for ( int i = 0; i < bufferFrames; ++i) {
        
        buffer[i]= tanh(buffer[i]);
        
    }

}

void Distortion::printInfo()
{
    cout << "Im a Distortion: " << endl;
    cout << "Input gain is: " << getLevel() << endl;
    cout << "Output gain is: " << outputGain << endl;    
}