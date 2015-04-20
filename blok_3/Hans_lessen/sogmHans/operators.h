//
//  operators.h
//  sogmHans
//
//  Created by Andri Pétur Þrastarson on 02/04/15.
//
//

#ifndef __sogmHans__operators__
#define __sogmHans__operators__

#include <stdio.h>

class Iets{
    double value;
public:
    Iets() {
        value = 0;
    }
    
    Iets(double val) {
        value = val;
    }
    
    double plus(iets b) {
        return value + b.value;
    }
    
    double operator+ (Iets b) {
        return value + b.value;
    }
};

#endif /* defined(__sogmHans__operators__) */
