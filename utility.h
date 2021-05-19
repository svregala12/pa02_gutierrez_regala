// utility.h

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

class LinkedList {

    private:
        struct Place {
            string name;
            double rating;
            Place* next;
        };

        Place* first;

    public:

        LinkedList();
        ~LinkedList();

        void append(double movieRating, string movieName);

        void compare();

};


#endif