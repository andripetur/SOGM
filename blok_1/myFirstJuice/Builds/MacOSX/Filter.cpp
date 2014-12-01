//
//  Filter.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#include "Filter.h"

void Filter::setFilterMode(int filterMode)
{
    this->lastFilterMode = this->currentFilterMode;
    this->currentFilterMode = filterMode;
    
} // setFilterMode
