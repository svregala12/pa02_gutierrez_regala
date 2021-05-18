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

    //int count;
    // special case of empty tree first
    if (!root) {
        //count = 0;
        root = new Node(name, rating);
        //root -> depth = count;
        return true;
    }

    // otherwise use recursive helper
    //count++;
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
            //n->left->depth = count; // here
            n->left->parent = n;
            return true;
        }
    }

    else {
        if (n->right)
            return insert(name, rating, n->right);
        
        else {
            n->right = new Node(name, rating);
            //n->right->depth = count; //here
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

void movieBST::searchForNode(string name) const {

    int count(0);
    Node* p;
    p = searchForNode(name, root, count);
    p->depth = count;

}

movieBST::Node* movieBST::searchForNode(string name, Node* n, int& count) const {

    if (n) {
        
        if (n -> name == name) {
            return n;
        }

        else if (n -> name < name) {
            count++;
            return (searchForNode(name, n -> right, count));
        }

        else if (n -> name > name) {
            count++;
            return (searchForNode(name, n -> left, count));
        }

    }

    return NULL;

}

void movieBST::traverse() const {
    Node* n = this->root;
    if (n) {
        searchForNode(n->name);
        while (n->left) {
            traverse();
            n = n->left;
        }
        //traverse(n->left);
        while (n->right) {
            traverse();
            n = n->right;
        }
    }
}