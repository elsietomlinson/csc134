/*
elsie tomlinson
csc134
11/5/2025
m5 lab1
*/



//define all the functions
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void house_inside();
void house_basement();

#include <iostream>
#include <limits>
using namespace std; 

// input validation
int get_valid_int(int min, int max) {
    int choice;
    while (true) {
        cout << "Choose: ";
        cin >> choice;

        if (cin.fail()) { // not an integer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between " << min << " and " << max << "." << endl;
        } else if (choice < min || choice > max) { // out of range
            cout << "Invalid choice. Enter a number between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean up input buffer
            return choice;
        }
    }
}
int main () {
 cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // end of main 
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You're in front of a spooky old house..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
   if (cin.fail()) { // handle bad input like letters
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and 4.\n";
        return; // go back to top of loop
    }
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
   choice_go_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
          return; // go back to main()
  } 
    else {
    cout << "That's not a valid choice, please try again." << endl;
      return; // repeat loop
    }
}


// FUNCTION DEFINITIONS
void choice_front_door() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_go_home();
  }
}

void choice_back_door() { 
    cout << "You choose to go around the back.:" << endl;
    cout << "The house is so spooky and dark!" << endl; 
    cout << "You hear1 a rustling in the woods!" << endl;
    cout << "Do you: " << endl;
    cout << "1. Investigate." << endl; 
    cout << "2. Continue for the back door." << endl; 
    int choice; 
    cin >> choice; 
        if (choice == 1 ) {
            cout << "It's just a cat! Keep moving along." << endl; 
           house_inside();
        }
        else if ( choice == 2 ) {
            cout << "Ignore it! The house is way more interesting!" << endl;
            house_inside();
        }
        else {
            cout << "Oooh gurl, what is that?" << endl;
        }
}

void choice_go_home() { cout << "Oh, well. Not everyone is adventurous!" << endl; 

}

void house_inside() {
    cout << "The back door is unlocked!" << endl; 
    cout << "You enter the spooky house!" << endl; 
    cout << "You hear a banging coming from the basement." ;
    cout << "Do you : " << endl;
    cout << "1. Investigate." << endl;
    cout << "2. Leave, girl." << endl; 
    int choice; 
    cin >> choice; 
    if (choice == 1 ) {
        cout << "Dude that's a ghost!" << endl; 
       
        house_basement();
    }
    if (choice == 2) {
        cout << "Goodjob!  You have good surivival instincts, you made it out." << endl; 
    }
}
 void house_basement() {
   cout << "You climb down the creaky stairs to the dingy and dark basement." ;
   cout << "You hear a creature moving in the dark!" ;
   cout << endl;
}