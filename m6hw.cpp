/* elsie tomlinson
m6hw
11/18/2025
prototype for my final project
*/
#include <iostream> 
#include <string> 
#include <vector>
#include <map> 

using namespace std;
// here is my moving fucntion
 void initialCONNECTIONS();



// constants for my directions
enum Direction {
    NORTH = 0,
    SOUTH = 1, 
    EAST = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};
//DEFINE MY ROOMS
enum Room {
    BEDROOM = 0, 
    BATHROOM = 1,
    HALLWAY = 2, 
    KITCHEN = 3, 
    MOMROOM = 4,
    NUM_ROOMS = 5
};
 // STRING NAMES FOR ROOMS 
    string roomnames[NUM_ROOMS] = {
        "Bedroom" ,
        "Bathroom" ,
        "Hallway" ,
        "Kitchen" ,
        "Mom's Room"
    };
    // room descriptions for array meow 
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    string roomdescriptions[NUM_ROOMS] = {
        "Welcome to your childhood bedroom that looks the same as the day you moved out for university." ,
        "The bathroom light flickers on as you look around the dimly lit room. It's dirty in here." , 
        "The hallway is dark and dim. You see your grandfather's old map haning on the wall." ,
        "The kitchen is dirty and dark. You see the key to the front door on the counter." , 
        "Your mothers room is dark and disheveled. There was a struggle in here."
    };

int main() {
// adding string for inventory
vector<string> playerInventory;
string roomItems[NUM_ROOMS] = {
    "", "", "", "", "key"   // key is in mom's room
};

    // calling the movement function
   initialCONNECTIONS();
int currentRoom = BEDROOM; // starting room (example)
  bool playing = true;

    // You can immediately use your room arrays
    cout << roomnames[currentRoom] << endl;
    cout << roomdescriptions[currentRoom] << endl;

    while (playing) {

        // Show room name + description
        cout << "\n--- " << roomnames[currentRoom] << " ---\n";
        cout << roomdescriptions[currentRoom] << endl;

        // Show item if present
        if (roomItems[currentRoom] != "") {
            cout << "You see a " << roomItems[currentRoom] << " here.\n";
        }

        // Get player input
        cout << "\nEnter command (north/south/east/west, take, inventory, quit): ";
        string command;
        cin >> command;

        // MOVEMENT COMMANDS
        if (command == "north") {
            if (connections[currentRoom][NORTH] != -1)
                currentRoom = connections[currentRoom][NORTH];
            else
                cout << "You can't go that way.\n";
        }
        else if (command == "south") {
            if (connections[currentRoom][SOUTH] != -1)
                currentRoom = connections[currentRoom][SOUTH];
            else
                cout << "You can't go that way.\n";
        }
        else if (command == "east") {
            if (connections[currentRoom][EAST] != -1)
                currentRoom = connections[currentRoom][EAST];
            else
                cout << "You can't go that way.\n";
        }
        else if (command == "west") {
            if (connections[currentRoom][WEST] != -1)
                currentRoom = connections[currentRoom][WEST];
            else
                cout << "You can't go that way.\n";
        }

        // TAKE ITEM
        else if (command == "take") {
            if (roomItems[currentRoom] != "") {
                cout << "You picked up the " << roomItems[currentRoom] << "!\n";
                playerInventory.push_back(roomItems[currentRoom]);
                roomItems[currentRoom] = ""; // remove from room
            } else {
                cout << "There's nothing to take.\n";
            }
        }

        // PRINT INVENTORY
        else if (command == "inventory") {
            cout << "You are carrying:\n";
            if (playerInventory.empty()) {
                cout << "Nothing.\n";
            } else {
                for (string item : playerInventory) {
                    cout << "- " << item << endl;
                }
            }
        }

        // QUIT GAME
        else if (command == "quit") {
            playing = false;
        }

        // UNKNOWN COMMAND
        else {
            cout << "I don't understand that command.\n";
        }
    }

    return 0;
 
}


// here is my initial conditions function

void initialCONNECTIONS () {
       
        
        // Initialize all connections to -1 (no connection)
        for (int i = 0; i < NUM_ROOMS; i++) {
            for (int j = 0; j < NUM_DIRECTIONS; j++) {
                connections[i][j] = -1;
            }
        }
        // now define the connections between all of the rooms 
        connections[BEDROOM][NORTH] = HALLWAY;
        connections[BEDROOM][SOUTH] = -1;
        connections[BEDROOM][EAST] = -1;
        connections[BEDROOM][WEST] = -1;
        // connections for the hall way
        connections[HALLWAY][NORTH] = KITCHEN;
        connections[HALLWAY][SOUTH] = BEDROOM; 
        connections[HALLWAY][EAST] = BATHROOM; 
        connections[HALLWAY][WEST] = MOMROOM; 

        // connections for KITCHEN
        connections[KITCHEN][NORTH] = -1; 
        connections[KITCHEN][SOUTH] = HALLWAY;
        connections[KITCHEN][EAST] = -1; 
        connections[KITCHEN][WEST] = -1; 

        // connections for mom;s room
        connections[MOMROOM][NORTH] = -1; 
        connections[MOMROOM][SOUTH] = -1;
        connections[MOMROOM][WEST] = -1;
        connections[MOMROOM][EAST] = HALLWAY;
        
        // connection for bathroom 
        connections[BATHROOM][NORTH] = -1;
        connections[BATHROOM][SOUTH] = -1;
        connections[BATHROOM][WEST] = HALLWAY;
        connections[BATHROOM][EAST] = -1; 
}