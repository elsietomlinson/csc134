/* elsie tomlinson
 m7t1 
 12/01/2025
 meow
 */
#include <iostream>
 using namespace std;
// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        // only valide ratings allowed
        if (r>=0 && r<=5) {
             rating = r;
        } 
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
  
};
 int main () {

  cout << "M7T1 - Restaurant Reviews" << endl;

    return 0;
 }