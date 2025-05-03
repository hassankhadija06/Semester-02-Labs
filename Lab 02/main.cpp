#include<iostream>
#include"employee.h"
#include"bankAccount.h"
#include"rectangle.h"
#include"locker.h"
using namespace std;
int main(){
	int choice;
	cout<<"_______DISPLAYING MENU_______"<<endl;
	cout<<"Choose from the following options:"<<endl;
	cout<<"1. Employee "<<endl;
	cout<<"2. Bank account "<<endl;
	cout<<"3. Rectangle"<<endl;
	cout<<"4. Locker "<<endl;
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice){
		case 1:{
			Employee e;
           	e.displayDetails();
			break;
		}

        case 2:{
        	BankAccount b("PK0309800780100","",10000.23);
            b.showAccountDetails();
			break;
		}
        
        case 3:{
       	    Rectangle r;
          //Rectangle r(2.3f,5.6f);
          //Rectangle r(3.4f);
            r.showDetails();
			break;
		}
        	
        case 4:{
        	cout<<"Creating locker automatically in stack"<<endl;
       {
            Locker stacklocker;    //automatically constructor and destructor called when object is created
        }
        cout<<"Creating locker dynamically in heap"<<endl;
        Locker* heapLocker= new Locker();     //manually allocating and deleting memory on heap
        cout<<"Deleting locker manually"<<endl;
        delete heapLocker;
			break;
		}

        default:
        	cout<<"Invalid input!"<<endl;
        	break;
	}

}

