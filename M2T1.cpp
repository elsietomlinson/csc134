/*
csc-134
elsie tomlinson
9/3/2025
m2t1 apple store w/ input
*/



#include <iostream>
using namespace std;
int main()  {

    //declare variables
    string item = "kamkwats";
    double cost_per = 0.99;
    int amount = 20;
    //variables for user input
    int amount_purchased;
    double total_cost;
    //Greet the user
cout << "Hello! Welcome to our " << item << " store." << endl;
    // ask for information
cout << "Each of the " << item << " cost $" << cost_per << "." << endl;
cout << endl; 
cout << "How many kamkwats would you like to buy?" << endl;
   //cin put something in from the keyboard
   cin >> amount_purchased;
//do some processing 

    
    //output the answer
cout << "You are buying " << amount_purchased << " " << item << endl;
return 0;
}