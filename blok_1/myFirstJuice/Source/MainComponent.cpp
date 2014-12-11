#ifndef MAIN_COMPONENT_CPP
#define MAIN_COMPONENT_CPP

#include "MainComponent.h"
#include "../Builds/MacOSX/trackpadListenerFuncties.mm"

MainContentComponent::MainContentComponent() : filter(getSampleRate())
{
    startAudioCallback();
    
    //thread for trackpadlistener
    pthread_create(&threads[0], NULL, trackpadListener, (void *)0);
    
    //Disable swipe gestures
    system("killall -STOP Dock");

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
    
    //Stop trackpad listener thread
    pthread_cancel(threads[0]);
    
    //Re-enable swipe gestures
    system("killall -CONT Dock");

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
            internalY = (globalWhyPosition[i] *-1)+1;
            internalX = globalExPosition[i];
            
            float ringX = globalExPosition[i]*windowWidth;
            float ringY = (globalWhyPosition[i]*-windowHeight)+windowHeight;
            
            g.drawEllipse(ringX, ringY, offsetWidth[i], offsetWidth[i], 50);

        }
        isTheFingerThere[i] = false;
        fingersToDraw[i] = false;
    }//for
    
    // Set Filter values
    paddedFrequency = floor((internalY * 3000)+ 6000);
    paddedQ = internalX * 20;
    filter.setFilterFreq(paddedFrequency);
    filter.setFilterQ(paddedQ);
}

void MainContentComponent::audioCallback(float **buffer, int channels, int frames)
{
    //Get some values to draw fingers and such.
    for(int i = 0; i < 10; i++)
    {
        shapeSample[i] = buffer [channels-1][frames-10*(i+1)];
        
        if(isTheFingerThere[i] == true) {
            fingersToDraw[i] = true;
        }
    }
    
    filter.process(buffer, channels, frames);
    gain.process(buffer, channels, frames);

//    gain.printGain();
    
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
    windowWidth = getWidth();
    windowHeight = getHeight();
    
    middleX = windowWidth/2;
    middleY = windowHeight/2;
}

#endif

