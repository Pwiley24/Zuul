#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

void play();
void printInventory(vector<char*> inventory);

/*
 * Note for Exit setting: 0 = no exit; 1 = exit there
 */

void play(){
  vector <char*> inventory;
  bool won = false;
  char* input = new char[20];
  
  //gate exit room:
  Room* gateExit = new Room();
  gateExit->setDescription("You are at the Zoo exit gates.");
   
  
  //information center:
  Room* infoCenter = new Room();
  infoCenter->setDescription("You are in the Information Center.");
 
  //Big Cats room:
  Room* bigCat = new Room();
  bigCat->setDescription("You are in the Big Cat exibit. It looks like they're out though... You won't be able to cross. Maybe you could distract them with something...");
 
  //girrafe room:
  Room* girrafe = new Room();
  girrafe->setDescription("You are in the Girrafe exibit.");
   girrafe->setItems("Orange Key");

  //Elephant room:
  Room* elephant = new Room();
  elephant->setDescription("You are in the elephant exibit.");
   elephant->setItems("Bamboo");

  //bird room:
  Room* bird = new Room();
  bird->setDescription("You are in the bird exibit");
 
  //alligator room:
  Room* alligator = new Room();
  alligator->setDescription("You are in the Alligator exibit.");
  alligator->setItems("Red Meat");
  
  //Aquatic Creatures room:
  Room* aqua = new Room();
  aqua->setDescription("You are in the Aquatic Creatures exibit.");
 
  //otter room:
  Room* otter = new Room();
  otter->setDescription("You are in the Otter exibit.");
 
  //polar bear room:
  Room* polar = new Room();
  polar->setDescription("You are in the Polar Bear exibit.");
 
  //penguin room:
  Room* penguin = new Room();
  penguin->setDescription("You are in the Penguin exibit.");
   penguin->setItems("Blue Key");

  //insect room:
  Room* insect = new Room();
  insect->setDescription("You are in the Insect exibit.");
 
  //reptile room:
  Room* reptile = new Room();
  reptile->setDescription("You are in the Reptile exibit.");
 
  //panda room:
  Room* panda = new Room();
  panda->setDescription("You are in the Panda exibit. It looks like they're out though... You won't be able to cross. Maybe you can distract them with something...");
 
  //Bear room:
  Room* bear = new Room();
  bear->setDescription("You are in the Bear exibit.");
 
  //monkey room:
  Room* monkey = new Room();
  monkey->setDescription("You are in the Monkey exibit.");
  monkey->setItems("Yellow Key");
  
  //set the exits:
  gateExit->setExits(infoCenter, NULL, NULL, NULL);
  infoCenter->setExits(NULL, bigCat, gateExit, alligator);
  bigCat->setExits(NULL, NULL, NULL, NULL);//will change if you have item
  girrafe->setExits(NULL, elephant, bigCat, NULL);
  elephant->setExits(NULL, bird, NULL, girrafe);
  alligator->setExits(reptile, infoCenter, NULL, aqua);
  aqua->setExits(insect, alligator, otter, NULL);
  otter->setExits(aqua, NULL, NULL, polar);
  polar->setExits(NULL, otter, penguin, NULL);
  penguin->setExits(polar, NULL, NULL, NULL);
  insect->setExits(NULL, reptile, aqua, NULL);
  reptile->setExits(NULL, panda, alligator, insect);
  panda->setExits(NULL, NULL, NULL, NULL);//will change if you have item
  bear->setExits(NULL, monkey, panda, NULL);
  monkey->setExits(NULL, NULL, NULL, bear);

  Room* currentRoom = gateExit;



  
  cout << "You are in a zoo. You need to get out. But the gates are locked." <<endl;
 		  

  //Move loop:
  while (won == false){ //while you haven't won yet, continue making moves
    currentRoom->printDescription();
    currentRoom->printExits();
    currentRoom->printItems();
    printInventory(inventory);
      cout << "Make a move (north, west, east, south, pickup, drop):" << endl;
      cin.get(input, 10);
      cin.ignore(10, '\n');
      if(strcmp(input, "north") == 0 &&
	 currentRoom->northExit != NULL){ //go north if they can
	  currentRoom = currentRoom->getExit("north");
      }else if(strcmp(input, "west") == 0 &&
	       currentRoom->westExit != NULL){//go west if they can
	currentRoom = currentRoom->getExit("west");
      }else if(strcmp(input, "south") == 0 &&
	       currentRoom->southExit != NULL){//go south if can
	currentRoom = currentRoom->getExit("south");
      }else if(strcmp(input, "east") == 0 &&
	        currentRoom->eastExit != NULL){//go east if can
	currentRoom = currentRoom->getExit("east");
      }else if(strcmp(input, "pickup") == 0){
	vector <char*> roomItems = currentRoom->getItems();
	if(roomItems.size() != 0){//something to pick up
	  vector <char*>::iterator ptr;
	  for(ptr = roomItems.begin(); ptr < roomItems.end(); ptr++){
	    inventory.push_back(*ptr);//add all items to inventory
	  }
	}
      }else if(strcmp(input, "drop") == 0 &&
	       inventory.size() != 0){//something to drop
	cout << "What would you like to drop? " << endl;
	printInventory(inventory);
	//check input to see if it matches item in inventory
	//checkDrop(inventory, input)
	
      }else {//no exit
	cout << "Sorry, you can't perform that action." << endl;
      }
  }
  
};



void printInventory(vector<char*> inventory){
  cout << "Inventory: ";
  vector <char*>::iterator ptr;

  for(ptr = inventory.begin(); ptr < inventory.end(); ptr++){
    cout << (*ptr) << " ";
  }
  cout << "." << endl;
}
 

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
