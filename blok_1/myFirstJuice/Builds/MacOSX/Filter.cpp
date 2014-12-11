//
//  Filter.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#include "Filter.h"

Filter::Filter(float theSamplerate) : samplerate(theSamplerate)
{
    lastFilterFreq = 6000;
    setFilterFreq(6000);
    CalculateCoeff(filterFreq);
    
    for (int i = 0; i < 3; i++) {
        leftBuffer[i] = 0.0;
        rightBuffer[i] = 0.0;
        
        leftOutBuffer[i] = 0.0;
        rightOutBuffer[i] = 0.0;
        
        oldLeftBuffer[i] = 0.0;
        oldRightBuffer[i] = 0.0;
        
        oldLeftOutBuffer[i] = 0.0;
        oldRightOutBuffer[i] = 0.0;
    }
}

void Filter::setFilterMode(int filterMode)
{
    this->lastFilterMode = this->currentFilterMode;
    this->currentFilterMode = filterMode;
    
} // setFilterMode

void Filter::setFilterFreq(double freq)
{
    lastFilterFreq = filterFreq;
    filterFreq = freq;
    
//    CalculateCoeff(filterFreq);
//    printCoeffs();
}

void Filter::setFilterQ(double q)
{
    filterQ = q;
}

void Filter::process(float **buffer, int channels, int frames)
{

    if ( lastFilterFreq == filterFreq )
    {
        CalculateBuffer(buffer, channels, frames);
    }
    else
    {
        
        CalculateCoeff(filterFreq);
        CalculateBuffer(buffer, channels, frames);
        lastFilterFreq = filterFreq;

    }
    
//    else {
//        CalculateCoeff(lastFilterFreq);
//        
//        for (int ch = 0; ch < channels; ch++) {
//            for (int fr = 0; fr < frames; fr++) {
//                
//                if(ch == 0) {
//                    shiftBufferLeft(&oldLeftBuffer[3]);
//                    shiftBufferLeft(&oldLeftOutBuffer[3]);
//                    
//                    oldLeftOutBuffer[2] = buffer[ch][fr];
//                    
//                    oldFilter[ch][fr] = calculateSample(oldLeftBuffer,oldLeftOutBuffer);
//                }
//                
//                if(ch == 1) {
//                    shiftBufferLeft(&oldRightBuffer[3]);
//                    shiftBufferLeft(&oldRightOutBuffer[3]);
//                    
//                    oldRightOutBuffer[2] = buffer[ch][fr];
//                    
//                    oldFilter[ch][fr] = calculateSample(oldRightBuffer,oldRightOutBuffer);
//                }
//            }
//        } // fill oldBuffer
//        
//        CalculateCoeff(filterFreq);
//        
//        for (int ch = 0; ch < channels; ch++) {
//            for (int fr = 0; fr < frames; fr++) {
//                
//                if(ch == 0){
//                    shiftBufferLeft(&leftBuffer[3]);
//                    shiftBufferLeft(&leftOutBuffer[3]);
//                    
//                    leftBuffer[2] = buffer[ch][fr];
//                    
//                    newFilter[ch][fr] = calculateSample(leftBuffer, leftOutBuffer);
//                    
//                } else if (ch == 1) {
//                    shiftBufferLeft(&rightBuffer[3]);
//                    shiftBufferLeft(&rightOutBuffer[3]);
//                    
//                    rightBuffer[2] = buffer[ch][fr];
//                    
//                    newFilter[ch][fr] = calculateSample(rightBuffer, rightOutBuffer);
//                }
//            }
//        } // fill newBuffer
//
//        xFadeBuffers(buffer, oldFilter, newFilter, channels, frames);
//        
//        for (int i = 0; i < 3; i++) {
//            int offset = (i * -1)+ 3;
//            
//            oldLeftOutBuffer[i] = buffer[0][frames-offset];
//            oldRightOutBuffer[i] = buffer[1][frames-offset];
//        }
//    } // if
//
//    for (int i = 0; i < 3; i++) {
//        
//        leftOutBuffer[i] = oldLeftOutBuffer[i];
//        rightOutBuffer[i] = oldRightOutBuffer[i];
//        
//        oldLeftBuffer[i] = leftBuffer[i];
//        oldRightBuffer[i]= rightBuffer[i];
//        
//        //            leftBuffer[i] = 0;
//        //            rightBuffer[i] = 0;
//        
//        //            leftOutBuffer[i] = 0.0;
//        //            rightOutBuffer[i] = 0.0;
//        
//    }
    
}//process()

void Filter::CalculateBuffer(float **buffer, int channels, int frames)
{
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            
            if(ch == 0){
                shiftBufferLeft(&oldLeftBuffer[3], buffer[ch][fr]);
                shiftBufferLeft(&oldLeftOutBuffer[3], 0);
                                
                buffer[ch][fr] = calculateSample(oldLeftBuffer,oldLeftOutBuffer);
                
            } else if (ch == 1) {
                shiftBufferLeft(&oldRightBuffer[3], buffer[ch][fr]);
                shiftBufferLeft(&oldRightOutBuffer[3], 0);
                
                buffer[ch][fr] = calculateSample(oldRightBuffer,oldRightOutBuffer);
            }
        }
    }
} // calcBuffer



void Filter::shiftBufferLeft(float *buffer, float newSample)
{
    buffer[0] = buffer[1];
    buffer[1] = buffer[2];
    
    buffer[2] = newSample;
}

float Filter::calculateSample(float x[], float y[])
{
    int n = 2;
    
    y[n] = ((a0*x[n] +
            a1 * x[n-1]+
            a2 * x[n-2]-
            
            b1 * y[n-1]+
            b2 * y[n-2])
    * b0);
    
    return y[n];
    
} // calculateSample()

void Filter::xFadeBuffers(float **outputBuffer, float oBuf[2][1024], float nBuf[2][1024],
                      int channels, int frames)
{
    float fadeInVal = 1/(frames-1);
    float fadeOutVal = -1/(frames-1);
    
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            
            oBuf[ch][fr] *= ( fadeOutVal * fr ) + 1.0;
            nBuf[ch][fr] *= fadeInVal * fr;
            
            outputBuffer[ch][fr] = oBuf[ch][fr] + nBuf[ch][fr];
        }
    }

} // xFadeBuffers

void Filter::CalculateCoeff(int centerFrequency)
{    
//    double Q = 0.7071;
//    double Q = 0.9;
    double norm;
    double K = tan(M_PI * (double)centerFrequency/(float)samplerate);

    norm = 1 / (1 + K / filterQ + K * K);
    a0 = K * K * norm;
    a1 = 2 * a0;
    a2 = a0;
    b1 = 2 * (K * K - 1) * norm;
    b2 = (1 - K / filterQ + K * K) * norm;
    
    b0 = 0.9;
}

void Filter::printCoeffs() {
    
    std::cout << "Filter frequency:  " << filterFreq << std::endl;
    std::cout << "a0: " << a0 << " a1: " << a1 << " a2: " << a2 << std::endl;
    std::cout << "b0: " << b0 << " b1: " << b1 << " b2: " << b2 << std::endl;
    std::cout << "filter Samplrate: " << samplerate << std::endl;
    std::cout << std::endl;
}