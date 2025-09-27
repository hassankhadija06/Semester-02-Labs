#include <iostream>
//#include<stdexcept>
using namespace std;
//Defining functions outside the main

// Function for Task 1: Division by zero handling
void task1_division() {
    cout<<"\n=== TASK 1: Division by Zero Handling ==="<<endl;
    
    double numerator, denominator;
    
    // Getting the value for numerator
    cout<<"Enter numerator: ";
    cin>>numerator;
    
    // Getting the value for denominator with validation
    while(true){
        cout<<"Enter denominator: ";
        cin>>denominator;
        
        if(denominator == 0) {
            cout<<"Error: Denominator cannot be zero! Please enter a non-zero value."<<endl;
        } else {
            break; // Valid input, exit loop
        }
    }
    
    double result = numerator / denominator;
    cout<<"Result: "<<numerator<<" / "<<denominator<<" = "<<result<<endl;
}

// Function for Task 2: Array index handling
void task2_array() {
    cout<<"\n=== TASK 2: Array Index Handling ==="<<endl;
    
    int arr[4] = {0}; // Initializing array of size 4 with zeros
    
    // Displaying current array
    cout<< "Current array: ";
    for (int i = 0; i < 4; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int index, value;
    
    // Getting the index they want to store the value at with validation
    while(true){
        cout<<"Enter index (0-3): ";
        cin>>index;
        
        if(index < 0 || index >= 4) {
            cout<<"Error: Index must be between 0 and 3! Please try again."<<endl;
        } else {
            break; // Valid input, exit loop
        }
    }
    
    // Getting the value they want to store at that index
    cout << "Enter value to store: ";
    cin >> value;
    
    // Storing the value entered
    arr[index] = value;
    
    cout << "Value stored successfully!" << endl;
    cout << "Updated array: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    
    cout << "C++ Exception Handling Lab Tasks" << endl;
    cout << "=================================" << endl;
    
    while (true) {
        cout<<"\nChoose an operation:"<<endl;
        cout<<"1. Division by Zero Handling"<<endl;
        cout<<"2. Array Index Handling"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice (1-3): ";
        
        cin>>choice;
        
        switch(choice) {
            case 1:
                task1_division();
                break;
            case 2:
                task2_array();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
                // Clear input buffer in case of invalid input
                cin.clear();
                cin.ignore(1000, '\n');
        }
    }
    
    return 0;
}