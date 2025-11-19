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

int main() {
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
 
}
