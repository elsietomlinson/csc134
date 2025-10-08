/* 
elsie tomlinson
m3hw 
q2
gold tier 
meow
*/
#include <iostream> 
#include <iomanip> // to make it PRETTY
using namespace std; 
int main () {

cout << "Question 2;" << endl;
// set up thine variables
double price; 
string storename = "Fuel for your physical manifestation.";
string fooditem; 
int hereortogo; // for here or to go man
cout << fixed << setprecision (2); 

// do the thing bro
cout << "Welcome to " << storename << endl;
cout << "What would you like to eat today?" << endl;
cin >> fooditem;
cout << endl; 
cout << "Enter price of you sustenance of choice today: " << endl;
cin >> price; 
cout << "Would you like to eat in or out today? 1 for here, 2 for to go." << endl; 
cin >> hereortogo; 
cout << "You are eating " << fooditem << " and it is: " << price << "dollars." << endl;
cout << endl; 

// figure out the actual amath


    return 0;
}