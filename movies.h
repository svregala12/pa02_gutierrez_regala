// movies.h

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class movieBST {

    public:

        int size;

        movieBST();               // constructor
        ~movieBST();              // desctructor

        bool insert(string name, double rating, string sub);    // insert into movie BST
        void printPreOrder() const;                 // print preorder traversal

        void searchForNode(string name) const;      // determine depth of node based on given string

        void firstTrav();                           // main traverse function

        void searchHigh(string sub);



        /*
        set Node pointer to root
        traverse through the tree and compare ratings, i
            if rating i > root
            switch the node pointer to point to this one
            repeat steps

            exit for loop

        call print PreOrder function
        cout the contents of the node pointer

        */


        /*
        function for getting the highest rating of the designated pre-fix

        have an empty array of strings

        we have an argument arg3 (include string)

        get the size of the arg 3 substring --> for example, size is 3

        get the substring of the name of each Node of size 3 --> call this value

        we compare the value to the arg 3
            if there is a match, store in array
            store in array until no more match

    
        iterate through array and determine which of those have the highest rating

        */




    /*
        - constructor
        - destructor
        - copy constructor?
        - copy assignment operator?
        - print statements/function
        

        - MUST HAVE'S:
            - constructor
            - destructor
            - insert function
            - print PreOrder
            - search function for the prefix

    */


    private:

        struct Node {
            string name;
            double rating;
            int depth;
            Node *parent, *right, *left;
            Node(string v, double r) : name(v), rating(r), depth(0), left(0), right(0), parent(0) {}
        };

        Node *root;

        bool insert(string name, double rating, Node *n, string sub);  // helper function for main insert
        void clear(Node *n);                    // helper function for destructor
        void printPreOrder(Node *n) const;      // helper function print preorder traversal

        // helper function to determine the depth of a node based on given string
        Node* searchForNode(string name, Node* n, int& count) const;

        // helper function for main traverse
        void traverse(Node* n);

        // helper function for secondary traverse (find the highest rating)
        void traverseTwo(Node* n);




    //Node* search Prefix function


};

#endif



void movieBST::searchPrefix(Node* n, string prefix, int count)
{
    /*
    Node* n;
    n = this->root;
    */

    // run that new node through this function
    Node* array;
    array = new (Node*)[]


    if (n->name.substr(0, prefix.length()-1) == prefix) {
        return;
    }

    return;

    /*
    if(prefix[0] != n->name[0]) return;
    else
    {
        int flag(1);
        for(int i=0; i<prefix.size(); i++)
        {
            if((n->name[i]) == (prefix[i]))
            {
                flag = 0;
            }

            else 
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            //return 

        }

    }
    */
}