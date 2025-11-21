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
    string roomdescriptions[NUM_ROOMS] = {
        "Welcome to your childhood bedroom that looks the same as the day you moved out for university." ,
        "The bathroom light flickers on as you look around the dimly lit room. It's dirty in here." , 
        "The hallway is dark and dim. You see your grandfather's old map haning on the wall." ,
        "The kitchen is dirty and dark. You see the key to the front door on the counter." , 
        "Your mothers room is dark and disheveled. There was a struggle in here."
    };

int main() {
   
int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
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
    connections[KITCHEN][SOUTH] = BEDROOM;
    connections[KITHEN][EAST] = -1; 
    connections[KITCHEN][WEST] = -1; 

    // connections for mom;s room
    connections[MOMROOM][NORTH] = -1; 
    connections[MOMROOM][SOUTH] = -1;
    connections[MOMROOM][WEST] = -1;
    connections[MOMROOM][EAST] = HALLWAY;
    
    // connection for bathroom 
    connections[BATHROOM][NORTH] = -1;
    connetions[BATHROOM][SOUTH] = -1;
    connections[BATHROOM][WEST] = HALLWAY;
    connections[BATHROOM][EAST] = -1; 
    return 0;
 
}
