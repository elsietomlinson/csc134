/* 
elsie tomlinson
csc-134 
gold tier
m3hw question 1 
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std; 
int main () {
cout << "QUESTION 4" << endl; 
cout << endl; 
// random number seed
int seed = time(0);
srand(seed);

//variables
const int MAX = 9;
int digit1, digit2, usersum, total; 

//random numbers 
digit1 = (rand() % MAX) + 1;
digit2 = (rand() % MAX) + 1;
total = digit1 + digit2;

//print out all numbers
cout << "Let's practice some math! What does " << digit1 << " + " << digit2 << " = " << endl; 
cin >> usersum;
// now tell them if it is correct or not
if (usersum  == total) {
    cout << usersum << " is correct!" << endl; 
}
if (usersum != total) {
    cout << usersum << " is not right." << endl;
    cout << "Sorry, try again." << endl; 
}

    return 0;
}