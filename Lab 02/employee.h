#include<iostream>
using namespace std;
class Employee{
	int id;
	string name;
	float salary;
	public:
	Employee(){         //Default Constrcutor 
		id = 0;
        name = "Not Assigned";
        salary = 0.0;
	}
		void displayDetails() {
        cout<<"=========================="<<endl;
        cout<<"|    EMPLOYEE DETAILS     |"<<endl;
        cout<<"=========================="<<endl;
        cout<<"| NAME:    :"<<name<<endl;
        cout<<"| ID:      :"<<id<<endl;
        cout<<"| SALARY   :"<<salary<<endl;
        cout<<"=========================="<<endl;
    }
	
};