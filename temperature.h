#include<iostream>
using namespace std;
class temperature{
	public:
		//data members
	int tempc,tempf;
	
	    //member functions
	void getTemperature(){
		cout<<"Enter temperature in Celcius: ";
		cin>>tempc;
	}
	void convertToFahrenheit(){
		tempf=(tempc*9/5)+32;
	}
	
    void displayBothTemperatures() {
        cout<<fixed<<setprecision(2);
        cout<<"\nTemperature in Celsius: "<<tempc<<"C"<<endl;
        cout<<"Temperature in Fahrenheit: "<<tempf<<"F"<<endl;
    }
    
    void temperatureMenu() {
        int choice;
        do {
            cout << "\n=== Temperature Converter ===" << endl;
            cout << "1. Enter new temperature" << endl;
            cout << "2. Convert to Fahrenheit" << endl;
            cout << "3. Display temperatures" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice) {
                case 1: getTemperature(); break;
                case 2: convertToFahrenheit(); break;
                case 3: displayBothTemperatures(); break;
                case 0: break;
                default: cout << "Invalid choice!" << endl;
            }
        } while(choice != 0);
    }
};