/*
    Maya Tabbah 
    CSCI 235 - Spring 2024
    Cavern.cpp = The implementation of the subclass of array bag
*/
#include "Cavern.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
*/
Cavern::Cavern() : ArrayBag<Creature>()
{
    level_sum_ = 0; 
    tame_count_ = 0;
}

/** 
     * @param   :   A reference to a Creature entering the Cavern
     * @post    :   If the given Creature is not already in the Cavern, add Creature to the Cavern and updates the level sum and the tame Creature count if the creature is tame.
     * @return  :   returns true if a Creature was successfully added to the Cavern, false otherwise
                :   Hint: Use the above definition of equality will help determine if a Creature is already in the Cavern
**/
bool Cavern::enterCavern(const Creature &entering)
{
    if(!contains(entering)) //if creature is not already in cavern
    {
        add(entering); //add them to the cavern
        level_sum_ = level_sum_ + entering.getLevel(); //add the creatures level to the level sum

        if(entering.isTame()) //if the creature is tame 
        {
            tame_count_++;  //add one to the tame count 
        }

        return true; //return true since it is added 
    }
    else if(contains(entering)) //if the character was already contained 
    {
        return true; //return true since character was accounted for 
    }
    else
    {
        return false; //was not successfully added return false
    }
}

/** 
     * @param   :   A  reference to a Creature leaving the Cavern
     * @return  :  returns true if a creature was successfully removed from the Cavern (i.e. items_), false otherwise
     * @post    :    removes the creature from the Cavern and updates the level sum. 
                     If the Creature is tame it also updates the tame count.
**/
bool Cavern::exitCavern(const Creature &exiting)
{
    if(remove(exiting))    //if the creature is being removed
    {
        if(exiting.isTame() == true)   //and if the creature is tame 
        {
            tame_count_--;          //reduce tame count by one 
        }
        level_sum_ = level_sum_ - exiting.getLevel();   //subtract characters level from level sum
        return true;            
    }
    else{
        return false;
    }
}

/** 
* @return   :  The integer level count of all the creatures currently in the Cavern
**/
int Cavern::getLevelSum() const
{
    return level_sum_;
}

/**
 * @return   :  The average level (int) of all the creatures in the Cavern
 * @post     :  Computes the average level (double) of the Cavern rounded to the NEAREST integer.
 **/
int Cavern::calculateAvgLevel() const
{
    //we calculate the average level by adding all the levels of each character which was done in enter cavern and dividing it by the number of creatures in cavern

    int avg = 0;
    if(getCurrentSize() > 0 ) //if the current size is greater than 0 
    {
        avg = round(getLevelSum() / getCurrentSize());   //we divide the level sum by the current size and round
    }

    return avg;  

}

/**
    * @return   :  The integer count of tame Creatures in the Cavern
**/
int Cavern::getTameCount() const
{
    return tame_count_;
}

/**
     * @return   :  The percentage (double) of all the tame creatures in the Cavern
     * @post     :   Computes the percentage of tame creatures in the Cavern rounded up to 2 decimal places.
     **/
double Cavern::calculateTamePercentage() const
{
    if(getCurrentSize() > 0)
    {
    double mult = 100.0*(double(getTameCount()) / getCurrentSize());  //we divide the tame count by the currrent size multiplying it by 100 for the percentage value keeping the double output in mind
    double mul2 = std::ceil(100*mult);  //we use ceil to round up and we multiply the previous variable by 100 again 
    double percent = mul2 / 100; //we redivide to ensure the percentage and its double output 
    return percent;
    }
    else
    {
        return 0.0;
    }
    

}

/**
    * @param  :   A reference to a string representing a creature Category with value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"]
    * @return  :  An integer tally of the number of creatures in the Cavern of the given category. 
                If the argument string does not match one of the expected category values, the tally is zero. 
                NOTE: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Cavern::tallyCategory(const std::string &category) const
{
    int creature_tally = 0; 
    for(int i = 0; i < getCurrentSize(); i++) //looping through the current size 
    {
        if(items_[i].getCategory() == category)  //we compare the current item's category to the parameter 
        {
            creature_tally++;  //if it matches we increase the tally
        }
    }
    return creature_tally;
}

 /**
    @param  :   An integer representing the level threshold of the creatures to be removed from the Cavern, with default value 0
    @post   :   Removes all creatures from the Cavern whose level is less than the given level. If no level is given, removes all creatures from the Cavern. Ignore negative input.
    @return :   The number of creatures removed from the Cavern
*/
int Cavern::releaseCreaturesBelowLevel(int removed)
{
    int count = 0; 

    if(removed == 0) //if theres no level given we clear 
    {
        clear();
        level_sum_ = 0; 
        tame_count_ = 0; 
    }
    int size = getCurrentSize(); //setting a variable to the current size so the size doesnt decrease when we loop through 

    for(int i = 0; i < size; i++) // traverising through current size of cavern
    {
        if(items_[i].getLevel() < removed) //if the current item level is less than 0 
        {
            exitCavern(items_[i]); //remove that currently indexed item
            count++; //add one to the removed count 
        }

    }
    return count;
}

/**
    @param  : A reference to a string representing a creature Category with a value in ["UNKNOWN", "UNDEAD", "MYSTICAL", "ALIEN"], or default value "ALL" if no category is given
    @post   : Removes all creatures from the Cavern whose category matches the given category. If no category is given, removes all creatures from the Cavern.
    @return : The number of creatures removed from the Cavern
            NOTE: no pre-processing of the input string necessary, only uppercase input will match. If the input string does not match one of the expected category values, do not remove any creatures.
*/
int Cavern::releaseCreaturesOfCategory(const std::string &removed)
{
    int count = 0; 

    if(removed == "ALL") //if no category or default given we clear 
    {
        clear();
        level_sum_ = 0; 
        tame_count_ = 0; 
    }

    int size = getCurrentSize(); // setting a variable to the current size so the size doesnt decrease when we loop through

    for(int i = 0; i < size; i++) //traversing through current size of cavern
    {
        if(items_[i].getCategory() == removed) //if the current item's category matches the parameter
        {
            exitCavern(items_[i]);  //they exit the cavern
            count++;
        }
    }
    return count;

}

/**
     * @post    : Outputs a report of the creatures currently in the Cavern in the form:
                 "UNKNOWN: [x]\nUNDEAD: [x]\nMYSTICAL: [x]\nALIEN: [x]\n\n AVERAGE LEVEL: [x]\nTAME:[x]%\n"
                Note that the average level should be rounded to the NEAREST integer, and the percentage of tame creatures in the Cavern should be rounded to 2 decimal places.

                Example output: 
                UNKNOWN: 1
                UNDEAD: 3
                MYSTICAL: 2
                ALIEN: 1

                AVERAGE LEVEL: 5
                TAME: 85.72%
    */
void Cavern::cavernReport() const
{
    std::cout << "UNKNOWN: " << tallyCategory("UNKNOWN") << "\n" << "UNDEAD: " << tallyCategory("UNDEAD") << "\n" << "MYSTICAL: " << tallyCategory("MYSTICAL") << "\n" << "ALIEN: " << tallyCategory("ALIEN") << "\n" << "\n" << "AVERAGE LEVEL: " << calculateAvgLevel() << "\n" << "TAME: " << calculateTamePercentage() << "%" << "\n" <<std::endl;
}
