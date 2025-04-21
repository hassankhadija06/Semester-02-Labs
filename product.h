#include<iostream>
using namespace std;
class product{
	private:
		//private data members
		string name;
		double price;
		int quantity;
	public:
		//member functions
		
		//setters
        void setname(string n) {
        while(n.empty()) {
            cout << "Name cannot be empty! Please enter again: ";
            getline(cin, n);  // Using getline to allow spaces in names (not possible to write your full name just by using cin)
        }
        name = n;
    }
	    void setprice(double p) {
        while(p <= 0) {
            cout << "Price must be positive! Please enter again: ";
            cin >> p;
        }
        price = p;
    }
		 void setquantity(int q) {
        while(q < 0) {
            cout << "Quantity cannot be negative! Please enter again: ";
            cin >> q;
        }
        quantity = q;
    }
        //getters
		string getname(){
			return name;
		}
		double getprice(){
			return price;
		}
		int getquantity(){
			return quantity;
		}
		double get_total(){
			return price*quantity;
		}
};