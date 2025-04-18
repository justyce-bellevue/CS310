//******************************************************************* 
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: Vowel Remover
//
// Approach: Loop through the string with a while loop looking
// at each character. If the character is a vowel erase it.
// Then return the string.
//******************************************************************* 

#include <iostream> // Needed to output text
#include <string> // Needed to use strings

using namespace std; // Used to access the standard name space to avoid using std::

string removeVowels(string string1) // Make function of type string to return string
{
    int i = 0; // Declare i for iteration  
    while (i < string1.length())
    {
        switch (string1[i]) // Get character at index i
        {
            case 'a': // Check if character is a vowel
                string1.erase(i,1); // Remove character if it is a vowel
                break;
            case 'A':
                string1.erase(i,1);
                break;
            case 'e':
                string1.erase(i,1);
                break;
            case 'E':
                string1.erase(i,1);
                break;
            case 'i':
                string1.erase(i,1);
                break;
            case 'I':
                string1.erase(i,1);
                break;
            case 'o':
                string1.erase(i,1);
                break;
            case 'O':
                string1.erase(i,1);
                break;
            case 'u':
                string1.erase(i,1);
                break;
            case 'U':
                string1.erase(i,1);
            default: // If character is not a vowel
                i++; // Increase I only if character is not a vowel to avoid skipping characters since index shifts with removal
        }
    }

    return string1; // Return string without vowels
}

int main()
{
    string userString; // Declare string

    cout << "Enter a string: ";
    getline (cin, userString); // Getline used to capture whole string since cin only can take in single words

    int stringLength = userString.length(); // Store string length for error checking


    if (stringLength == 0) // Check for empty string
    {
        cout << "You did not enter a string. Please rerun the program";
        return 1; // End with error
    }

    userString = removeVowels(userString);

    if (userString.length() == stringLength) // Check if original and processed strings are the same by comparing length
    {
        cout << "There was no vowels in original string:" << endl;
        cout << userString << endl;
        return 0;
    } else { // Return string with vowels removed
        cout << "Here is the string with no vowels:" << endl;
        cout << userString;
        return 0;
    }

}
