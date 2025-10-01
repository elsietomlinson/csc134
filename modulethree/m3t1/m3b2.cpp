/* 
Elsie Tomlinson
csc-134 
mandatory bonus assignment 
meow 
*/
#include <iostream> 
using namespace std; 
// define functions before main  
int roll(); 

int main () {

cout << "Welcome to Elsie's game!" << endl; 








    return 0;
}

void combat () {
/* a simple d and d style demo 
attack roll _ bonu >= armor class then else miss*/
// variables
int attack_roll, attacking_bonus, enemy_armor;
cout << "You are fighting a goblin." << endl;
cout << "Enter your attack bonus: " << endl;
cin >> attacking_bonus;
cout << "Enemy armor class: " << endl;
cin >> enemy_armor;
// roll to hit

attack_roll = roll();
cout << "Roll: " << attack_roll << " + " << attacking_bonus << " = " << attack_roll+attacking_bonus << endl;
if (attack_roll + attacking_bonus >= enemy_armor) {
    cout << "Hit!" << endl; 
}
else {
    cout << "Miss!" << endl; 
}
// try dagain? 
cout << "You want to go again?" << endl;
string again;
cin >> again; 
if (again == "y") {
    //call function again 
    combat();
}
}

// new function 
int roll() {
    const int SIDES = 20;
    int my_roll;
    my_roll = (rand() % SIDES) + 1;
    return my_roll;
}