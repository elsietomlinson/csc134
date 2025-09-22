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
int roll1 = 2;
int roll2 = 5;
int sum = roll1 + roll2;


if (sum == 7) { 
    cout << "Lucky Seven -- you win!" << endl;
}
else { 
    cout << "Did not roll a seven." << endl;
    
}
}



return 0;    
}

//define helper function
int roll () {
    //roll a six sided die
    return 6;

}

