/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/
#ifndef MAIN_COMPONENT_CPP
#define MAIN_COMPONENT_CPP

#include "MainComponent.h"
#include "../Builds/MacOSX/sendMultiTouches.mm"

#include <math.h>
#include <stdio.h>

void *StartOsc(void *threadid)
{
    long tid;
    tid = (long)threadid;
    threadThang();
    pthread_exit(NULL);
}

//==============================================================================
MainContentComponent::MainContentComponent()
//                    :   rerouter(this)
{
    pthread_create(&threads[0], NULL, StartOsc, (void *)0);
    
    startAudioCallback();
            
    setSize (500, 400);
    startTimer(45);
    
    windowWidth = getWidth();
    windowHeight = getHeight();
    
    middleX = windowWidth/2;
    middleY = windowHeight/2;
    
    filter.printCoeffs();
    
}

MainContentComponent::~MainContentComponent()
{
    stopAudioCallback();
    
    pthread_cancel(threads[0]); //close thread
    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::deeppink);
    
    float offsetWidth = fabs(currentSample) * 50;
    
    for(int i = 0; i < 10; i++) {
        if(fingersToDraw[i] == true) {
            float ringX = globalExPosition[i]*windowWidth;
            float ringY = (globalWhyPosition[i]*-windowHeight)+windowHeight;
            
            g.drawEllipse(ringX, ringY, offsetWidth, offsetWidth, 50);
        }
        isTheFingerThere[i] = false;
        fingersToDraw[i] = false;
    }
    
//    g.drawEllipse(middleX, middleY, offsetWidth, offsetWidth, 50);
    
    
}

void MainContentComponent::audioCallback(float **buffer, int channels, int frames)
{
    //CrazyDrawing
    currentSample = buffer [channels-1][frames-1];
    
    for(int i = 0; i < 10; i++) {
        if(isTheFingerThere[i] == true) {
            fingersToDraw[i] = true;
        }
    }

    filter.process(buffer, channels, frames);
    gain.process(buffer, channels, frames);
    
//    gain.printGain();
    
    /*
    float g = gain.averageValue(buffer, channels, frames);
    std::cout <<  "gain: " << g << std::endl;
    */
}


void MainContentComponent::mouseDown (const MouseEvent& event)
{
}

void MainContentComponent::isFingerDown()
{
    
}

void MainContentComponent::timerCallback()
{
    repaint();
}

void MainContentComponent::rerouteCallback(int id, float x, float y)
{
    
    xPosOnTrackPad = x;
    yPosOnTrackPad = y;
    
    setNewMsg(true);
}

void MainContentComponent::setNewMsg(bool nState)
{
    newMsg = nState;
}


void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    middleX = getWidth()/2;
    middleY = getHeight()/2;
}

#endif

