#include <iostream>
#include "song.h"
#include "playablesong.h"
#include "notatedsong.h"


int main(int argc, char ** argv)
{
  Song song1;
  song1.setTitle("Never gonna give you up");
  song1.setYear(1988);

  PlayableSong song2; 
  song2.setTitle("Girls just wanna have fun"); 
  song2.setYear(1983);
  song2.set_url("/home/music/girls.mp3");

  song2.play();

  NotatedSong song3; 
  song3.setTitle("Yriii"); 
  song3.setYear(1985);
  song3.set_sheet("/home/music/imsheet.mu");

  song3.display();



  if(song1.setYear(1901) == -1) {
    cout << "Alleen hippe liedjes" << endl;
  } else {

  cout << "Song 1:  " << song1.getTitle() <<
  " uit het jaar:  " <<  song1.getYear() << endl;
  }

  return 0;
}
