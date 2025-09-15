/* 
csc-134
elsie tomlinson 
m2hw1- question one
09/15/2025
*/
// magic words
#include <iostream> 
#include <iomanip>
using namespace std;

int main () {
// start the greeting
    cout << fixed << setprecision (2);
cout << "Welcome to the bank!" << endl;
cout << "Please enter name:" << endl;
cout << endl; 

//declare your variables

string lname;
string fname;
double start_balance, deposit, withdrawal, final_balance;
int account_number = 123456789;
// start your input
cout << "First Name:" << endl;
cin >> fname;
cout << "Last Name: " << endl;
cin >> lname;
string name = fname + " " + lname;
cout << "Hello, " << name << "!" << endl;
cout << "Your account number is: " << account_number << "." << endl;

// q 2 asking for deposit
cout << "Starting balance: $" << endl;
cin >> start_balance;
cout << "How much would you like to deposit today? $" << endl;
cin >> deposit;
cout << "How much would you like to withdraw? $" << endl;
cin >> withdrawal;
// now do the "math" to calculate your final balance
final_balance = (start_balance - withdrawal) + deposit;
cout << "Your total is: $" << final_balance << "." << endl;
// now say farewell
cout << "Thank you so much for banking with us!" << endl;
return 0;
}