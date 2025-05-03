#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;
public:
                                               // Parameterized Constructor
    BankAccount(string n, string h, double b) {
        if (n.empty()) {
            cout << "Account Number was empty! Setting it as UNKNOWN.\n";
            accountNumber = "UNKNOWN";
        } else {
            accountNumber = n;
        }

        if (h.empty()) {
            cout << "Account Holder Name was empty! Setting it as UNKNOWN.\n";
            accountHolder = "UNKNOWN";
        } else {
            accountHolder = h;
        }

        if (b < 0) {
            cout << "Balance was negative! Setting balance to $0.\n";
            balance = 0.0;
        } else {
            balance = b;
        }
    }

    void showAccountDetails() {
        cout << "\n=======BANK ACCOUNT DETAILS=======\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};
