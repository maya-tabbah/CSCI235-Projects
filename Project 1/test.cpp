//Maya Tabbah 
//January 30, 2024
//test.cpp = This tests the creature class
#include "Creature.hpp"



int main(){


//Creature my_creature; //test default constuctor 
/*
//test set and get name 
my_creature.setName("MAAAAAyyyyAAAAAA2003");
std::cout << my_creature.getName() << std::endl;

//test set and get category 
my_creature.setCategory(Creature::ALIEN);
std::cout << my_creature.getCategory() << std::endl; 
//THIS ISNT WORKING FOR UNKNOWN INPUTS 

//test set and get hitpoints 
my_creature.setHitpoints(9999);
std::cout << my_creature.getHitpoints() << std::endl; 

//test set and get level
my_creature.setLevel(999);
std::cout << my_creature.getLevel() << std::endl; 

//test set and get tame 
my_creature.setTame(true);
std::cout << my_creature.isTame() << std::endl; 
*/

/*
  2.1 
  - Instantiate a creature with the default constructor
  - Set its hitpoints to 10 using the appropriate setter function.
  - Set its level to 5 using the appropriate setter functions
  - Set its tame flag to True using the appropriate setter function.

  - Print out the creature's information using the display() function:

  Expected output:
  NAMELESS
  Category: UNKNOWN
  Hitpoints: 10
  Level: 5
  Tame: TRUE
*/

Creature weird_creature; 
weird_creature.setHitpoints(10); 
weird_creature.setLevel(5);
weird_creature.setTame(true); 
weird_creature.display();

/*
  2.2
  - Instantiate a creature with the parameterized constructor with the following creature details:
  Name: Wormy
  Category: MYSTICAL
  Hitpoints: 3
  Level: 2
  - Set Wormy as Tame with the appropriate setter function.

  - Print out the creature's information using the display() function:
*/

Creature wow_creature("Wormy", Creature::MYSTICAL, 3, 2); 
wow_creature.setTame(true);

wow_creature.display();
}