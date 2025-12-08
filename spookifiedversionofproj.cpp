/* elsie tomlinson
m6hw
11/18/2025
spookified mysterious edition
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// ===== ANSI COLOR CODES =====
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string MAGENTA = "\033[35m"; // mysterious purple
const string CYAN    = "\033[36m";
const string GREY    = "\033[90m"; // dim whisper
const string RESET   = "\033[0m";

// prototypes
void initialCONNECTIONS();
void showExits(int room);
void slowPrint(const string &text, int ms = 25);
void randomSpook();
string toLower(string s);

// constants for directions
enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3, NUM_DIRECTIONS = 4 };
// DEFINE ROOMS
enum Room { BEDROOM = 0, BATHROOM = 1, HALLWAY = 2, KITCHEN = 3, MOMROOM = 4, OUTSIDE = 5, NUM_ROOMS = 6 };

// ROOM NAMES & DESCRIPTIONS
string roomnames[NUM_ROOMS] = { "Bedroom", "Bathroom", "Hallway", "Kitchen", "Mom's Room", "Outside" };
string roomdescriptions[NUM_ROOMS] = {
    "Faded wallpaper peels in slow, unreadable patterns. A single drawer sits half-open, as if expecting you.",
    "The sink is full of cold water. A pale pattern stains the tile; you can't tell if it's shadow or something else.",
    "The map on the wall seems wrong: routes curve where they shouldn't. The hall feels slightly longer than before.",
    "Light from the window throws unlikely angles across the counters. Beyond the door, the world tastes different.",
    "A dresser lies broken; one drawer holds a small brass key that hums when you breathe near it.",
    "The night air is still. For a moment the sky seems to be listening. You have left the place — but did you leave it behind?"
};

int connections[NUM_ROOMS][NUM_DIRECTIONS];

// small utility: slow-print for atmosphere
void slowPrint(const string &text, int ms) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
}

// small random ambient messages to create unease
void randomSpook() {
    int r = rand() % 8; // tune chance
    switch (r) {
        case 0:
            cout << GREY; slowPrint("A whisper just beyond hearing...\n", 18); cout << RESET; break;
        case 1:
            cout << MAGENTA; slowPrint("The map on the wall seems to blink when you turn away.\n", 22); cout << RESET; break;
        case 2:
            cout << GREY << "Something moved in the corner of your eye." << RESET << "\n"; break;
        case 3:
            cout << CYAN << "A soft ticking begins, then stops as if embarrassed.\n" << RESET; break;
        case 4:
            cout << MAGENTA; slowPrint("For a heartbeat you think you saw your reflection smile.\n", 25); cout << RESET; break;
        default:
            // mostly silence
            break;
    }
}

string toLower(string s) {
    for (char &c : s) c = tolower(static_cast<unsigned char>(c));
    return s;
}

// show available exits (keeps original behavior)
void showExits(int room) {
    cout << CYAN << "Exits: " << RESET;
    bool first = true;
    if (connections[room][NORTH] != -1) { cout << (first?"":" , ") << "north"; first = false; }
    if (connections[room][SOUTH] != -1) { cout << (first?"":" , ") << "south"; first = false; }
    if (connections[room][EAST]  != -1) { cout << (first?"":" , ") << "east";  first = false; }
    if (connections[room][WEST]  != -1) { cout << (first?"":" , ") << "west";  first = false; }
    cout << endl;
}

int main() {
    srand((unsigned)time(nullptr));

    vector<string> playerInventory;

    // Items in rooms (bag in bedroom, key in mom's room)
    string roomItems[NUM_ROOMS] = { "bag", "map", "knife", "", "key", "" };

    initialCONNECTIONS();

    int currentRoom = BEDROOM;
    bool playing = true;
    bool hasKey = false;
    bool hasBag = false;

    slowPrint(MAGENTA + "You return to the house as the evening folds into itself...\n" + RESET, 18);
    slowPrint(GREY + "There is a feeling of wrong geometry here — keep your eyes open.\n\n" + RESET, 18);

    while (playing) {
        cout << CYAN << "\n=== " << roomnames[currentRoom] << " ===" << RESET << endl;
        slowPrint(MAGENTA + roomdescriptions[currentRoom] + "\n" + RESET, 12);

        showExits(currentRoom);

        if (roomItems[currentRoom] != "") {
            cout << YELLOW;
            slowPrint("You notice: " + roomItems[currentRoom] + "\n", 10);
            cout << RESET;
        }

        cout << "\n(try commands: north, south, east, west, take, inventory, quit)\n";
        cout << "-> ";

        string line;
        getline(cin, line);
        if (line.empty()) { // handle leading newline
            getline(cin, line);
        }
        string command = toLower(line);

        bool valid = false;

        // movement
        if (command == "north" || command == "south" || command == "east" || command == "west") {
            valid = true;
            int dir = (command == "north") ? NORTH : (command == "south") ? SOUTH : (command == "east") ? EAST : WEST;
            int nextRoom = connections[currentRoom][dir];

            if (nextRoom == -1) {
                cout << RED << "You can't go that way." << RESET << endl;
            }
            else if (nextRoom == OUTSIDE && !hasKey) {
                cout << RED << "The heavy door refuses you. A key would help." << RESET << endl;
            }
            else {
                slowPrint(GREEN + "You move " + command + ".\n" + RESET, 8);
                currentRoom = nextRoom;

                // small chance to trigger ambient
                if ((rand() % 100) < 40) randomSpook();
            }
        }
        // take / pick up
        else if (command.rfind("take",0) == 0 || command.rfind("pick up",0) == 0 || command.rfind("grab",0) == 0) {
            valid = true;

            if (roomItems[currentRoom] == "") {
                cout << RED << "There's nothing obvious to take." << RESET << endl;
            }
            else {
                // if item is not bag and player lacks bag -> block
                if (!hasBag && roomItems[currentRoom] != "bag") {
                    cout << RED << "You have nothing to carry items with. Perhaps there's something in your room." << RESET << endl;
                }
                else {
                    slowPrint(GREEN + "You take the " + roomItems[currentRoom] + ".\n" + RESET, 12);
                    playerInventory.push_back(roomItems[currentRoom]);
                    if (roomItems[currentRoom] == "key") { hasKey = true; slowPrint(MAGENTA + "The key feels oddly warm.\n" + RESET, 14); }
                    if (roomItems[currentRoom] == "bag") { hasBag = true; slowPrint(CYAN + "You sling the bag over your shoulder; it fits like memory.\n" + RESET, 14); }
                    roomItems[currentRoom] = "";
                }
            }
        }
        // inventory
        else if (command == "inventory" || command == "i") {
            valid = true;
            cout << CYAN << "Inventory:" << RESET << endl;
            if (playerInventory.empty()) cout << GREY << "(empty)" << RESET << endl;
            else for (auto &it : playerInventory) cout << "- " << YELLOW << it << RESET << endl;
        }
        // quit
        else if (command == "quit" || command == "exit") {
            valid = true;
            slowPrint(RED + "You decide to leave... for now.\n" + RESET, 14);
            playing = false;
        }

        if (!valid) {
            cout << RED << "Invalid command. Try a direction or an action." << RESET << endl;
        }
    }

    return 0;
}

// initial connections
void initialCONNECTIONS () {
    for (int i = 0; i < NUM_ROOMS; i++) for (int j = 0; j < NUM_DIRECTIONS; j++) connections[i][j] = -1;

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
