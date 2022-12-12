
#ifndef NAME
#define NAME
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room{
 public:
  char* description;
  Room* northExit;
  Room* westExit;
  Room* southExit;
  Room* eastExit;
  char* item;
  vector <char*> items;

  void setDescription(char*);
  void printDescription();
  /*
   * 0 = no exit there
   * 1 = exit there
   */
  void setExits(Room* north, Room* west, Room* south, Room* east);
  void printExits();
  void setItems(char*);
  void printItems();
  Room* getExit(char*);
  vector <char*> getItems();
};


#endif
