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

void Amplifier::process()
{
    cout << "I'm processing " << endl;

}
