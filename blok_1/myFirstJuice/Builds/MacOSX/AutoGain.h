//
//  AutoGain.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#ifndef __myFirstJuce__AutoGain__
#define __myFirstJuce__AutoGain__

class AutoGain
{
public:
    void process(float **buffer, int channels, int frames);
    
private:
    float feedbackLowLimit;
    float feedbackHighLimit;
    
    float gainer = 1;
    
    float averageValue(float **buffer, int channels, int frames);
    
};

#endif /* defined(__myFirstJuce__AutoGain__) */
