#include<iostream>
using namespace std;
class Student{
	//data members
	public:
	string name;
	int rollNumber;
	float marks;
	//member functions declared and defined inside the class
	void get_data(){
		cout<<"_________Getting Information_________"<<endl;
		cout<<"Enter name of student: ";
		cin>>name;
		cout<<"Enter roll number: ";
		cin>>rollNumber;
		cout<<"Enter marks: ";
		cin>>marks;
		cout<<endl;
	}
	void display_data(){
		cout<<"_________Displaying Information_________"<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Roll Number: "<<rollNumber<<endl;
		cout<<"Marks: "<<marks<<endl;
	}
};