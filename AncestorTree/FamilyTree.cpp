
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "FamilyTree.hpp"
#include <algorithm>
#include <tuple>

using namespace std;
using namespace family;

namespace family
{
    //build first root
    family::myRoot::myRoot(string rootName)
    {
        name = rootName;
        father = nullptr;//nullptr is generally recommended for pointer over null to avoit confusion and assignment mistakes
        mother = nullptr;
    };

    //build a root
    family::Tree::Tree(string name)
    {
        root = new myRoot(name);
    };


    /**
     this method gets a name (string) of someone that might be inside the tree
     return pointer to this person inside the tree if found,if not return null

     this will be recursive function:
     each person has father and mother, they exist or are null
     if exist,they have function findsomeone which can be called recursivly
     if their name matches string, we have found our target
     if not, try mother or father, if both null return null

     inside scope of funtion:
     we have acces to current object of myRoot Class
     because this is activated trough a myRoot object
     this
     */
    myRoot* myRoot::findsomeone(string someName)
    {
        //we need to check if name is the same;


        //if not we need to check with father
        if (this->father != nullptr)
        {
            if (this->father->name == someName)
            {
                return this->father;
            }
            else
            {
                myRoot* tmp = this->father->findsomeone(someName);
                if (tmp != nullptr)
                {
                    return tmp;
                }
            }
        }

        //if we get null we check mother
        if (this->mother != nullptr)
        {
            if (this->mother->name == someName)
            {
                return this->mother;
            }
            else
            {
                myRoot* tmp = this->mother->findsomeone(someName);
                if (tmp != nullptr)
                {
                    return tmp;
                }
                else      //if we get null we return null
                {
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    family::myRoot::~myRoot() {
        name = "";
        father = nullptr;
        mother = nullptr;
    }

    //set a father to the tree
    void Tree::setFather(family::myRoot rootnName, string fatherName)
    {
        //check if father exists
        if (rootnName.father != nullptr)
        {
            rootnName.father->name = fatherName;
        }
        else
        {
            throw invalid_argument("you dont have a father yet, so you cant set a new name");
        }

    };



    //get a father to the tree
    family::myRoot* Tree::getFather(family::myRoot rootnName, string fatherName)
    {
        return  rootnName.father;//we want to return pointer so . should be right
    };

    //add a Mother
    //we already have access to son name, we have find someone function trough root of tree,if we find we can try add
    //if we dont find we reject
    Tree family::Tree::addFather(string rootnName, string fatherName) {

        myRoot *temp;
        if (root->name != rootnName)
        {
            temp = root->findsomeone(rootnName);
        }
        else {
            temp = root;
        }
        if (temp != nullptr) {
            temp->addFather(fatherName);
        }
        else
        {
            throw invalid_argument("no son");
        }
        return *this;
    }
    bool family::myRoot::addFather(string fatherName) {
        //as we see we found someone, so we can now try to add mother.
        if (father != nullptr) {

            throw invalid_argument("it already have a daddy");
        }
        else
        {
            myRoot* dad = new myRoot(fatherName);
            father = dad;//we put into the branch the pointer to the new node
            return true;
        }
    }
};


//set a mother to the tree
void family::Tree::setMother(family::myRoot rootnName, string MotherName)
{
    //check if mother exists
    if (rootnName.mother != nullptr)
    {
        rootnName.mother->name = MotherName;
    }
    else
    {
        throw invalid_argument("you dont have a mother yet, so you cant set a new name");
    }

};


//get a mother to the tree
family::myRoot* family::Tree::getMother(family::myRoot rootnName, string mothername)
{
    return  rootnName.mother;
};


//add mother to the tree
family::Tree family::Tree::addMother(string rootnName, string MotherName) {
    myRoot *temp;
    if (root->name != rootnName)
    {
        temp = root->findsomeone(rootnName);
    }
    else {
        temp = root;
    }
    if (temp != nullptr) {
        temp->addMother(MotherName);
    }
    else {
        throw invalid_argument("no son");
    }
    return *this;
}
bool family::myRoot::addMother(string name)
{
    //as we see we found someone, so we can now try to add mother.
    if (mother != nullptr)
    {
        throw invalid_argument("it already have a mom");
    }
    else
    {
        myRoot* mom = new myRoot(name);
        mother = mom;//we put into the branch the pointer to the new node
        return true;
    }
}


//display the tree
void family::Tree::display()
{
    root->rootdisplay();


};

//display from root
void family::myRoot::rootdisplay()
{
    string fathername = "doesntExist";
    string motherName = "doesntExist";
    if (father != nullptr)
    {
        fathername = father->name;
    }

    if (mother != nullptr)
    {
        motherName = mother->name;
    }

    cout << name << "   " << fathername << "   " << motherName << endl;

    if (father != nullptr)
    {
        father->rootdisplay();
    }

    if (mother != nullptr)
    {
        mother->rootdisplay();
    }

}

tuple<int, bool> Parser(string input)
{
    tuple<int, bool> result;
    int index = 0;
    //int i = 0;//counter
    input = input + "-";
    vector<string> wordsfromtext;//vector of strings

    //we go in a for loop on the text and every time when we find the delimiter ' '
    //we put the word from index to i-index into the vector.
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) == '-')
        {
            wordsfromtext.push_back(input.substr(index, (i - index)));
            index = i + 1;/*add 1 becouse we want our new index be after the delimiter ' '
					  as we know the i stop at text.at(i)== ' ').
					  so we add 1 to begin the index where the new word begin.*/
        }
    }
    bool gender;
    int sizegreat = wordsfromtext.size();
    if (wordsfromtext.at(sizegreat - 1) == "grandfather")
    {
        gender = false;

    }

    else if (wordsfromtext.at(sizegreat - 1) == "grandmother")
    {
        gender = true;//found mother
    }
    else {
        throw invalid_argument("The tree cannot handle the 'uncle' relation");
    }

    result = tuple<int, bool>(sizegreat, gender);
    return result;

}
//find someone in the tree
string family::Tree::find(string someone)
{
    if (someone == "me")
    {
        if (root != nullptr)
        {
            return root->name;
        }
        else {
            throw invalid_argument("no root");
        }
    }

    if (someone == "mother" || someone == "mom")
    {
        if (root->mother != nullptr)
        {
            return root->mother->name;
        }
        else
        {
            throw invalid_argument("no mom");
        }
    }

    if (someone == "father" || someone == "dad")
    {
        if (root->father != nullptr)
        {
            return root->father->name;
        }
        else
        {
            throw invalid_argument("no dad");
        }
    }
    tuple<int, bool> a = Parser(someone);
    string result = root->findsomeone(get<0>(a) + 1, get<1>(a));
    if (result == "")
    {
        throw invalid_argument("sorry, we cant find it");
    }
    return result;



};

//true is female false is the male
string family::myRoot::findsomeone(int counter, bool gender) {
    string result = ""; // if we not intilize it may be trouble later
    if (counter == 1)
    {
        int i = 0;
        if (gender == 1)
        {
            if (mother != nullptr) {
                return mother->name;
            }
        }
        else {
            if (father != nullptr) {
                return father->name;
            }
        }
    }
    else {
        if (father != nullptr) {
            result = father->findsomeone(counter - 1, gender);
            if (result != "") {
                return result;
            }
        }
        if (mother != nullptr) {
            return mother->findsomeone(counter - 1, gender);
        }

    }
    return result;
};

myRoot* family::myRoot::findsomeoneforRemove(string name)
{

    //if not we need to check with father
    if (this->father != nullptr)
    {
        if (this->father->name == name)
        {
            return this;
        }
        else
        {
            myRoot* tmp = this->father->findsomeoneforRemove(name);
            if (tmp != nullptr)
            {
                return tmp;
            }
        }
    }

    //if we get null we check mother
    if (this->mother != nullptr)
    {
        if (this->mother->name == name)
        {
            return this;
        }
        else
        {
            myRoot* tmp = this->mother->findsomeoneforRemove(name);
            if (tmp != nullptr)
            {
                return tmp;
            }
            else      //if we get null we return null
            {
                return nullptr;
            }
        }
    }
    return nullptr;

}
//remove someone from the tree
void family::Tree::remove(string name)
{
    myRoot* temp = root->findsomeoneforRemove(name);
    if (temp == nullptr)
    {
        throw invalid_argument("you cant remove someone that doesnt exist");
    }

    else
    {

        //now either father or mother of temp is target
        if (temp->father != nullptr)
        {
            if (temp->father->name == name)
            {
                temp->father->remove();
                temp->father = nullptr;
            }
        }
        if (temp->mother != nullptr)
        {
            if (temp->mother->name == name)
            {


                temp->mother->remove();
                temp->mother = nullptr;
            }
        }
    }
};



//remove someone from root
void family::myRoot::remove()
{
    if (father != nullptr) {

        father->remove();
        delete father;
    }
    if (mother != nullptr) {
        mother->remove();
        delete mother;
    }
    //now all that are connected to us are removed
    //we can safely remove me

    return;


}

//show relation
string family::Tree::relation(string someone)
{
    //cout<<"hi"<<endl;
    if (root->name == someone)
    {
        return "me";
    }
    string a = root->rootrelation(someone, 0);
    if (a == "")
    {
        a = "unrelated";
    }
    return a;

};
//if we find we print relation according to counter and then have everyone return true
//if we dont find, everyone returns false and we can throw exception
//show relation from the root
string family::myRoot::rootrelation(string someone, int counter) {//we define male as 0 and female as 1
    string container = "";
    if (father != nullptr) {
        if (father->name == someone) {
            return (this->printRelation(false, counter + 1));

        }
        else {
            container = father->rootrelation(someone, counter + 1);
            if (container != "") {
                return container;
            }
        }
    }
    if (mother != nullptr) {
        if (mother->name == someone) {
            return this->printRelation(true, counter + 1);
        }
        else {
            return mother->rootrelation(someone, counter + 1);
        }

    }
    return container;
}

string family::myRoot::printRelation(bool gender, int counter) {//we define male as 0 and female as 1
    string a = "";
    if (counter == 0) {
        a = "me";
        return a;
    }
    if (counter == 1) {
        if (gender)//female
        {
            a = "mother";
            return a;
        }
        else {
            a = "father";
            return a;
        }

    }

    for (int i = 2; i < counter; i++) {
        a = a + "great-";
    }

    if (gender) {
        a = a + "grandmother";
        return a;
    }
    else {
        a = a + "grandfather";
        return a;
    }

}


