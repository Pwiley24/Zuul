#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

void play();
bool winningInventory(vector <char*> inventory);
void printInventory(vector<char*> inventory);

/*
 * This program is a zuul program set in the zoo. The goal as the user is to collect the three keys and 
 * escape the zoo through the exit gates.
 *Note for Exit setting: 0 = no exit; 1 = exit there.
 *Author: Paige Wiley
 *Date: 12-15-22
 */

void play(){
  vector <char*> inventory;
  bool won = false;
  char* input = new char[20];
  
  //gate exit room:
  Room* gateExit = new Room();
  gateExit->setDescription("You are at the Zoo exit gates.");
  gateExit->setName("Gate Exit"); 

  
  //information center:
  Room* infoCenter = new Room();
  infoCenter->setDescription("You are in the Information Center.");
  infoCenter->setName("Information Center");
  
  
  //Big Cats room:
  Room* bigCat = new Room();
  bigCat->setDescription("You are in the Big Cat exibit. It looks like they're out though... You won't be able to cross. Maybe you could distract them with something...");
  bigCat->setName("Big Cats");
  
  
  //girrafe room:
  Room* girrafe = new Room();
  girrafe->setDescription("You are in the Girrafe exibit.");
  girrafe->setItems("Orange Key");
  girrafe->setName("Girrafe");
  

  //Elephant room:
  Room* elephant = new Room();
  elephant->setDescription("You are in the elephant exibit.");
  elephant->setItems("Bamboo");
  elephant->setName("Elephant");
  
  
  //bird room:
  Room* bird = new Room();
  bird->setDescription("You are in the bird exibit");
  bird->setName("Bird");
  
  
  //alligator room:
  Room* alligator = new Room();
  alligator->setDescription("You are in the Alligator exibit.");
  alligator->setItems("Red Meat");
  alligator->setName("Alligator");
  
  
  //Aquatic Creatures room:
  Room* aqua = new Room();
  aqua->setDescription("You are in the Aquatic Creatures exibit.");
  aqua->setName("Aquatic Creatures");
  
  
  //otter room:
  Room* otter = new Room();
  otter->setDescription("You are in the Otter exibit.");
  otter->setName("Otter");
  
  
  //polar bear room:
  Room* polar = new Room();
  polar->setDescription("You are in the Polar Bear exibit.");
  polar->setName("Polar Bears");

  
  //penguin room:
  Room* penguin = new Room();
  penguin->setDescription("You are in the Penguin exibit.");
  penguin->setItems("Blue Key");
  penguin->setName("Penguins");
  

  //insect room:
  Room* insect = new Room();
  insect->setDescription("You are in the Insect exibit.");
  insect->setName("Insects");
  
  
  //reptile room:
  Room* reptile = new Room();
  reptile->setDescription("You are in the Reptile exibit.");
  reptile->setName("Reptiles");

  
  //panda room:
  Room* panda = new Room();
  panda->setDescription("You are in the Panda exibit. It looks like they're out though... You won't be able to cross. Maybe you can distract them with something...");
  panda->setName("Pandas");

  
  //Bear room:
  Room* bear = new Room();
  bear->setDescription("You are in the Bear exibit.");
  bear->setName("Bears");

  
  //monkey room:
  Room* monkey = new Room();
  monkey->setDescription("You are in the Monkey exibit.");
  monkey->setItems("Yellow Key");
  monkey->setName("Monkeys");

  
  //set the exits:
  gateExit->setExits(infoCenter, NULL, NULL, NULL);
  infoCenter->setExits(NULL, bigCat, gateExit, alligator);
  bigCat->setExits(NULL, NULL, NULL, infoCenter);//will change if you have item
  girrafe->setExits(NULL, elephant, bigCat, NULL);
  elephant->setExits(NULL, bird, NULL, girrafe);
  alligator->setExits(reptile, infoCenter, NULL, aqua);
  aqua->setExits(insect, alligator, otter, NULL);
  otter->setExits(aqua, NULL, NULL, polar);
  polar->setExits(NULL, otter, penguin, NULL);
  penguin->setExits(polar, NULL, NULL, NULL);
  insect->setExits(NULL, reptile, aqua, NULL);
  reptile->setExits(NULL, panda, alligator, insect);
  panda->setExits(NULL, NULL, NULL, reptile);//will change if you have item
  bear->setExits(NULL, monkey, panda, NULL);
  monkey->setExits(NULL, NULL, NULL, bear);

  Room* currentRoom = gateExit;



  
  cout << "You are in a zoo. You need to get out. But the gates are locked." <<endl;
  cout << "\n" << endl;
 		 

  //Move loop:
  while (won == false){ //while you haven't won yet, continue making moves
    currentRoom->printDescription();
    currentRoom->printExits();
    currentRoom->printItems();
    printInventory(inventory);
      cout << "Make a move (north, west, east, south, pickup, drop):" << endl;
      cin.get(input, 10);
      cin.ignore(10, '\n');

      //go north
      if(strcmp(input, "north") == 0 &&
	 currentRoom->northExit != NULL){ //go north if they can
	  currentRoom = currentRoom->getExit("north");

	  //go west
      }else if(strcmp(input, "west") == 0 &&
	       currentRoom->westExit != NULL){//go west if they can
	currentRoom = currentRoom->getExit("west");

	//go south:
      }else if(strcmp(input, "south") == 0 &&
	       currentRoom->southExit != NULL){//go south if can
	currentRoom = currentRoom->getExit("south");

	//winning condition:
      }else if(strcmp(input, "south") == 0 &&
	       strcmp(currentRoom->getName(), "Gate Exit") == 0 &&
	       winningInventory(inventory)){//you are exiting the zoo gates and have all the keys
	cout << "Congratulations! You escaped the Zoo!" << endl;
	won = true;

	//go east:
      }else if(strcmp(input, "east") == 0 &&
	        currentRoom->eastExit != NULL){//go east if can
	currentRoom = currentRoom->getExit("east");

	//pickup command:
      }else if(strcmp(input, "pickup") == 0){
	vector <char*> roomItems = currentRoom->getItems();
	if(roomItems.size() != 0){//something to pick up
	  vector <char*>::iterator ptr;
	  for(ptr = roomItems.begin(); ptr < roomItems.end(); ptr++){
	    inventory.push_back(*ptr);//add all items to inventory
	    currentRoom->clearItems(); //remove from room
	  }
	}

	//drop command:
      }else if(strcmp(input, "drop") == 0 &&
	       inventory.size() != 0){//something to drop
	cout << "What would you like to drop? " << endl;
	printInventory(inventory);
	
	//check input to see if it matches item in inventory:
	cin.get(input, 20);
	cin.ignore(20, '\n');
	vector <char*>::iterator ptr;
	for(ptr = inventory.begin(); ptr < inventory.end(); ptr++){
	  if(strcmp(input, (*ptr)) == 0){//input matches one in the inventory
	    //drop item and add to room:
	    inventory.erase(ptr);
	    currentRoom->setItems(input);
	  }
	}
	
      }else {//no exit
	cout << "Sorry, you can't perform that action." << endl;
      }


      //check if you can now pass big cats or panda exibits:
      vector <char*> items;
      if(strcmp(currentRoom->getName(), "Big Cats") == 0){//if you are currently in big cat exibit
	items = currentRoom->getItems();
	vector <char*>::iterator ptr;
	
	for(ptr = items.begin(); ptr < items.end(); ptr++){
	  if(strcmp((*ptr), "Red Meat") == 0){
	    bigCat->setExits(girrafe, NULL, NULL, infoCenter);
	    bigCat->setDescription("You are in the Big Cat exibit. It looks safe to cross now that they're distracted.");
	    currentRoom = bigCat;
	  }
	}
	
      }else if(strcmp(currentRoom->getName(), "Pandas") == 0){//if you are currently in panda exibit
	items = currentRoom->getItems();
	vector <char*>::iterator ptr;

	for(ptr = items.begin(); ptr < items.end(); ptr++){
	  if(strcmp((*ptr), "Bamboo") == 0){
	    panda->setExits(bear, NULL, NULL, reptile);
	    panda->setDescription("You are in the Panda exibit. It looks safe to cross now that they're distracted.");
	    currentRoom = panda;
	  }
	}
      }

     
      
      cout << "\n" << endl;
  }
  
};

/*
 *You need 3 keys to win: Orange, Blue, and Yellow
 */
bool winningInventory(vector <char*> inventory){
  vector <char*>::iterator ptr;
  int keys = 0; 
  for(ptr = inventory.begin(); ptr < inventory.end(); ptr++){
    if(strcmp((*ptr), "Orange Key") == 0 ||
       strcmp((*ptr), "Yellow Key") == 0 ||
       strcmp((*ptr), "Blue Key") == 0){
      keys++;
    }

    if(keys == 3){
      return true;
    }
  }
  return false;
}


void printInventory(vector<char*> inventory){
  cout << "Inventory: ";
  vector <char*>::iterator ptr;

  for(ptr = inventory.begin(); ptr < inventory.end(); ptr++){
    cout << (*ptr) << " ";
  }
  cout << " " << endl;
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
