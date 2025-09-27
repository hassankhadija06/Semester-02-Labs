#include <iostream>
#include <string>
using namespace std;

// Display class for handling output
class Display {
private:
    double lastResult;
    
public:
    Display() : lastResult(0) {}
    
    void showResult(double result, const string& operation = "") {
        lastResult = result;
        if (!operation.empty()) {
            cout << operation << " Result: " << result << endl;
        } else {
            cout << "Result: " << result << endl;
        }
    }
    
    double getLastResult() const {
        return lastResult;
    }
    
    void reset() {
        lastResult = 0;
    }
};

// Calculator class with composition
class Calculator {
private:
    Display display;
    
public:
    void add(double a, double b) {
        double result = a + b;
        display.showResult(result, "Addition");
    }
    
    void multiply(double a, double b) {
        double result = a * b;
        display.showResult(result, "Multiplication");
    }
    
    double getLastResult() const {
        return display.getLastResult();
    }
    
    void resetDisplay() {
        display.reset();
    }
};

// Student class using aggregation
class Student {
private:
    string name;
    
public:
    Student(const string& n) : name(n) {}
    
    void solveAddition(Calculator* calc, double a, double b) {
        cout << name << " is performing addition:" << endl;
        calc->add(a, b);
    }
    
    void solveMultiplication(Calculator* calc, double a, double b) {
        cout << name << " is performing multiplication:" << endl;
        calc->multiply(a, b);
    }
    
    void checkLastResult(Calculator* calc) {
        cout << name << " checked last result: " << calc->getLastResult() << endl;
    }
    
    const string& getName() const {
        return name;
    }
};

// Function to demonstrate composition
void demonstrateComposition() {
    cout << "\n=== DEMONSTRATING COMPOSITION ===\n";
    cout << "In composition, Calculator OWNS its Display.\n";
    cout << "The Display is created and destroyed with the Calculator.\n\n";
    
    Calculator calc;
    calc.add(5, 10);
    calc.multiply(3, 7);
    cout << "Final result from Calculator: " << calc.getLastResult() << endl;
}

// Function to demonstrate aggregation
void demonstrateAggregation() {
    cout << "\n=== DEMONSTRATING AGGREGATION ===\n";
    cout << "In aggregation, Students USE a Calculator but don't own it.\n";
    cout << "The Calculator can exist independently of the Students.\n\n";
    
    // Create a shared calculator
    Calculator sharedCalc;
    
    // Create students
    Student s1("Alice");
    Student s2("Bob");
    
    // Students use the shared calculator
    s1.solveAddition(&sharedCalc, 5, 7);
    s2.solveMultiplication(&sharedCalc, 3, 3);
    
    s1.checkLastResult(&sharedCalc);
    s2.checkLastResult(&sharedCalc);
}

// Function to get user choice
int getUserChoice() {
    int choice;
    cout << "============================================\n";
    cout << "    COMPOSITION vs AGGREGATION DEMONSTRATION\n";
    cout << "============================================\n";
    cout << "1. Demonstrate Composition (Calculator owns Display)\n";
    cout << "2. Demonstrate Aggregation (Students share Calculator)\n";
    cout << "3. Demonstrate Both\n";
    cout << "4. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    return choice;
}

// Main function
int main() {
    int choice;
    
    do {
        choice = getUserChoice();
        
        switch(choice) {
            case 1:
                demonstrateComposition();
                break;
            case 2:
                demonstrateAggregation();
                break;
            case 3:
                demonstrateComposition();
                demonstrateAggregation();
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