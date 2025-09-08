/* 
csc 134
M1HW1
elsie tomlinson
8/27/2025
purpose: write program giving name and release date of movie
*/
//magic words
#include <iostream> 
using namespace std;

int main() {
    //declare variables
    string item_name = "'Shrek.'";
    int year_released = 2001;
    double gross_income = 427;

// actual text
cout << "The motion picture " << item_name << endl;
cout << "was released in the year " << year_released << "," << endl; 
cout << " and it grossed " << gross_income << " million dollars."<< endl;
cout << "some memorable quotes include,'What are you doing in my swamp?!'" << endl;
cout << "and 'I like that boulder, that's a nice boulder!'" << endl;
cout << "The movie " << item_name << " is a heart felt, animated kids film about learning to let people into your life and creating a family." << endl;
// end program
return 0;
}