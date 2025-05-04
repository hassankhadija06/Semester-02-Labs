#include<iostream>
using namespace std;
//class BankAccount{
//	private:
//		double *balance;
//		public:
//			BankAccount(double amount){
//				balance = new double;
//				*balance=amount;
//			}
//			void displayBalance(){
//				cout<<"Balance: "<<*balance<<endl;
//			}
//			void setBalance(double amount){
//				*balance=amount;
//			}
//			~BankAccount(){
//				delete balance;
//				cout<<"Destructor called."<<endl;
//			}
//};
class BankAccount {
private:
    float* balance;
public:
    BankAccount(float b) {
        balance = new float(b);
    }
    BankAccount(const BankAccount& other) {
        balance = new float(*other.balance);  
        cout << "Deep copy constructor called.\n";
    }
    void setBalance(float b) {
        *balance = b;
    }
    void displayBalance() const {
        cout << "Balance: " << *balance << endl;
    }
    ~BankAccount() {
        delete balance;
        cout << "Destructor called.\n";
    }
};
