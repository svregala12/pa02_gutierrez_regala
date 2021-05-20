#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#include "movies.cpp"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
  // Declare object of type movieBST
  movieBST movieList;

  LinkedList objectThing; // helper LinkedList
  
  string sub = argv[3]; // declare string equal to the prefix we're looking for
  
  if (flag) {

    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects

      movieList.insert(movieName, movieRating, sub, objectThing);
      movieList.firstTrav(); // declares the depth of each node
    }

    movieFile.close();

    movieList.printPreOrder();
    objectThing.compare();

  }


  else {

    cout << "The average time to search..." << endl;
    cout << "Number of nodes visited" << endl;

  }
  

  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}


/*
  Part 2 Questions
  
  Idea: 
  - Nodes visited
  - If you have a list of all the names, the csv file (input set)
    - create a list/vector of these, loop through the list of names
    - search information will give you the same thing
    - the average time should be equal to the depth
    - the amount of nodes visited is depth + 1

    - have a search function for when we visit a node, implement a counter
    - equal to the depth of the tree
    - used only on things inserted in the tree, never gonna search for something not in the tree
    
    - second part is timing data
    - loop through all these movies and search for them in the nodes
      - then store that into a vector or something
    - Each name in the list has a specific timing value
    - start a timer and end a timer
    - Have a certain number where w is the amount of times you run this experiment
    - loop through all the movies and search for the BST 50 times
      - minimum time and maximum time it took to search 


    - clock_t time;
    - time = clock();
    - clock_t startTime = clock();
      // some operation
      clock_t endTime = clock();

    - clock_t passed = endTime - startTime;
    - passed * 1e6 * 1.0 / CLOCKS_PER_SEC

    - output how much time it took
    - 2 comma separated values
      - 0, 0
      - 1, 2
      - ...
      - ^ print this out in the terminal


      - for i in csv
        - find i in the BST
          - implement timer when looking for i in bst
          - record time it took to find i
        - then the next i, 
  
      - then add up all the times 


        - 
        - perform certain amount of W times --> 50 times
        - what is the median time
          - min and max amount of time, what is the median


  - part 1, we could use the BST that already exists, use search function we've already created
    - measure how long it it took
  - Do it in main, 1st part
  - 2nd part, we might have to modify BST class
    - keep track of how many comparisons we did
    - maybe change something in the insert function
    

*/