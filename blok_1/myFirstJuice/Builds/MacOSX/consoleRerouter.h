//
//  sendThread.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 09/12/14.
//
//
#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>

#include <iostream>
#include <sstream>

using namespace std;

#ifndef myFirstJuce_sendThread_h
#define myFirstJuce_sendThread_h

class MainContentComponent;

class consoleRerouter : public Thread
{
public:
    
    // Constructor
    consoleRerouter(MainContentComponent * const owner) :
        Thread("Console Rerouter Thread"),
        parent(owner)
    {}
    
    // End Thread
    ~consoleRerouter()
    {
        stopThread(2000);
    }
    
    // Start Thread
    void run()
    {
        redirectStream();
    }
    
    void redirectStream();
    void callBackToMainComponent(int id, float x, float y);
    void parseString(String me );
    
private:
    MainContentComponent * const parent;
};

#endif
