/*
Maya Tabbah 
CSCI235 Spring 2024
May 14, 2024
SkillTree.cpp - The implementaion for the SkillTree class
*/



#include "SkillTree.hpp"

//Default Constructor
SkillTree::SkillTree(){}

/**
     * @param: A const reference to string: the name of a csv file
     * @post: The SkillTree is populated with Skills from the csv file
     * The file format is as follows:
     * id,name,description,leveled
     * Ignore the first line. Each subsequent line represents a Skill to be added to the SkillTree.
*/
SkillTree::SkillTree(const std::string &input_string)
{
    std::ifstream inFile(input_string);
    std::string skipline, string_id, string_name, string_description, string_leveled; 
    int integer_id;
    bool bool_leveled; 

    std::getline(inFile, skipline); 

    while(std::getline(inFile, skipline))
    {
        std::istringstream ss(skipline);

        std::getline(ss, string_id, ',');
        std::getline(ss, string_name, ',');
        std::getline(ss, string_description, ',');
        std::getline(ss, string_leveled, ',');

        std::istringstream stringIDtoIntID(string_id);
        stringIDtoIntID >> integer_id;

        bool_leveled = (string_leveled == "0" ? false : true);

        //Skill addToSkill = new Skill(integer_id, string_name, string_description, bool_leveled);

         Skill skill(integer_id, string_name, string_description, bool_leveled); // create Skill object and add it to the tree
        addSkill(skill);
    }
    inFile.close();
}

/**
    * @param: A const reference to int representing the id of the Skill to be found
    * @return: A pointer to the node containing the Skill with the given id, or nullptr if the Skill is not found
*/
std::shared_ptr<BinaryNode<Skill>> SkillTree::findSkill(const int& skillToFind) const
{
    Skill ah = Skill(skillToFind, "name", "idk", false);

    return findNode(getRoot(), ah);
    
}

/**
 * @param: A const reference to Skill 
 * @post: The Skill is added to the tree (in BST order as implemented in the base class) only if it was not already in the tree. 
        * Note that all comparisons are id-based as implemented by the Skill comparison operators.
 * @return: True if the Skill is successfully added to the SkillTree, false otherwise
 */
bool SkillTree::addSkill(const Skill &oop)
{
    if(contains(oop))
    {
        return false;
    }
    else
    {
        add(oop);
        return true;
    }

}

/**
     * @param: A const reference to string: the name of a Skill
     * @return: True if the Skill is successfully removed from the SkillTree, false otherwise
     */
bool SkillTree::removeSkill(const std::string& nameOfSkill)
{
    std::shared_ptr<BinaryNode<Skill>> root = getRoot();
    std::shared_ptr<BinaryNode<Skill>> parent = nullptr;

       while (root != nullptr) {
        if (root->getItem().name_ == nameOfSkill) {
            break; 
        } else if (root->getItem().name_ > nameOfSkill) {
            parent = root;
            root = root->getLeftChildPtr();
        } else {
            parent = root;
            root = root->getRightChildPtr();
        }
    }

    if (root == nullptr) {
        return false; // skill not found
    }

     if (parent == nullptr) { 
       remove(root->getItem()); 
    } else if (parent->getLeftChildPtr() == root) {
        parent->setLeftChildPtr(nullptr); 
        remove(root->getItem());
    } else {
        parent->setRightChildPtr(nullptr); 
        remove(root->getItem());
    }

    return true;


}

//std::shared_ptr<BinaryNode<Skill>> SkillTree::wholeTreeSearch(std::shared_ptr<BinaryNode<Skill>> subtree_ptr,const std::string & nameOfSkill){}




 /**
    * @post: Clears the tree
*/
void SkillTree::clear()
{
   root_ptr_ = nullptr;
}

/**
    * @param: A const reference to int representing the id of a Skill
        * Note: For a Skill to be leveled up, its parent Skill must also be leveled up, thus the Skill points are the number of Skills that must be leveled up before and including the Skill with the given id.
    * @return: an integer: the number of skill points needed to level up the Skill with the given id, starting from the root (i.e. the number of nodes from root to the given Skill).
    * Include the Skill with the given id in the count. For example, if the tree contains the following Skills (represented by their ids):
    *   5
    *  / \
    * 1   8
    * and the function parameter queries for id 8, the function should return 2.
    * Disregard the leveled_ field of the existing Skills in the tree.
    * If the Skill with the given id is not found, return -1.
*/
int SkillTree::calculateSkillPoints(const int & id) const
{
    std::shared_ptr<BinaryNode<Skill>> calc = findSkill(id);
    if (calc == nullptr) return -1;
    int total = 1; // include the root node
    std::shared_ptr<BinaryNode<Skill>> curr = root_ptr_;
    while (curr != nullptr && curr->getItem().id_ != id) {
        if (curr->getItem().id_ > id) {
            curr = curr->getLeftChildPtr();
        } else {
            curr = curr->getRightChildPtr();
        }
        total++;
    }
    return total;
}

//balance helper function
std::shared_ptr<BinaryNode<Skill>> SkillTree::balanceTree(const std::vector<Skill>& sorted_skills, int begin, int finish) const {
    if (begin > finish) {
        return nullptr;
    }
    int midpoint = (begin + finish) / 2;
    std::shared_ptr<BinaryNode<Skill>> root = std::make_shared<BinaryNode<Skill>>(sorted_skills[midpoint]);
    root->setLeftChildPtr(balanceTree(sorted_skills, begin, midpoint - 1));
    root->setRightChildPtr(balanceTree(sorted_skills, midpoint + 1, finish));
    return root;
}

//inorder traversal function
void SkillTree::inorder(std::shared_ptr<BinaryNode<Skill>> curr, std::vector<Skill>& skillSort) const {
    if (curr != nullptr) {
        inorder(curr->getLeftChildPtr(), skillSort);
        skillSort.push_back(curr->getItem());
        inorder(curr->getRightChildPtr(), skillSort);
    }
}

/**
     * @post: Balances the tree. Recall the definition of a balanced tree:
     * A tree is balanced if for any node, its left and right subtrees differ in height by no more than 1. * All paths from root of subtrees to leaf differ in length by at most 1
     * Hint: You may sort the elements and build the tree recursively using a divide and conquer approach      
*/
void SkillTree::balance()
{
    std::vector<Skill> skillSort;
    inorder(root_ptr_, skillSort);
    root_ptr_ = balanceTree(skillSort, 0, skillSort.size() - 1);  

}

void SkillTree::preorder(std::shared_ptr<BinaryNode<Skill>> curr, std::function<void(const Skill&)> inp) const{
if(curr != nullptr) {
    inp(curr->getItem());
    preorder(curr->getLeftChildPtr(), inp);
    preorder(curr->getRightChildPtr(), inp);
}
}

/**
     * @post: prints the tree in preorder, in the format:
     [id_] [name_]\n
     [description_]\n 
     [leveled_]
*/
void SkillTree::preorderDisplay()
{
     preorder(getRoot(), [](const Skill& skill) {
        std::cout << skill.id_ << skill.name_ << "\n";
        std::cout << skill.description_ << "\n";
        std::cout << (skill.leveled_ ? 1 : 0) << "\n\n";
    });

}