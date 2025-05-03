#include<iostream>
using namespace std;
class Rectangle{
	float length;
	float width;
	public:
		Rectangle(){      //Default Constructor
			length=1.0;
			width=1.0;
		}
		Rectangle(float l, float w){    //Parameterized Constructor
			length=l;
			width=w;
		}
		Rectangle(float p){       
			length=p;
			width=length;
		}
		void showDetails(){         
			cout<<"========================"<<endl;
			cout<<"|    RECTANGLE DETAILS  "<<endl;
			cout<<"| Length: "<<length<<endl;
			cout<<"| Width: "<<width<<endl;
			cout<<"========================"<<endl;
		}
};