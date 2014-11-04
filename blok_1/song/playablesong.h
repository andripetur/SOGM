#include "song.h"

//// Child Classes
//   inherits everything from song

class PlayableSong : public Song
{
public:
  void set_url(string url);
  void play();
  void play(long duration);
  void play(int from, int to); 

private: 
  string url;

}; // PlayableSong{}

