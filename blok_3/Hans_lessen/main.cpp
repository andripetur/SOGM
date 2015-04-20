//
//  main.cpp
//  sogmHans
//
//  Created by Andri Pétur Þrastarson on 02/04/15.
//
//

#include <stdio.h>
#include <cmath>
#include "event.h"
#include "scheduler.h"

int main()
{
    srand (time(0));
    
    long sLength = 10;
    Event *sequence = new Event[sLength];
    
    // connect sequence
    for ( int i = 0; i < sLength-1; ++i) {
        sequence[i].insert(&sequence[i+1]);
    }
    
    // Print sequence
    sequence[0].showAll();
    
    cout << "   sorting..." << endl << endl;
    
    EventPtr next;
    
    // sort sequence.
    for ( int i = 0; i<sLength; i++)
    {
        if(( next = sequence[i].getNextPtr()) != NULL) {
            if( sequence[i] >= *next )
            {
                Event::swapPlaces( &sequence[i], next );
                i = 0;
            }
        }
    }
    
    // sort sequence
//    for ( EventPtr x = &sequence[0]; x->getNextPtr() != NULL; x = x->getNextPtr() ) {
//            if (*x > *(next = x->getNextPtr()))
//            {
//                Event::swapPlaces(x,next);
//                x= next->getPrevPtr(); 
//            }
//    }

    cout << "   finding first event..." << endl << endl;

    // find first event in sequence.
    long firstID = 0;
    for ( int i = 0; i <sLength; ++i) {
        if (sequence[i].getPrevPtr() == NULL ) {
            firstID = sequence[i].getID();
            break;
        }
    }
    
    // print sorted sequence
    sequence[firstID].showAll();
    
//    for ( int i = 0; i <sLength; ++i){
//        sequence[i].show(); 
//    }

    return 0;
}