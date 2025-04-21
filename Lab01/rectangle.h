#include<iostream>
using namespace std;
class Rectangle{
	public:
		//data members
	int length;
	int width;
	   //member functions declared inside the class
	void setdimensions();
	int area();
	int perimeter();   
	
};
      //member functions defined outside the class
void Rectangle::setdimensions(){
	cout<<"Enter length of rectangle: ";
	cin>>length;
	cout<<"Enter width of rectangle: ";
	cin>>width;
}
int Rectangle::area(){
	return (length*width);
}
int Rectangle::perimeter(){
	return 2*length+2*width;
	
}