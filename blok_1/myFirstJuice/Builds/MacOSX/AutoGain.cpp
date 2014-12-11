//
//  AutoGain.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#include "AutoGain.h"
#include <math.h>

AutoGain::AutoGain()
{
    for ( int j = 0; j < 2; j ++ ) {
        for ( int i = 0; i < 1024; i++ ) {
            tempBuffer[j][i] = 0;
        }
    }
    
}// AutoGain

void AutoGain::process(float **buffer, int channels, int frames)
{
    // Fill tempBuffer
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++)
        {
            tempBuffer[ch][fr] = buffer[ch][fr]*gainer;
        }
    }//for
    
    avg = averageValue(tempBuffer, channels, frames);
    
    if ( avg == NAN || avg == INFINITY) {
        avg = 1;
    }
    
    if (avg < feedbackLowLimit) {
        gainer *= 1.9;
    } else if (avg > feedbackHighLimit)
    {
        gainer *= 0.9;
    }
    
    //Disort
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++)
        {
            buffer[ch][fr] = tanhf(buffer[ch][fr]*gainer);
        }
    }//for
    
}//Process()


float AutoGain::averageValue(float buffer[2][1024], int channels, int frames)
{
    int NrOfSamples = channels * frames;
    float sum = 0;
    
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            sum += fabs(buffer[ch][fr]);
        }
    }
    
    return sum / (float)NrOfSamples;
    
}// avgValue

void AutoGain::printGain()
{
    std::cout << "Avg gain: " << avg <<std::endl;
    std::cout << "Gainer: " << gainer << std::endl;
    std::cout << std::endl;
}