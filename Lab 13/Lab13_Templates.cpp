#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Task 1: Calculator Template with Exception Handling
template<typename T>
class Calculator {
	private:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
    T multiply(T a, T b) { return a * b; }
    T divide(T a, T b) {
        if (b == 0) throw runtime_error("Error: Division by zero!");
        return a / b;
    }
public:
    void runCalculator() {
        cout << "\n=== Calculator Template ===" << endl;
        
        T a, b;
        char operation;
        
        cout << "Enter first number: ";
        cin >> a;
        
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        
        cout << "Enter second number: ";
        cin >> b;
        
        try {
            T result;
            switch (operation) {
                case '+':
                    result = add(a, b);
                    cout << "Result: " << a << " + " << b << " = " << result << endl;
                    break;
                case '-':
                    result = subtract(a, b);
                    cout << "Result: " << a << " - " << b << " = " << result << endl;
                    break;
                case '*':
                    result = multiply(a, b);
                    cout << "Result: " << a << " * " << b << " = " << result << endl;
                    break;
                case '/':
                    result = divide(a, b);
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                    break;
                default:
                    cout << "Error: Invalid operation!" << endl;
                    return;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
    

};

// Task 2: Logger Template
template<typename T>
class Logger {
private:
    string logName;
    
public:
    Logger(const string& name = "DefaultLogger") : logName(name) {}
    
    void runLogger() {
        cout << "\n=== Logger Template ===" << endl;
        int choice;
        
        while (true) {
            cout << "\nLogger Menu:\n1. Log message\n2. Log with timestamp\n3. Back to main menu\nEnter choice (1-3): ";
            cin >> choice;
            
            if (choice == 3) break;
            
            cin.ignore(); // Clear newline
            
            if (choice == 1 || choice == 2) {
                cout << "Enter message to log: ";
                T message;
                cin >> message;
                
                if (choice == 1) {
                    log(message);
                } else {
                    logWithTimestamp(message);
                }
            } else {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
    
    void log(const T& message) {
        cout << "[" << logName << "] " << message << endl;
    }
    
    void logWithTimestamp(const T& message) {
        cout << "[" << logName << "][TIMESTAMP] " << message << endl;
    }
};

// Function to demonstrate Calculator Template
void task1_calculator() {
    cout << "\n=== TASK 1: Calculator Template ===" << endl;
    
    int dataType;
    cout << "Choose data type:\n1. int\n2. double\n3. float\nEnter choice (1-3): ";
    cin >> dataType;
    
    if (dataType == 1) {
        Calculator<int> calc;
        calc.runCalculator();
    } else if (dataType == 2) {
        Calculator<double> calc;
        calc.runCalculator();
    } else if (dataType == 3) {
        Calculator<float> calc;
        calc.runCalculator();
    } else {
        cout << "Invalid choice! Using int by default." << endl;
        Calculator<int> calc;
        calc.runCalculator();
    }
}

// Function to demonstrate Logger Template
void task2_logger() {
    cout << "\n=== TASK 2: Logger Template ===" << endl;
    
    int dataType;
    cout << "Choose data type for logging:\n1. int\n2. double\n3. float\nEnter choice (1-3): ";
    cin >> dataType;
    
    cin.ignore(); // Clear newline
    
    string loggerName;
    cout << "Enter logger name: ";
    getline(cin, loggerName);
    
    if (dataType == 1) {
        Logger<int> logger(loggerName);
        logger.runLogger();
    } else if (dataType == 2) {
        Logger<double> logger(loggerName);
        logger.runLogger();
    } else if (dataType == 3) {
        Logger<float> logger(loggerName);
        logger.runLogger();
    } else {
        cout << "Invalid choice! Using int by default." << endl;
        Logger<int> logger(loggerName);
        logger.runLogger();
    }
}

int main() {
    int choice;
    
    cout << "C++ Templates Lab Tasks" << endl;
    cout << "=======================" << endl;
    
    while (true) {
        cout << "\nChoose a task:" << endl;
        cout << "1. Calculator Template" << endl;
        cout << "2. Logger Template" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        
        cin >> choice;
        
        switch (choice) {
            case 1:
                task1_calculator();
                break;
            case 2:
                task2_logger();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
        }
    }
}