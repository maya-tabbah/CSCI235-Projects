/*
CSCI235 Spring 2024
Maya Tabbah
Project 4 - Derived Class
March 21, 2024
Ghoul.cpp implements the constructors and private and public functions of the Ghoul class
*/

/*
CSCI235 Spring 2024
Project 2 - Derived Classes
Georgina Woo
Dec 23 2023
Ghoul.cpp implements the constructors and private and public functions of the Ghoul class
*/

#include "Ghoul.hpp"

Ghoul::Ghoul() :  decay_{0}, faction_{NONE}, transformation_{false}
{
    setCategory(UNDEAD); 
}

Ghoul::Ghoul(const std::string& name, Category category, int hitpoints, int level, bool tame, int decay, Faction faction, bool transformation) : Creature(name, category, hitpoints, level, tame)
{
    if(!setDecay(decay))
    {
        decay_ = 0;
    }
    faction_ = faction;
    transformation_ = transformation;
}

int Ghoul::getDecay() const
{
    return decay_;
}

bool Ghoul::setDecay(const int& decay)
{
    if(decay >= 0)
    {
        decay_ = decay;
        return true;
    }
    else
    {
        return false;
    }
}

std::string Ghoul::getFaction() const
{
    switch(faction_)
    {
        case FLESHGORGER:
            return "FLESHGORGER";
        case SHADOWSTALKER:
            return "SHADOWSTALKER";
        case PLAGUEWEAVER:
            return "PLAGUEWEAVER";
        default:
            return "NONE";
    }
}

void Ghoul::setFaction(const Faction& faction)
{
    faction_ = faction;
}

bool Ghoul::getTransformation() const
{
    return transformation_;
}

void Ghoul::setTransformation(const bool& transformation)
{
    transformation_ = transformation;
}

/**
    @post   : If the creature is UNDEAD, it becomes tame if not already, as it appreciates the gesture, even though as an UNDEAD it does not really eat. It gains 1 hitpoint from the mysterious powers it receives by wearing the mushroom as a hat. Nothing else happens.
              If the creature is of Faction FLESHGORGER, it becomes so offended by being offered a mushroom that it becomes untamed if it was tame. If it was already untamed, it leaves the Cavern. Nothing else happens.
              If the creature was of Faction SHADOWSTALKER, if it was untame, it hides from the mushroom and nothing happens. If it was tame, it eats the mushroom and loses 1 hitpoint, unless it only had 1 hitpoint left in which case it stays at 1 hitpoint but becomes untame. Nothing else happens.
    @return   : true if the creature leaves the Cavern, false otherwise
*/
bool Ghoul::eatMycoMorsel()
{
    if(getCategory() == "UNDEAD") //if the creature is undead 
    {
        setTame(true);  //it becomes tame 
        setHitpoints(getHitpoints() + 1); //it gains one hitpoint 
        return false; //nothing else happens 
    }

    else if(getFaction() == "FLESHGORGER") //if the creature is a fleshgorger 
    {
        
        if(isTame() == true) //if it was already tames 
        {
            setTame(false); //it becomes untamed 
            return false;
        }
        else //if it was already tamed 
        {
            return true; //it leaves the cavern 
        }  

       
    }
    else if(getFaction() == "SHADOWSTALKER") //if it is a shadowstalker 
    {
        if(isTame() == false) //if it was already untame 
        {
            return false; //nothing happens 
        }
        if(isTame() == true) //if it is tame 
        {
            if(getHitpoints() > 1) //if it is greater than one hitpoint 
            {
                setHitpoints(getHitpoints() - 1); //it loses a hitpoint  
            }
            else if(getHitpoints() == 1) //if it is only at one hitpoint 
            {
                setTame(false); //it becomes untamed 
            }
        return false; //nothing else happens 
        }
    }
    else{
        return false; 
    }
    
}

/**
    @post     : displays Ghoul data in the form:
    GHOUL - [NAME]\n
    CATEGORY: [CATEGORY]\n
    HP: [HITPOINTS]\n
    LVL: [LEVEL]\n
    TAME: [TRUE/FALSE]\n
    DECAY: [DECAY]\n
    FACTION: [FACTION]\n
    IT [CAN/CANNOT] TRANSFORM\n"

    Example:
    GHOUL - JHRAT
    CATEGORY: MYSTICAL
    HP: 4
    LVL: 8
    TAME: TRUE
    DECAY: 3
    FACTION: FLESHGORGER
    IT CAN TRANSFORM

*/
void Ghoul::display() const
{
    std::cout << "GHOUL - " << getName() << "\n" << "CATEGORY: "<< getCategory()<< "\n" << "HP: " << getHitpoints() << "\n" << "LVL: " << getLevel() << "\n" << "TAME: " << (isTame() ? "TRUE" : "FALSE") << "\n" << "DECAY: " << getDecay() << "\n" << "FACTION: " << getFaction() << "\n" << "IT " << (getTransformation() ? "CAN" : "CANNOT") << " TRANSFORM" << "\n" << std::endl; 
}