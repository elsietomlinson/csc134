/* elsie tomlisnon
m6t1
11/10/2025
 meow meow
 buckshot roulette? idk what that is, never played it. 
 */
#include <iostream>
using namespace std; 

// function declaration 
void method1(); 
void method2();



int main() {
// call functions
 method1(); 
 method2();
    return 0;
}

/// now we write out fucntions 
void method1() {
    // started 
    cout << "Enter each Pokemon found per day." << endl; 
    cout << "Day 0 = Monday, Day 4 = Friday." << endl;
    
    const int SIZE = 5; 
    int count = 0; 
    double poke_avg = 0;
    int poke_today; // current amount of pokemon
    int poke_total = 0; // add up / average
    while (count < SIZE) {
        cout << "Day " << count << ": ";
        cin >> poke_today; 
        poke_total += poke_today; 
    
        count++; // move to next day
    }
cout << "Total = " << poke_total << endl; 
poke_avg = poke_total / SIZE;
cout << "Average = " << poke_avg << endl; 
}

void method2() {
    // started
   const int SIZE = 5; 
   string days[SIZE] = {"M" , "T" , "W" , "TH" , "F"}; // initialized
   int pokemon[SIZE];
   double poke_avg = 0.0; 
   int poke_total = 0; 

   for (int i=0; i < SIZE; i++) {
    cout << "# on  " << days[i] << ": " << endl;
    cin >> pokemon[i];
   }
   for (int i=0; i < SIZE; i++) {
    cout << "Day \t Pokemon" << endl; 
    cout << days[i] << "\t" << pokemon[i] << endl; 
    // find the total 
    poke_total += pokemon[i];
   }
   
   // [romt pit om a table]
   poke_avg = (double) poke_total / SIZE;
   cout << "Total = " << poke_total << endl; 
   cout << "Average = " << poke_avg << endl; 

}