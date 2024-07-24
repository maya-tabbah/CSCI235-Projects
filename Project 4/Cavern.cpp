/*
CSCI235 Spring 2024
Maya Tabbah
Project 4 - Cavern class 
March 21, 2024
Caven.cpp implements the Cavern class along with its private and public members
*/

/*
CSCI235 Spring 2024
Project 3 - Cavern Class
Georgina Woo
Dec 24 2023
Taven.cpp declares the Cavern class along with its private and public members
*/
#include "Cavern.hpp"

Cavern::Cavern() : ArrayBag<Creature*>(), level_sum_{0}, tame_count_{0} {
}

/**
    @param: the name of an input file (a string reference)
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
    1. TYPE: An uppercase string [DRAGON, GHOUL, MINDFLAYER]
    2. NAME: An uppercase string
    3. CATEGORY: An uppercase string [ALIEN, MYSTICAL, UNDEAD]
    4. HITPOINTS: A positive integer
    5. LEVEL: A positive integer
    6. TAME: 0 (False) or 1 (True)
    7. ELEMENT/FACTION: Uppercase string or strings representing the ELEMENT (For Dragons), or FACTION (For Ghouls) of the creature. If the creature is of a different subclass, the value will be NONE
    8. HEADS: A positive integer of the number of heads the Dragon has. If the creature is of a different subclass, the value will be 0
    9. FLIGHT/TRANSFORM/SUMMONING: 0 (False) or 1 (True) representing if the creature can fly (Dragons), transform (Ghouls), or summon a Thoughtspawn (Mindflayers).
    10. DECAY: A non-negative integer representing the level of decay of the Ghoul. If the creature is of a different subclass, the value will be 0
    11. AFFINITIES: Only applicable to Mindflayers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a semicolon. Th value may be NONE for a Mindflayer with no affinities, or creatures of other subclasses.
    12. PROJECTILES: Only applicable to Mindflayers. PROJECTILES are of the form [PROJECTILE TYPE1]-[QUANTITY];[PROJECTILE TYPE 2]-[QUANTITY] where multiple types of projectiles are separated by a semicolon. The value may be NONE for a Mindflayer with no projectiles, or creatures of other subclasses.
*/
Cavern::Cavern(const std::string &input_string)
{
  std::ifstream inFile(input_string);
  std::string line, type, name, s_category, s_element, s_hitpoints, s_level, s_heads, s_decay, s_tame, s_faction, s_summoning, s_affinities, s_projectiles; 
  int hitpoints, level, heads, decay;
  bool tame, summoning; 

  Creature::Category category;
  Dragon::Element element;
  Ghoul::Faction faction;

  std::vector <Mindflayer::Variant> affinities; 
  std::vector <Mindflayer::Projectile> projectiles;

  std::getline(inFile, line);

  while(std::getline(inFile, line))
  {
    std::istringstream ss(line);

    std::getline(ss, type, ',');
    std::getline(ss, name, ',');
    std::getline(ss, s_category, ',');
    std::getline(ss, s_hitpoints, ',');
    std::getline(ss, s_level, ',');
    std::getline(ss, s_tame, ',');
    std::getline(ss, s_element, ',');
    std::getline(ss, s_heads, ',');
    std::getline(ss, s_summoning, ',');
    std::getline(ss, s_decay, ',');
    std::getline(ss, s_affinities, ',');
    std::getline(ss, s_projectiles, ',');

    std::istringstream hps(s_hitpoints);
    hps >> hitpoints;

    std::istringstream lps(s_level);
    lps >> level;

    std::istringstream headps(s_heads);
    headps >> heads;

    std::istringstream dps(s_decay);
    dps >> decay;

    

    tame = (s_tame == "0" ? false : true);
    summoning = (s_summoning == "0" ? false : true);

  
      if(s_category == "UNKNOWN")
      {
        category = Creature::UNKNOWN;
      }
      else if(s_category == "UNDEAD")
      {
        category = Creature::UNDEAD;
      }
      else if(s_category == "MYSTICAL")
      {
        category = Creature::MYSTICAL;
      }
      else if(s_category == "ALIEN")
      {
        category = Creature::ALIEN;
      }

  
    if(type == "DRAGON")
    {
      if(s_element == "NONE")
      {
        element = Dragon::NONE;
      }
      else if(s_element == "FIRE")
      {
        element = Dragon::FIRE;
      }
      else if(s_element == "WATER")
      {
        element = Dragon::WATER;
      }
      else if(s_element == "EARTH")
      {
        element = Dragon::EARTH;
      }
      else if(s_element == "AIR")
      {
        element = Dragon::AIR;
      }

      Dragon* dragony = new Dragon(name, category, hitpoints, level, tame, element, heads, summoning);
      enterCavern(dragony);
    }

    else if(type == "GHOUL")
    {
      if(s_element == "NONE")
      {
        faction = Ghoul::NONE;
      }
      else if(s_element == "FLESHGORGER")
      {
        faction = Ghoul::FLESHGORGER;
      }
      else if(s_element == "SHADOWSTALKER")
      {
        faction = Ghoul::SHADOWSTALKER;
      }
      else if(s_element == "PLAGUEWEAVER")
      {
        faction = Ghoul::PLAGUEWEAVER;
      }

      Ghoul* ghoulia = new Ghoul(name, category, hitpoints, level, tame, decay, faction, summoning);
      enterCavern(ghoulia);
    }


    else if(type == "MINDFLAYER")
    {
      affinities.clear();
      projectiles.clear();

      std::string dummy_affinities; 

      std::istringstream ds(s_affinities);

      while(std::getline(ds, dummy_affinities, ';'))
      {
        if(dummy_affinities == "PSIONIC")
        {
          affinities.push_back(Mindflayer::PSIONIC);
        }
        else if(dummy_affinities == "TELEPATHIC")
        {
          affinities.push_back(Mindflayer::TELEPATHIC);
        }
        else if(dummy_affinities == "ILLUSIONARY")
        {
          affinities.push_back(Mindflayer::ILLUSIONARY);
        }
      }

      std::string dummy_projectiles; 
      std::istringstream vs(s_projectiles);

      while(std::getline(vs, dummy_projectiles, ';'))
      {
        std::string v_type, s_quantity; 
        int v_quantiity; 

        std::istringstream ps(dummy_projectiles);

        std::getline(ps, v_type, '-');
        std::getline(ps, s_quantity, '-');

        std::istringstream squ(s_quantity);
        squ >> v_quantiity; 

        //v_quantiity = stoi(s_quantity);

        if(v_type == "PSIONIC")
        {
          projectiles.push_back({ Mindflayer::PSIONIC, v_quantiity});
        }
        else if(v_type == "TELEPATHIC")
        {
          projectiles.push_back({ Mindflayer::TELEPATHIC, v_quantiity});
        }
        else if(v_type == "ILLUSIONARY")
        {
          projectiles.push_back({ Mindflayer::ILLUSIONARY, v_quantiity});
        }
      }

      Mindflayer* mindy = new Mindflayer(name, category, hitpoints, level, tame, projectiles, summoning, affinities);
      enterCavern(mindy);
    }

  }

}

bool Cavern::enterCavern(Creature* new_creature) {
  if (getIndexOf(new_creature) == -1) {
    if (add(new_creature)){
      level_sum_ += new_creature->getLevel();
      if (new_creature->isTame()) {
        tame_count_++;
      }
      return true;
    }
  }
  return false;
}

bool Cavern::exitCavern(Creature* creature_to_remove) {
  if (remove(creature_to_remove)) {
    level_sum_ -= creature_to_remove->getLevel();
    if (creature_to_remove->isTame()) {
      tame_count_--;
    }
    return true;
  }
  return false;
}

int Cavern::getLevelSum() const {
  return level_sum_;
}

int Cavern::calculateAvgLevel() const {
  if (isEmpty()) {
    return 0;
  }
  return round(level_sum_ / getCurrentSize());
}

int Cavern::getTameCount() const {
  return tame_count_;
}

double Cavern::calculateTamePercentage() const {
  if (isEmpty()) {
    return 0;
  }
  double tame_percent = (tame_count_>0) ?  (double(tame_count_) / item_count_) * 100: 0.0;
  // return the tame percentage rounded up to two decimal places

  return std::ceil(tame_percent * 100) / 100;
 
}

int Cavern::tallyCategory(const std::string& category) const {
  if(category != "UNKNOWN" && category != "UNDEAD" && category != "MYSTICAL" && category != "ALIEN") {
    return 0;
  }
  int count = 0;
  for (int i = 0; i < getCurrentSize(); i++) {
    if (items_[i]->getCategory() == category) {
      count++;
    }
  }
  return count;
}

int Cavern::releaseCreaturesBelowLevel(int level) {
  int count = 0;
  if (level < 0) {
    return 0;
  }
  else if (level == 0) {
    count = getCurrentSize();
    clear();
    return count;
  }
  else {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
      if (items_[i]->getLevel() < level) {
        exitCavern(items_[i]);
        count++;
      }
    }
    return count;
  }
}

int Cavern::releaseCreaturesOfCategory(const std::string& category) {
  int count = 0;
  if (category == "ALL") {
    count = getCurrentSize();
    clear();
    return count;
  }
  else if (category != "UNKNOWN" && category != "UNDEAD" && category != "MYSTICAL" && category != "ALIEN") {
    return 0;
  }
  else {
    int size = getCurrentSize();
    for (int i = 0; i < size; i++) {
    if (items_[i]->getCategory() == category) {
      exitCavern(items_[i]);
      count++;
    }
  }
  return count;
  }
}

void Cavern::cavernReport() const {
  std::cout << "UNKNOWN: " << tallyCategory("UNKNOWN") << std::endl;
  std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << std::endl;
  std::cout << "MYSTICAL: " << tallyCategory("MYSTICAL") << std::endl;
  std::cout << "ALIEN: " << tallyCategory("ALIEN") << std::endl;
  std::cout << std::endl;

  std::cout << "AVERAGE LEVEL: " << calculateAvgLevel() << std::endl;
  std::cout << "TAME: " << calculateTamePercentage() << "%" << std::endl;
}

/**
    @post: For every creature in the cavern, displays each creature's information
*/
void Cavern::displayCreatures() const
{

  for(int i = 0; i < getCurrentSize(); i++)
  {
    items_[i]->display();
  }
}

/**
    @param: a string reference to a category
    @post: For every creature in the cavern of the given category (only exact matches to the input string), displays each creature's information

*/
void Cavern::displayCategory(const std::string &category)
{

  int size = getCurrentSize(); //setting a variable to the current size so it doesn't decrement through the loop 

  for(int i = 0; i < size; i++) //looping through the size 
  {
    if(items_[i]->getCategory() == category)
    {
      items_[i]->display();
    }

  }


}

/**
  @post: Every creature in the cavern eats a MycoMorsel.
*/
void Cavern::mycoMorselFeast()
{
  

  int size = getCurrentSize();

  for(int i = 0; i < size; i++)
  {
    
    if(items_[i]->eatMycoMorsel())
    {
      exitCavern(items_[i]);
    }
  }

}