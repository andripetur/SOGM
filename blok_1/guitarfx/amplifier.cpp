#include "amplifier.h"

Amplifier::Amplifier()
{
    this->level=5; // default
}

void Amplifier::showLevel()
{
    cout << "Amplifier: " << endl;
    cout << "Amplifier level: " << level << endl;
    cout <<" " << endl;
}

long Amplifier::getLevel()
{
    return level;
}

void Amplifier::setLevel(long level)
{
    this->level=level;
}

void Amplifier::process(float* buffer, int bufferframes)
{
    for( int i = 0; i < bufferframes; ++i)
    {
        buffer[i]*= level;
        
        //clip
        buffer[i] = clip(buffer[i]);
        
    } // for
    
}//process()

float Amplifier::clip(float input)
{
    if( input > 1 )
    {
        input = 1;
    }
    else if (input < -1)
    {
        input = -1;
    } // clip
    
    return input;
}

void Amplifier::printInfo() {
    cout << "Im an amplifier. " << endl;
    cout << "My level is: "<< level << endl;
    cout << endl;
}
