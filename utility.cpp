// movies.cpp
// Implementation of movieBST
// Steve Regala | Angel Gutierrez | 5/18/21

#include "utility.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : first(NULL) {}

LinkedList::~LinkedList() {

    while (first) {
        Place* next = first -> next;
        delete first;
        first = next;
    }

}

void LinkedList::append(double movieRating, string movieName) {

    if (first == NULL) { // empty list
        first = new Place;
        first->name = movieName;
        first->rating = movieRating;
        first->next = NULL;
    }

    else {
        Place *n = this->first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Place;
        n->next->name = movieName;
        n->next->rating = movieRating;
        n->next->next = NULL;
    }
}

void LinkedList::compare() {

    Place* x;
    Place* curr;

    curr = this->first; //what we're going to use to iterate through
    x = curr; //placeholder for what we want]

    if (!curr)
    {
        cout<<endl;
        return;
    }

    while (curr && curr->next) {
        if (curr->rating == x->rating) {
            if (curr->name < x->name) {
                x = curr;
            }
        }
        if (curr->rating > x->rating) {
            x = curr;
        }
        curr = curr->next;
    }

    //we're supposed to compare x and the current node that's why it doesn't work!!!
    cout << endl << "\nBest movie is " << x->name << " with rating " << x->rating << endl;

}


void LinkedList::printForTest() {

    Place *p;
    p = first;

    while (p) {
        cout << p->name << " has the rating " << p->rating << endl;
        p = p->next;
    }

}