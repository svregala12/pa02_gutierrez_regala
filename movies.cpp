// movies.cpp
// Implementation of movieBST
// Steve Regala | Angel Gutierrez | 5/18/21

#include "movies.h"
#include <iostream>

using namespace std;


// constructor --> initialized as an empty tree
movieBST::movieBST() {
    root = NULL;
    size = 0;
}


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


// main printPreOrder function
void movieBST::printPreOrder() const {
    printPreOrder(root);
}


// helper printPreOrder function
void movieBST::printPreOrder(Node *n) const {

    if (n) {
        cout << n->name << ", " << n->rating << ", " << n->depth << endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }

}


// main searchForNode function
void movieBST::searchForNode(string name) const {

    int count(0);
    Node* p;
    p = searchForNode(name, root, count);
    p->depth = count;

}


// helper searchForNode function
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


// search for prefix function
void movieBST::searchPrefix(Node* n, string prefix, LinkedList& object) {
    
    if (n->name.substr(0, prefix.length()) == prefix) {
        object.append(n->rating, n->name);
    }

}


// Part 1 of Part 2 for PA02
void movieBST::storeTime(vector<string> movie, vector<double>& timeVect, vector<double>& totalTimeList) {

    int iter(0);
    for (string i : movie) {

        clock_t time;
        time = clock();
        clock_t startTime = clock();
        searchForNode(i);
        clock_t endTime = clock();

        clock_t passed = endTime - startTime;
        passed = passed * 1e6 * 1.0 / CLOCKS_PER_SEC;

        timeVect.insert(timeVect.begin() + iter, passed);

        iter++;
    }

    double total(0);
    for (double x : timeVect) {

        total += x;

    }

    totalTimeList.push_back(total);

    timeVect.clear(); // clear the time vector for new times to be recorded
    
}


// Part 2 of Part 2 of PA02
// main function of insertTwo
void movieBST::insertTwo(string name, std::vector<std::pair<int, int>>& pairVector) {

    // special case of empty tree first
    if (!root) {
        root = new Node(name, 0);
        firstTrav();
        pairVector.push_back(std::make_pair(size, root->depth));
        return;
    }

    // otherwise use recursive helper
    //return insert(name, rating, root, sub, object);
    insertTwo(name, root, pairVector);
}


// helper function for insertTwo
void movieBST::insertTwo(string name, Node* n, std::vector<std::pair<int, int> >& pairVector){

    if (name == n->name) {
        return;
    }

    if (name < n->name) {
        if (n->left) {
            insertTwo(name, n->left, pairVector);
        }
        else {
            n->left = new Node(name, 0);
            size++;
            firstTrav();
            pairVector.push_back(std::make_pair(size, n->left->depth));
            n->left->parent = n;
            return;
        }
    }

    else {
        if (n->right)
            insertTwo(name, n->right, pairVector);
        
        else {
            n->right = new Node(name, 0);
            size++;
            firstTrav();
            pairVector.push_back(std::make_pair(size, n->right->depth));
            n->right->parent = n;
            return;
        }
    }

}