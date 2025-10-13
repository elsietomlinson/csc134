/*
m4t2
elsie tomlinson
using ai to modify our choose your own adventure game 
meowmoew moew meow meow
*/
#include <iostream>
#include <string>
using namespace std;

void bedroom();       // starting room
void store();         // store room
void gameOver();      // losing end
void victory();       // winning end
void grocerylist();   // the mini-game

// main()
int main () {
    cout << "Welcome to this thrilling adventure!" << endl << endl;
    cout << "You're in your childhood bedroom. Do you:" << endl;
    cout << "1. Go to the store" << endl;
    cout << "2. Stay home" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Brave soul leaving your home! Don't run into anyone you know!" << endl; 
        store();
        victory();
        cout << endl;
        grocerylist(); // Launch the grocery game
    }
    else if (choice == 2) {
        gameOver();
    }
    else {
        cout << "Don't do that babe." << endl;
        cout << "Use the functions I told you." << endl;
    }

    return 0;
}

// Endings
void gameOver() {
    cout << "Go bed rot on TikTok till your parents call you!" << endl;
    cout << "You lose cause you don't have groceries." << endl; 
}

void victory() {
    cout << "You made it to the store, you win cause you went grocery store." << endl;
}

// Store intro
void store() {
    cout << "Welcome to the store! You have ventured out of your humble abode!" << endl;
    cout << "Now you must do the grocery shopping for the week or you'll starve!" << endl;
}

// Grocery list mini-game
void grocerylist() {
    cout << "\nTime to shop! Here's your grocery list: Eggs, Milk, Coffee, Chocolate." << endl;
    cout << "Find all 4 to survive the week!" << endl << endl;

    int correct = 0;
    string answer;

    // Item 1: Eggs
    cout << "You arrive at the dairy aisle. What do you pick up?" << endl;
    cout << "a) A block of cheese\nb) A dozen eggs\nc) Butter" << endl;
    cout << "Your choice: ";
    cin >> answer;
    if (answer == "b" || answer == "B") {
        cout << "✅ You got the eggs!" << endl;
        correct++;
    } else {
        cout << "❌ Nope, you missed the eggs." << endl;
    }

    // Item 2: Milk
    cout << "\nYou move on to the cold drinks section. What do you grab?" << endl;
    cout << "a) Milk\nb) Soda\nc) Orange juice" << endl;
    cout << "Your choice: ";
    cin >> answer;
    if (answer == "a" || answer == "A") {
        cout << "✅ You got the milk!" << endl;
        correct++;
    } else {
        cout << "❌ Wrong shelf, no milk for you." << endl;
    }

    // Item 3: Coffee
    cout << "\nNext stop, the beverage aisle. Pick something to stay awake!" << endl;
    cout << "a) Tea\nb) Coffee\nc) Sports drink" << endl;
    cout << "Your choice: ";
    cin >> answer;
    if (answer == "b" || answer == "B") {
        cout << "✅ You got the coffee!" << endl;
        correct++;
    } else {
        cout << "❌ Oops, that’s not coffee." << endl;
    }

    // Item 4: Chocolate
    cout << "\nFinally, you head to the snacks aisle for a sweet treat. What do you pick?" << endl;
    cout << "a) Crackers\nb) Trail mix\nc) Chocolate" << endl;
    cout << "Your choice: ";
    cin >> answer;
    if (answer == "c" || answer == "C") {
        cout << "✅ You got the chocolate!" << endl;
        correct++;
    } else {
        cout << "❌ Where’s the chocolate, huh?" << endl;
    }

    // Final result
    cout << "\nYou collected " << correct << " out of 4 items." << endl;

    if (correct == 4) {
        cout << "🏆 You got everything on your list! You're a grocery-shopping legend!" << endl;
    } else if (correct >= 2) {
        cout << "👍 Not bad, you got most of it. You’ll survive... probably." << endl;
    } else {
        cout << "😬 You didn’t get enough. Better luck (and groceries) next time." << endl;
    }
}