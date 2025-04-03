#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 5; i++)  // Error 1: Missing opening brace '{' for the loop
        cout << "Number: " << i << endl;
    
    return 0 // Error 2: Missing semicolon ';' at the end of return statement
}
