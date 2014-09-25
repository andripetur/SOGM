#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.141592654
float SAMPLERATE = 48000.0;

int main() {
  // Select frequency
  int frequency = 480;  

  // Calculate the size of one period
  float onePeriod = SAMPLERATE / frequency; 
  
  //Put dat shit in a for loop
  for(float i = 0; i < onePeriod; i++) {

  //Calculate step size in radians
  float radian = i / onePeriod * 2*M_PI;
 
  cout << sin(radian) << endl;
  
  }

return 0;
}


