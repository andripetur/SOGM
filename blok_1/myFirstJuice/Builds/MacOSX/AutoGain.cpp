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
}

void AutoGain::process(float **buffer, int channels, int frames)
{
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            buffer[ch][fr] *= gainer;
        }
    }//for
    
    float avg = averageValue(buffer, channels, frames);
    
    if (avg < feedbackLowLimit) {
        gainer *= 1.1;
    } else if (avg > feedbackHighLimit)
    {
        gainer *= 0.8;
    }
    
}//Process()


float AutoGain::averageValue(float **buffer, int channels, int frames)
{
    int NrOfSamples = channels * frames;
    float sum;
    
    
    for (int ch = 0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            sum += fabs(buffer[ch][fr]);
        }
    }
    
    return sum / (float)NrOfSamples;
    
}// avgValue

void AutoGain::printGain()
{
    std::cout << "Gain: " << gainer << std::endl;
    std::cout << std::endl;
}