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
    
    float averageValue(float **buffer, int channels, int frames);
    
private:
    float feedbackLowLimit = 4.9;
    float feedbackHighLimit = 8;
    
    float gainer = 1;
    
    
    
};

#endif /* defined(__myFirstJuce__AutoGain__) */
