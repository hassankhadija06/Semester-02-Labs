#include <iostream>
#include "BankAccount.h"
#include "Person.h"
#include "Student.h"
#include "Shape.h"
#include "Rectangle.h"
using namespace std;
int main() {
    int choice;
	                                                 // Displaying menu options
    cout << "======== WELCOME TO THE OOP DEMO PROGRAM ========\n";
    cout << "Please choose from the following options:\n";
    cout << "1. Simulate use of Deep Copy (BankAccount)\n";
    cout << "2. Simulate Single Inheritance (Student -> Person)\n";
    cout << "3. Simulate Constructor in Inheritance (Rectangle -> Shape)\n";
    cout << "--------------------------------------------------\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cout << "==================================================\n";

    switch (choice) {
        case 1: {
            // Demonstrating Deep Copy with BankAccount
            cout << "\n[Deep Copy Simulation - BankAccount]\n";
            BankAccount b1(700.8);
            cout << "Initial b1: ";
            b1.displayBalance();

            BankAccount b2 = b1; // Deep copy
            cout << "Copied b2 from b1: ";
            b2.displayBalance();

            b2.setBalance(45.6); // Changing b2 should not affect b1
            cout << "\nAfter modifying b2's balance:\n";
            cout << "b1: ";
            b1.displayBalance();
            cout << "b2: ";
            b2.displayBalance();
            break;
        }
        case 2: {
            // Demonstrating Single Inheritance
            cout << "\n[Single Inheritance Simulation - Student -> Person]\n";
            Student s;
            s.setStudent("Khadija", 20, 9);
            s.showStudent();
            break;
        }
        case 3: {
            // Demonstrating Constructor in Inheritance
            cout << "\n[Constructor Inheritance Simulation - Rectangle -> Shape]\n";
            Rectangle r;
            break;
        }
        default:
            // Handling invalid input
            cout << "Invalid input! Please run the program again with a valid choice.\n";
            break;
    }

    cout << "\n=========== PROGRAM ENDED ===========\n";
    return 0;
}
