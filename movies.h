// movies.h

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class movieBST {

    public:

        movieBST();               // constructor
        ~movieBST();              // desctructor

        bool insert(string name, double rating);    // insert into movie BST
        void printPreOrder() const;                 // print preorder traversal

        void searchForNode(string name) const;      // determine depth of node based on given string

        void firstTrav();

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

        bool insert(string name, double rating, Node *n);
        void clear(Node *n);                    // helper function for destructor
        void printPreOrder(Node *n) const;      // helper function print preorder traversal

        // helper function to determine the depth of a node based on given string
        Node* searchForNode(string name, Node* n, int& count) const;

        // helper function for main traverse
        void traverse(Node* n);

    //Node* searchPreFix


};

#endif