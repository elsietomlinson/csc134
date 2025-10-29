/*
elsie tomlinson
csc-134
m4hw1
gold tier meow
10/27/2025
*/
// each function to each part of the hw
void part1();
void part2();
void part3();
// magic words
#include <iostream> 
using namespace std;
    int main() {
        int selection; //  input
        bool keep_going = true;

        while (true == keep_going) {
            cout << "Select Question part you would like to see." << endl; 
            cout << "Type 1, 2, 3, 4, or 0 to end." << endl;
            cin >> selection; 
    if (selection == 1) {
        part1(); 
        cout << endl;
    }
    else if (selection == 2) {
        part2();
        cout << endl; 
    }
    else if (selection == 3) {
        part3();
        cout << endl; 
    }
    else if (selection == 0) {
        cout << "Bye! See ya later!" << endl; 
        cout << endl; 
        keep_going = false; 
    }
    else {
        cout << "Type the options I gave you." << endl;
    }
}  
    
    return 0;
}
// question one
 void part1()  {
int const TABLE = 5;
int n = 0;
int product; 
 while (n < 12) {
    n++;
    product = TABLE * n;
    cout << TABLE << " times " << n << " equals " << product << endl; 
 }
}