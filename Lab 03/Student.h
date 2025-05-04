#include<iostream>
using namespace std;
class Student: protected Person{
	private:
		int rollNumber;
		public:
			void setStudent(string n, int a, int r){
				setPerson( n, a);
				while(r<0){
					cout<<"Roll number cannot be negative. Try again."<<endl;
				}
				rollNumber=r;
			}
			void showStudent(){
				showPerson();
				cout<<"Roll number: "<<rollNumber<<endl;
			}
};