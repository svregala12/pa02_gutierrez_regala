// movies.h

#ifndef MOVIES_H
#define MOVIES_H

#include "utility.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class movieBST {

    public:

        int size;

        movieBST();               // constructor
        ~movieBST();              // desctructor

        void insert(string name, double rating, string sub, LinkedList& object);    // insert into movie BST
        void printPreOrder() const;                 // print preorder traversal

        void searchForNode(string name) const;      // determine depth of node based on given string

        void firstTrav();                           // main traverse function

        void storeTime(vector<string> movie, vector<double>& timeVect, vector<double>& totalTimeList);
        
        void insertTwo(string word, std::vector<std::pair<int, int> >& pairVector);
    

    private:

        struct Node {
            string name;
            double rating;
            int depth;
            Node *parent, *right, *left;
            Node(string v, double r) : name(v), rating(r), depth(0), left(0), right(0), parent(0) {}
        };

        Node *root;

        void insert(string name, double rating, Node *n, string sub, LinkedList& object);  // helper function for main insert
        void clear(Node *n);                    // helper function for destructor
        void printPreOrder(Node *n) const;      // helper function print preorder traversal

        Node* searchForNode(string name, Node* n, int& count) const;            // helper function to determine the depth of a node based on given string

        void traverse(Node* n);                 // helper function for main traverse

        void searchPrefix(Node*n, string prefix, LinkedList& object);           // helper function for secondary traverse (find the highest rating)

        void insertTwo(string word, Node* n, std::vector<std::pair<int, int>>& pairVector);       // helper function for insertPartTwo
};

#endif


/*
Notes (IGNORE):

        set Node pointer to root
        traverse through the tree and compare ratings, i
            if rating i > root
            switch the node pointer to point to this one
            repeat steps

            exit for loop

        call print PreOrder function
        cout the contents of the node pointer

        /////

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