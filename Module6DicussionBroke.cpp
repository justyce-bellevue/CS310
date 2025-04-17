#include <iostream>

using namespace std; //Avoid have to use std::

enum Months {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec};

int main ()
{
    Months birthMonth = March;

    cout << "My month I was born was " << birthMonth << endl;

    return 0
  
}