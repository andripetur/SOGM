#include <string>

using namespace std;

class Song
{

private: 
string title;
unsigned short year;

public:
  void setTitle(string newTitle);
  int setYear(unsigned short newYear);

  string getTitle();
  unsigned short getYear();


}; // Song{}

