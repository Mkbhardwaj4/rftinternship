#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    
    string accountNumber;
    string holderName;
    double balance;
    const double MIN_BALANCE = 500.0; 

public:
    
    BankAccount(string accNum, string name, double initialDeposit) {
        accountNumber = accNum;
        holderName = name;
        
        if (initialDeposit >= MIN_BALANCE) {
            balance = initialDeposit;
            cout << "\nAccount created successfully for " << holderName << endl;
        } else {
            balance = MIN_BALANCE;
            cout << "\nInitial deposit was low. Set to minimum balance: " << MIN_BALANCE << endl;
        }
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }


    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (balance - amount < MIN_BALANCE) {
            
            cout << "Transaction Denied! Minimum balance of $" << MIN_BALANCE << " must be maintained." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << fixed << setprecision(2) << amount << endl;
        }
    }

    
    void displayBalance() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    string accNum, name;
    double initialAmt;

    cout << "Welcome to the Bank Account Simulator" << endl;
    cout << "Enter Account Number: ";
    getline(cin, accNum);
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Deposit (Min $500): ";
    cin >> initialAmt;

    
    BankAccount myAccount(accNum, name, initialAmt);

    int choice;
    double amount;

    
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nSelect Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.displayBalance();
                break;
            case 4:
                cout << "Exiting. Thank you for using this bank!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}