//*********************************************************************
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: Bank Account Management System
//
// Approach: Define a base class bankAccount and derive checkingAccount
// and savingsAccount classes from it. Implement operations for managing
// account details, deposits, withdrawals, interest, and service charges.
//*********************************************************************

#include <iostream> // Used to output text and get input
#include <string>   // Needed to use string data type (though not explicitly used for member vars here, good practice)
#include <iomanip>  // Needed for use of setw(), right, left, fixed, setprecision()

using namespace std; // Avoid using std:: prefix

class bankAccount {
public:
    // Constructors
    bankAccount(int accNum = 0, double bal = 0.0);
    // Member functions
    void setAccountNumber(int accNum);    
    int getAccountNumber() const;         
    double getBalance() const;             
    void deposit(double amount);            
    virtual void withdraw(double amount);   
    virtual void printAccountInformation() const; 

protected: 
    int accountNumber;    // Stores the customer's account number
    double acctBalance;       // Stores the current account balance
};


// Constructor for bankAccount
bankAccount::bankAccount(int accNum, double bal) {
    accountNumber = accNum;
    acctBalance = bal;
    if (bal < 0) { //
        cout << "Initial balance cannot be negative. Setting balance to 0.00." << endl;
        acctBalance= 0.0;
    }
}

// Sets the account number for the bank account
void bankAccount::setAccountNumber(int accNum) {
    accountNumber = accNum;
}

int bankAccount::getAccountNumber() const {
    return accountNumber;
} //

// Returns the current balance of the bank account
double bankAccount::getBalance() const {
    return acctBalance;
}

// Deposits a specified amount into the bank account
void bankAccount::deposit(double amount) {
    if (amount > 0) {
        acctBalance += amount;
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << acctBalance << endl;
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

// Withdraws a specified amount from the bank account
void bankAccount::withdraw(double amount) {
    if (amount > 0) {
        if (acctBalance >= amount) {
            acctBalance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << acctBalance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    } else {
        cout << "Withdrawal amount must be positive." << endl;
    }
}

// Prints the basic account information
void bankAccount::printAccountInformation() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << fixed << setprecision(2) << acctBalance << endl;
}

class checkingAccount : public bankAccount {
public:
    // Constructors
    checkingAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0, double minBal = 0.0, double servChg = 0.0);

    // Member functions
    void setInterestRate(double rate);     
    double getInterestRate() const;        
    void setMinimumBalance(double minBal); 
    double getMinimumBalance() const;       
    void setServiceCharge(double charge);   
    double getServiceCharge() const;       
    void postInterest();                
    bool isBelowMinimumBalance() const; 
    void writeCheck(double amount);        
    void withdraw(double amount) override;  
    void printAccountInformation() const override;

private:
    double interestRate;    // Interest rate like 2% is 0.02
    double minimumBalance;  // Minimum balance to avoid service charge
    double serviceCharge;   // Service charge if balance falls below minimum
};

// Constructor for checkingAccount
checkingAccount::checkingAccount(int accNum, double bal, double intRate, double minBal, double servChg): bankAccount(accNum, bal) { 
    interestRate = intRate;
    minimumBalance = minBal;
    serviceCharge = servChg;

    // Validate inputs for checking account specific members
    if (intRate < 0) {
        cout << "Interest rate cannot be negative. Setting to 0.0." << endl;
        interestRate = 0.0;
    }
    if (minBal < 0) {
        cout << "Minimum balance cannot be negative. Setting to 0.00." << endl;
        minimumBalance = 0.0;
    }
    if (servChg < 0) {
        cout << "Service charge cannot be negative. Setting to 0.00." << endl;
        serviceCharge = 0.0;
    }
}

// Sets the interest rate for the checking account
void checkingAccount::setInterestRate(double rate) {
    if (rate >= 0) {
        interestRate = rate;
    } else {
        cout << "Interest rate cannot be negative." << endl;
    }
}

// Returns the interest rate of the checking account
double checkingAccount::getInterestRate() const {
    return interestRate;
}

// Sets the minimum balance for the checking account
void checkingAccount::setMinimumBalance(double minBal) {
    if (minBal >= 0) {
        minimumBalance = minBal;
    } else {
        cout << "Minimum balance cannot be negative." << endl;
    }
}

// Returns the minimum balance of the checking account
double checkingAccount::getMinimumBalance() const {
    return minimumBalance;
}

// Sets the service charge for the checking account
void checkingAccount::setServiceCharge(double charge) {
    if (charge >= 0) {
        serviceCharge = charge;
    } else {
        cout << "Service charge cannot be negative." << endl;
    }
}

// Returns the service charge of the checking account
double checkingAccount::getServiceCharge() const {
    return serviceCharge;
}

// Posts interest to the checking account balance
void checkingAccount::postInterest() {
    double interestEarned = acctBalance * interestRate; 
    acctBalance += interestEarned;
    cout << "Interest posted: $" << fixed << setprecision(2) << interestEarned
              << ". New balance: $" << fixed << setprecision(2) << acctBalance << endl;
}

// Checks if the current balance is below the minimum required balance
bool checkingAccount::isBelowMinimumBalance() const {
    return acctBalance < minimumBalance;
}

// Processes a check withdrawal from the checking account
void checkingAccount::writeCheck(double amount) {
    cout << "Attempting to write a check for: $" << fixed << setprecision(2) << amount << endl;
    withdraw(amount); 
}

void checkingAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Amount must be positive." << endl;
        return;
    }

    if (acctBalance >= amount) {
        acctBalance -= amount;
        cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << acctBalance << endl;
        if (isBelowMinimumBalance()) {
            cout << "Balance is below minimum. Service charge of $" << fixed << setprecision(2) << serviceCharge << " applied." << endl;
            if (acctBalance >= serviceCharge) {
                acctBalance -= serviceCharge;
                cout << "New balance after service charge: $" << fixed << setprecision(2) << acctBalance << endl;
            } else {
                cout << "Insufficient funds to cover full service charge. Balance may be depleted." << endl;
                acctBalance = 0;
            }
        }
    } else {
        cout << "Insufficient funds for withdrawal." << endl;
    }
}

// Prints checking account specific information
void checkingAccount::printAccountInformation() const {
    bankAccount::printAccountInformation();
    cout << "Account Type: Checking Account" << endl;
    cout << "Interest Rate: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
    cout << "Minimum Balance: $" << fixed << setprecision(2) << minimumBalance << endl;
    cout << "Service Charge: $" << fixed << setprecision(2) << serviceCharge << endl;
}

class savingsAccount : public bankAccount {
public:
    // Constructors
    savingsAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0);

    // Member functions
    void setInterestRate(double rate);      
    double getInterestRate() const;        
    void postInterest();                    
    void withdraw(double amount) override;  
    void printAccountInformation() const override;

private:
    double interestRate;
};

// Constructor for savingsAccount
savingsAccount::savingsAccount(int accNum, double bal, double intRate): bankAccount(accNum, bal) 
{ 
    interestRate = intRate;
    if (intRate < 0) {
        cout << "Interest rate cannot be negative. Setting to 0.0." << endl;
        interestRate = 0.0;
    }
}

// Sets the interest rate for the savings account
void savingsAccount::setInterestRate(double rate) {
    if (rate >= 0) {
        interestRate = rate;
    } else {
        cout << "Interest rate cannot be negative." << endl;
    }
}

// Returns the interest rate of the savings account
double savingsAccount::getInterestRate() const {
    return interestRate;
}

void savingsAccount::postInterest() {
    double interestEarned = acctBalance * interestRate; 
   acctBalance += interestEarned;
    cout << "Interest posted: $" << fixed << setprecision(2) << interestEarned
              << ". New balance: $" << fixed << setprecision(2) << acctBalance << endl;
}

// Withdraws an amount from the savings account
void savingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Withdrawal amount must be positive." << endl;
        return;
    }
    if (acctBalance >= amount) {
        acctBalance -= amount;
        cout << "Withdrawal from savings successful. New balance: $" << fixed << setprecision(2) << acctBalance << endl;
    } else {
        cout << "Insufficient funds for withdrawal from savings." << endl;
    }
}

// Prints savings account specific information
void savingsAccount::printAccountInformation() const {
    bankAccount::printAccountInformation();
    cout << "Account Type: Savings Account" << endl;
    cout << "Interest Rate: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
}

int main() {
    // Set output to 2 decimal places for currency consistently
    cout << fixed << setprecision(2);

    checkingAccount chkAcc1(12345, 1500.00, 0.015, 500.00, 25.00);
    chkAcc1.printAccountInformation();
    cout << endl; 

    // Test deposit
    cout << "Depositing $200.00 to checking account..." << endl;
    chkAcc1.deposit(200.00);
    chkAcc1.printAccountInformation();
    cout << endl;

    // Test writing a check (successful)
    cout << "Writing a check for $300.00 from checking account..." << endl;
    chkAcc1.writeCheck(300.00);
    chkAcc1.printAccountInformation();
    cout << endl;

    // Test writing a check that brings balance below minimum
    cout << "Writing a check for $1000.00 from checking account (balance will drop below minimum)..." << endl;
    chkAcc1.writeCheck(1000.00); // Balance was 1700 (1500+200), then 1400 (1700-300). Now 1400-1000 = 400. Min bal 500. Service charge 25. New bal 375.
    chkAcc1.printAccountInformation();
    cout << endl;

    // Test posting interest
    cout << "Posting interest to checking account..." << endl;
    chkAcc1.postInterest(); // Interest on 375.00
    chkAcc1.printAccountInformation();
    cout << endl;

    // Test withdrawal
    cout << "Attempting to withdraw $500.00 from checking account..." << endl;
    chkAcc1.withdraw(500.00);
    chkAcc1.printAccountInformation();
    cout << endl;
    checkingAccount chkAcc2(67890, 100.00, 0.01, 200.00, 15.00);
    chkAcc2.printAccountInformation();
    cout << endl;

    cout << "Withdrawing $50.00 from checking account 2 (will trigger service charge)..." << endl;
    chkAcc2.withdraw(50.00); 
    chkAcc2.printAccountInformation();
    cout << endl;


    savingsAccount savAcc1(98765, 2000.00, 0.025);
    savAcc1.printAccountInformation();
    cout << endl;

    // Test deposit into savings
    cout << "Depositing $500.00 to savings account..." << endl;
    savAcc1.deposit(500.00);
    savAcc1.printAccountInformation();
    cout << endl;

    // Test withdrawal from savings
    cout << "Withdrawing $300.00 from savings account..." << endl;
    savAcc1.withdraw(300.00);
    savAcc1.printAccountInformation();
    cout << endl;

    // Test posting interest to savings
    cout << "Posting interest to savings account..." << endl;
    savAcc1.postInterest(); // Interest on 2200 (2000+500-300)
    savAcc1.printAccountInformation();
    cout << endl;

    // Test withdrawal (insufficient funds)
    cout << "Attempting to withdraw $2500.00 from savings account..." << endl;
    savAcc1.withdraw(2500.00);
    savAcc1.printAccountInformation();
    cout << endl;

    return 0;
}