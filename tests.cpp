// tests.cpp
// tests for movieCPP

#include "tests.h"
#include "movies.h"
#include "utility.h"

#include <iostream>

using namespace std;

int main() {

    string divider = "--------------------------------------------------------------------";
    cout << endl;

    test_insert();

    cout << divider << endl << endl;

    test_print_preorder();

    cout << divider << endl << endl;

    test_first_trav_for_depth();

    cout << divider << endl << endl;

    test_append_linkedlist();

    cout << divider << endl << endl;

    test_compare();

    return 0;
}


void test_insert()
{
    START_TEST("Test insert function");
    cout << endl;
    movieBST test1;
    LinkedList objectThing;

    test1.insert("dolphin", 2.2, "do", objectThing);
    test1.insert("the ocean", 5.3, "do", objectThing);
    test1.insert("whales", 1.4, "do", objectThing);
    test1.insert("sharks", 100.2, "do", objectThing);
    test1.insert("fish", 1.2, "do", objectThing);

    test1.firstTrav();
    
    cout << "ACTUAL OUTPUT -->" << endl << endl;
    test1.printPreOrder();
    cout << endl;

    cout << "EXPECTED OUTPUT -->" << endl << endl;
    cout << "dolphin, 2.2, 0\nthe ocean, 5.3, 1\nsharks, 100.2, 2\nfish, 1.2, 3\nwhales, 1.4, 2" << endl << endl;

    END_TEST("Test insert function");
}


void test_print_preorder() {

    START_TEST("Test printPreOrder function");
    cout << endl;

    movieBST test1;
    LinkedList objectThing;

    test1.insert("dolphin", 2.2, "do", objectThing);
    test1.insert("the ocean", 5.3, "do", objectThing);
    test1.insert("whales", 1.4, "do", objectThing);
    test1.insert("sharks", 100.2, "do", objectThing);
    test1.insert("fish", 1.2, "do", objectThing);
    
    test1.firstTrav();

    cout << "ACTUAL OUTPUT -->" << endl << endl;
    test1.printPreOrder();
    cout << endl;

    cout << "EXPECTED OUTPUT -->" << endl << endl;
    cout << "dolphin, 2.2, 0\nthe ocean, 5.3, 1\nsharks, 100.2, 2\nfish, 1.2, 3\nwhales, 1.4, 2" << endl << endl;

    END_TEST("Test printPreOrder function");
}


void test_first_trav_for_depth() {

    START_TEST("Test Depth Function");

    movieBST test1;
    LinkedList objectThing;

    test1.insert("dolphin", 2.2, "do", objectThing);
    test1.insert("the ocean", 5.3, "do", objectThing);
    test1.insert("whales", 1.4, "do", objectThing);
    test1.insert("sharks", 100.2, "do", objectThing);
    test1.insert("fish", 1.2, "do", objectThing);

    cout<<"\nBefore determining the node depth -->" << endl << endl;
    test1.printPreOrder();

    cout<<"\nAfter determining the node depth -->" << endl << endl;
    test1.firstTrav();
    test1.printPreOrder();

    cout << endl;
    END_TEST("Test Depth Function");
}


void test_append_linkedlist() {

    START_TEST("Test LinkedList append function");
    cout << endl;

    LinkedList object;

    object.append(3.2, "cat");
    object.append(2.55, "dog");
    object.append(49.66, "squirrel");
    object.append(122.212, "whale");

    cout << "ACTUAL OUTPUT -->" << endl << endl;
    object.printForTest();
    cout << endl;

    cout << "EXPECTED OUTPUT -->" << endl << endl;
    cout << "cat has the rating 3.2\ndog has the rating 2.55\nsquirrel has the rating 49.66\nwhale has the rating 122.212" << endl << endl;

    END_TEST("Test LinkedList append function");
}


void test_compare() {

    START_TEST("Test LinkedList compare function");

    movieBST test1, test2, test3;
    LinkedList objectThing, objectThing2, objectThing3;

    cout << "\nPrints out movie with the highest rating given a prefix." << endl;
    cout << "Designated Prefix : \"do\"" << endl << endl;

    test1.insert("dolphin", 2.2, "do", objectThing);
    test1.insert("the ocean", 5.3, "do", objectThing);
    test1.insert("whales", 1.4, "do", objectThing);
    test1.insert("sharks", 100.2, "do", objectThing);
    test1.insert("fish", 1.2, "do", objectThing);

    cout << "ACTUAL OUTPUT -->";
    objectThing.compare();

    cout << endl;
    cout << "EXPECTED OUTPUT -->\nBest movie is dolphin with rating 2.2" << endl << endl;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;

    cout << "Test case for when multiple movies have the same prefix and rating:" << endl;
    cout << "Movies with same prefix and rating: \"the star\", 2.2 and\t\"the ocean\", 2.2" << endl << endl;

    test2.insert("the star", 2.2, "the", objectThing2);
    test2.insert("the ocean", 2.2, "the", objectThing2);
    test2.insert("whales", 1.4, "the", objectThing2);
    test2.insert("sharks", 100.2, "the", objectThing2);
    test2.insert("fish", 1.2, "the", objectThing2);

    cout<<"ACTUAL OUTPUT -->";
    objectThing2.compare();

    cout << endl;
    cout << "EXPECTED OUTPUT -->\nBest movie is the ocean with rating 2.2" << endl << endl;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;

    cout << "Test case for when none of the movie names include the designated prefix:" << endl;
    cout << "Designated Prefix : \"hello\"" << endl << endl;

    test3.insert("the star", 2.2, "hello", objectThing3);
    test3.insert("the ocean", 2.2, "hello", objectThing3);
    test3.insert("whales", 1.4, "hello", objectThing3);
    test3.insert("sharks", 100.2, "hello", objectThing3);
    test3.insert("fish", 1.2, "hello", objectThing3);

    cout << "ACTUAL OUTPUT -->" << endl;
    objectThing3.compare();

    cout << endl;
    cout << "EXPECTED OUTPUT -->" << endl << endl;

    END_TEST("Test LinkedList compare function");
}
//yes