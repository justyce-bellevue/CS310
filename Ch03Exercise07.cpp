#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
    // Declare variables
    double netBalance, payment, interestRate;
    int d1, d2;

    // Collect user input
    cout << "Enter net balance: ";
    cin >> netBalance;
    cout << "Enter payment made: ";
    cin >> payment;
    cout << "Enter interest rate, as a decimal like .07: ";
    cin >> interestRate;
    cout << "Enter days in billing cycle: ";
    cin >> d1;
    cout << "Enter the number of days the payment was made before due date: ";
    cin >> d2;

    double averageDailyBalance = (netBalance*d1 - payment*d2)/d1;
    double interest = averageDailyBalance * interestRate;

    // Format output
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    //Display results
    cout << "Interest on unpaid ballance $" << interest << endl;

    return 0;
}