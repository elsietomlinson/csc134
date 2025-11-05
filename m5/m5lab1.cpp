/*
elsie tomlinson
csc134
11/5/2025
m5 lab1
*/

//define all the functions???
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void house_inside();

#include <iostream>
using namespace std; 
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
  } else {
    cout << "That's not a valid choice, please try again." << endl; //  validation and tells liek "loops" it 
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
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
        cout << "GAME OVER" << endl; 
        main_menu();
    }
    if (choice == 2) {
        cout << "Goodjob!  You have good surivival instincts, you made it out." << endl; 
    }
}