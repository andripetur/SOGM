//
//  Filter.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#include "Filter.h"


Filter::Filter()
{
    
    for (int i = 0; i < 3; i++) {
        leftBuffer[i] = 0.0;
        rightBuffer[i] = 0.0;
        
        leftOutBuffer[i] = 0.0;
        rightOutBuffer[i] = 0.0;
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
    
    CalculateCoeff(freq);
}

void Filter::process(float **buffer, int channels, int frames)
{
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            
            if(ch == 0){
                //Shift all samples to the left. 
                leftBuffer[0] = leftBuffer[1];
                leftBuffer[1] = leftBuffer[2];
                buffer[ch][fr] = leftBuffer[2];
                
                buffer[ch][fr] = calculateSample(leftBuffer, leftOutBuffer);
            } else if (ch == 1) {
                //Shift all samples to the left.
                rightBuffer[0] = rightBuffer[1];
                rightBuffer[1] = rightBuffer[2];
                buffer[ch][fr] = rightBuffer[2];
                
                buffer[ch][fr] = calculateSample(rightBuffer, rightOutBuffer);
            }
        }
    }
}//process()

float Filter::calculateSample(float x[], float y[])
{
    
    int n = 2;
    
    y[n] = (a0*x[n] +
            a1 * x[n-1]+
            a2 * x[n-2]-
            
            b1 * y[n-1]+
            b2 * y[n-2])
    * b0;
    
    return y[n];
    
} // calculateSample()

void Filter::CalculateCoeff(double Fc)
{
    double Q = 1; 
    double norm;
    double K = tan(M_PI * Fc);

    norm = 1 / (1 + K / Q + K * K);
    a0 = K * K * norm;
    a1 = 2 * a0;
    a2 = a0;
    b1 = 2 * (K * K - 1) * norm;
    b2 = (1 - K / Q + K * K) * norm;

}