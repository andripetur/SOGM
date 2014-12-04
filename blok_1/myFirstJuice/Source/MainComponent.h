/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include "filter.h"
#include "AutoGain.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, private Timer , private AudioCallback
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    
    void mouseDown(const MouseEvent& event);
    
private:
    void timerCallback();
    void audioCallback (float** buffer, int channels, int frames);
    
    float currentSample; 
    int middleX;
    int middleY;
    
    double freq = 100; 
    
    Filter filter;
    AutoGain gain;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
