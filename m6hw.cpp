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

// ===== ANSI COLOR CODES =====
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN    = "\033[36m";
const string RESET   = "\033[0m";

// function prototypes
void initialCONNECTIONS();
void showExits(int room);

// constants for directions
enum Direction {
    NORTH = 0,
    SOUTH = 1, 
    EAST = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// DEFINE ROOMS
enum Room {
    BEDROOM = 0, 
    BATHROOM = 1,
    HALLWAY = 2, 
    KITCHEN = 3, 
    MOMROOM = 4,
    OUTSIDE = 5,
    NUM_ROOMS = 6
};

// ROOM NAMES
string roomnames[NUM_ROOMS] = {
    "Bedroom" ,
    "Bathroom" ,
    "Hallway" ,
    "Kitchen" ,
    "Mom's Room",
    "Outside"
};

// ROOM DESCRIPTIONS
string roomdescriptions[NUM_ROOMS] = {
    "Welcome to your childhood bedroom that looks the same as the day you moved out.",
    "The bathroom light flickers on as you look around the dimly lit, dirty room.",
    "The hallway is dark and quiet. Your grandfather's old map hangs on the wall.",
    "The kitchen is cluttered and dim. You see the front door—freedom is close!",
    "Your mother's room is dark and disheveled. A struggle happened here. A key rests on the dresser.",
    "You made it outside! Time to run from the ominous banging behind the door."
};

int connections[NUM_ROOMS][NUM_DIRECTIONS];

int main() {
    vector<string> playerInventory;

    // Items in each room
    string roomItems[NUM_ROOMS] = {
        "bag",   // bedroom
        "map",   // bathroom
        "knife", // hallway
        "",      // kitchen
        "key",   // mom's room
        ""       // outside
    };

    initialCONNECTIONS();

    int currentRoom = BEDROOM;
    bool playing = true;
    bool hasKey = false;
    bool hasBag = false;

    string command;

    // GAME LOOP
    while (playing) {

        // Room Header
        cout << CYAN << "\n=== " << roomnames[currentRoom] << " ===" << RESET << endl;

        // Description
        cout << MAGENTA << roomdescriptions[currentRoom] << RESET << endl;

        showExits(currentRoom);

        // Show item if present
        if (roomItems[currentRoom] != "") {
            cout << YELLOW << "You see a " << roomItems[currentRoom] << " here." 
                 << RESET << endl;
        }

        // Input
        cout << "\nEnter command (north/south/east/west, take, inventory, quit): ";
        cin >> command;

        bool valid = false;

        // MOVEMENT -----------------------------
        if (command == "north" || command == "south" ||
            command == "east"  || command == "west")
        {
            valid = true;

            int direction;
            if (command == "north") direction = NORTH;
            if (command == "south") direction = SOUTH;
            if (command == "east")  direction = EAST;
            if (command == "west")  direction = WEST;

            int nextRoom = connections[currentRoom][direction];

            if (nextRoom == -1) {
                cout << RED << "You can't go that way." << RESET << endl;
            }
            else if (nextRoom == OUTSIDE && !hasKey) {
                cout << RED << "The door is locked. You need the key from Mom's room." 
                     << RESET << endl;
            }
            else {
                cout << GREEN << "You move " << command << "." 
                     << RESET << endl;
                currentRoom = nextRoom;
            }
        }

        // TAKE --------------------------------
        else if (command == "take") {
            valid = true;

            if (roomItems[currentRoom] == "") {
                cout << RED << "There's nothing to take." << RESET << endl;
            }
            else if (!hasBag && roomItems[currentRoom] != "bag") {
                cout << RED << "You need something to hold items first." << RESET << endl;
            }
            else {
                cout << GREEN << "You picked up the " << roomItems[currentRoom] << "!" 
                     << RESET << endl;
                playerInventory.push_back(roomItems[currentRoom]);

                // Flags
                if (roomItems[currentRoom] == "key") {
                    hasKey = true;
                }
                if (roomItems[currentRoom] == "bag") {
                    hasBag = true;
                    cout << CYAN << "You can now carry other items." << RESET << endl;
                }

                roomItems[currentRoom] = "";
            }
        }

        // INVENTORY ----------------------------
        else if (command == "inventory") {
            valid = true;
            cout << CYAN << "You are carrying:" << RESET << endl;

            if (playerInventory.empty()) {
                cout << MAGENTA << "Nothing." << RESET << endl;
            }
            else {
                for (string item : playerInventory) {
                    cout << "- " << YELLOW << item << RESET << endl;
                }
            }
        }

        // QUIT --------------------------------
        else if (command == "quit") {
            valid = true;
            playing = false;
            cout << RED << "You quit the game." << RESET << endl;
        }

        // INVALID ------------------------------
        if (!valid) {
            cout << RED << "Invalid command. Try again." << RESET << endl;
        }
    }

    return 0;
}


// INITIAL CONNECTION SETUP
void initialCONNECTIONS () {
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }

    connections[BEDROOM][NORTH]  = HALLWAY;

    connections[HALLWAY][SOUTH]  = BEDROOM;
    connections[HALLWAY][NORTH]  = KITCHEN;
    connections[HALLWAY][EAST]   = BATHROOM;
    connections[HALLWAY][WEST]   = MOMROOM;

    connections[KITCHEN][SOUTH]  = HALLWAY;
    connections[KITCHEN][NORTH]  = OUTSIDE;

    connections[MOMROOM][EAST]   = HALLWAY;

    connections[BATHROOM][WEST]  = HALLWAY;
}


// SHOW AVAILABLE EXITS
void showExits(int room) {
    cout << CYAN << "Exits: " << RESET;

    bool first = true;

    if (connections[room][NORTH] != -1) {
        cout << (first ? "" : ", ") << "north";
        first = false;
    }
    if (connections[room][SOUTH] != -1) {
        cout << (first ? "" : ", ") << "south";
        first = false;
    }
    if (connections[room][EAST] != -1) {
        cout << (first ? "" : ", ") << "east";
        first = false;
    }
    if (connections[room][WEST] != -1) {
        cout << (first ? "" : ", ") << "west";
          first = false;
    }

    cout << endl;
}
