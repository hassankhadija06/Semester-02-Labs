#include<iostream>
using namespace std;
class Person{
	private:
		string name;
		int age;
		public:
		void setPerson(string n, int a){
		while(n==""){
			cout<<"Name cannot be empty. Try again."<<endl;
		}
		name=n;
		while(a<0){
			cout<<"Age cannot be negative. Try again."<<endl;
		}	
		age=a;
		}
		void showPerson(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};