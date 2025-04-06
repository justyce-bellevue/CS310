#include <iostream>
using namespace std;

int main() {
    int a, b, t;

    cout << "Enter the time, in minutes, to prepare the first dish: ";
    cin >> a;
    cout << "Enter the additional time each dish will take to make: ";
    cin >> b;
    cout << "Enter the total time available for cooking: ";
    cin >> t;

    int dishes = 0;
    int timeSpent = 0;

    while (true) {
        int dishTime = a + b * dishes;
        if (timeSpent + dishTime > t) {
            break;
        }
        timeSpent += dishTime;
        dishes++;
    }

    cout << "Bianca can prepare " << dishes << " dishes." << endl;

    return 0;
}