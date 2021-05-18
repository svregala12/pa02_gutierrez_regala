// movies.h

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

using namespace std;

class movieBST {

    public:

        movieBST();
        ~movieBST();

        bool insert(string name, double rating);
        void printPreOrder() const;

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
        void clear(Node *n);
        void printPreOrder(Node *n) const;

    //Node* searchPreFix


};

#endif