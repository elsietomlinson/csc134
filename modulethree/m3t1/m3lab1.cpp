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
void store(); // another place to be 
void gameOver(); // ending 
void victory(); // winning 
void grocerylist();// what do you need to buy at the grocery

// main()
int main () {
    cout << "Welcome to this thrilling adventure!" << endl;
    cout << endl;
    cout << "You're in your childhood bedroom. Do you:" << endl;
    cout << "1. Go to the store" << endl;
    cout << "2. Stay home" << endl;

    int choice;
    cin >> choice; 
    if (choice == 1)
    {
        cout << "Brave soul leaving your home! Don't run into anyone you know!" << endl; 
        store(); // go to store
        victory();// you win!
        cout << endl;
        grocerylist(); // now you have to shop
    }
    else if (choice == 2) { 
        gameOver();// game ends and you bed rot and don't go out 
    }
    else {
        cout << "Don't do that babe." << endl;
        cout << "Use the functions I told you." << endl;
    }
    return 0; // end of main
} 

// end of main beginning of new function
// DEFINE all the other functions here, in this format:
/*
void myfunction() {}
*/


void gameOver() {
    cout << "Go bed rot on Tik Tok till your parents call you!" << endl;
    cout << "You lose cause you don't have groceries." << endl; 
}
    //game over function
 void store() {
    cout << "Welcome to the store! You have ventured out of your humble abode!" << endl;
    cout << "Now you must do the grocery shopping for the week or you'll starve!" << endl;
}
void victory() {
    cout << "You made it to the store, you win cause you went grocery store." << endl;
}
void grocerylist() {
    cout << "Now you have to shop!" << endl;
    cout << "Here's your list! Eggs, milk, coffee, and chocolate." << endl;
}