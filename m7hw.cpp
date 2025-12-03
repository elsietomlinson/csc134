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
  int player, computer;
    int playerWins = 0, compWins = 0;

    while (playerWins < 2 && compWins < 2) {
        cout << "\nEnter your choice (1=Rock, 2=Paper, 3=Scissors): ";
        cin >> player;

        computer = (rand() % 3) + 1;

        cout << "You chose: " << player << endl;
        cout << "Computer chose: " << computer << endl;

        if (player == computer) {
            cout << "Round result: Tie!" << endl;
        }
        else if ((player == 1 && computer == 3) ||
                 (player == 2 && computer == 1) ||
                 (player == 3 && computer == 2)) {
            cout << "Round result: You win!" << endl;
            playerWins++;
        }
        else {
            cout << "Round result: Computer wins!" << endl;
            compWins++;
        }

        cout << "Score: You " << playerWins << " - "
             << compWins << " Computer\n";
    }

    cout << "\n=== Final Result ===\n";
    if (playerWins > compWins)
        cout << "You win the match!" << endl;
    else
        cout << "Computer wins the match!" << endl;

}
// here is the ai transcript for this 
/*
hey chat I want to write a C++ program for rock paper scissors. can you write me some skeleton code to show me how that would look like. Just base game mechanics
would like to be able to write it into one singular function
do you think we could implement a match feature to have it be best out of three? how would we added that into the already written code without changing it too much.








*/