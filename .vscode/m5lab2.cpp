/*
elsie tomlinson 
m5lab2
11/3/2025
csc -134
*/

//completeing bobs halffinished program 
// get length
// get width etc
// fucntions go here.

// menu functions 
void menu_main();
void menu_area();
// rectangle functions
double getLength(); // get the length
double getWidth(); // width
double getArea(double length, double width); // areea
void displayData (double length, double width, double area); // display
// display data, void function simply shows the values and what
#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here because they have to be outside of main

int main()
{

	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//menu functions
void menu_main() {
    // menu choice -- main area or quit
        cout << " MAIN MENU " << endl; 
        cout << "-----------" << endl; 
        cout << "1. Area of a rectangle." << endl;
        cout << "2. Exit." << endl;
        cout << endl;
        cout << "Enter Choice: " << endl;
        int choice;
        cin >> choice;

                if (choice == 1) {
                menu_area(); // area code
            }
            else if ( choice == 2) {
                cout << "Goodbye." << endl;
            }
            else {
                cout << "Invalid choice. Try again." << endl;
            }
}
void menu_area() {
double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
}

//rectangle functions

double getLength(){
    double length; 
    cout << "What is the length?" << endl; 
    cin >> length;
    return length;
} // get the length

double getWidth() {
    double width; 
    cout << "What is the width?" << endl;
    cin >> width;
    return width;
} // width

double getArea(double length, double width) {
    double area;
    area = length * width;
    return area;

} // areea

void displayData (double length, double width, double area) {
    cout << "Rectangle is " << length << " by " << width << "." << endl;
    cout << "Area is: " << area << endl;
    return;// return is assumed at teh end for a void fucntion
} // display
// display data, void function simply shows the values and what