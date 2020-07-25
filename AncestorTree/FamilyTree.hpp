#pragma once#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

namespace family
{
    class myRoot
    {
    public:
        myRoot* father;//father branch
        myRoot* mother;//mother branch
        string name;

        //constructor
        myRoot(string name);

        //destructor
        ~myRoot();

        //find someone place in the tree by name
        myRoot* findsomeone(string someName);

        myRoot* findsomeoneforRemove(string name);

        void remove();

        bool addMother(string MotherName);//function is boolean in case we want to know if succesfull, we only care if it manages to add or not
        bool addFather(string fatherName);

        void rootdisplay();
        string printRelation(bool gender, int counter);//only added for order and simplicitys sake
        string rootrelation(string someone, int counter);
        //static vector <string> females;
        //static vector <string> males;

        string findsomeone(int counter, bool gender);
    };

    class Tree
    {
    public:

        myRoot* root;

        Tree(string name);

        //we have to find son in the tree and return his father name if exist, otherwise null.
        myRoot* getFather(family::myRoot rootnName, string fatherName);

        //find father and change his name (if the father exist)
        void setFather(family::myRoot rootnName, string fatherName);

        //add father tree branch
        Tree addFather(string rootnName, string fatherName);


        //we have to find son in the tree and return his father name if exist, otherwise null.
        myRoot* getMother(family::myRoot rootnName, string MotherName);

        //find mother and change her name (if the mother exist)
        void setMother(family::myRoot, string MotherName);//

        //add father tree branch
        Tree addMother(string rootnName, string MotherName);


        //find the relation between the root and someone (if someone exist in the tree)
        string relation(string someone);

        //find name by relation
        string find(string someone);



        //show the tree in 2d
        void display();

        //remove branch from the tree
        void remove(string name);




    };

};

/*#include <iostream>
#include <string.h>
#include <exception>
using namespace std;

//we using namespace to organize code into logical groups and to prevent name collisions that can occur.
namespace family
{
	//this is class node
	class Node
	{
		public:
				string name;
				string relation = "i am";
				Node *father;//father node
				Node *mother;//mother node
				int id;

				//constructor
				Node() //default constructor
				{
					father=NULL;
					mother=NULL;
					name="not activated yet";
					id=1;

				}

				Node(string Name)
				{
					this->name=Name;
					this->father=NULL;
					this->mother=NULL;
					this->id = 1; // this is uniq id for the root
				}

				Node (string Name,int id) // This constructor is used to build
				{
					this->name=Name;
					this->father=NULL;
					this->mother=NULL;
					this->id = id;
				}

				//destructor
				~Node();

				//set'rs
				bool setFather(Node* father);
				bool setMother(Node* mother);


				//get'rs
				Node* getMother();
				Node* getFather();
				Node* getbyname(string name);
				Node* getbyrelation(string relation);
				Node* getbykidname(string kidname);
				int getid();

				bool addrecmom(string name, string mother,string relation);
				bool addrecdad(string name, string father,string relation);

				void print (Node *root, int space);


	};

	//build class Tree
	class Tree
			{
			 public:
					Node* root = new Node;

					//this method is get a string from a user
					// this string is the name of the tree node

					 Tree(string name)
					 {
						 root.

					 }

					 //constructors
					 Tree(){};

					 //destructor
					 ~Tree(){};

					 //this method add a father to the kid, its gets a name
					 //of the child and the name of the father
					 //returns Tree
					 Tree &addFather(string childName, string fatherName);

					 //this method add a mother to the kid, its gets a name
					 //of the child and the name of the mother
					 //returns Tree
					 Tree &addMother(string childName, string motherName);

					 //this method is gets a name
					 //and returns the relation between the root
					 //and the name
					 string relation(string name);

					 //this method is gets a relation of someone
					 //and return me his name
					 string find(string relationname);

					 //this method display my tree
					 void display();

					 //this method gets name and remove
					 //the branch of that name
					 void remove(string name);

			  };
}*/