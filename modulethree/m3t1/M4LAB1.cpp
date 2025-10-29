/* 
elsie tomlinson
csc-134
bonus but not bonus assignment 
ai has got free pass for this i guess
norris i have no clue what's going on adn assignments keep chaing :,(
*/
#include <iostream> 
using namespace std;
    int main () { // main
int choice;
cout << "Choose 1 to view inventory and choose 2 to view health bar, or choose 3 to access player stats." << endl;
cin >> choice; // choosing where the code takes you 
        if (choice == 1){
                string equipment[5] = {
                "Iron Sword",
                "Leather Armor",
                "Health Potion",
                "Magic Ring",
                "Rope"
            };
            cout << "=== YOUR INVENTORY ===" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << equipment[i] << endl;
            }
            cout << "======================" << endl;
            cout << "Search: " << endl;
            cin.ignore(); // set up function
            string searchItem;
            getline(cin, searchItem); // getline is a function in c++ that reads all lines of code and helps you find things
// search function
            bool found = false; 
            int position = -1; 
            for (int i = 0; i <5; i++) {
                if (equipment[i] == searchItem) {
                    found = true;
                    position = i + 1; 
                    break;
                }
            }
            if (found) {
                cout << "Found " << searchItem << " in slot " << position << "!" << endl;
            }
            else {
                cout << searchItem << "was not found in inventory." << endl;        
             }
        }

else if (choice == 2) {
    // health function
    cout << "Don't let your health get to zero!" << endl; 
int health = 20; 
int Maxhealth = 100;
while (health < Maxhealth)
{
    health = health + 10;
    cout << "Health: " << health << "/" << Maxhealth << endl;
}
cout << "Fully Recovered!" << endl;
}

    else if (choice == 3) {
    cout << "=== Character Stats up to Level 10 ===" << endl; // character stat function
    for (int level = 1; level <= 10; level ++) {
        int health = 100 + level * 20;
        int attack = 10 + level * 5;
        int defense = 3 + level * 4; 

        // now you can type in your output
        cout << "====Level==== " << level << ":" << endl;
        cout << "Health: " << health << "." << endl;
        cout << "Attack: " << attack << "." << endl;
        cout << "Defense: " << defense << "." << endl;
    }}
        return 0; }