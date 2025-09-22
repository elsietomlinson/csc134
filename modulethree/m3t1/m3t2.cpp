/*
elsie tomlinson 
m3t2- craps part 1
09/22/2025
csc-134 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//helper functions, always define these in the code
int roll() {
    return rand() % 6 + 1; // returns a random number between 1 and 6
}
int num = roll();
// main
int main () {
cout << "Let's play some craps!" << endl;
cout << "Roll the die!"<< endl;

// craps cycle
cout << num << endl;
int roll1 = 3;
int roll2 = 4;
int point; // roll if it doesn't win or lose
cout << "Enter two dice (press ENTER between)" << endl;
cin >> roll1;
cin >> roll2;
int sum = roll1 + roll2;
cout << "The first roll was a " << roll1 << "." << endl;
cout << "The second roll was a " << roll2 << "." << endl; 

if  ( (sum == 7) || (sum == 11) ) { 
    cout << "Lucky Seven -- you win!" << endl;
}

// lose on 2, 3, 12 
else if ( (sum == 2) || (sum == 3) || (sum == 12)  ) {
cout << "2,3, 12 -- Womp womp you lost." << endl;
}
else { 
    point = sum;
    cout << "Rolled a point." << endl;
cout << "Your point is: " << point << endl;
}
 return 0;}




