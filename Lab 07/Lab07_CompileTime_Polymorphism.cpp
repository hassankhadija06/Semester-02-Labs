#include <iostream>
using namespace std;

// Function Overloading Demonstration
class Calculator {
public:
    // Integer addition
    int add(int a, int b) {
        cout << "Adding integers: " << a << " + " << b << endl;
        return a + b;
    }
    
    // Double addition
    double add(double a, double b) {
        cout << "Adding doubles: " << a << " + " << b << endl;
        return a + b;
    }
    
    // Three integer addition
    int add(int a, int b, int c) {
        cout << "Adding three integers: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }
    
    // Mixed types
    double add(int a, double b) {
        cout << "Adding mixed types: " << a << " + " << b << endl;
        return a + b;
    }
};

// Operator Overloading Demonstration
class Complex {
public:
    double real, imag;
    
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(double real, double imag) : real(real), imag(imag) {}
    
    // Operator overloading for addition
    Complex operator + (const Complex& other) const {
        cout << "Adding complex numbers: (" << real << " + " << imag << "i) + (" 
             << other.real << " + " << other.imag << "i)" << endl;
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Operator overloading for subtraction
    Complex operator - (const Complex& other) const {
        cout << "Subtracting complex numbers: (" << real << " + " << imag << "i) - (" 
             << other.real << " + " << other.imag << "i)" << endl;
        return Complex(real - other.real, imag - other.imag);
    }
    
    // Display complex number
    void display() const {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
        cout << endl;
    }
};

// Function to demonstrate function overloading
void demonstrateFunctionOverloading() {
    cout << "\n=== FUNCTION OVERLOADING DEMONSTRATION ===\n\n";
    
    Calculator calc;
    
    cout << "Result: " << calc.add(5, 6) << endl << endl;
    cout << "Result: " << calc.add(5, 6, 4) << endl << endl;
    cout << "Result: " << calc.add(5.8, 6.9) << endl << endl;
    cout << "Result: " << calc.add(10, 3.14) << endl << endl;
}

// Function to demonstrate operator overloading
void demonstrateOperatorOverloading() {
    cout << "\n=== OPERATOR OVERLOADING DEMONSTRATION ===\n\n";
    
    Complex c1(2.3, 3.2);
    Complex c2(4.0, 4.5);
    Complex c3(1.5, -2.8);
    
    cout << "Complex number 1: ";
    c1.display();
    
    cout << "Complex number 2: ";
    c2.display();
    
    cout << "Complex number 3: ";
    c3.display();
    
    cout << "\nPerforming operations:\n";
    
    Complex result1 = c1 + c2;
    cout << "c1 + c2 = ";
    result1.display();
    
    Complex result2 = c1 - c3;
    cout << "c1 - c3 = ";
    result2.display();
    
    Complex result3 = c1 + c2 + c3;
    cout << "c1 + c2 + c3 = ";
    result3.display();
}

// Display menu
void displayMenu() {
    cout << "============================================\n";
    cout << "    COMPILE-TIME POLYMORPHISM DEMONSTRATION\n";
    cout << "============================================\n";
    cout << "1. Demonstrate Function Overloading\n";
    cout << "2. Demonstrate Operator Overloading\n";
    cout << "3. Demonstrate Both\n";
    cout << "4. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                demonstrateFunctionOverloading();
                break;
            case 2:
                demonstrateOperatorOverloading();
                break;
            case 3:
                demonstrateFunctionOverloading();
                demonstrateOperatorOverloading();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        if (choice != 4) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 4);
    
    return 0;
}