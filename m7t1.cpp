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
  void printInf() {
    // output for the restaurant
    cout << "Restaurant Name:" << endl;
    cout << "Rating;" << rating << " out of five stars." << endl; 

  }
};
 int main () {

  cout << "M7T1 - Restaurant Reviews" << endl;
// classes of the restaurants
  Restaurant breakfast =  Restaurant ("Taco Bell", 3.5); 
  Restaurant lunch     =  Restaurant("Jersey Mike's" , 4.5);
  Restaurant dinner    = Restaurant("Jason's Deli", 3.5);


// printing function 
  breakfast.printInf(); 
  lunch.printInf();
dinner.printInf();
  
  
  return 0;
 }