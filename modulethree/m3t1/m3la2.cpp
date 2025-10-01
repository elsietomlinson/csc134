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
void letter_grader();
void combat();
int roll();


int main () {
letter_grader(); 
void combat();
return 0;
}

// define other fucntions under main
void letter_grader() {
   
    // input a number grade
    double num_grade; 
    string letter_grade;
    // constants for grade points
    const double A_GRADE = 90;
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;
    cout << "Enter a number grade 0-100:" << endl;
   
    // respond with a letter grade
    cin >> num_grade;

    // create if statements 
  if (num_grade >= 90) {
    letter_grade = "A";
  }
  else if (num_grade >= B_GRADE) {
    letter_grade = "B";
  }
   else if (num_grade >= C_GRADE) {
    letter_grade = "C";
   }
   else if (num_grade >= D_GRADE) {
    letter_grade = "D";
   }
   else {
    letter_grade = "F";
   }
    //output answer
    cout << "A number grade of " << num_grade << " is:  " << letter_grade;
    cout << endl << endl;
}

void combat () {
/* a simple d and d style demo 
attack roll _ bonu >= armor class then else miss*/
// variables
int attack_roll, attacking_bonus, enemy_armor;
cout << "You are fighting a goblin." << endl;
cout << "Enter your attack bonus: " << endl;
cin >> attacking_bonus;
cout << "Enemy armor class: " << endl;
cin >> enemy_armor;
// roll to hit

attack_roll = roll();
cout << "Roll: " << attack_roll << " + " << attacking_bonus << " = " << attack_roll+attacking_bonus << endl;
if (attack_roll + attacking_bonus >= enemy_armor) {
    cout << "Hit!" << endl; 
}
else {
    cout << "Miss!" << endl; 
}
// try dagain? 
cout << "You want to go again?" << endl;
string again;
cin >> again; 
if (again == "y") {
    //call function again 
    combat();
}
}

// new function 
int roll() {
    const int SIDES = 20;
    int my_roll;
    my_roll = (rand() % SIDES) + 1;
    return my_roll;
}

//how do i stop the grade code and start the game code???????? BRUH SDLFJKS:LDKJF