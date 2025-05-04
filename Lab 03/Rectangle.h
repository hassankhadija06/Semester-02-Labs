#include<iostream>
using namespace std;
class Rectangle:public Shape{
	public:
		Rectangle(){
			cout<<"Rectangle constructor called (child constructor)"<<endl;
		}
};