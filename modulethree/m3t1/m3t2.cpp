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
int roll();
int num = roll();
// main
int main () {
cout << "Let's play some craps!" << endl;
cout << "Roll the die!"<< endl;

// craps cycle
cout << num << endl;
int roll1 = 3;
int roll2 = 4;
int sum = roll1 + roll2;
cout << "The first roll was a " << roll1 << "." << endl;
cout << "The second roll was a " << roll2 << "." << endl; 

if (sum == 7) { 
    cout << "Lucky Seven -- you win!" << endl;
}
else { 
    cout << "Did not roll a seven." << endl;

}




return 0;    
}
//define helper function

    //roll a six sided die
 int roll() {
 
    return 0; 
}



