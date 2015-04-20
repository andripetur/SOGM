//
//  scheduler.h
//  sogmHans
//
//  Created by Andri Pétur Þrastarson on 16/04/15.
//
//

#ifndef __sogmHans__scheduler__
#define __sogmHans__scheduler__

#include <stdio.h>
#include "event.h"

class Scheduler {
    EventPtr    start,      // pointer to first element of queue
                end,        // pointer to last element of queue
                last;       // pointer to element last inserted in queue
    
    double      tStart,     // lowest timeStamp = timestamp of first element in queue
                tEnd,       // highest timeStamp = timestamp of last element in queue
                tLast;      // timeStamp of last inserted element.
    double      _localtime; // _localtime of this Scheduler
    long        total;      //total number of events present in queue
    double      (*clock)();
    
public:
    Scheduler( double (*fp)()); // constructor needs a clock
    ~Scheduler();               // destructor delets all elements in queue
    bool postForward(EventPtr here, EventPtr aNew);
    bool postaBackward(EventPtr here, EventPtr anew);
    bool post(EventPtr aNew);
    
    long pending() {return total; }
    bool p();                           // process queue
    void show();                        // show queue
    double localTime() {return _localtime; }
    double maxTime() {return tEnd; }
    double End()    { return tEnd;}     // return value of tEnd
    double Start()  { return tStart; }  // return value of tStart
    double Last()   { return tLast; }   // return val of tLast
    void setLocalTime(double val) { _localtime = val; }
    double advance(double delta);       // advances _localtime
    void flush();                       //flushes all pending events
    
};

double SampleClock()
{
    static double val = 0.0;
    double res = val; val+= 0.001;
    return res;
}
#endif /* defined(__sogmHans__scheduler__) */
