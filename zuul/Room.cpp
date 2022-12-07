#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

void Room::setDescription(char* outline){
  description = new char[30];
  strcpy(description, outline);
  
}

void Room::printDescription(){
  cout << description << endl;
}

void Room::setExits(int north, int west, int south, int east){
  if(north == 1){//north exit
    northExit = 1;
  }
  if(west == 1){//west exit
    westExit = 1;
  }
  if(south == 1){//south exit
    southExit = 1;
  }
  if(east ==1){//east exit
    eastExit = 1;
  }
}

void Room::printExits(){
  cout << "You can exit: ";
  if(northExit == 1){
    cout << "North ";
  }
  if(westExit == 1){
    cout << "West ";
  }
  if(southExit == 1){
    cout << "South ";
  }
  if(eastExit == 1){
    cout << "East";
  }
  cout << " " << endl;
}


