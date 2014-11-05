#include "amplifier.h"

Amplifier::Amplifier()
{
    this->level=5; // default
}

void Amplifier::show_level()
{
    cout << "Amplifier level: " << level << endl;
}
