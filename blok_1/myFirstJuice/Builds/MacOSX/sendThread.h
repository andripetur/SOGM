//
//  sendThread.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 09/12/14.
//
//
#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>

#ifndef myFirstJuce_sendThread_h
#define myFirstJuce_sendThread_h

class sendThread : public Thread
{
public:
    
    // Constructor
    sendThread() : Thread("OscSend Thread")
    {}
    
    // End Thread
    ~sendThread()
    {
        stopThread(2000);
    }
    
    // Start Thread
    void run()
    {
//        system("/Users/andripetur/HKU/2_Ár/Sogm_files/SendMultiTouches/sendMultiTouches");
    }
};

#endif
