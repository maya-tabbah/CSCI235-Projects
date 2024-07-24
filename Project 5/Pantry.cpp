/*
    Maya Tabbah 
    CS235 - Spring 2024 
    April 4, 2024 
    Pantry.cpp = implementation of the pantry class
*/



#include "Pantry.hpp"


/**
    Default Constructor
*/
Pantry::Pantry(){}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
        Name: A string
        Description: A string
        Quantity: A non negative integer
        Price: A non negative integer
        Recipe: A list of Ingredient titles of the form [NAME1] [NAME2];
        For example, to make this ingredient, you need (Ingredient 1 AND Ingredient 2)
        The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The recipe are separated by a semicolon and may be NONE.
        - The recipe may be in any order.
        - If any of the recipe are not in the list, they should be created as new ingredients with the following information:
            - Title: The name of the ingredient
            - Description: "UNKNOWN"
            - Quantity: 0
            - Recipe: An empty vector
        - However, if you eventually encounter a ingredient that matches one of the "UNKNOWN" ingredients while parsing the file, you should update all the ingredient details.
        
        For example, given a row in the file:
        Inferno_Espresso,An energizing elixir brewed with mystical flames providing resistance to caffeine crashes for a limited time.,1,50,Fiery_Bean Ember_Spice

        The order of the ingredients in the list:
        Fiery_Bean, Ember_Spice, Inferno_Espresso
        Hint: update as needed using addIngredient()
        
    @post: Each line of the input file corresponds to a ingredient to be added to the list. No duplicates are allowed.
    Hint: use std::ifstream and getline()
*/

Pantry::Pantry(const std::string input_file)
{
    std::ifstream inFile(input_file);
    std::string skip_line, string_name, string_description, string_quantity, string_price, string_recipie; 
    int i_quantity, i_price; 
   // std::vector<Ingredient> *param_recipies; 

     std::getline(inFile, skip_line); //skips the first line

     while(std::getline(inFile, skip_line)) //while the header is being checked
     {
        std::istringstream chk(skip_line);    

        //setting variable names to column names in csv file
        std::getline(chk, string_name, ',');
        std::getline(chk, string_description, ',');
        std::getline(chk, string_quantity, ',');
        std::getline(chk, string_price, ',');
        std::getline(chk, string_recipie, ',');

        //setting int values to the string value recieved
        std::istringstream in1(string_quantity);
        in1 >> i_quantity;

        std::istringstream in2(string_price);
        in1 >> i_price;


       // std::string dummy_recipie; 
        std::istringstream dr(string_recipie);

       // if(string_recipie != "NONE")
        //{
            //while(std::getline(dr, dummy_recipie, ' '))
        //{
           //param_recipies->push_back(dummy_recipie);
             
            

       // }
        }

     }

     /**
        Destructor
        @post: Explicitly deletes every dynamically allocated Ingredient object
    */
   Pantry::~Pantry()
   {
        clear();
   }




 /**
    @param: A const string reference to a ingredient name
    @return: The integer position of the given ingredient if it is in the Pantry, -1 if not found.
*/
template<class T>
int Pantry::getPosOf(const std::string &ingredient_name) const
{
    // Node<T>* curr_ptr = head_ptr_; 
    
    // while(curr_ptr != nullptr)
    // {
    //     if(ingredient_name == curr_ptr->getNodeAt())
    //     {
    //         return curr_ptr;

    //     }
    //     else
    //     {
    //         return -1; 
    //     }

    //     curr_ptr = curr_ptr->getNext();

    return 2;


}
    //implement getNext and take a look at the node class




/**
    @param: A const string reference to a ingredient name
    @return: True if the ingredient information is already in the Pantry
*/
template<class T>
bool Pantry::contains(const std::string &ingredient_name) const
{
    // Node<T>* curr_ptr = head_ptr_; 
    // bool found = false;

    
    // while(!found && (curr_ptr != nullptr))
    // {
    //     if(ingredient_name == curr_ptr->getNodeAt())
    //     {
    //         found = true; 
            
    //     }
    //     else
    //     {
            
    //         curr_ptr = curr_ptr->getNext();
    //     }

    //     return found; 
    // }

    return true;



}

/**
    @param:  A pointer to an Ingredient object
    @post:  Inserts the given ingredient pointer into the Pantry, unless an ingredient of the same name is already in the pantry. 
            Each of its Ingredients in its recipe are also added to the Pantry IF not already in the list.
    @return: True if the ingredient was added successfully, false otherwise.
*/
bool Pantry::addIngredient(Ingredient *ing)
{
    return true;

}


/**
    @param: A const string reference representing a ingredient name
    @param: A const string reference representing ingredient description
    @param: A const int reference representing the ingredient's quantity
    @param: A const int reference representing the ingredient's price
    @param: A const reference to a vector holding Ingredient pointers representing the ingredient's recipe
    @post:   Creates a new Ingredient object and inserts a pointer to it into the Pantry. 
            Each of its Ingredients in its recipe are also added to the Pantry IF not already in the list.
    @return: True if the ingredient was added successfully
*/
bool Pantry::addIngredient(const std::string &ingredient_name, const std::string &ingredient_description, const int &ingredient_quantity, const int &ingredient_price, const std::vector<Ingredient> *recipie)
{
    return true;

}

 /**
    @param:  A Ingredient pointer
    @return: A boolean indicating if all the given ingredient can be created (all of the ingredients in its recipe can be created, or if you have enough of each ingredient in its recipe to create it)
*/
void Pantry::canCreate(Ingredient *ing) const
{
    std::cout << " . " << std::endl;

}

/**
    @param: A Ingredient pointer
    @post: Prints the ingredient name, quantity, and description.
    The output should be of the form:
    [Ingredient Name]: [Quantity]\n
    [Ingredient Description]\n
    Price: [Price]\n
    Recipe:\n
    [Ingredient0] [Ingredient1]\n


    If the ingredient has no recipe, print "Recipe:\nNONE\n\n" after the price.
*/
void Pantry::printIngredient(Ingredient *in) const
{
    std::cout << in->name_ << " :" << in->quantity_ << "\n" << in->description_ << "\n" << "Price: " << in->price_ << "\n" << "Recipie: " << "\n" << std::endl; 



}

/**
    @param: A const string reference to a ingredient name
    @post:  Prints a list of ingredients that must be created before the given ingredient can be created (missing ingredients for its recipe, where you have 0 of the needed ingredient).
            If the ingredient is already in the pantry, print "In the pantry([quantity])\n"
            If there are no instances of the ingredient, if it cannot be crafted because of insufficient ingredients, print "[Ingredient Name](0)\nMISSING INGREDIENTS"
            If it can be crafted, recursively print the ingredients that need to be used (if there are instances of them) or created (if there are no instances of them) in the order that the ingredients appear in the recipe, joined by "<-".
            If the ingredient has no recipe, print "UNCRAFTABLE\n" at the end of the function.

            Below are some of the expected forms. "Scenario: [scenario] is not part of the output. It is just to help you understand the expected output.":

            Scenario: The Ingredient does not exist in the list
            Query: [Ingredient Name]
            No such ingredient

            Scenario: The Ingredient exists in the list, and there are >0 instances of it
            Query: [Ingredient Name]
            In the pantry ([Quantity])

            Scenario: The Ingredient exists in the list, and there are 0 instances of it, and it is craftable by using an ingredient that is already in the pantry
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](1)

            Scenario: The Ingredient exists in the list, and there are 0 instances of it, and it is craftable by using an ingredient that has to be crafted
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](C) <- [Ingredient Name2](3)
            
            Scenario: The Ingredient exists in the list, and there are 0 instances of it, and there are multiple ingredients that have to be crafted (each row represents a different ingredient inå the original recipe)
            Query: [Ingredient Name0]
            [Ingredient Name0](C)
            [Ingredient Name1](C) <- [Ingredient Name2](3)
            [Ingredient Name3](C) <- [Ingredient Name4](C) <- [Ingredient Name5] (3)

            Scenario: The Ingredient exists in the list, and there are 0 instances of it, and it is not craftable (it has no recipe)
            Query: [Ingredient Name0]
            UNCRAFTABLE

            Scenario: The Ingredient exists in the list, and there are 0 instances of it, and it has a recipe, but you do not have enough of the ingredients to craft it
            Query: [Ingredient Name0]
            [Ingredient Name0](0)
            MISSING INGREDIENTS

    HINT: Use canCreate() to determine if the ingredient can be created.
*/
void Pantry::ingredientQuery(const std::string &ingredient_name) const
{
    std::cout << " . " << std::endl;

}

/**
    @return: An integer sum of the price of all the ingredients currently in the list.
    Note: This should only include price values from ingredients that you have 1 or more of. Do not consider ingredients that you have 0 of, even if you have the ingredients to make them.
*/
int Pantry::calculatePantryValue() const
{
    return 2; 
    
}

/**
    @param: A const string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every ingredient in the list.
        With filter "CONTAINS":   Only print out the ingredients with >0 instances in the list.
        With filter "MISSING": Only print out the ingredients with 0 instances in the list.
        With filter "CRAFTABLE":  Only print out the ingredients where you have all the ingredients to craft them.
        If an invalid filter is passed, print "INVALID FILTER\n"
        Printing ingredients should be of the form:

        [Ingredient name]: [Quantity]
        [Ingredient description]\n
        Price: [price]\n
        Recipe:\n
        [Ingredient0] [Ingredient1]\n\n

        If the ingredient has no recipe, print "Recipe:\nNONE\n\n" after the price.
*/
void Pantry::pantryList(const std::string &filter)
{
    std::cout << " . " << std::endl;

}