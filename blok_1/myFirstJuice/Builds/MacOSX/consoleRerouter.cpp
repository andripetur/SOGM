//
//  consoleRerouter.cpp
//  myFirstJuce
//
//  Created by Andri Pétur Þrastarson on 10/12/14.
//
//

#include "consoleRerouter.h"
#include "mainComponent.h"

void consoleRerouter::callBackToMainComponent(int id, float x, float y)
{
    parent->rerouteCallback(id, x, y);
}

void consoleRerouter::redirectStream() {
    std::stringstream   redirectStream;
    std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

    std::string str;
    
    while(std::getline(redirectStream, str))
    {
    fprintf(stdout,"Line: %s\n",str.c_str());
    // loop enter once for each line.
    // Note: str does not include the '\n' character.
    }

    // In real life use RAII to do this. Simplified here for code clarity.
    std::cout.rdbuf(oldbuf);
    
}

void consoleRerouter::parseString(juce::String me)
{
    

}

