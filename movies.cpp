// movies.cpp
// Implementation of movieBST
// Steve Regala | Angel Gutierrez | 5/18/21

#include "movies.h"
//#include "utility.cpp"
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
void movieBST::insert(string name, double rating, string sub, LinkedList& object) {

    // special case of empty tree first
    if (!root) {
        root = new Node(name, rating);
        searchPrefix(root, sub, object);  // HERE
        //return true;
        return;
    }

    // otherwise use recursive helper
    //return insert(name, rating, root, sub, object);
    insert(name, rating, root, sub, object);
}


// insert helper function
void movieBST::insert(string name, double rating, Node* n, string sub, LinkedList& object){

    if (name == n->name) {
        return;
    }

    if (name < n->name) {
        if (n->left)
            insert(name, rating, n->left, sub, object);

        else {
            n->left = new Node(name, rating);
            searchPrefix(n->left, sub, object);
            n->left->parent = n;
            return;
        }
    }

    else {
        if (n->right)
            insert(name, rating, n->right, sub, object);
        
        else {
            n->right = new Node(name, rating);
            searchPrefix(n->right, sub, object);
            n->right->parent = n;
            return;
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


// main traverse function
void movieBST::firstTrav() {

    Node *n;
    n = this->root;
    traverse(n);
    
}


// helper traverse function
void movieBST::traverse(Node* n) {

    if (n) {
        searchForNode(n->name);
        traverse(n->left);
        traverse(n->right);
    }

}


void movieBST::searchPrefix(Node* n, string prefix, LinkedList& object) {
    
    if (n->name.substr(0, prefix.length()) == prefix) {
        object.append(n->rating, n->name);
    }

}