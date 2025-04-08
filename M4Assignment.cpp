#include <iostream>

using namespace std;

int main() {

    int firstDishTime;
    int additionalTimePerDish;
    int totalPrepareTime;

    cout << "How many minutes does it take to cook the first dish? ";
    cin >> firstDishTime;

    cout << "How many additional minutes will it take to cook the next dish? ";
    cin >> additionalTimePerDish;

    cout << "How long, in minutes, do you have to prepare the dishes? ";
    cin >> totalPrepareTime;

    int currentCookTime = 0;
    int dishesCooked = 0;
    while (currentCookTime < totalPrepareTime){
        if (dishesCooked == 0) {
            currentCookTime = firstDishTime;
            dishesCooked += 1;
        } else if (currentCookTime + additionalTimePerDish * dishesCooked < totalPrepareTime){
            currentCookTime += additionalTimePerDish * dishesCooked;
            dishesCooked += 1;
        } else {
            break;
        }
    }
    cout << "You can cook " << dishesCooked << " in " << totalPrepareTime << " minutes." << endl;

    return 0;
}
