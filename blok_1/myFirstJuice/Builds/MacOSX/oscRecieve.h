//
//  oscRecieve.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 08/12/14.
//  mostly borrowed code from https://github.com/hemmer/mlrVST
//

#ifndef __myFirstJuce__oscRecieve__
#define __myFirstJuce__oscRecieve__

#include "../JuceLibraryCode/JuceHeader.h"

#include "OscReceivedElements.h"
#include "UdpSocket.h"
#include "OscPacketListener.h"


#include <iostream>
#include <cstdlib>
#include <cstring>

//forward decleration
class MainContentComponent;


class oscListener : public osc::OscPacketListener,
                    public Thread
{
    
public:
    oscListener(MainContentComponent * const owner);
    
    ~oscListener()
    {
        s.AsynchronousBreak();
        stopThread(2000);
    }

    void run()
    {
        s.Run();
    }
    
    void callBackToMainApp(float x, float y);
    

private:
    MainContentComponent* const parent;
    UdpListeningReceiveSocket s;
    
    int incomingPort = 9109;
    
    JUCE_LEAK_DETECTOR(oscListener);
    

protected:
    void ProcessMessage( const osc::ReceivedMessage& m, const IpEndpointName&
    /*remoteEndpoint*/);
};


#endif /* defined(__myFirstJuce__oscRecieve__) */
