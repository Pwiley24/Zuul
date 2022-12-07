#ifndef NAME
#define NAME
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room{
 public:
  char* description;
  int northExit;
  int westExit;
  int southExit;
  int eastExit;
  vector <char[]> items;

  void setDescription(char*);
  void printDescription();
  /*
   * 0 = no exit there
   * 1 = exit there
   */
  void setExits(int north, int west, int south, int east);
  void printExits();

};


#endif
