#include <iostream> // Used to print
#include <random> // Used to generate random numbers

using namespace std; // Avoid using std::

int main() {
    random_device ranSeed{}; // Used to generate different seed each run
    default_random_engine num{ ranSeed() };
    uniform_int_distribution<int> ranNum{10, 100}; // Generates random numbers 10 - 100

    int randomNumbers[25]; //Used to store random numbers if needed later

    for(int i = 0; i < 25; i++){
        randomNumbers[i] = ranNum(num); // Store number
        cout << randomNumbers[i] << endl; // Print generate number
    }

    return 0;
}