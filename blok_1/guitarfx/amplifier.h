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
    void process();
    
    virtual void printInfo();
    
private:
    long level;
}; // Amplifier{}

