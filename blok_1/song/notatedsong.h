#ifndef _NOTATED_SONG_H_
#define _NOTATED_SONG_H_

#include "song.h"

typedef string Notation;

//// Child Classes
//   inherits everything from song

class NotatedSong : public Song
{
public: 
  void set_sheet(Notation sheet);
  void display();

private: 
  Notation sheet; 
}; // NotatedSong{}

#endif
