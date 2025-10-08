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
// calculate subtotal and total
double subtotal, total, heretotal, gototal;
subtotal = price; // changes if they buy more 

// calculate tax
double tax = 0.08; // 8% tax
double taxowed = subtotal * tax; 
gototal = subtotal + taxowed; 

// calculate your tip
double tip = 0.15; // 15% tip 
double tipowed = subtotal * tip; // tip amount for item
heretotal = subtotal + tipowed + taxowed; 

// if statements for actual code
if (hereortogo == 1) {
    total = heretotal; 
}
if (hereortogo == 2) {
    total = gototal; 
    tipowed = 0;
}
else {
    fooditem = "Not real food babe.";
subtotal = 0; 
taxowed = 0;
tipowed = 0; 
total = 0;
}
   
// actual print out of receipt
cout << "    RECEIPT" << endl; 
cout << "----------------" << endl; 
cout << endl; 
cout << "1 " << fooditem << endl; 
cout << endl; 
cout << "--------------------" << endl; 
cout << "Subtotal:     $" << subtotal << endl; 
cout << " Tax:          $" << taxowed << endl; 
cout << " Tip:           $" << tipowed << endl; 
cout << "-------------------" << endl; 
cout << "Total           $" << endl; 
cout << "------------------" << endl; 
cout << endl; 



return 0;
}