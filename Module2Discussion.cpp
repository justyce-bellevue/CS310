#include <iostream>

using namespace std;

int main() 
{
    int age;
    char initial;
    
    cout << "Enter your age: "
    cin >> age;
    cout << "Enter the first letter of your last name: ";
    cin << initial;
    
    cout << "You are " << age << " years old and your last name starts with " << initial << endl;
    
    return 0;
}
