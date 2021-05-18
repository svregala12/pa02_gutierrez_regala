// movies.cpp
// Implementation of movieBST
// Steve Regala | Angel Gutierrez | 5/17/21

#include "movies.h"
#include <iostream>

using namespace std;

// constructor --> initialized as an empty tree
movieBST::movieBST() : root(NULL) {}

// destructor --> delete all nodes
movieBST::~movieBST() {
    clear(root);
}

// recursive help for destructor
void movieBST::clear(Node *n) {

    if (n) {
    clear(n->left);
    clear(n->right);
    delete n;
    }

}

// insert value in BST
bool movieBST::insert(string name, double rating) {

    // special case of empty tree first
    if (!root) {
    root = new Node(name, rating);
    return true;
    }

    // otherwise use recursive helper
    return insert(name, rating, root);
}

bool movieBST::insert(string name, double rating, Node* n){

    if (name == n->name) {
        return false;
    }

    if (name < n->name) {
        if (n->left)
            return insert(name, rating, n->left);

        else {
            n->left = new Node(name, rating);
            n->left->parent = n;
            return true;
        }
    }

    else {
        if (n->right)
            return insert(name, rating, n->right);
        
        else {
            n->right = new Node(name, rating);
            n->right->parent = n;
            return true;
        }
    }

}

void movieBST::printPreOrder() const {
    printPreOrder(root);
}

void movieBST::printPreOrder(Node *n) const {

    if (n) {
        cout << n->name << ", " << n->rating << ", " << n->depth << endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }

}