#include<iostream>
using namespace std;
class Voter{
	public:
		//data members
	string name;
	int age;
	   //member functions declared inside the class
	void get_details();
	bool is_eligible();
	void display_message();
	
};
      //member functions defined outside the class
void Voter::get_details(){
	cout<<"Enter your name: ";
	cin>>name;
	cout<<"Enter age: ";
	cin>>age;
}
bool Voter::is_eligible(){
	if(age>18){
		return true;
	}
	else{
		return false;
	}
}
void Voter::display_message(){
	if(is_eligible()){
		cout<<"You are eligible to vote!"<<endl;
	}
	else{
		cout<<"You are not eligible to vote yet."<<endl;
	}
}