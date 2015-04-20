//
//  event.h
//  sogmHans
//
//  Created by Andri Pétur Þrastarson on 02/04/15.
//
//

#ifndef __sogmHans__event__
#define __sogmHans__event__

#include <cstdio>
#include <cstdlib>
#include <iostream>

class Event;
typedef Event* EventPtr;

class Scheduler;
typedef Scheduler *SchedulerPtr;

using namespace std;

class Event
{
    static long number;
    long ID;
    double time;
    EventPtr next, prev;
    SchedulerPtr myScheduler; // the scheduler that holds this event
    
public:
    Event() {
        ID = number++;
        next = prev = NULL;
        time = (rand() % 500);
    }
    
    Event(long time) {
        ID = number++;
        next = prev = NULL;
        this-> time = time;
    }
    
    EventPtr insert(EventPtr ev) {
        EventPtr temp = next;
        next = ev;
        ev->prev = this;
        ev->next  = temp;
        if(temp) temp->prev = ev;
        return ev;
    }
 
    /* {
//    void static swapPlaces(EventPtr a, EventPtr b ) {
//        if(b->next){
//            a->next = b->next;
//            b->next->prev = a;
//        } else {
//            a->next = NULL;
//        }
//        
//        if(a->prev){
//            b->prev = a->prev;
//            a->prev->next = b;
//        } else {
//            b->prev = NULL;
//        }
//        
//        b->next = a;
//        a->prev = b;
//    }
    } // oldSwap */
    
    void static swapPlaces(EventPtr a, EventPtr b ) {
        EventPtr tempA, tempB;
        
        tempA = a->next;
        tempB = b->prev;
        
        if (b->next) {
            a->next = b->next;
            b->next->prev = a;
        } else {
            a->next = NULL;
        }
        
        if (a->prev) {
            b->prev = a->prev;
            a->prev->next = b;
        } else {
            b->next = NULL;
        }
        
        // check if elements are side by side.
        if (tempA == b) {
            b->next = a;
            a->prev = b;
        } else {
            b->next = tempA;
            b->next->prev = b;
        
            a->prev = tempB;
            a->prev->next = a;
        }
    } // swapPlaces()
    
    void show() {
        cout << "ID: " << ID << endl;
        cout << "time: " << time << endl;
//        cout << endl; 
        
        if (prev) {
            cout << "Prev ID: " << prev->ID << endl;
        }
        if(next) {
            cout << "Next ID: " << next->ID << endl << endl;
        } else {
            cout << endl; 
        }
    }
    
    virtual void doit(){
        cout << "Event::doit()" << endl;
        show();
    }
    
    // A recursive function to double linked list info.
    void showAll(){
        // Show this if first in sequence;
        if (!prev) {
            this->show();
        }
        
        // if there is next show it, and call it's showAll
        if (next) {
            next->show();
            next->showAll();
        }
    }
    
    // Operator overloading
    bool operator< (Event b){
        return(time < b.time );
    }
    bool operator<= (Event b){
        return(time <= b.time );
    }
    
    bool operator> (Event b){
        return(time > b.time );
    }
    
    bool operator>= (Event b){
        return(time >= b.time );
    }
    
    long getID(){
        return ID;
    }
    
    void setNextPtr(EventPtr ep){
        this->next = ep;
    }
    
    void setPrevPtr(EventPtr ep){
        this->prev = ep;
    }
    
    Event getNext(){
        return *next; 
    }
    
    EventPtr getNextPtr(){
        return next;
    }
    
    EventPtr getPrevPtr(){
        return prev;
    }
};

#endif /* defined(__sogmHans__event__) */
