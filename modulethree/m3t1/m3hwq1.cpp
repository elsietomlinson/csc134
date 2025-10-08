// elsie tomlinson
//csc134
// tiergold m3hw
// 10/08/2025

#include <iostream> 
using namespace std; 

int main () {

cout << "Question One: " << endl;

// my variables
string answer; // so i can ask user yes or no
cout << "Hi, I'm a basic chit chatter. Do you want to be my friend?"<< endl; 
cout << "Yes or No." << endl;
cin >> answer; 
cout << endl; 
// conditions 
if (answer == "yes" || answer == "Yes") {
    cout << "Yay! I would like to be your friend too!" << endl; 

}
else if ( answer == "no" || answer == "No") {
    cout << "Oh, ok. Guess we'll just sit here." << endl;
}
else {
    cout << "Don't make me read gibberish!" << endl; 
}

// good byeeee
cout << endl;
cout << "Thanks for chilling with me!!" << endl;



    return 0;
}