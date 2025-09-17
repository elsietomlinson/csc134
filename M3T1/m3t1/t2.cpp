/* elsie tomlinson
m3t1/t2
csc-134
09/17/2025
area of a rectangle
*/
#include <iostream> 
using namespace  std;

int main () { 
//get info on two rectangles
double length1, length2, width1, width2;
double area1, area2;
cout << "Enter the length and width of two rectangles in inches." << endl;
cout << "First rectangle." << endl;
cout << "Length:" << endl;
cin >> length1;
cout << "Width: " << endl;
cin>> width1;
cout << endl;
cout << "Second rectangle." << endl;
cout << "Length: " << endl; 
cin >> length2;
cout << "Width: " << endl;
cin >> width2;
//calculate the area
area1 = length1 * width1;
area2 = length2 * width2; 
//print the output
cout << "The area of the first rectangle is: " << area1 << " inches." << endl;
cout << "The are of the second rectangle is: " << area2 << " inches." << endl;
// then use your if statements 
cout << "First rectangle area = " << area1 << endl;
cout << "Second rectangle area = " << area2 << endl;
//compare both rectangles
if (area1 > area2) {
    cout << "The first rectangle is larger." << endl;

}

if (area2 > area2) 
{
    cout << "The second rectangle is larger." << endl;

}
if (area1 == area2) { // "==" means equal to
    cout << "The rectangles are the same size." << endl;

}




    return 0; // no errors
}