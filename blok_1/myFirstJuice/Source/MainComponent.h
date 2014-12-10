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

#include <stdlib.h>
#include <pthread.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, private Timer , public ChangeBroadcaster, private AudioCallback
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
    
    void rerouteCallback(int id, float x, float y);
    void isFingerDown();
    
    void mouseDown(const MouseEvent& event);
    
    void setNewMsg(bool nState);
    
private:
    void timerCallback();
    void audioCallback (float** buffer, int channels, int frames);
    
    bool newMsg = false;
    
    float currentSample; 
    int middleX;
    int middleY;
    
    float windowWidth;
    float windowHeight; 
    
    float xPosOnTrackPad;
    float yPosOnTrackPad;
    
    double freq = 100;
    
    pthread_t threads[2];
    int OSC_PID;
    
    bool fingersToDraw[10];
        
    Filter filter;
    AutoGain gain;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
