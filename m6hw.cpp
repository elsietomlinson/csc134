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
void showExits(int room);


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
    OUTSIDE = 5,
    NUM_ROOMS = 6
};
 // STRING NAMES FOR ROOMS 
    string roomnames[NUM_ROOMS] = {
        "Bedroom" ,
        "Bathroom" ,
        "Hallway" ,
        "Kitchen" ,
        "Mom's Room",
        "Outside."
    };
    // room descriptions for array meow 
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    string roomdescriptions[NUM_ROOMS] = {
        "Welcome to your childhood bedroom that looks the same as the day you moved out for university." ,
        "The bathroom light flickers on as you look around the dimly lit room. It's dirty in here." , 
        "The hallway is dark and dim. You see your grandfather's old map haning on the wall." ,
        "The kitchen is dirty and dark. You see the front door, freedom is so close!" , 
        "Your mothers room is dark and disheveled. There was a struggle in here. You see a key on the dresser.",
        "You have made it outside and beat the game! Time to run from the ominous sounds banging on the front door behind you."
    };

int main() {
    // adding string for inventory
    vector<string> playerInventory;

    // Item locations: key is in mom's room
    string roomItems[NUM_ROOMS] = {
        "bag", "map", "knife", "", "key"   // adjust index if needed
    };

    // calling the movement function
    initialCONNECTIONS();

    int currentRoom = BEDROOM; // starting room
    bool playing = true;
    bool hasKey = false;
    bool hasBag = false;
   string command;
    // GAME LOOP
    while (playing) {

        // Show room info
        cout << "\n--- " << roomnames[currentRoom] << " ---\n";
        cout << roomdescriptions[currentRoom] << endl;
        showExits(currentRoom);

        // Show item if present
        if (roomItems[currentRoom] != "") {
            cout << "You see a " << roomItems[currentRoom] << " here.\n";
        }

        // Input
        cout << "\nEnter command (north/south/east/west, take, inventory, quit): ";
        cin >> command;

       bool valid = false;

// ---------------------------
// MOVEMENT
// ---------------------------
if (command == "north") {
    valid = true;
    int nextRoom = connections[currentRoom][NORTH];

    if (nextRoom == -1)
        cout << "You can't go that way.\n";
    else if (nextRoom == OUTSIDE && !hasKey)
        cout << "The door is locked. You need the key from Mom's room.\n";
    else
        currentRoom = nextRoom;
}

else if (command == "south") {
    valid = true;
    int nextRoom = connections[currentRoom][SOUTH];

    if (nextRoom == -1)
        cout << "You can't go that way.\n";
    else if (nextRoom == OUTSIDE && !hasKey)
        cout << "The door is locked. You need the key from Mom's room.\n";
    else
        currentRoom = nextRoom;
}

else if (command == "east") {
    valid = true;
    int nextRoom = connections[currentRoom][EAST];

    if (nextRoom == -1)
        cout << "You can't go that way.\n";
    else if (nextRoom == OUTSIDE && !hasKey)
        cout << "The door is locked. You need the key from Mom's room.\n";
    else
        currentRoom = nextRoom;
}

else if (command == "west") {
    valid = true;
    int nextRoom = connections[currentRoom][WEST];

    if (nextRoom == -1)
        cout << "You can't go that way.\n";
    else if (nextRoom == OUTSIDE && !hasKey)
        cout << "The door is locked. You need the key from Mom's room.\n";
    else
        currentRoom = nextRoom;
}

// ---------------------------
// TAKE
// ---------------------------
else if (command == "take") {
    valid = true;

    if (!hasBag) {
        cout << "You have no bag! You can't carry anything yet.\n";
    }
    else if (roomItems[currentRoom] != "") {
        cout << "You picked up the " << roomItems[currentRoom] << "!\n";
        playerInventory.push_back(roomItems[currentRoom]);

        if (roomItems[currentRoom] == "key")
            hasKey = true;

        roomItems[currentRoom] = "";
    } else {
        cout << "There's nothing to take.\n";
    }
}

// ---------------------------
// INVENTORY
// ---------------------------
else if (command == "inventory") {
    valid = true;

    cout << "You are carrying:\n";
    if (playerInventory.empty())
        cout << "Nothing.\n";
    else
        for (string item : playerInventory)
            cout << "- " << item << endl;
}

// ---------------------------
// QUIT
// ---------------------------
else if (command == "quit") {
    valid = true;
    playing = false;
}

// ---------------------------
// INVALID INPUT
// ---------------------------
if (!valid) {
    cout << "Invalid command. Try again.\n";
}



        // ---------------------------
        // TAKE ITEM
        // ---------------------------
             if (command == "take") {

    if (roomItems[currentRoom] == "") {
        cout << "There's nothing to take.\n";
    }
    else {
        // If the player does not have the bag, only allow taking the bag itself
        if (!hasBag && roomItems[currentRoom] != "bag") {
            cout << " You should find something to hold items.\n";
        }
        else {
            // Take item
            cout << "You picked up the " << roomItems[currentRoom] << "!\n";
            playerInventory.push_back(roomItems[currentRoom]);

            // Set flags
            if (roomItems[currentRoom] == "key") {
                hasKey = true;
            }
            if (roomItems[currentRoom] == "bag") {
                hasBag = true;
                cout << "You can now pick up other items.\n";
            }

            // Remove from room
            roomItems[currentRoom] = "";
        }
    }
}



        // ---------------------------
        // INVENTORY
        // ---------------------------
        else if (command == "inventory") {
            cout << "You are carrying:\n";

            if (playerInventory.empty()) {
                cout << "Nothing.\n";
            }
            else {
                for (string item : playerInventory) {
                    cout << "- " << item << endl;
                }
            }
        }


        // ---------------------------
        // QUIT
        // ---------------------------
        else if (command == "quit") {
            playing = false;
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
        connections[KITCHEN][NORTH] = OUTSIDE; 
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

        // connections outside
}
//exits function
void showExits(int room) {
    cout << "Exits: ";

    bool first = true;
    if (connections[room][NORTH] != -1) {
        cout << (first ? "" : ", ") << "north";
        first = false;
    }
    if (connections[room][SOUTH] != -1) {
        cout << (first ? "" : ", ") << "south";
        first = false;
    }
    if (connections[room][EAST]  != -1) {
        cout << (first ? "" : ", ") << "east";
        first = false;
    }
    if (connections[room][WEST]  != -1) {
        cout << (first ? "" : ", ") << "west";
        first = false;
    }

    cout << "\n";
}
