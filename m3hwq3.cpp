/* 
elsie tomlinson
csc-134
m3hw quesiton 3
gold tier
*/
// set up a looping programc
#include <iostream> 
using namespace std; 
// path options for game
    void begin(); // staying in matrix
    void path(); // live in the lie
    void option1(); // choice to stay where you are
    void option2(); // choice to defy the laws of fate. 
int main () {

cout << "QUESTION 3" << endl;
cout << endl; 
// define your variables 
int option1; 
int option2; 

// begin actual game 
cout << "Defy the laws of fate and choose your own path!" << endl; 
cout << "You are faced with the choice of breaking out of the matrix or continuing to live in a lie. " << endl;
cout << "1. Break free of the matrix." << endl; 
cout << "2. Stay in the lie." << endl; 
cout << "Type 1 or 2." << endl;
cin >> option1; 
cout << endl; 

// now you have to type if statements 
if (option1 == 1) {

}








    return 0; 
}
// output for begin // choosing to stay in the matrix. 
void begin(); {

    cout << "You choose to live in a lie." << endl; 
    cout << "You die trying to climb a infinitie corporate ladder." << endl; 
    cout << "Pray there's an after life." << endl; 
}