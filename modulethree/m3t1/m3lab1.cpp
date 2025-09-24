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
void forest (); // outside
void store (); // another place to be 
void gameOver (); // ending 
void victory (); // winning 
int main () {
cout << "Welcome to this thrilling adventure!" << endl;
cout << endl;
void bedroom (); {
cout << "Welcome to your childhood bedroom." << endl;
cout << "Do you choose door one or door two?" << endl; 
int choice;
cin >> choice; 
if (choice == 1)
{
    cout << "Brave soul leaving your home! Don't run into anyone you know!" << endl; 
    store(); // go to store
}
else { 
    cout << "Go bed rot on Tik Tok till your parents call you!" << endl;
    gameOver();
} 
}






    return 0;
}