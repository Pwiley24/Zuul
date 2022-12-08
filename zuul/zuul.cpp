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

  //Big Cats room:
  Room* bigCat = new Room();
  bigCat->setDescription("You are in the Big Cat exibit. It looks like they're out though... You won't be able to cross. Maybe you could distract them with something...");
  bigCat->setExits(0, 0, 0, 1);

  //girrafe room:
  Room* girrafe = new Room();
  girrafe->setDescription("You are in the Girrafe exibit.");
  girrafe->setExits(1, 1, 1, 0);

  //Elephant room:
  Room* elephant = new Room();
  elephant->setDescription("You are in the elephant exibit.");
  elephant->setExits(0, 1, 0, 1);

  //bird room:
  Room* bird = new Room();
  bird->setDescription("You are in the bird exibit");
  bird->setExits(0, 0, 0, 1);

  //alligator room:
  Room* alligator = new Room();
  alligator->setDescription("You are in the Alligator exibit.");
  alligator->setExits(1, 1, 0, 1);

  //Aquatic Creatures room:
  Room* aqua = new Room();
  aqua->setDescription("You are in the Aquatic Creatures exibit.");
  aqua->setExits(1, 1, 1, 0);

  //otter room:
  Room* otter = new Room();
  otter->setDescription("You are in the Otter exibit.");
  otter->setExits(1, 0, 0, 1);

  //polar bear room:
  Room* polar = new Room();
  polar->setDescription("You are in the Polar Bear exibit.");
  polar->setExits(0, 1, 1, 0);

  //penguin room:
  Room* penguin = new Room();
  penguin->setDescriptin("You are in the Penguin exibit.");
  penguin->setExits(1, 0, 0, 0);

  //insect room:
  Room* insect = new Room();
  insect->setDescription("You are in the Insect exibit.");
  insect->setExits(0, 1, 1, 0);

  //reptile room:
  Room* reptile = new Room();
  reptile->setDescription("You are in the Reptile exibit.");
  reptile->setExits(0, 1, 1, 1);

  //panda room:
  Room* panda = new Room();
  panda->setDescription("You are in the Panda exibit.");
  panda->setExits(1, 0, 0, 1);
  


		   
  
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
