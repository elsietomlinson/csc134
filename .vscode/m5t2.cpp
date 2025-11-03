/*
elsie tomlinson
m5t2
11/03/2025
meow
*/
#include <iostream> 
using namespace std; 
// declare your funtions
int square(int num); 
void printanswerline(int num1, int num2);

//start main now

int main() {
    int num = 0;
    while (num < 10) {
        num++;
        int answer = square(num); 
        printanswerline(num, answer); 

    }
    return 0;
}
int square(int num) {
    int answer = num * num;
    return answer; 
}

void printanswerline (int num1, int num2) {
    cout << "The square of " << num1 << " is " << num2 << "." << endl;
}