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
    void setFilterFreq(double freq);
    
    void setFilterQ(double q);
    
    void process(float **buffer, int channels, int frames);
    void printCoeffs();
    
private:
    int lastFilterMode;
    int currentFilterMode;
    
    double filterFreq;
    double lastFilterFreq;
    
    double filterQ;
    double lastFilterQ;
    
    float calculateSample(float inBuffer[], float outBuffer[]);
    void CalculateBuffer(float **buffer, int channels, int frames);
    void CalculateCoeff(int centerFrequency);
    
    void shiftBufferLeft(float *buffer, float newSample);
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
