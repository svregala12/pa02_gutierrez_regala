// tests.cpp
// tests for movieCPP

#include "movies.h"
#include "movies.cpp"
#include <iostream>

using namespace std;

int main() {

    // test for declaring object
    movieBST test1;
    cout << "Declaration Done" << endl;

    // tests for insert function
    test1.insert("Hello", 2.2);
    test1.insert("World", 5.3);
    test1.insert("Okay Sir", 1.4);
    test1.insert("A", 100.2);

    // test for pre-order traversal
    test1.printPreOrder();


    return 0;
}