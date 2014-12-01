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
    for (int ch=0; ch < channels; ch++) {
        for (int fr = 0; fr < frames; fr++) {
            
//            buffer[ch][fr] = tanh(buffer[ch][fr]);
            currentSample = buffer [ch][fr];
            buffer[ch][fr] = 0;
        }
    }
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
}
