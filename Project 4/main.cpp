/*
CSCI235 Spring 2024
Maya Tabbah
Project 4 - Main
March 21, 2024
main.cpp - tests the functions we've made 
*/




#include "Creature.hpp"
#include "Dragon.hpp"
#include "Ghoul.hpp"
#include "Mindflayer.hpp"
#include "Cavern.hpp"

int main()
{
    
    //Creature uhh; 
    Dragon boo;
    Ghoul idk; 

    Cavern help ("creatures.csv"); 

   // help.displayCreatures();

    help.displayCategory("ALIEN");

     //help.mycoMorselFeast();


    return 0; 
}