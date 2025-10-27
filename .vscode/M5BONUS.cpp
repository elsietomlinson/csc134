/* 
elsie tomlinson
m5bonus assignment
orange pass for ai
10/27/2025
*/
// paste game
/*
ai transcript
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Item class
class Item {
public:
    string name;
    string description;
    
    Item(string n, string desc) : name(n), description(desc) {}
};

// Room class
class Room {
public:
    string name;
    string description;
    map<string, Room*> exits;
    vector<Item*> items;
    bool visited;
    
    Room(string n, string desc) : name(n), description(desc), visited(false) {}
    
    void addExit(string direction, Room* room) {
        exits[direction] = room;
    }
    
    void addItem(Item* item) {
        items.push_back(item);
    }
    
    Item* removeItem(string itemName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->name == itemName) {
                Item* item = *it;
                items.erase(it);
                return item;
            }
        }
        return nullptr;
    }
    
    Item* findItem(string itemName) {
        for (Item* item : items) {
            if (item->name == itemName) return item;
        }
        return nullptr;
    }
};

// Player class
class Player {
public:
    vector<Item*> inventory;
    int suspicion;
    Room* currentRoom;
    
    Player() : suspicion(0), currentRoom(nullptr) {}
    
    void addItem(Item* item) {
        inventory.push_back(item);
    }
    
    bool hasItem(string itemName) {
        for (Item* item : inventory) {
            if (item->name == itemName) return true;
        }
        return false;
    }
    
    Item* getItem(string itemName) {
        for (Item* item : inventory) {
            if (item->name == itemName) return item;
        }
        return nullptr;
    }
    
    void showInventory() {
        if (inventory.empty()) {
            cout << "\nYour pockets are empty. Très tragique.\n";
        } else {
            cout << "\n=== INVENTORY ===\n";
            for (Item* item : inventory) {
                cout << "  • " << item->name << "\n";
            }
        }
    }
    
    void addSuspicion(int amount = 1) {
        suspicion += amount;
        if (suspicion == 1) {
            cout << "\n⚠️  SUSPICION RAISED (1/3) - A guard glances your way...\n";
        } else if (suspicion == 2) {
            cout << "\n⚠️⚠️  SUSPICION RAISED (2/3) - Security is watching you closely!\n";
        } else if (suspicion >= 3) {
            cout << "\n🚨🚨🚨 SUSPICION MAXED (3/3) 🚨🚨🚨\n";
        }
    }
};

// Game State class
class GameState {
public:
    Player player;
    vector<Room*> rooms;
    vector<Item*> allItems;
    bool gameOver;
    bool won;
    bool guardDistracted;
    bool codeEntered;
    string jewelCode;
    int hintsUsed;
    
    GameState() : gameOver(false), won(false), guardDistracted(false), codeEntered(false), jewelCode("1789"), hintsUsed(0) {}
    
    ~GameState() {
        for (Room* room : rooms) delete room;
        for (Item* item : allItems) delete item;
    }
    
    void initializeGame() {
        // Create items
        Item* newspaper = new Item("newspaper", "Le Monde - the guard's favorite distraction");
        Item* keycard = new Item("keycard", "A sleek access card for the Gallery Wing");
        Item* note = new Item("note", "A cryptic note: 'Look for liberté, égalité, fraternité'");
        
        allItems.push_back(newspaper);
        allItems.push_back(keycard);
        allItems.push_back(note);
        
        // Create rooms
        Room* entrance = new Room("Entrance Hall", 
            "The grand foyer of the Château. Marble floors gleam under chandeliers.\n"
            "A bored security guard sits at a desk, scrolling his phone.\n"
            "An archway leads NORTH to the Gallery Wing (locked by keycard).");
        
        Room* gallery = new Room("Gallery Wing",
            "Walls adorned with priceless art. The air smells of old money and newer crimes.\n"
            "Three paintings dominate the space:\n"
            "  🎨 'Liberty Leading the People' (1830)\n"
            "  🎨 'Equality in the Garden' (1889)\n"
            "  🎨 'Brotherhood at Dawn' (1789) ⭐\n"
            "A heavy door leads NORTH to the Jewels Chamber.");
        
        Room* jewels = new Room("Jewels Chamber",
            "The heart of the collection. Behind bulletproof glass:\n"
            "✨ The Diamond of Versailles - worth more than a small nation's GDP.\n"
            "A keypad glows beside the case, demanding a code.\n"
            "An emergency exit is visible to the EAST.");
        
        // Set up exits
        entrance->addExit("north", gallery);
        gallery->addExit("south", entrance);
        gallery->addExit("north", jewels);
        jewels->addExit("south", gallery);
        
        // Add items to rooms
        entrance->addItem(newspaper);
        entrance->addItem(keycard);
        gallery->addItem(note);
        
        rooms.push_back(entrance);
        rooms.push_back(gallery);
        rooms.push_back(jewels);
        
        player.currentRoom = entrance;
    }
    
    void showIntro() {
        cout << "\n";
        cout << "╔════════════════════════════════════════════════╗\n";
        cout << "║         🎭 LE GRANDE HEIST 🎭                 ║\n";
        cout << "║    A Text Adventure in Redistribution         ║\n";
        cout << "╚════════════════════════════════════════════════╝\n\n";
        cout << "You are a master thief with a conscience.\n";
        cout << "Tonight's target: The Château de Richesse, where billionaires\n";
        cout << "hoard stolen wealth while people starve outside.\n\n";
        cout << "Your mission: Steal the Diamond of Versailles.\n";
        cout << "Your motive: Sell it and feed a thousand families.\n\n";
        cout << "Remember: Three strikes and you're caught. Bonne chance!\n\n";
        cout << "Type 'help' for commands. Debug mode: type 'win' to skip to victory.\n";
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    }
    
    void look() {
        Room* room = player.currentRoom;
        cout << "\n📍 " << room->name << "\n";
        cout << room->description << "\n";
        
        if (!room->items.empty()) {
            cout << "\nYou notice:\n";
            for (Item* item : room->items) {
                cout << "  • " << item->name << "\n";
            }
        }
        
        // Show suspicion
        cout << "\n🎭 Suspicion: " << player.suspicion << "/3\n";
    }
    
    void help() {
        cout << "\n=== COMMANDS ===\n";
        cout << "Movement: north, south, east, west (or n, s, e, w)\n";
        cout << "Actions:\n";
        cout << "  look / l - look around\n";
        cout << "  examine [item] / x [item] - examine something\n";
        cout << "  take [item] - pick up an item\n";
        cout << "  use [item] - use an item\n";
        cout << "  inventory / i - check your pockets\n";
        cout << "  help / h - show this message\n";
        cout << "Special: win - debug skip to victory\n\n";
    }
};

// Parser and game logic
class GameEngine {
private:
    GameState& state;
    
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    
    vector<string> tokenize(string input) {
        vector<string> tokens;
        stringstream ss(input);
        string word;
        while (ss >> word) {
            tokens.push_back(toLowerCase(word));
        }
        return tokens;
    }
    
public:
    GameEngine(GameState& gs) : state(gs) {}
    
    void processCommand(string input) {
        vector<string> tokens = tokenize(input);
        if (tokens.empty()) return;
        
        string command = tokens[0];
        
        // Debug command
        if (command == "win") {
            debugWin();
            return;
        }
        
        // Movement
        if (command == "north" || command == "n" || 
            command == "south" || command == "s" ||
            command == "east" || command == "e" ||
            command == "west" || command == "w") {
            move(command);
        }
        // Look
        else if (command == "look" || command == "l") {
            state.look();
        }
        // Inventory
        else if (command == "inventory" || command == "i") {
            state.player.showInventory();
        }
        // Help
        else if (command == "help" || command == "h") {
            state.help();
        }
        // Examine
        else if (command == "examine" || command == "x") {
            if (tokens.size() > 1) {
                examine(tokens[1]);
            } else {
                cout << "Examine what?\n";
            }
        }
        // Take
        else if (command == "take" || command == "get") {
            if (tokens.size() > 1) {
                take(tokens[1]);
            } else {
                cout << "Take what?\n";
            }
        }
        // Use
        else if (command == "use") {
            if (tokens.size() > 1) {
                use(tokens[1]);
            } else {
                cout << "Use what?\n";
            }
        }
        else {
            cout << "I don't understand that command. Type 'help' for options.\n";
        }
    }
    
    void move(string direction) {
        // Normalize direction
        if (direction == "n") direction = "north";
        if (direction == "s") direction = "south";
        if (direction == "e") direction = "east";
        if (direction == "w") direction = "west";
        
        Room* current = state.player.currentRoom;
        
        // Special handling for locked gallery
        if (current->name == "Entrance Hall" && direction == "north") {
            if (!state.guardDistracted) {
                cout << "\nThe guard blocks your path. \"Gallery's closed for cleaning, mon ami.\"\n";
                return;
            }
            if (!state.player.hasItem("keycard")) {
                cout << "\nThe door requires a keycard. Maybe the guard has one?\n";
                return;
            }
        }
        
        // Special handling for jewel chamber exit (win condition)
        if (current->name == "Jewels Chamber" && direction == "east") {
            if (state.player.hasItem("diamond")) {
                triggerWin();
                return;
            } else {
                cout << "\nYou can't leave empty-handed! The diamond awaits...\n";
                return;
            }
        }
        
        // Normal movement
        if (current->exits.find(direction) != current->exits.end()) {
            state.player.currentRoom = current->exits[direction];
            cout << "\n➜ Moving " << direction << "...\n";
            state.look();
        } else {
            cout << "\nYou can't go that way.\n";
        }
    }
    
    void examine(string itemName) {
        Room* room = state.player.currentRoom;
        
        // Special examination for paintings
        if (room->name == "Gallery Wing") {
            if (itemName == "liberty" || itemName == "painting" || itemName == "paintings") {
                cout << "\n'Liberty Leading the People' - Delacroix, 1830. Magnificent.\n";
                return;
            }
            if (itemName == "equality") {
                cout << "\n'Equality in the Garden' - A serene scene from 1889.\n";
                return;
            }
            if (itemName == "brotherhood") {
                cout << "\n'Brotherhood at Dawn' - Painted in 1789.\n";
                cout << "Wait... 1789? The year of the French Revolution!\n";
                cout << "Could this be the code? 🔑\n";
                return;
            }
        }
        
        // Check room items
        Item* item = room->findItem(itemName);
        if (item) {
            cout << "\n" << item->description << "\n";
            return;
        }
        
        // Check inventory
        item = state.player.getItem(itemName);
        if (item) {
            cout << "\n" << item->description << "\n";
            return;
        }
        
        cout << "\nYou don't see that here.\n";
    }
    
    void take(string itemName) {
        Room* room = state.player.currentRoom;
        
        // Special case: taking keycard from entrance
        if (room->name == "Entrance Hall" && itemName == "keycard") {
            if (!state.guardDistracted) {
                cout << "\nThe guard is watching too closely. You need a distraction first.\n";
                state.player.addSuspicion();
                checkGameOver();
                return;
            }
        }
        
        Item* item = room->removeItem(itemName);
        if (item) {
            state.player.addItem(item);
            cout << "\nTaken: " << item->name << "\n";
        } else {
            cout << "\nYou can't take that.\n";
        }
    }
    
    void use(string itemName) {
        Room* room = state.player.currentRoom;
        
        // Use newspaper on guard
        if (itemName == "newspaper" && room->name == "Entrance Hall") {
            if (!state.player.hasItem("newspaper")) {
                cout << "\nYou don't have that.\n";
                return;
            }
            cout << "\nYou casually leave the newspaper on the guard's desk.\n";
            cout << "\"Ah, merci!\" He becomes engrossed in the sports section.\n";
            cout << "Perfect. Time to move. 🎭\n";
            state.guardDistracted = true;
            return;
        }
        
        // Use keycard on gallery door
        if (itemName == "keycard" && room->name == "Entrance Hall") {
            if (!state.player.hasItem("keycard")) {
                cout << "\nYou don't have that.\n";
                return;
            }
            cout << "\nYou'll use the keycard when you move north.\n";
            return;
        }
        
        // Use code on jewel case
        if (itemName == "code" && room->name == "Jewels Chamber") {
            cout << "\nEnter the 4-digit code: ";
            string input;
            cin >> input;
            cin.ignore(); // Clear newline
            
            if (input == state.jewelCode) {
                cout << "\n✨✨✨ CLICK ✨✨✨\n";
                cout << "The case hisses open. The Diamond of Versailles is yours!\n";
                cout << "\"Liberté, égalité, fraternité,\" you whisper. \"And justice.\"\n";
                Item* diamond = new Item("diamond", "The Diamond of Versailles - freedom in crystallized form");
                state.allItems.push_back(diamond);
                state.player.addItem(diamond);
                state.codeEntered = true;
                cout << "\n🎯 Now GET OUT! Head EAST to the emergency exit!\n";
            } else {
                cout << "\n❌ INCORRECT CODE\n";
                cout << "An alarm beeps once. Security is alerted!\n";
                state.player.addSuspicion(2);
                checkGameOver();
            }
            return;
        }
        
        cout << "\nYou can't use that here.\n";
    }
    
    void checkGameOver() {
        if (state.player.suspicion >= 3) {
            cout << "\n╔════════════════════════════════════════════════╗\n";
            cout << "║              🚨 CAUGHT! 🚨                     ║\n";
            cout << "╚════════════════════════════════════════════════╝\n";
            cout << "\nSecurity swarms you. Handcuffs click shut.\n";
            cout << "\"Bonne nuit, mon ami,\" smirks a guard.\n\n";
            cout << "The rich stay rich. The poor stay hungry.\n";
            cout << "Better luck next time, Robin Hood.\n\n";
            cout << "GAME OVER - Try again!\n";
            state.gameOver = true;
            state.won = false;
        }
    }
    
    void triggerWin() {
        cout << "\n╔════════════════════════════════════════════════╗\n";
        cout << "║         ⭐ VICTOIRE! ⭐                        ║\n";
        cout << "╚════════════════════════════════════════════════╝\n\n";
        cout << "You slip into the night, diamond in hand.\n";
        cout << "Behind you, alarms finally blare - but you're already gone.\n\n";
        cout << "Three weeks later, the news reports:\n";
        cout << "\"Anonymous donor feeds 1,000 families for a year.\"\n\n";
        cout << "💎 The rich got a little poorer.\n";
        cout << "🍞 The poor got a little fed.\n";
        cout << "🎭 And you? You vanished into legend.\n\n";
        cout << "\"Mangez les riches,\" you whisper to the moon.\n";
        cout << "\"Eat the rich indeed.\"\n\n";
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        cout << "🏆 CONGRATULATIONS - YOU WON! 🏆\n";
        cout << "Thanks for playing LE GRANDE HEIST!\n\n";
        state.gameOver = true;
        state.won = true;
    }
    
    void debugWin() {
        cout << "\n[DEBUG MODE] Skipping to victory...\n";
        Item* diamond = new Item("diamond", "The Diamond of Versailles - freedom in crystallized form");
        state.allItems.push_back(diamond);
        state.player.addItem(diamond);
        triggerWin();
    }
};

// Main game loop
int main() {
    GameState game;
    game.initializeGame();
    GameEngine engine(game);
    
    game.showIntro();
    game.look();
    
    string input;
    while (!game.gameOver) {
        cout << "\n> ";
        getline(cin, input);
        
        if (input.empty()) continue;
        
        engine.processCommand(input);
    }
    
    cout << "\nPress Enter to exit...";
    cin.get();
    
    return 0;
}