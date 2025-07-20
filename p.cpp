#include <iostream>
#include <map>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account() : accountNumber(0), holderName(""), balance(0.0) {} 

    Account(int accNo, string name, double initialDeposit)
        : accountNumber(accNo), holderName(name), balance(initialDeposit) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs. " << amount << " successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn Rs. " << amount << " successfully.\n";
        }
    }

    void display() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name   : " << holderName << endl;
        cout << "Balance       : Rs. " << balance << endl;
    }

    int getAccountNumber() const { return accountNumber; }
};

class Bank {
private:
    map<int, Account> accounts;

public:
    void createAccount(int accNo, string name, double deposit) {
        if (accounts.count(accNo)) {
            cout << "Account number already exists.\n";
            return;
        }
        accounts[accNo] = Account(accNo, name, deposit);
        cout << "Account created successfully!\n";
    }

    void depositMoney(int accNo, double amount) {
        if (accounts.count(accNo)) {
            accounts[accNo].deposit(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void withdrawMoney(int accNo, double amount) {
        if (accounts.count(accNo)) {
            accounts[accNo].withdraw(amount);
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayAccount(int accNo) {
        if (accounts.count(accNo)) {
            accounts[accNo].display();
        } else {
            cout << "Account not found.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice, accNo;
    string name;
    double amount;

    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Account\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                 cin >> accNo;
                cin.ignore();
                cout << "Enter Holder Name: "; 
                getline(cin, name);
                cout << "Enter Initial Deposit: ";
                 cin >> amount;
                bank.createAccount(accNo, name, amount);
                break;
            case 2:
                cout << "Enter Account Number: "; 
                cin >> accNo;
                cout << "Enter Deposit Amount: "; 
                cin >> amount;
                bank.depositMoney(accNo, amount);
                break;
            case 3:
                cout << "Enter Account Number: ";
                 cin >> accNo;
                cout << "Enter Withdrawal Amount: ";
                 cin >> amount;
                bank.withdrawMoney(accNo, amount);
                break;
            case 4:
                cout << "Enter Account Number: ";
                 cin >> accNo;
                bank.displayAccount(accNo);
                break;
            case 5:
                cout << "Thank you for using the Bank Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
