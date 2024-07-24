/*
CSCI235 Spring 2024
Maya Tabbah
Project 4 - Derived Class
March 21, 2024
Mindflayer.hpp defines the constructors and private and public functions of the Mindflayer class
*/

/*
CSCI235 Spring 2024
Project 2 - Derived Classes
Georgina Woo
Dec 23 2023
Mindflayer.hpp defines the constructors and private and public functions of the Mindflayer class
*/

#ifndef MINDFLAYER_HPP
#define MINDFLAYER_HPP

#include "Creature.hpp"
#include <vector>



class Mindflayer : public Creature{
    public:

        enum Variant {PSIONIC, TELEPATHIC, ILLUSIONARY};
    
struct Projectile{
    Variant type_;
    int quantity_;
};
        /**
            Default constructor.
            Default-initializes all private members. 
            Default Category: ALIEN
            Default summoning: False
        */
        Mindflayer();

        /**
            Parameterized constructor.
            @param      : A reference to the name of the Mindflayer (a string)
            @param      : The category of the Mindflayer (a Category enum) with default value ALIEN
            @param      : The Mindflayer's hitpoints (an integer), with default value 1 if not provided, or if the value provided is 0 or negative
            @param      : The Mindflayer's level (an integer), with default value 1 if not provided, or if the value provided is 0 or negative
            @param      : A flag indicating whether the Mindflayer is tame, with default value False
            @param      : The projectiles (a vector of Projectile structs), with default value an empty vector if not provided
            @param      : A flag indicating whether the Mindflayer can summon a Thoughtspawn, with default value False
            @param      : The affinities (a vector of Variant enums), with default value an empty vector if not provided
            @post       : The private members are set to the values of the corresponding parameters.
            Hint: Notice the default arguments in the parameterized constructor.
        */
        Mindflayer(const std::string& name, Category category = ALIEN, int hitpoints = 1, int level = 1, bool tame = false, std::vector<Projectile> projectiles = {}, bool summoning = false, std::vector<Variant> affinities = {});

        /**
            Getter for the projectiles.
            @return     : The projectiles (a vector of Projectile structs)
        */
        std::vector<Projectile> getProjectiles() const;

        /**
            Setter for the projectiles.
            @param      : A reference to the projectiles (a vector of Projectile structs)
            @post       : The projectiles are set to the value of the parameter. There should not be any duplicate projectiles in Mindflayer's projectiles vector.
                        : For example, if the vector in the given parameter contains the following Projectiles: {{PSIONIC, 2}, {TELEPATHIC, 1}, {PSIONIC, 1}, {ILLUSIONARY, 3}}, 
                        : the projectiles vector should be set to contain the following Projectiles: {{PSIONIC, 3}, {TELEPATHIC, 1}, {ILLUSIONARY, 3}}. 
                        : If the quantity of a projectile is 0 or negative, it should not be added to the projectiles vector.
                        : Note the order of the projectiles in the vector.
        */
        void setProjectiles(const std::vector<Projectile>& projectiles);

        /**
            Getter for the summoning.
            @return     : The summoning (a boolean)
        */
        bool getSummoning() const;

        /**
            Setter for the summoning.
            @param      : A reference to the summoning (a boolean)
            @post       : The summoning is set to the value of the parameter.
        */
        void setSummoning(const bool& summoning);

        /**
            Getter for the affinities.
            @return     : The affinities (a vector of Variant enums)
        */
        std::vector<Variant> getAffinities() const;

        /**
            Setter for the affinities.
            @param      : A reference to the affinities (a vector of Variant enums)
            @post       : The affinities are set to the value of the parameter.
                        : There should not be any duplicate affinities in Mindflayer's affinities vector. 
                        : For example, if the vector in the given parameter contains the following affinities: {PSIONIC, TELEPATHIC, PSIONIC, ILLUSIONARY}, 
                        : the affinities vector should be set to contain the following affinities: {PSIONIC, TELEPATHIC, ILLUSIONARY}.
                        : Note the order of the affinities in the vector.
        */
        void setAffinities(const std::vector<Variant>& affinities);

        /**
            @param       : A reference to the Variant 
            @return      : The string representation of the variant
        */
        std::string variantToString(const Variant& variant) const;

         /**
            @post     : Modifies the creature's private member variables (the exact modifications will be subclass specific)
            @return   : true if the creature leaves the Cavern, false otherwise
        */
        bool eatMycoMorsel() override;

        /**
            @post     : displays Mindflayer data in the form:
            "MINDFLAYER - [NAME]\n
            CATEGORY: [CATEGORY]\n
            HP: [HITPOINTS]\n
            LVL: [LEVEL]\n
            TAME: [TRUE/FALSE]\n
            SUMMONING: [SUMMONING]\n
            [PROJECTILE TYPE 1]: [QUANTITY 1]\n
            [PROJECTILE TYPE 2]: [QUANTITY 2]\n
            AFFINITIES: \n
            [AFFINITY 1]\n
            [AFFINITY 2]\n"

            NOTE: For the Projectiles, print out the type and quantity of each projectile in the format: 
            [TYPE]: [QUANTITY] for each projectile in the vector, where the type is the string equivalent of the Variant (eg. "PSIONIC"/"TELEPATHIC"/"ILLUSIONARY"). If there are no projectiles, don't print anything. 

            For the Affinities, print out each affinity in the format: [AFFINITY 1]\n[AFFINITY 2]\n for each Affinity in the vector, where the Affinity is the string equivalent of the Variant (eg. "PSIONIC"/"TELEPATHIC"/"ILLUSIONARY"). If there are no affinities, don't print anything, including the label "AFFINITIES:". 

            Example:
            MINDFLAYER - JHOCTOPUS
            CATEGORY: UNDEAD
            HP: 3
            LVL: 6
            TAME: TRUE
            SUMMONING: TRUE
            PSIONIC: 2
            TELEPATHIC: 11
            AFFINITIES: 
            PSIONIC
            ILLUSIONARY

        */
        void display() const override; 

    private:
        std::vector<Projectile> projectiles_;
        bool summoning_;
        std::vector<Variant> affinities_;

};
#endif // MINDFLAYER_HPP