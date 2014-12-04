/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <math.h>
#include <stdio.h>


//==============================================================================
MainContentComponent::MainContentComponent()
{
    startAudioCallback();
    
    setSize (500, 400);
    startTimer(33);
    
    middleX = getWidth()/2;
    middleY = getHeight()/2;
    
    filter.printCoeffs();
    
}

MainContentComponent::~MainContentComponent()
{
    stopAudioCallback();
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::deeppink);
    
    float offsetWidth = fabs(currentSample) * 50;

    g.drawEllipse(middleX, middleY, offsetWidth, offsetWidth, 50);
    
}

void MainContentComponent::audioCallback(float **buffer, int channels, int frames)
{
    //CrazyDrawing
    currentSample = buffer [channels-1][frames-1];

    filter.process(buffer, channels, frames);
    gain.process(buffer, channels, frames);
    
    gain.printGain();
    
    /*
    float g = gain.averageValue(buffer, channels, frames);
    std::cout <<  "gain: " << g << std::endl;
    */
}


void MainContentComponent::mouseDown (const MouseEvent& event)
{
}

void MainContentComponent::timerCallback()
{
    repaint();
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    middleX = getWidth()/2;
    middleY = getHeight()/2;
}
