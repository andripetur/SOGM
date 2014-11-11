#pragma once

#include <iostream>

using namespace std;

class Amplifier
{
public:
    Amplifier(); // constructor for the class
    void showLevel();
    long getLevel();
    void process();
    
private:
    long level;
}; // Amplifier{}

