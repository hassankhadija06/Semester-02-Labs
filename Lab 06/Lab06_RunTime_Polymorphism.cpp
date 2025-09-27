#include<iostream>
using namespace std;
class Shape{
	public:
		virtual double area(){
			cout<<"Calculating area"<<endl;
		    return 0;
		}
};
class Circle: public Shape{
	double radius;
	public:
		Circle(double r){
			this-> radius=r;
		}
		double area() override{
			cout<<"Area of Circle: "<<3.14*(radius*radius)<<endl;
		}
};
class Rectangle: public Shape{
	int length, width;
	public:
		Rectangle(int l, int w){
			this->length=l;
			this->width=w;
			
		}
		double area() override{
			cout<<"Area of Rectangle: "<<length*width<<endl;
		}
};
int main(){
	int choice;
	cout<<"____Demonstrating Run Time Polymorphism____"<<endl;
	cout<<"What do you want to do?"<<endl;
	cout<<"1. Calculate area of circle"<<endl;
	cout<<"2. Calculate area of rectangle"<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice){
		case 1:{
			
		
			cout<<"Circle selected"<<endl;
				Shape* shape;
	            Circle c(2.3);
	            shape=&c;
	            shape->area();
	            break;}
	    case 2:{
		    cout<<"Rectangle selected"<<endl;
		       Shape* shape;
		       Rectangle r(2,4);
		       shape=&r;
		       shape->area();      
			   break;}
		default:
		cout<<"Incorrect choice!"<<endl;	     
	}
}
////1.Function Overriding w/o Virtual Inheritance
//class Animal{             
//	public:
//		void makeSound(){
//			cout<<"Animal sound"<<endl;
//		}
//		
//};
//class Dog: public Animal{
//	public:
//		void makeSound(){
//			cout<<"Dog barks"<<endl;
//		}
//};
////2. Function Overriding with Virtual Inheritance
//class Animal{             
//	public:
//		virtual void makeSound(){
//			cout<<"Animal sound"<<endl;
//		}
//		
//};
//class Dog: public Animal{
//	public:
//		void makeSound() override {
//			cout<<"Dog barks"<<endl;
//		}
//};
//int main(){
//	Animal *a= new Dog;
//	a->makeSound();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//// Base class with virtual function
//class Animal {
//public:
//    virtual void makeSound() const {
//        cout << "Animal sound" << endl;
//    }
//    
//    virtual ~Animal() {} // Virtual destructor
//};
//
//// Derived classes
//class Dog : public Animal {
//public:
//    void makeSound() const override {
//        cout << "Dog barks: Woof! Woof!" << endl;
//    }
//};
//
//class Cat : public Animal {
//public:
//    void makeSound() const override {
//        cout << "Cat meows: Meow! Meow!" << endl;
//    }
//};
//
//// Base class WITHOUT virtual function
//class AnimalNonVirtual {
//public:
//    void makeSound() const {
//        cout << "Animal sound (non-virtual)" << endl;
//    }
//};
//
//class DogNonVirtual : public AnimalNonVirtual {
//public:
//    void makeSound() const {
//        cout << "Dog barks (non-virtual)" << endl;
//    }
//};
//
//int main() {
//    cout << "=== RUNTIME POLYMORPHISM DEMO ===\n\n";
//    
//    // With virtual functions (runtime polymorphism)
//    cout << "WITH VIRTUAL FUNCTIONS:\n";
//    Animal* animal1 = new Dog();
//    Animal* animal2 = new Cat();
//    
//    animal1->makeSound(); // Calls Dog's method
//    animal2->makeSound(); // Calls Cat's method
//    
//    delete animal1;
//    delete animal2;
//    
//    cout << "\nWITHOUT VIRTUAL FUNCTIONS:\n";
//    // Without virtual functions (compile-time binding)
//    AnimalNonVirtual* animal3 = new DogNonVirtual();
//    animal3->makeSound(); // Calls Animal's method (WRONG!)
//    
//    delete animal3;
//    
//    return 0;
//}