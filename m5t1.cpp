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

double double_a_number(); // num times two 


int main() {
    double my_num;
    int another_num;
    cout << "welcome to a program" << endl; 
    cout << " Please enter a number (with or without decimal place)" << endl; 
    cin >> my_num;
    my_num = my_num * 2;
    cout << "Double the number is: " << my_num << endl; 
    
    return 0;
}

// function defintions the whole function goes here
void say_hello() { //says hi

}
int get_the_answer(){
    
} // provides the anser

double double_a_number(double the_num) {
    double answer = the_num * 2; 
    return answer;
}// num times two 
