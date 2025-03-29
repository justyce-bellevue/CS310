#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    // Declare variables
    const double OPTION_1_ADVANCE = 5000.0;
    const double OPTION_1_PUBLISH = 20000.0;
    const double OPTION_2_ROYALTY_RATE = 0.125;
    const double OPTION_3_ROYALTY_RATE_1 = 0.10;
    const double OPTION_3_ROYALTY_RATE_2 = 0.14;
    const int OPTION_3_LIMIT = 4000;

    double netPrice;
    int estimatedCopies;

    // Collect user input
    cout << "Enter the net price per copy sold: $";
    cin >> netPrice;
    cout << "Enter the estimated number of copies sold: ";
    cin >> estimatedCopies;

    // Calculate 3 different options
    double royalties1 = OPTION_1_ADVANCE + OPTION_1_PUBLISH;
    
    double royalties2 = netPrice * estimatedCopies * OPTION_2_ROYALTY_RATE;

    double royalties3;
    if (estimatedCopies <= OPTION_3_LIMIT) {
        royalties3 = netPrice * estimatedCopies * OPTION_3_ROYALTY_RATE_1;
    } else {
        royalties3 = netPrice * OPTION_3_LIMIT * OPTION_3_ROYALTY_RATE_1;
        royalties3 += (netPrice * (estimatedCopies - OPTION_3_LIMIT) * OPTION_3_ROYALTY_RATE_2);
    }

    // Output 3 options
    cout << fixed << setprecision(2);
    cout << "\nRoyalties for Option 1: $" << royalties1 << endl;
    cout << "Royalties for Option 2: $" << royalties2 << endl;
    cout << "Royalties for Option 3: $" << royalties3 << endl;

    // Determine the best option
    int bestOption;
    if (royalties1 >= royalties2 && royalties1 >= royalties3) {
        bestOption = 1;
    } else if (royalties2 >= royalties1 && royalties2 >= royalties3) {
        bestOption = 2; 
    } else {
        bestOption = 3; 
    }

    // Output the best option
    switch (bestOption) {
        case 1:
            cout << "\nThe best option is Option 1." << endl;
            break;
        case 2:
            cout << "\nThe best option is Option 2." << endl;
            break;
        case 3:
            cout << "\nThe best option is Option 3." << endl;
            break;
        default:
            cout << "\nError: Invalid option." << endl;
    }

    return 0;   
}
