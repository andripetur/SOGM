#pragma once

#include <string>
#include <iostream>

using namespace std;


// Parent class
class Song
{
public:
  void setTitle(string newTitle);
  int setYear(unsigned short newYear);

  string getTitle();
  unsigned short getYear();

private: 
  string title;
  unsigned short year;

}; // Song{}


