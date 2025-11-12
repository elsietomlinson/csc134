/*
elsie tomlinson 
m5h3w
11/12/2025
*/
#include <iostream> 
#include <iomanip>
using namespace std;
// hey here are my quesiton parts
void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

int main() {

int selection; 
bool keep_going = true;

cout << "SELECT QUESTION" << endl; 
cout << "1. Question 1" << endl;
cout << "2. Question 2" << endl;
cout << "3. Question 3" << endl;
cout << "4. Question 4" << endl; 
cout << "5. Question 5" << endl; 
cout << "0. Quit. " << endl; 
cout << "What's it gonna be?" << endl; 
cin >> selection; 
// if statements to create main menu
    if (selection = 1) {
        Q1();
    }
    else if (selection = 2) {
        Q2();
    }
    else if (selection = 3) {
        Q3();
    }
    else if (selection = 4) {
        Q4();
    }
    else if (selection = 5) {
        Q5();
    }
    
    else if (selection = 0) {
        cout << "Bye. " ;
        keep_going = false;
        cout << endl; 
    }
    else {
        cout << "Type any of the given values." << endl; 
    }
    
    return 0; 
}
// END OF MAIN NOW WE START ACTUALLY CODING> 
/// we have more functionsssss
double avgrain (double num1, double num2, double num3) {
    double avgrain = (num1 + num2 +num3) / 3.0;
    return avgrain;

}
void Q1() {
    cout << "QUESTION ONE:" << endl; 
    double avgrain;
    // my months that i can put in meow meow moew 
    string m1, m2, m3, m4;
    double rfm1, rfm2, rfm3; // rainfall permonth
    cout << "Enter 3 months of the year." << endl;
    cin >> m1;
    cin >> m2;
    cin >> m3;
    
}

void Q2() {
    cout << "NOt ready" << endl;
}

void Q3() {
    cout << "Not ready" << endl; 
}

void Q4() {
    cout << "not ready" ;
}

void Q5() {
    cout << "NOt ready" ;
}
