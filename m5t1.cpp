/*
elsie tomlinson
csc 134 
m5 t1
all about functions */
//purpose demoand value returning fucntions
#include <iostream>
using namespace std;
// function declarations 
void say_hello(); //says hi

int get_the_answer(); // provides the anser

double double_a_number(double the_num); // num times two 


int main() {
    double my_num;
    int another_num;
    say_hello(); 
    cout << " Please enter a number (with or without decimal place)" << endl; 
    cin >> my_num;
    my_num = double_a_number(my_num);
    cout << "Double the number is: " << my_num << endl; 
    cout << "But the only answer your need is : " << endl;
    cout << get_the_answer() << endl;
    return 0;
}

// function defintions the whole function goes here
void say_hello() { //says hi
cout << "Welcome to a function." << endl;
}
int get_the_answer(){
return 42;
} // provides the anser

double double_a_number(double the_num) {
    double answer = the_num * 2; 
    return answer;
}// num times two 
