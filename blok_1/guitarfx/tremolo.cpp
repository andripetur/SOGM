#include "tremolo.h"

Tremolo::Tremolo()
{
    Amplifier();
    this->modDepth = 1;
    this->frequency = 0.5;
}

void Tremolo::setDepth(float modDepth)
{
    this->modDepth = modDepth;
}

void Tremolo::setFreq(float frequency)
{
    this->frequency = frequency;
}

void Tremolo::process()
{
    cout << "Im a Tremolo: " << endl;
    cout << "I'm processing " << endl;
    cout << "With a depth of:" << modDepth << endl;
    cout << "And a frequency of: " << frequency << endl;
    cout << endl;
    
}

void Tremolo::printInfo()
{
    cout << "Im a Tremolo: " << endl;
    cout << "With a depth of:" << modDepth << endl;
    cout << "And a frequency of: " << frequency << endl;
    cout << endl;
}