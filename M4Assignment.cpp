#include <iostream>
using namespace std;

int main() {
    int firstDish, additionalTime, totalTime;

    cout << "Enter the time, in minutes, to prepare the first dish: ";
    cin >> firstDish;
    cout << "Enter the additional time each dish will take to make: ";
    cin >> additionalTime;
    cout << "Enter the total time available for cooking: ";
    cin >> totalTime;

    int dishes = 0;
    int timeSpent = 0;

    while (true) {
        int dishTime = firstDish + additionalTime * dishes;
        if (timeSpent + dishTime > totalTime) {
            break;
        }
        timeSpent += dishTime;
        dishes++;
    }

    cout << "Bianca can prepare " << dishes << " dishes." << endl;

    return 0;
}
