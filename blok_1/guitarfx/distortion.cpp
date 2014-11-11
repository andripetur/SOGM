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

void Distortion::process(float input)
{
    float output;
    output = tanh(input);
    
    cout << "Distortion: " << endl;
    cout << "Processing input" << endl;
    cout << "Input gain is: " << getLevel() << endl;
    cout << "Output gain is: " << outputGain << endl;
    cout << endl;
}