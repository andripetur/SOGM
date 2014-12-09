/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

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

void *quitOsc(void *threadid)
{
    system("oscKiller");
    pthread_exit(NULL);
}

//==============================================================================
MainContentComponent::MainContentComponent() : listener(this) /*, trackpad() */
{
    pthread_create(&threads[0], NULL, StartOsc, (void *)0);
    

    startAudioCallback();
    
//    trackpad.startThread();
    
    sender.startThread();
    listener.startThread();
    DBG("OSC thread started");
    
    setSize (500, 400);
    startTimer(33);
    
    middleX = getWidth()/2;
    middleY = getHeight()/2;
    
    filter.printCoeffs();
    
}

MainContentComponent::~MainContentComponent()
{
    stopAudioCallback();
    
    pthread_cancel(threads[0]); //close thread
    
//    pthread_create(&threads[1], NULL, quitOsc, (void *)1);
//    system("oscKiller");

    
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::deeppink);
    
    float offsetWidth = fabs(currentSample) * 50;
    
    if(newMsg){
    std::cout << "x: " << xPosOnTrackPad <<" "<< "y: " << yPosOnTrackPad << std::endl;
    setNewMsg(false);
    }
    
    g.drawEllipse(middleX, middleY, offsetWidth, offsetWidth, 50);
    
    
}

void MainContentComponent::audioCallback(float **buffer, int channels, int frames)
{
    //CrazyDrawing
    currentSample = buffer [channels-1][frames-1];

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

void MainContentComponent::mouseCallback(int state, float x, float y)
{
    yPosOnTrackPad = y;
    xPosOnTrackPad = x;
    
    setNewMsg(true);
}

void MainContentComponent::timerCallback()
{
    repaint();
}

void MainContentComponent::oscCallback(float x, float y)
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

