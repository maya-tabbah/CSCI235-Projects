/*
CSCI235 Spring 2024
Maya Tabbah
Project 4 - Derived Class
March 21, 2024
Dragon.cpp implements the constructors and private and public functions of the Dragon class
*/



/*
CSCI235 Spring 2024
Project 2 - Derived Classes
Georgina Woo
Dec 23 2023
Dragon.cpp implements the constructors and private and public functions of the Dragon class
*/

#include "Dragon.hpp"

Dragon::Dragon() : element_{NONE}, number_of_heads_{1}, flight_{false}
{
    setCategory(MYSTICAL); 
    
}


Dragon::Dragon(const std::string& name, Category category, int hitpoints, int level, bool tame, Element element, int number_of_heads, bool flight) : Creature(name, category, hitpoints, level, tame)
{
    element_ = element;
    if(!setNumberOfHeads(number_of_heads))
    {
        number_of_heads_ = 1;
    }
    flight_ = flight;
}

std::string Dragon::getElement() const
{
    switch(element_)
    {
        case FIRE:
            return "FIRE";
        case WATER:
            return "WATER";
        case EARTH:
            return "EARTH";
        case AIR:
            return "AIR";
        default:
            return "NONE";
    }
}

void Dragon::setElement(const Element& element)
{
    element_ = element;
}

int Dragon::getNumberOfHeads() const
{
    return number_of_heads_;
}

bool Dragon::setNumberOfHeads(const int& number_of_heads)
{
    if(number_of_heads > 0)
    {
        number_of_heads_ = number_of_heads;
        return true;
    }
    else
    {
        return false;
    }
}

bool Dragon::getFlight() const
{
    return flight_;
}

void Dragon::setFlight(const bool& flight)
{
    flight_ = flight;
}

/**
@post   : If the creature is UNDEAD, it becomes tame if not already, as it appreciates the gesture, even though as an UNDEAD it does not really eat. 
            It gains 1 hitpoint from the mysterious powers it receives by wearing the mushroom as a hat. Nothing else happens.
            If the creature is an ALIEN, it consumes the mushroom and gains 1 additional hitpoint. Nothing else happens.
            If the creature is MYSTICAL, it consumes the mushroom and gains 1 additional hitpoint if it has FIRE or EARTH affinity (Either by cooking the mushroom first, or by being fungi-tolerant). Nothing else happens.
            But if it is MYSTICAL and has WATER, AIR, or no affinity, if it only has 1 hitpoint left, it doesn't want to risk it and leaves the Cavern. If it has more than 1 hitpoint, it loses 1 hitpoint and becomes untamed if it was tame. Nothing else happens.
@return : true if the creature leaves the Cavern, false otherwise
*/
bool Dragon::eatMycoMorsel()
{

    if(getCategory() == "UNDEAD") //if the creature is undead 
    { 
        setTame(true); //it becomes tame if not already 
        setHitpoints(getHitpoints() + 1); //it gains one hitpoint
        return false;  //returns false bc nothing else happens 
    }

    else if(getCategory() == "ALIEN") //if the creature is an alien 
    {
        setHitpoints(getHitpoints() + 1); //it gains one hit point 
        return false;   //nothing else happens 
    }

    else if(getCategory() == "MYSTICAL") //if the creature is mystical 
    {
        if(getElement() == "FIRE" || getElement() == "EARTH") //if it has a fire or earth affinity 
        {
            setHitpoints(getHitpoints() + 1); //gains an extra hitpoint
            return false;  //nothing else happens 
        }
        else  //if it is mystical and it has water, air, or no affinity 
        {
            if(getHitpoints() > 1) //if it has more than one hitpoint 
            {
                setHitpoints(getHitpoints() - 1); //it loses one hitpoint 
                setTame(false); //and becomes untamed
                return false; //nothing else happens 
            }
            else  //if it only has one hitpoint left 
            {
                return true; //exits cavern 
            }
        }

        
    }
}


/**
    @post     : displays Dragon data in the form:
    "DRAGON - [NAME]\n
    CATEGORY: [CATEGORY]\n
    HP: [HITPOINTS]\n
    LVL: [LEVEL]\n
    TAME: [TRUE/FALSE]\n
    ELEMENT: [ELEMENT]\n
    HEADS: [NUMBER OF HEADS]\n
    IT [CAN/CANNOT] FLY\n"
    
    Example:
    DRAGON - JHIZARD
    CATEGORY: ALIEN
    HP: 7
    LVL: 5
    TAME: TRUE
    ELEMENT: FIRE
    HEADS: 3
    IT CAN FLY
    
*/
void Dragon::display() const
{
    std::cout << "DRAGON - " << getName() << "\n" << "CATEGORY: " << getCategory() << "\n" << "HP: " << getHitpoints() << "\n" << "LVL: " << getLevel() << "\n" << "TAME: " << (isTame() ? "TRUE" : "FALSE") << "\n" << "ELEMENT: " << getElement() << "\n" << "HEADS: " << getNumberOfHeads() << "\n" << "IT " << (getFlight() ? "CAN" : "CANNOT") << " FLY" << "\n" << std::endl;
    
}