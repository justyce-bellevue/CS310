#include <iostream>


int main() {

    int firstDishTime;
    int additionalTimePerDish;
    int totalPrepareTime;

    std::cout << "How many minutes does it take to cook the first dish? ";
    std::cin >> firstDishTime;

    std::cout << "How many additional minutes will it take to cook the next dish? ";
    std::cin >> additionalTimePerDish;

    std::cout << "How long, in minutes, do you have to prepare the dishes? ";
    std::cin >> totalPrepareTime;

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
    std::cout << "You can cook " << dishesCooked << " dishes in " << totalPrepareTime << " minutes." << endl;

    return 0;
}
