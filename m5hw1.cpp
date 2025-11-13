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
    if (selection == 1) {
        Q1();
    }
    else if (selection == 2) {
        Q2();
    }
    else if (selection == 3) {
        Q3();
    }
    else if (selection == 4) {
        Q4();
    }
    else if (selection == 5) {
        Q5();
    }
    
    else if (selection == 0) {
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
double avgRain (double num1, double num2, double num3) {
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
    cout << "Enter the rain fall for each month" << endl; 
    cin >> rfm1;
    cin >> rfm2;
    cin >> rfm3;
    cout << setprecision(2) << fixed;
    avgrain = avgRain(rfm1,rfm2, rfm3);
    cout << "The average rain fall for " << m1 << ", " << m2 << ", " << m3 << " is " << avgrain << " inches. " << endl;
}

void Q2() {
    cout << "QUESTION 2:" << endl;
    double length, width, height;  
    double volume; 
    bool calculate = true; // this ends the loop!!!!
    cout << "Enter length." << endl; 
    cin >> length;
    cout << endl; 
    cout << "Enter width." << endl; 
    cin >> width;
    cout << endl; 
    cout << "Enter height." << endl; 
    cout << endl; 
    cin >> height; 
    cout << endl; 

    while (calculate == true) {
        if (length > 0 && height > 0) {
            volume = length * width * height; 
            cout << "The volume of the block is " << volume << endl;
        
            calculate = false; 
        }
        else {
            cout << "Not a valid option." << endl;
            return Q2();
        }
        
    }
}

void Q3() {
   cout << "QUESTION 3:" << endl;
   int num;
   bool program3 = true;
   cout << "Enter an integer 1 - 10: " << endl;
   cin >> num;

   while (program3 == true) {
    if (num >= 1 && num <= 10) {
        
        if (num == 1) {
            cout << "Roman numeral for " << num << " is I." << endl;
            program3 = false; 
        }
        else if (num == 2) {
            cout << "The roman numeral for " << num << " is II." << endl;
            program3 = false; 
        }
        else if (num == 3) {
            cout << "The roman numeral for " << num << " is III." << endl; 
            program3 = false;
        }
        else if (num == 4) {
            cout << "The roman numeral for " << num << " is IV." << endl; 
            program3 = false; 
        }
        else if (num == 5) {
            cout << "The roman numeral for " << num << " is V." << endl; 
            program3 = false;
        }
        else if (num == 6) {
            cout << "The roman numeral for " << num << " is VI." << endl; 
            program3 = false;
        }
        else if (num == 7) {
            cout << "The roman numeral for " << num << " is VII." << endl;
            program3 = false;
        }
        else if (num == 8) {
            cout << "The roman numeral for " << num << "is VIII." << endl; 
            program3 = false; 
        }
        else if (num == 9) {
            cout << "The roman numeral for " << num << " is IX." << endl; 
            program3 = false; 
        }
        else if (num == 10) {
            cout << "The roman numeral for " << num << " is  X." << endl; 
            program3 = false; 
        }
        else {
            cout << " Input values from 1 to 10." << endl; 
            cout << endl; 
            return Q3();
        }
    }
   }
}

void Q4() {
    cout << "QUESTION 4: " << endl;
    int selection;
    bool program4 = true;
   

    while (program4 == true) {
        cout << "Geometry Calculator!" << endl;
        cout << "1. Area of a circle." << endl; 
        cout << "2. Area of a rectangle." << endl; 
        cout << "3. Area of a triangle." << endl; 
        cout << "0. Go back to menu." << endl; 
        cout << "Enter your choice!" << endl; 
        cin >> selection; 
        cout << endl; 

        if (selection == 1) {
            double radius;
            double circleA; 
            const double PI = 3.14159;
            cout << "Enter Radius of your circle! MEOW." << endl; 
            cin >> radius; 

            if (radius > 0) {
                cout << setprecision(2) << fixed;
                circleA = radius * radius * PI;
                cout << "The area of your circle is " << circleA << endl; 
                program4 = false; 
            }
            else {
                cout << "Your radius must be positive." << endl; 
            }
        }

        else if (selection == 2) { 

            double length;
            double width; 
            double rectangleA; 
            cout << "Enter rectangle length!" << endl;
            cin >> length;
            cout << endl; 
            cout << "Can I get that width now? " << endl; 
            cin >> width;

            if (length > 0 && width > 0) {
                cout << setprecision(2) << fixed; 
                rectangleA = length * width; 
                cout << "Your area is " << rectangleA << endl; 
                program4 = false;
            }
            else {
                cout << "It's gotta be positive values friend." << endl;
                cout << endl;
            }
        }

        else if (selection == 3) {

            // triangle area code goes here
            double base; 
            double height; 
            double triangleA;
            cout << "Enter your triangle's base. " << endl; 
            cin >> base; 
            cout << "Enter the height of the triangle. " << endl; 
            cin >> height;
    
            if (base > 0 && height > 0) {
                cout << setprecision(2) << fixed;
                triangleA = base * height * 0.5; 
                cout << "The area of your triangle is " << triangleA << endl;
            program4 = false;
            }

        }
        else {
            cout << "Your values must be positive." << endl; 
        }
    } 

    if (selection == 0) {
        cout << "Ending program." << endl; 
        program4 = false;
    }
    else {
        cout << "That is an invalid input, try again." << endl; 
        return Q4();
    }
}


// question 5
void Q5() {
    cout << "QUESTION 5:" << endl;
    int speed; 
    double totaltime;
    double dph; // distance per hour
    cout << "Enter the speed of thine vehicle in mph: " << endl;
    cin >> speed; 
    cout << endl; 
    cout << "Enter time spent traveling in hours. " << endl; 
    cin >> totaltime; 

    int hour = 0;
    while (hour < totaltime && totaltime > 0 && speed > 0) {
        hour++;
        dph = hour * speed; 
        cout << "Hour: " << hour << " distance travelled is " << dph << endl;
    }
}
