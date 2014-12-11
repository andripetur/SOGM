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
    Filter(float theSamplerate);
    void setFilterMode(int filterMode);
    void setFilterFreq(int freq);
    
    void printCoeffs(); 
    void process(float **buffer, int channels, int frames);
    
    void shiftBufferLeft(float *buffer);
    
private:
    int lastFilterMode;
    int currentFilterMode;
    
    double filterFreq;
    double lastFilterFreq;
    
    float calculateSample(float inBuffer[], float outBuffer[]);
    void CalculateCoeff(double Fc);
    
    void xFadeBuffers(float **outputBuffer, float oBuf[2][1024], float nBuf[2][1024],
                      int channels, int frames);

    // x buffers
    float leftBuffer[3];
    float rightBuffer[3];
    // y buffer
    float leftOutBuffer[3];
    float rightOutBuffer[3];
    
    float oldLeftBuffer[3];
    float oldRightBuffer[3];
    
    float oldLeftOutBuffer[3];
    float oldRightOutBuffer[3];
    
    float oldFilter[2][1024];
    float newFilter[2][1024];
     
    double a0, a1, a2;
    double b0, b1, b2;
    
    float samplerate;
    
};
#endif /* defined(__myFirstJuce__Filter__) */
