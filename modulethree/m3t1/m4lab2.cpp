/*
elsie tomlinson
m4lab2 =nested loops and rectangles
10/8/2025
Task: draw a rectangle*/

#include <iostream>
using namespace std;


int main () {

//declare your variables
int length, height;
string tile = " ✨"; // any character/ emoji

// example 1L print horixontally (ROW)
    for (int i=0; i < length; i++) {
        cout << tile;
    }
cout << endl;
//example 2 samte thing witha while loop
int count = 0;
    while (count < length) {
        cout << tile;
        count ++;
    }
cout << endl;
//ex3 for loop but in a column now
for (int i = 0; i < height; i++) {
    cout << tile << endl;
}
return 0; // no errors 
}