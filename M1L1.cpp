/*
csc 134
m1lab
elsie tomlinson
8/27/2025
purpose: the "kamkwat" sales program.
*/

// magic words
#include <iostream>
using namespace std;

int main() {
  // start program
  // declare all of your variables ("whiteboards")
  string item_name = "kamkwat"; // replaced with your item
  int    num_items = 10;
  double cost_per = 0.25;

  //give our sales pitch
  cout << "Welcome to the " << item_name << " store!" << endl;
  cout << "Each " << item_name << " is $" << cost_per << endl;
  cout << "We have " << num_items << " total." << endl;
  // do the proscessing
double total_cost = num_items * cost_per;


  //end program 
  return 0;
}