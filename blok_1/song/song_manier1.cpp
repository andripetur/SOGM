#include <string>
#include <iostream>

using namespace std;

class Song
{

private: 
string title;
unsigned short year;

public:
  void setTitle(string newTitle)
  {
  title = newTitle; 
  }

  int setYear(unsigned short newYear)
  {
    if(newYear < 1900) {
    return -1;
    }
    else year = newYear;
    return 0;
    
  }


  string getTitle()
  {
  return title;
  }

  unsigned short getYear()
  {
  return year;
  }


};


int main(int argc, char ** argv)
{
  Song song1;
  song1.setTitle("Never gonna give you up");

  if(song1.setYear(1901) == -1) {
  cout << "Alleen hippe liedjes" << endl;
  } else {
  cout << "Titel 1: " << song1.getTitle() <<
  " uit het jaar:  " <<  song1.getYear() << endl;
  }

  return 0;
}
