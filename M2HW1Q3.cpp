/*
elsie tomlinson 
csc-134-gold
m2hw1 q3
pizza party program
09/16/2025
*/


#include <iostream>
using namespace std;
int main() {
    // variables 
const int slices_per_guest = 3;
int pizza, slices_per_pizza, party_goers;
// how many pizzas were ordered
cout << "Welcome to Chuckee Cheez! How many pizza's would you like to order today?" << endl;
cin >> pizza;
cout << endl;
// how many slices do they wnat
cout << "How many slices would you like?" << endl;
cin >> slices_per_pizza;
cout << endl;
// how many guests are there going to be? 
cout << "How big is your party?" << endl;
cin >> party_goers;
// calculate how much pizza is left
 int total_slices = pizza * slices_per_pizza; 
int total_eaten = party_goers * slices_per_guest; 
int leftover = total_slices - total_eaten;
//then display how much was eaten and how much is left. 
cout << "You have a total of " << leftover << " pizza slices leftover." << endl;






    return 0; // no errors
}