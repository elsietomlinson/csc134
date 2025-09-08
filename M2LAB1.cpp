/*
elsie tomlinson 
csc-134 
M2 LAB 1 - case study with crates
09/08/2025
*/ 

#include <iostream> 
using namespace std;

int main() {
    // set up the variables 
double length, width, height; // size of the crate
double volume;
double cost_to_make, charge_to_customer; // pricing
double profit;

const double COST_PER_CUBIC_FOOT = 0.23; // relates to cost
const double CHARGE_PER_CUBIC_FOOT = 0.5; // relates to charge


    // get crate information
cout << "Welcome to the crate program. " << endl; 
cout << "Crate Length: " << endl;
cin >> length;
cout << "Crate Width: " << endl;
cin >> width; 
cout << "Crate height: " << endl;
cin >> height;
    // calculate cost and prices
volume = length * width * height;
cost_to_make = volume * COST_PER_CUBIC_FOOT;
charge_to_customer = volume * CHARGE_PER_CUBIC_FOOT;
profit = charge_to_customer - cost_to_make;
    //display the results
cout << endl; 
cout << "Your crate is " << volume << " cubic feet." << endl; 
cout << "Customer Price:$" << charge_to_customer << endl;
cout << "Cost to build: $" << cost_to_make << endl;
cout << "Profit       : $" << profit << endl;
    return 0; //no errors
}