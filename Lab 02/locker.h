#include<iostream>
using namespace std;
class Locker{
	public:
		Locker(){       //Constructor
			cout<<"Locker allocated to customer"<<endl;
		}
		~Locker(){      //Destructor
			cout<<"Locker returned by customer"<<endl;
		}
};