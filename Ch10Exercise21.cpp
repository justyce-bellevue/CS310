//*********************************************************************
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: Bank account class
//
// Approach: Construct a bank account class with relevant functions
// like deposit and withdraw. Then show example uses cases.
//*********************************************************************


#include <iostream> // Used to output text
#include <string> // Needed to use string data type
#include <iomanip> // Needed for use of setw(), right, left, fixed, setprecision

// Avoid using std::
using namespace std;

class bankAccount {
private:
    // Data members for the bank account
    string accountHolder;
    int accountNumber;
    string accountType; // "checking" or "saving"
    double balance;
    double interestRate; // Stored as a decimal (e.g., 0.05 for 5%)

    // Used to generate account numbers
    static int nextAccountAvail;

public:
    // Constructor with default arguments
    bankAccount(string name = "", string type = "", double initial_balance = 0.0, double rate = 0.0);

    // Member function to deposit funds into the account.
    void deposit(double amount);

    // Member function to withdraw funds from the account.
    void withdraw(double amount);

    // Member function to display all details of the bank account.
    void displayAccountDetails();

    // Function to retrieve the account number.
    int getAccountNumber();

    // Function to retrieve the current balance.
    double getBalance();

    // Function to apply interest to the account balance.
    void applyInterest();

};

// Start of account numbers
int bankAccount::nextAccountAvail = 1;

// Implementation of the constructor
bankAccount::bankAccount(string name, string type, double initial_balance, double rate):
    accountHolder(name), accountType(type), balance(initial_balance), interestRate(rate) {
        accountNumber = nextAccountAvail++;
        cout << "Account created for " << accountHolder
             << " with Account Number: " << accountNumber << endl;
}

// Implementation of the deposit function
void bankAccount::deposit(double amount) { 
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << fixed << setprecision(2) << amount
                 << ". New balance for Account " << accountNumber << ": $"
                 << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
}

// Implementation of the withdraw function
void bankAccount::withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << fixed << setprecision(2) << amount << ". New balance for Account " << accountNumber << ": $" << fixed << setprecision(2) << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds for withdrawal from Account " << accountNumber << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

// Implementation of the displayAccountDetails function
void bankAccount::displayAccountDetails(){
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "Interest Rate: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
        cout << "-----------------------" << endl;
    }


// Return account number of account
int bankAccount::getAccountNumber() {
    return accountNumber;
}

// Return ballance of an account
double bankAccount::getBalance() {
    return balance;
}

// Implementation of the applyInterest function
void bankAccount::applyInterest() {
        if (accountType == "saving") {
            double interest_earned = balance * interestRate;
            balance += interest_earned;
            cout << "Interest of $" << fixed << setprecision(2) << interest_earned << " applied to Account " << accountNumber << ". New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Interest not applicable to " << accountType << " account (Account " << accountNumber << ")." << endl;
        }
}


int main() {
    bankAccount customers[10];

    // Keep track of how many accounts are actually in the array
    int customerAmmt = 0;

    // Add some sample customer accounts to the array.
    if (customerAmmt < 10) {
        customers[customerAmmt] = bankAccount("Phillip Boy", "saving", 1500.75, 0.015); // 1.5% interest rate, Phil is my dog
        customerAmmt++;
    }
    if (customerAmmt < 10) {
        customers[customerAmmt] = bankAccount("Norman Dog", "checking", 500.00, 0.0); // 0% interest rate, Norm is my dog
        customerAmmt++;
    }
    if (customerAmmt < 10) {
        customers[customerAmmt] = bankAccount("Justyce Bonczynski", "saving", 2500.50, 0.02); // 2% interest rate
        customerAmmt++;
    }

    // Display details of all created accounts.
    cout << "\n--- Initial Account Details ---" << endl;
    for (int i = 0; i < customerAmmt; ++i) {
        customers[i].displayAccountDetails();
    }

    // Perform transactions
    cout << "\n--- Performing Transactions ---" << endl;

    // Account that is a checkings account
    int checkingAccount = 2; 
    // Loop through the actual number of customers.
    for (int i = 0; i < customerAmmt; ++i) {
        if (customers[i].getAccountNumber() == checkingAccount) {
            customers[i].deposit(200.00); // Deposit $200
            customers[i].withdraw(50.00);  // Withdraw $50
        }
    }

    // Example of a savings account interest
    int savingsAccount = 3;
     for (int i = 0; i < customerAmmt; ++i) {
        if (customers[i].getAccountNumber() == savingsAccount) {
            customers[i].applyInterest(); // Apply interest
        }
    }

    // Display the account details again after the transactions to show the updated balances.
    cout << "\n--- Account Details After Transactions ---" << endl;
    // Loop through the actual number of customers.
    for (int i = 0; i < customerAmmt; ++i) {
        customers[i].displayAccountDetails();
    }

    return 0;
}
