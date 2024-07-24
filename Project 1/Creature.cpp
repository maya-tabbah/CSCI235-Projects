//Maya Tabbah 
//January 30, 2024
//Creature.cpp = the implementation for the creature class 

#include "Creature.hpp"

 /**
      Default constructor.
      Default-initializes all private members. 
      Default creature name: "NAMELESS". 
      Booleans are default-initialized to False. 
      Default enum value: UNKNOWN 
      Default Hitpoints and Level: 1.
   */

Creature::Creature():name_{"NAMELESS"}, category_{UNKNOWN}, hitpoints_{1}, level_{1},is_tame_{false}{}

/**
    Parameterized constructor.
    @param      : The name of the creature (a string). Set the creature's name to NAMELESS if the provided string contains only non-alphabetic characters.
    @param      : The category of the creature (a Category enum) with default value UNKNOWN
    @param      : The creature's hitpoints (an integer) , with default value 1 if not provided, or if the value provided is 0 or negative
    @param      : The creature's level (an integer), with default value 1 if not provided, or if the value provided is 0 or negative
    @param      : A flag indicating whether the creature is tame, with default value False
    @post       : The private members are set to the values of the corresponding parameters. The name is converted to UPPERCASE if it consists of alphabetical characters only, otherwise it is set to NAMELESS.
*/

Creature::Creature(const std::string &name, Category category, int hitpoints, int level, bool tame): Creature() { 
   setName(name); // checks valid name
   setCategory(category); //checks valid category   //I THINK THIS IS WRONG
   (hitpoints > 0) ? hitpoints_ = hitpoints: hitpoints_ = 1;
    (level > 0) ? level_ = level: level_ = 1;
    is_tame_ = tame; 

}

/**
    @param : the name of the Creature, a reference to string
    @post  : sets the Creature's name to the value of the parameter in UPPERCASE. 
             (convert any lowercase character to uppercase)
             Only alphabetical characters are allowed. 
           : If the input contains only non-alphabetic characters, do nothing.
    @return : true if the name was set, false otherwise
*/
bool Creature::setName(const std::string &name) 
{
    std::string nameUpper = "";
    for(int i = 0; i <name.size();i++)
    {
        if(std::isalpha(name[i]))
        {
            nameUpper+= toupper(name[i]);
        }
    }

    if(nameUpper != "")
    {
        name_ = nameUpper;
        return true;
    }
    else
    {
        return false; 
    }
}

/**
    @return : the name of the Creature
*/
std::string Creature::getName() const
{
    return name_;
}


/**
     @param  : a reference to Category, the category of the Creature (an enum)
    @post   : sets the Creature's category to the value of the parameter
            : If the given category was invalid, set race_ to UNKNOWN.
*/
void Creature::setCategory(const Category &category)
{
    if(category == UNDEAD)
    {
        category_ = UNDEAD;
    }
    else if(category == MYSTICAL)
    {
        category_ = MYSTICAL; 
    }
    else if(category == ALIEN)
    {
        category_ = ALIEN; 
    }
    else
    {
        category_ = UNKNOWN;    
    }
}

/**
    @return : the race of the Creature (in string form)
*/
std::string Creature::getCategory() const
{
    if(category_ == UNDEAD)
    {
        return "UNDEAD";
    }
    else if(category_ == MYSTICAL)
    {
        return "MYSTICAL";
    }
    else if(category_ == ALIEN)
    {
        return "ALIEN";
    }
    else
    {
        return "UNKNOWN";
    }
}

/**
    @param  : an integer that represents the creature's hitpoints
    @pre    : hitpoints >= 0 : Characters cannot have negative hitpoints 
            (do nothing for invalid input)
    @post   : sets the hitpoints private member to the value of the parameter
    @return : true if the hitpoints were set, false otherwise
*/
bool Creature::setHitpoints(const int &hitpoints)
{
    if(hitpoints >= 0)
    {
        hitpoints_ = hitpoints;
        return true;
    }
    else
    {
        return false;
    }
}

/**
    @return : the value stored in hitpoints_
*/
int Creature::getHitpoints() const
{
    return hitpoints_; 
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative level
    @post   : sets the level private member to the value of the parameter 
            (do nothing for invalid input)
    @return : true if the level was set, false otherwise
*/
bool Creature::setLevel(const int &level){
    if(level >= 0)
    {
        level_ = level;
        return true;
    }
    else
    {
        return false; 
    }
}

/**
    @return : the value stored in level_
*/
int Creature::getLevel() const
{
    return level_; 
}

/**
    @param  : a boolean value
    @post   : sets the tame flag to the value of the parameter
*/
void Creature::setTame(const bool &tame)
{
    is_tame_ = tame; 
}

/**
    @return true if the creature is tame, false otherwise
    Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getTame
*/
bool Creature::isTame() const
{
    if(is_tame_ == true)
    {
        return true;
    }
    else
    {
        return false; 
    }
}

/**
@post     : displays Creature data in the form:
            "[NAME]\n
            Category: [CATEGORY]\n
            Level: [LEVEL]\n
            Hitpoints: [Hitpoints]\n
            Tame: [TRUE/FALSE]"   
*/
void Creature::display() const
{
    std::cout << getName() << "\n" << "Category: " << getCategory() << "\n" << "Level: " << getLevel() << "\n"<< "Hitpoints: " << getHitpoints() << "\n" << "Tame: " << (isTame() ? "TRUE" : "FALSE") << std::endl;
}
