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
double getLength(); // get the length
double getWidth(); // width
double getArea(); // areea
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
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors

	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea();
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

double getLength(){
    cout << "code not ready yet" << endl; 
return 0.0;
} // get the length

double getWidth() {
    cout << "code not ready yet" << endl; 
return 0.0;
} // width

double getArea(double length, double width) {
    cout << "code not ready" << endl;
return 0.0;
} // areea

void displayData (double length, double width, double area) {
    cout << "code not ready" << endl;
} // display
// display data, void function simply shows the values and what