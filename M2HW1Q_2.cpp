/*
csc-134
elsie tomlinon
M2HW1 Question 2
*/
// copy m2 lab 1 one into to start building off of it for this assigment
// put in your magic words and use set precision
#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
    cout << "QUESTION 2." << endl;
    // set up the variables 
double length, width, height; // size of the crate
double volume;
double cost_to_make, charge_to_customer; // pricing
double profit;
//constants
const double COST_PER_CUBIC_FOOT = 0.3; // relates to cost
const double CHARGE_PER_CUBIC_FOOT = 0.52; // relates to charge
// set your precision
cout << setprecision(2) << fixed << showpoint;

    // get crate information
cout << "Welcome to the crate program. " << endl; 
cout << "What is the length of your crate? : " << endl;
cin >> length; 
cout << "What is your crates width? : " << endl;
cin >> width; 
cout << "What is your crates height? : " << endl;
cin >> height;
    // calculate cost and prices
volume = length * width * height;
// caclculating
cost_to_make = volume * COST_PER_CUBIC_FOOT;
// actual cost
charge_to_customer = volume * CHARGE_PER_CUBIC_FOOT;
// profit for the customer
profit = charge_to_customer - cost_to_make;
    //display the results
cout << endl; 
cout << "Your crate is " << volume << " cubic feet." << endl; 
cout << "Customer Price:$" << charge_to_customer << endl;
cout << "Cost to build: $" << cost_to_make << endl;
cout << "Profit\t: $" << profit << endl;
    return 0; //no errors
}