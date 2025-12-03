/* 
elsie tomlinson
m7hw
gold tier
12/3/2025
mini rock paper scissors
*/
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std; 

void intro();
void game(); 
int main () {
intro();

    return 0;
}

void intro()  {

    cout << "Welcome to the mini project!" << endl; 
    cout << "ー═┻┳︻▄ξ(╬ಠ益ಠ)ξ▄︻┻┳═一" << endl;
    cout << "Would you like to play rock paper scissors with me?" ;
    cout << endl;
    cout << "Yes or No." << endl;
    string decision;
    cin  >> decision;

    if (decision == "Yes") {
        game();
    }
    else if (decision == "No") {
        cout << "Ok, bye!" << endl;
    }
    else {
        cout << "I don't understand that commad." << endl;
    }
    
}

void game() {
    srand(time(nullptr));

    int player, computer;

    cout << "Choose your weapon! (1=Rock, 2=Paper, 3=Scissors): ";
    cin >> player;

    computer = (rand() % 3) + 1;

    cout << "You chose: " << player << endl;
    cout << "Computer chose: " << computer << endl;

    if (player == computer) {
        cout << "It's a tie!" << endl;
    }
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2)) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins! Womp Womp!" << endl;
    }

}