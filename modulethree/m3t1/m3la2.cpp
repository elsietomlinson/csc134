/*
elsie tomlinson 
csc-134
module three lab 2
putting in numerical grades and getting a letter grade back (changed to game mechanics test)
*/


#include <iostream> 
#include <cstdlib> // for randon
#include <ctime> // to seed random
using namespace std; 
// delcaring functions
// to make things easier, write in a function 
void leter_grader();
void combat();



int main () {
letter_grader(); 
//combat();

return 0;
}

// define other fucntions under main
void letter_grader() {
    // input a number grade
    double num_grade; 
    string letter_grade;
    cout << "Enter a number grade 0-100:" << endl;
        // respond with a letter grade
    cin >> num_grade;

    // create if statements 
    letter_grade = "A";
    //output answer
    cout << "A number gade of" << num_grade << " is a(n) " << letter_grade;
    cout << endl << endl;
}