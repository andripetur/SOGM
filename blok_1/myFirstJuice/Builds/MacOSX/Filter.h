//
//  Filter.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#ifndef __myFirstJuce__Filter__
#define __myFirstJuce__Filter__

#include <math.h>
#include <iostream>

class Filter
{
public:
    Filter();
    void setFilterMode(int filterMode);
    void setFilterFreq(double freq);
    
    void printCoeffs(); 
    void process(float **buffer, int channels, int frames);
    
private:
    int lastFilterMode;
    int currentFilterMode;
    
    double filterFreq;
    double lastFilterFreq;
    
    float calculateSample(float inBuffer[], float outBuffer[]);
    void CalculateCoeff(double Fc);

    float leftBuffer[3];
    float rightBuffer[3];
    
    float leftOutBuffer[3];
    float rightOutBuffer[3];
    
    double a0, a1, a2;
    double b0, b1, b2;
    
    int samplerate; 
    
};
#endif /* defined(__myFirstJuce__Filter__) */
