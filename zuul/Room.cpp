#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

void Room::setDescription(char* outline){
  description = new char[30];
  strcpy(description, outline);
  
}

void Room::printDescription(){
  cout << description << endl;
}

void Room::setExits(Room* north, Room* west, Room* south, Room* east){
  
  if(north != NULL){//north exit
    northExit = north;
  }else{
    northExit = NULL;
  }
  if(west != NULL){//west exit
    westExit = west;
  }else{
    westExit = NULL;
  }
  if(south != NULL){//south exit
    southExit = south;
  }else{
    southExit = NULL;
  }
  if(east != NULL){//east exit
    eastExit = east;
  }else{
    eastExit = NULL;
  }
}

void Room::printExits(){
  cout << "You can exit: ";
  if(northExit != NULL){
    cout << "North ";
  }
  if(westExit != NULL){
    cout << "West ";
  }
  if(southExit != NULL){
    cout << "South ";
  }
  if(eastExit != NULL){
    cout << "East";
  }
  cout << " " << endl;
}

void Room::printItems(){
  vector <char*>::iterator ptr;

  for(ptr = items.begin(); ptr < items.end(); ptr++){
    cout << (*ptr) << " ";
  }
  cout << " " << endl;
}

void Room::setItems(char* name){
  item = new char[20];
  strcpy(item, name);
  items.push_back(item);
}

Room* Room::getExit(char* direction){
  if(strcmp(direction, "north") == 0){
    return northExit;
  }else if(strcmp(direction, "west") == 0){
    return westExit;
  }else if(strcmp(direction, "south") == 0){
    return southExit;
  }else if(strcmp(direction, "east") == 0){
    return eastExit;
  }
  return NULL;
}

vector <char*> Room::getItems(){
  return items;
}
