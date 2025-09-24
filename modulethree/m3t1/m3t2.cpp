/*
elsie tomlinson 
m3t2- craps part 1
09/22/2025
csc-134 
*/
#include <iostream>
#include <cstdlib> // for rand() and srand () 
#include <ctime> // for time ()
using namespace std;
// declare helper function before main
int roll();
// main
int main () {
cout << "Let's play some craps!" << endl;
cout << "Roll the die!"<< endl;

// craps cycle
int roll1 = 3;
int roll2 = 4;
int point; // roll if it doesn't win or lose
// Seed the RNG before roll
srand(time(0));
//roll the die
roll1 = roll();
roll2 = roll();
int sum = roll1 + roll2;
cout << "The first roll was a " << roll1 << "." << endl;
cout << "The second roll was a " << roll2 << "." << endl; 
cout << "ROLL:" << sum << endl;
//win on 7 or 11
if  ( (sum == 7) || (sum == 11) ) { 
    cout << "Lucky Seven or Eleven -- you win!" << endl;
}

// lose on 2, 3, 12 
else if ( (sum == 2) || (sum == 3) || (sum == 12)  ) {
cout << "2,3, 12 -- Womp womp you lost." << endl;
}
else { 
    point = sum;
    cout << "You rolled a point." << endl;
cout << "Your point is: " << point << endl;
}
 return 0;}
// DEFINE HELPER FUNCTION
int roll() {
    int my_roll;
    my_roll = (rand() % 6) +1; // 1-6
    return my_roll;
}



