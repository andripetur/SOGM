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
    setFilterFreq(8000);
    
    for (int i = 0; i < 3; i++) {
        leftBuffer[i] = 0.0;
        rightBuffer[i] = 0.0;
        
        leftOutBuffer[i] = 0.0;
        rightOutBuffer[i] = 0.0;
    }
    
//    a0 = 0.2513790015131591;
//    a1 = 0.5027580030263182;
//    a2 = 0.2513790015131591;
//    b1 = -0.17124971441396285;
//    b2 = 0.1767567204665992;
//    b0 = 0.9;
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
    
   CalculateCoeff(filterFreq);
    
}

void Filter::process(float **buffer, int channels, int frames)
{
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            
            if(ch == 0){
                //Shift all samples to the left. 
                leftBuffer[0] = leftBuffer[1];
                leftBuffer[1] = leftBuffer[2];
                
                leftOutBuffer[0] = leftOutBuffer[1];
                leftOutBuffer[1] = leftOutBuffer[2];
                
                leftBuffer[2] = buffer[ch][fr];
                
                buffer[ch][fr] = calculateSample(leftBuffer, leftOutBuffer);
                
            } else if (ch == 1) {
                //Shift all samples to the left.
                rightBuffer[0] = rightBuffer[1];
                rightBuffer[1] = rightBuffer[2];
                
                rightOutBuffer[0] = rightOutBuffer[1];
                rightOutBuffer[1] = rightOutBuffer[2];
                
                rightBuffer[2] = buffer[ch][fr];
                
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
    Fc /= 44100;
    
    double Q = 0.7071;
    double norm;
    double K = tan(M_PI * Fc);

    norm = 1 / (1 + K / Q + K * K);
    a0 = K * K * norm;
    a1 = 2 * a0;
    a2 = a0;
    b1 = 2 * (K * K - 1) * norm;
    b2 = (1 - K / Q + K * K) * norm;
    
    b0 = 0.9;

}

void Filter::printCoeffs() {
    std::cout << "a0: " << a0 << " a1: " << a1 << " a2: " << a2 << std::endl;
    std::cout << "b0: " << b0 << " b1: " << b1 << " b2: " << b2 << std::endl;
    std::cout << std::endl;
}