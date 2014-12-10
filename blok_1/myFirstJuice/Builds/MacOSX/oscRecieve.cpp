//
//  oscRecieve.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 08/12/14.
//
//

#include "oscRecieve.h"
#include "mainComponent.h"

oscListener::oscListener(MainContentComponent * const owner) :
    Thread("OscListener Thread"),
    parent(owner), 
    s(IpEndpointName("localhost", incomingPort), this)
//    s(IpEndpointName(IpEndpointName::ANY_ADDRESS, incomingPort), this)
{}

void oscListener::ProcessMessage(const osc::ReceivedMessage &m, const IpEndpointName&
 /*remoteEndpoint*/)
{
    std::cout << "isPrcess message doing anything? if you see this yeas" << std::endl;
    
//    (void) remoteEndpoint; // suppress unused parameter warning
    
    try {
        
        String msgPattern = m.AddressPattern();
        
        if (msgPattern == "/finger")
        {
            // we need three arguments for button presses
            const int numArgs = m.ArgumentCount();
            if (numArgs != 3) throw osc::Exception();
            
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            int state; 
            float xPos, yPos;
            // unpack the monome button, row and state (button up or down)
            args >> state >> xPos >> yPos >> osc::EndMessage;
            
            callBackToMainApp(xPos, yPos);
        }
        
    }catch( osc::Exception& e ){
        std::cout << "error while parsing message: "
        << m.AddressPattern() << ": " << e.what() << "\n";
    }
}

void oscListener::callBackToMainApp(float x, float y)
{
//    parent->oscCallback(x, y);
}

