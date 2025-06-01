//*********************************************************************
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: Exceptions
//
// Approach: Prompt for inches and feet then convert to centimeters
// while making sure input is correct.
//*********************************************************************

#include <iostream> // For input and output
#include <string> // For strings

using namespace std; // avoid using std::

// Create exception classes
class negativeNumber{};

class nonNumber{};


int main() {
    try{
        // Declare variables
        string inchesString, feetString;
        const float IN_TO_CM = 2.54;

        cout << "Enter the feet: ";
        cin >> feetString;
        for (char c : feetString){ // Loop through each character
            if (!isdigit(c)){ // Check for non-digits
                throw nonNumber(); //Throw exception
            }
        }
        int feet = stoi(feetString); // Cast string to int
        if (feet < 0){ // Check for negative number
            throw negativeNumber()  ; 
        }

        cout << "Enter the inches: ";
        cin >> inchesString;
        for(char c : inchesString){
            if (!isdigit(c)){
                throw nonNumber();
            }
        }
        int inches = stoi(inchesString);
        if (inches < 0){
            throw negativeNumber();
        }

        float centimeters = ((feet * 12) + inches) * IN_TO_CM; //Convert to cm

        cout << feet << " feet and " << inches << " inches is " << centimeters << " centimeters";

    }
    catch(nonNumber){
        cout << "Must enter a number." << endl;
    }
    catch(negativeNumber){
        cout << "Must enter a positive number." << endl;
    }

    return 0;
}
