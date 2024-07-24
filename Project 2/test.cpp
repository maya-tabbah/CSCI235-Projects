//Maya Tabbah 
//February 9, 2024
//test.cpp

#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"


int main()
{

/*
2.1.1 Instantiate a default Dragon
    - Print out the information for the default Dragon based on the format below
*/

/*
NAME: [NAME]\n
CATEGORY: [CATEGORY]\n
HP: [HITPOINTS]\n
LVL: [LEVEL]\n
TAME: [TAME]\n
ELEMENT: [ELEMENT]\n
HEADS: [NUMBER OF HEADS]\n
FLIGHT: [FLIGHT]\n
*/
Dragon hampter; 
std::cout << "NAME: "<<  hampter.getName() << "\n" << "CATEGORY: " << hampter.getCategory() << "\n" << "HP: " << hampter.getHitpoints() << "\n" << "LVL: " << hampter.getLevel() << "\n" << "TAME: " << (hampter.isTame() ? "True" : "False") << "\n" << "ELEMENT: " << hampter.getElement() << "\n" << "HEADS: " << hampter.getNumberOfHeads() << "\n" << "FLIGHT: " << (hampter.getFlight() ? "True" : "False") << "\n" << std::endl;

/*
2.1.2 Instantiate a Dragon with the parameterized constructor with the following creature details:
Name: Smog

- Print out the information for Smog based on the format above
*/

Dragon smog("Smog"); 
std::cout << "NAME: "<<  smog.getName() << "\n" << "CATEGORY: " << smog.getCategory() << "\n" << "HP: " << smog.getHitpoints() << "\n" << "LVL: " << smog.getLevel() << "\n" << "TAME: " << (smog.isTame() ? "True" : "False") << "\n" << "ELEMENT: " << smog.getElement() << "\n" << "HEADS: " << smog.getNumberOfHeads() << "\n" << "FLIGHT: " << (smog.getFlight() ? "True" : "False") << "\n" << std::endl;

/*
2.1.3 Instantiate a Dragon with the parameterized constructor with the following creature details:
    Name: BURNY
    Category: UNDEAD
    Hitpoints: 100
    Level: 10
    Tame: True
    Element: FIRE
    Number of heads: 1
    Flight: True

- Print out the information for Burny based on the format above
*/

Dragon burny("Burny", Creature::UNDEAD, 100, 10, true, Dragon::FIRE, 1, true);
std::cout << "NAME: "<<  burny.getName() << "\n" << "CATEGORY: " << burny.getCategory() << "\n" << "HP: " << burny.getHitpoints() << "\n" << "LVL: " << burny.getLevel() << "\n" << "TAME: " << (burny.isTame() ? "True" : "False") << "\n" << "ELEMENT: " << burny.getElement() << "\n" << "HEADS: " << burny.getNumberOfHeads() << "\n" << "FLIGHT: " << (burny.getFlight() ? "True" : "False") << "\n" << std::endl;

/*
2.1.4 Make the following changes to Burny using the appropriate setter functions:
- Set the element to WATER
- Set the number of heads to 2
- Set the number of heads to 0
- Set the flight flag to False

- Print out the information for Burny based on the format above
*/

burny.setElement(Dragon::WATER); 
burny.setNumberOfHeads(2);
burny.setFlight(false);
std::cout << "NAME: "<<  burny.getName() << "\n" << "CATEGORY: " << burny.getCategory() << "\n" << "HP: " << burny.getHitpoints() << "\n" << "LVL: " << burny.getLevel() << "\n" << "TAME: " << (burny.isTame() ? "True" : "False") << "\n" << "ELEMENT: " << burny.getElement() << "\n" << "HEADS: " << burny.getNumberOfHeads() << "\n" << "FLIGHT: " << (burny.getFlight() ? "True" : "False") << "\n" << std::endl;


/*
2.2.1 Instantiate a default Ghoul
- Print out the information for the default Ghoul based on the format below
*/

/*
NAME: [NAME]\n
CATEGORY: [CATEGORY]\n
HP: [HITPOINTS]\n
LVL: [LEVEL]\n
TAME: [TAME]\n
DECAY: [DECAY]\n
FACTION: [FACTION]\n
TRANSFORM: [TRANSFORM]\n
*/
Ghoul fren; 
std::cout << "NAME: "<<  fren.getName() << "\n" << "CATEGORY: " << fren.getCategory() << "\n" << "HP: " << fren.getHitpoints() << "\n" << "LVL: " << fren.getLevel() << "\n" << "TAME: " << (fren.isTame() ? "True" : "False") << "\n" << "DECAY: " << fren.getDecay() << "\n" << "FACTION: " << fren.getFaction() << "\n" << "TRANSFORM: " << (fren.getTransformation() ? "True" : "False") << "\n" << std::endl;

/*
2.2.2 Instantiate a Ghoul with the parameterized constructor with the following creature details:
Name: Homph

- Print out the information for Homph based on the format above
*/

Ghoul homph("Homph");
std::cout << "NAME: "<<  homph.getName() << "\n" << "CATEGORY: " << homph.getCategory() << "\n" << "HP: " << homph.getHitpoints() << "\n" << "LVL: " << homph.getLevel() << "\n" << "TAME: " << (homph.isTame() ? "True" : "False") << "\n" << "DECAY: " << homph.getDecay() << "\n" << "FACTION: " << homph.getFaction() << "\n" << "TRANSFORM: " << (homph.getTransformation() ? "True" : "False") << "\n" << std::endl;

/*
2.2.3 Instantiate a Ghoul with the parameterized constructor with the following creature details:
Name: CHOMPER
Category: ALIEN
Hitpoints: 100
Level: 10
Tame: True
Decay: 3
Faction: FLESHGORGER
Transform: True

- Print out the information for Chomper based on the format above
*/
Ghoul chomper("CHOMPER", Ghoul::ALIEN, 100, 10, true, 3, Ghoul::FLESHGORGER, true);
std::cout << "NAME: "<<  chomper.getName() << "\n" << "CATEGORY: " << chomper.getCategory() << "\n" << "HP: " << chomper.getHitpoints() << "\n" << "LVL: " << chomper.getLevel() << "\n" << "TAME: " << (chomper.isTame() ? "True" : "False") << "\n" << "DECAY: " << chomper.getDecay() << "\n" << "FACTION: " << chomper.getFaction() << "\n" << "TRANSFORM: " << (chomper.getTransformation() ? "True" : "False") << "\n" << std::endl;


/*
2.2.4 Make the following changes to Chomper using the appropriate setter functions:
- Set the decay to 2
- Set the decay to -20
- Set the faction to SHADOWSTALKER
- Set the transformation flag to False

- Print out the information for Chomper based on the format above
*/

chomper.setDecay(2);
chomper.setDecay(-20); 
chomper.setFaction(Ghoul::SHADOWSTALKER);
chomper.setTransformation(false);
std::cout << "NAME: "<<  chomper.getName() << "\n" << "CATEGORY: " << chomper.getCategory() << "\n" << "HP: " << chomper.getHitpoints() << "\n" << "LVL: " << chomper.getLevel() << "\n" << "TAME: " << (chomper.isTame() ? "True" : "False") << "\n" << "DECAY: " << chomper.getDecay() << "\n" << "FACTION: " << chomper.getFaction() << "\n" << "TRANSFORM: " << (chomper.getTransformation() ? "True" : "False") << "\n" << std::endl;


/*
2.3.1 Instantiate a default Mindflayer
- Print out the information for the default Mindflayer based on the format below
*/

/*
NAME: [NAME]\n
CATEGORY: [CATEGORY]\n
HP: [HITPOINTS]\n
LVL: [LEVEL]\n
TAME: [TAME]\n
SUMMONING: [SUMMONING]\n
[PROJECTILE TYPE 1]: [QUANTITY 1]\n
[PROJECTILE TYPE 2]: [QUANTITY 2]\n
AFFINITIES: \n
[AFFINITY 1]\n
[AFFINITY 2]\n
*/

Mindflayer maya;
std::cout << "NAME: "<<  maya.getName() << "\n" << "CATEGORY: " << maya.getCategory() << "\n" << "HP: " << maya.getHitpoints() << "\n" << "LVL: " << maya.getLevel() << "\n" << "TAME: " << (maya.isTame() ? "True" : "False") << "\n" << "Summoning: " << (maya.getSummoning() ? "True" : "False") << "\n" << std::endl;


/*
2.3.2 Instantiate a Mindflayer with the parameterized constructor with the following creature details:
Name: BIGBRAIN
Category: MYSTICAL
Hitpoints: 100
Level: 10
Tame: True
Projectiles: {{PSIONIC, 2}, {TELEPATHIC, 1}, {PSIONIC, 1}, {ILLUSIONARY, 3}}
Summoning: True
Affinities: {PSIONIC, TELEPATHIC, PSIONIC, ILLUSIONARY}

- Print out the information for Bigbrain based on the format above
*/
//Mindflayer bigbrain("BIGBRAIN", Creature::MYSTICAL, 100, 10, true, {{Mindflayer::PSIONIC, 2}, {Mindflayer::TELEPATHIC, 1}, {Mindflayer::PSIONIC, 1}, {Mindflayer::ILLUSIONARY, 3}}, true, {Mindflayer::PSIONIC, Mindflayer::TELEPATHIC, Mindflayer::PSIONIC, Mindflayer::ILLUSIONARY} );

Mindflayer blob; 
blob.setProjectiles({{Mindflayer::PSIONIC, 2}, {Mindflayer::TELEPATHIC, 1}, {Mindflayer::PSIONIC, 1}, {Mindflayer::ILLUSIONARY, 3}});


for(int i = 0; i < blob.getProjectiles().size(); i++)
{
    Mindflayer::Projectile bloop = blob.getProjectiles()[i];
    std::cout << "TYPE:" << bloop.type_ << std::endl;
    std::cout << "Quantity" << bloop.quantity_ << std::endl;
}

}