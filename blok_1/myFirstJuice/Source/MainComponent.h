#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include "filter.h"
#include "AutoGain.h"

#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdio.h>

class MainContentComponent   : public Component, private Timer , private AudioCallback
{
public:
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    
    void mouseDown(const MouseEvent& event);
        
private:
    void timerCallback();
    void audioCallback (float** buffer, int channels, int frames);
    
    double paddedFrequency;
    double paddedQ;
    
    float internalX;
    float internalY;
    
    Filter filter;
    AutoGain gain;
    
    pthread_t threads[2];
    
    // Draw Variables
    bool fingersToDraw[10];
    float shapeSample[10];
    float offsetWidth[10];
    
    int middleX;
    int middleY;
    float windowWidth;
    float windowHeight;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
