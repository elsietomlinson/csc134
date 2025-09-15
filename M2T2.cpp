/*
elsie tomlinson 
csc-134 
M1T2 store with sales tax
09/14/2025
*/
// must include price before tax
// the amount of tax
// total after tax
#include <iostream>
#include <iomanip> // neccessary to make it look pretty with the decimals
using namespace std;
// magic wordsssssss
int main() {
//variables 
double food_price = 17.99; // double because it's decimal! not an integer
string storename = "Ranchoros!";
string fooditem = "Racheros";


// actual order
cout << "welcome to the " << storename << endl;
cout << "One order of " << fooditem << " is: " << food_price << endl;
//define subtotal and total
double subtotal, total;
subtotal = food_price;
//then do the math for taxes
double tax = 0.08;
double tax_owed = subtotal * tax;
total = subtotal + tax_owed; 

cout << fixed << setprecision (2); // keeps it at two decimal places 

// now write the receipt, \t is the tab ??? i think?? 
// now write out the receipt for your variables 
cout << endl;
cout << "\tRECEPIT" << endl;
cout << endl; 
cout << "\t ------" << endl; 
cout << "You have one count of " << fooditem << endl;
cout << endl; 
cout << "----------------------------" << endl; 
cout << "Your subtotal is: $" << subtotal << endl;
cout << "Total tax is: $" << tax_owed << endl; 
cout << " Total Price: $" << total << endl;
cout << endl;
cout << "Thank you for dining with us!" << endl;
cout << "\tHave a great day!" << endl;

cout << ":)" << endl;

return 0;
}