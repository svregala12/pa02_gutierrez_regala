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

    Place* p;
    Place* x;
    p = first; //what we're going to use to iterate through
    x = first; //placeholder for what we want

    if (!p) {
        cout << endl;
        return;
    }

    while (p) {

        if (p->next) {
            if (p->rating > p->next->rating) {
                x = p;
            }
            if (p->rating < p->next->rating) {
                x = p->next;
            }
            if (p->rating == p->next->rating) {
                // compare strings
                if (p->name < p->next->name) {
                    x = p;
                }
                else if (p->name > p->next->name) {
                    x = p->next;
                }
            }
        }
        p = p->next;

    }
    cout << endl << "Best movie is " << x->name << " with rating " << x->rating << endl;

}


void LinkedList::printForTest() {

    Place *p;
    p = first;

    while (p) {
        cout << p->name << " has the rating " << p->rating << endl;
        p = p->next;
    }

}
//yes