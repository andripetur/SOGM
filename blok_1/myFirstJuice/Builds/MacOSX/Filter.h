//
//  Filter.h
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 01/12/14.
//
//

#ifndef __myFirstJuce__Filter__
#define __myFirstJuce__Filter__

class Filter
{
public:
    void setFilterMode(int filterMode);
    
    void process(float **buffer, int channels, int frames);
    
private:
    int lastFilterMode;
    int currentFilterMode;
};
#endif /* defined(__myFirstJuce__Filter__) */
