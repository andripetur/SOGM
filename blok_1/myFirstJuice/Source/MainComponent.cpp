#ifndef MAIN_COMPONENT_CPP
#define MAIN_COMPONENT_CPP

#include "MainComponent.h"
#include "../Builds/MacOSX/trackpadListenerFuncties.mm"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    //thread for trackpadlistener
    pthread_create(&threads[0], NULL, trackpadListener, (void *)0);
    
    startAudioCallback();
    
    //Height=width * 0.72380952;
    setSize (500, 361);
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
    //Clear Window
    g.fillAll (Colour (0xffeeddff));

//    g.setFont (Font (16.0f));
    g.setColour (Colours::deeppink);
    
    //Draw a shape for every finger on trackpad
    for(int i = 0; i < 10; i++) {
        offsetWidth[i] = (fabs(shapeSample[i]) * 50)+0.008;
        
        if(fingersToDraw[i] == true) {
            float ringX = globalExPosition[i]*windowWidth;
            float ringY = (globalWhyPosition[i]*-windowHeight)+windowHeight;
            
            g.drawEllipse(ringX, ringY, offsetWidth[i], offsetWidth[i], 50);

        }
        isTheFingerThere[i] = false;
        fingersToDraw[i] = false;
    }//for
    
}

void MainContentComponent::audioCallback(float **buffer, int channels, int frames)
{
    //Get some values to draw fingers and such.
    for(int i = 0; i < 10; i++) {
        shapeSample[i] = buffer [channels-1][frames-10*(i+1)];
        if(isTheFingerThere[i] == true) {
            fingersToDraw[i] = true;
        }
    }
    
    if(lastXposition < 0.5){
        filter.setFilterFreq(8000);
    } else {
        filter.setFilterFreq(4000);
    }

    filter.process(buffer, channels, frames);
    gain.process(buffer, channels, frames);
    
//    gain.printGain();
    

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

void MainContentComponent::resized()
{
    windowWidth = getWidth();
    windowHeight = getHeight();
    
    middleX = windowWidth/2;
    middleY = windowHeight/2;
}

#endif

