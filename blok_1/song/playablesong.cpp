#include "playablesong.h"
// this -> pointer to the class variable. 

void PlayableSong::set_url(string url)
{
  this->url = url;
}

void PlayableSong::play()
{
  cout << "Now Playing " << url << endl; 
}

void PlayableSong::play(long duration)
{
 cout << "Now Playing " << url << endl; 
 cout << "For: " << duration << "seconds" << endl; 

}

void PlayableSong::play(int from, int to)
{
 cout << "Now Playing " << url << endl; 
 cout << "From: " << from << "To: " << to << endl; 

}



