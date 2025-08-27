/* 
csc 134
M1HW1
elsie tomlinson
8/27/2005
purpose: write program giving name and release date of movie
*/
//magic words
#include <iostream> 
using namespace std;

int main() {
    //declare variables
    string item_name = "Shrek.";
    int year_released = 2001;
    double gross_income = 427;
// actual text
cout << "The motion picture " << item_name << endl;
cout << "was released in the year " << year_released << "," << endl; 
cout << " and it grossed " << gross_income << " million dollars."<< endl;

// end program
return 0;
}