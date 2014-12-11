//
//  AutoGain.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#ifndef __myFirstJuce__AutoGain__
#define __myFirstJuce__AutoGain__

#include <iostream>

class AutoGain
{
public:
    AutoGain();
    void process(float **buffer, int channels, int frames);
    void printGain();
    
    float averageValue(float buffer[2][1024], int channels, int frames);
    
private:
    float feedbackLowLimit = 4.9;
    float feedbackHighLimit = 18.0;
    
    float tempBuffer[2][1024];
    
    float avg = 0; 
    double gainer = 1;
    
    
};

#endif /* defined(__myFirstJuce__AutoGain__) */
