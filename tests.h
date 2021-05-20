// tests.h
// Authors: Angel Gutierrez | Steve Regala | 5/19/21

#ifndef TESTS_H
#define TESTS_H

#include <iostream>

using namespace std;

// tests for movieBST
void test_insert();
void test_print_preorder();
void test_first_trav_for_depth();

// tests for LinkedList
void test_append_linkedlist();
void test_compare();


void START_TEST(string testname) {
    cout << "Start " << testname << endl;
}

void END_TEST(string testname) {
  cout << "End " << testname << endl << endl;
}

#endif