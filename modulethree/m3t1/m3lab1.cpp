/* 
elsie tomlinson
csc-134
M3LAB1
09/24/2025
meow meow meow meow making a game 
*/
#include <iostream> 
using namespace std;
// declare the "rooms" that you're going to be using   
void bedroom(); // starting room
void forest(); // outside
void store(); // another place to be 
void gameOver(); // ending 
void victory(); // winning 
int main () {
cout << "Welcome to this thrilling adventure!" << endl;
cout << endl;
    return 0; 
} 




// end of main beginning of new function
// DEFINE all the other functions here, in this format:
/*
void myfunction() {}
*/

  void bedroom() {
cout << "Welcome to your childhood bedroom." << endl;
cout << "Do you choose to venture out? (Type 1 to leave)" << endl; 
int choice;
cin >> choice; 
if (choice == 1)
{
    cout << "Brave soul leaving your home! Don't run into anyone you know!" << endl; 
    store(); // go to store
}}
 void store(); {

    
    cout << "Welcome to the store! You have ventured out of your humble abode!" << endl;
    cout << "Now you must do the grocery shopping for the week or you'll starve!" << endl; 

  }
if (choice == 2) { 
    gameOver();// game ends and you bed rot and don't go out 
    }
void gameOver(); {
    cout << "Go bed rot on Tik Tok till your parents call you!" << endl;
}
    //game over function

