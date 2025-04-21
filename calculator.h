#include<iostream>
using namespace std;
class calculator{
	public:
		//data members
		float num1, num2;
		//member functions declared and defined inside the class
		float add(){
			return num1+num2;
		}
		
		float subtract(){
			return num1-num2;
		}
		
		float multiply(){
			return num1*num2;
		}
		
		float divide(){
			if(num2!=0){
				return num1/num2;
			}
			else{
				cout<<"Invalid!"<<endl;
				return 0;
			}
		}
		void input_numbers(){
   	cout<<"Enter a number: ";
   	cin>>num1;
   	cout<<"Enter another number: ";
   	cin>>num2;
   }
   
   void performOperation(int operation) {
            switch(operation) {
                case 1:
                    cout<<"Result: "<<add()<<endl;
                    break;
                case 2:
                    cout<<"Result: "<<subtract()<<endl;
                    break;
                case 3:
                    cout<<"Result: "<<multiply()<<endl;
                    break;
                case 4:
                    cout<<"Result: "<<divide()<<endl;
                    break;
                default:
                    cout<<"Invalid operation!"<<endl;
            }
        }
};
