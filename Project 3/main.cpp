#include "Creature.hpp"
#include "Cavern.hpp"
#include "ArrayBag.hpp"


int main()
{
Creature oop;
Creature ana; 
Creature pablo; 
Cavern boop; 




oop.setTame(false);
ana.setTame(false);
pablo.setTame(true);

oop.setLevel(7);
ana.setLevel(14);
pablo.setLevel(13);

oop.isTame();
ana.isTame();

oop.setCategory(Creature::ALIEN);
ana.setCategory(Creature::MYSTICAL);
pablo.setCategory(Creature::UNDEAD);

boop.getTameCount();


boop.enterCavern(oop); 
boop.enterCavern(ana);
boop.enterCavern(pablo);

boop.cavernReport();

// std::cout << oop.getCategory();


// std::cout << boop.releaseCreaturesBelowLevel(10) << std::endl;
// std::cout << boop.releaseCreaturesOfCategory("ALIEN") << std::endl;

}