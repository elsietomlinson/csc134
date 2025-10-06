/* 
elsie tomlinson
csc-134
bonus but not bonus assignment 
ai has got free pass for this i guess
*/
#include <iostream> 
using namespace std;
    int main () {
int choice;
cout << "Choose 1 to view inventory and choose 2 to view health bar." << endl;
cin >> choice; 
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
int health = 50; 
int Maxhealth = 100;
while (health < Maxhealth)
{
    health = health + 10;
    cout << "Health: " << health << "/" << Maxhealth << endl;
}
}


        return 0;
    }