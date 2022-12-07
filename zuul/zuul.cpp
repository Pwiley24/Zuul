#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

void play();

/*
 * Note for Exit setting: 0 = no exit; 1 = exit there
 */

void play(){
  //gate exit room:
  Room* gateExit = new Room();
  gateExit->setDescription("You are at the Zoo exit gates.");
  gateExit->setExits(1, 0, 0, 0);

  //information center:
  Room* infoCenter = new Room();
  infoCenter->setDescription("You are in the Information Center.");
  infoCenter->setExits(0, 1, 1, 1);

  gateExit->printExits();
  infoCenter->printExits();
		   
  
};


int main(){
  bool playing = true;
  char input;
  while(playing){
    play();
    cout << "Play again?" << endl;
    cin >> input;
    cin.ignore(10, '\n');
    if(input == 'n'){
      playing = false;
    }
  }
  
  return 0;
}
