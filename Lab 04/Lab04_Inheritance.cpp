#include <iostream>
#include <string>
using namespace std;

// Task 1: Single Inheritance
class Person {
protected:
    string name;
    int age;
    
public:
    void setPersonInfo(string n, int a) {
        name = n;
        age = a;
    }
    
    void display_person_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    string student_id;
    
public:
    void setStudentInfo(string n, int a, string id) {
        setPersonInfo(n, a);
        student_id = id;
    }
    
    void display_student_info() {
        display_person_info();
        cout << "Student ID: " << student_id << endl;
    }
};

// Task 2: Multilevel Inheritance
class Employee : public Person {
protected:
    string employee_id;
    
public:
    void setEmployeeInfo(string n, int a, string id) {
        setPersonInfo(n, a);
        employee_id = id;
    }
    
    void display_employee() {
        display_person_info();
        cout << "Employee ID: " << employee_id << endl;
    }
};

class Manager : public Employee {
private:
    string department;
    
public:
    void setManagerInfo(string n, int a, string emp_id, string dept) {
        setEmployeeInfo(n, a, emp_id);
        department = dept;
    }
    
    void display_manager() {
        display_employee();
        cout << "Department: " << department << endl;
    }
};

// Task 3: Hierarchical Inheritance
class EmployeeBase {
protected:
    string name;
    double salary;
    
public:
    void setEmployeeBase(string n, double s) {
        name = n;
        salary = s;
    }
    
    void display_employee() {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Developer : public EmployeeBase {
private:
    string programming_language;
    
public:
    void setDeveloperInfo(string n, double s, string lang) {
        setEmployeeBase(n, s);
        programming_language = lang;
    }
    
    void display_developer() {
        display_employee();
        cout << "Programming Language: " << programming_language << endl;
    }
};

class Designer : public EmployeeBase {
private:
    string design_tool;
    
public:
    void setDesignerInfo(string n, double s, string tool) {
        setEmployeeBase(n, s);
        design_tool = tool;
    }
    
    void display_designer() {
        display_employee();
        cout << "Design Tool: " << design_tool << endl;
    }
};

// Task 4: Multiple Inheritance
class Printer {
public:
    void print_document() {
        cout << "Printing document..." << endl;
    }
};

class Scanner {
public:
    void scan_document() {
        cout << "Scanning document..." << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    void photocopy() {
        cout << "Photocopying process started:" << endl;
        scan_document();
        print_document();
    }
};

int main() {
    int choice;
    
    cout << "INHERITANCE DEMONSTRATION PROGRAM" << endl;
    cout << "=================================" << endl;
    
    while(true) {
        cout << "\nChoose inheritance type to demonstrate:" << endl;
        cout << "1. Single Inheritance (Person -> Student)" << endl;
        cout << "2. Multilevel Inheritance (Person -> Employee -> Manager)" << endl;
        cout << "3. Hierarchical Inheritance (Employee -> Developer/Designer)" << endl;
        cout << "4. Multiple Inheritance (Printer + Scanner -> Photocopier)" << endl;
        cout << "5. Demonstrate All" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer
        
        switch(choice) {
            case 1: {
                cout << "\n=== SINGLE INHERITANCE ===" << endl;
                Student s;
                string name, id;
                int age;
                
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter student ID: ";
                getline(cin, id);
                
                s.setStudentInfo(name, age, id);
                cout << "\nStudent Information:" << endl;
                s.display_student_info();
                break;
            }
            
            case 2: {
                cout << "\n=== MULTILEVEL INHERITANCE ===" << endl;
                Manager m;
                string name, emp_id, dept;
                int age;
                
                cout << "Enter manager name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter employee ID: ";
                getline(cin, emp_id);
                cout << "Enter department: ";
                getline(cin, dept);
                
                m.setManagerInfo(name, age, emp_id, dept);
                cout << "\nManager Information:" << endl;
                m.display_manager();
                break;
            }
            
            case 3: {
                cout << "\n=== HIERARCHICAL INHERITANCE ===" << endl;
                Developer dev;
                Designer des;
                
                // Developer info
                cout << "--- Developer ---" << endl;
                dev.setDeveloperInfo("Ali", 50000, "C++");
                dev.display_developer();
                
                cout << "\n--- Designer ---" << endl;
                des.setDesignerInfo("Sara", 45000, "Photoshop");
                des.display_designer();
                break;
            }
            
            case 4: {
                cout << "\n=== MULTIPLE INHERITANCE ===" << endl;
                Photocopier pc;
                
                cout << "Testing individual functions:" << endl;
                pc.print_document();
                pc.scan_document();
                
                cout << "\nTesting photocopy function:" << endl;
                pc.photocopy();
                break;
            }
            
            case 5: {
                cout << "\n=== DEMONSTRATING ALL INHERITANCE TYPES ===" << endl;
                
                // Single
                cout << "\n1. SINGLE INHERITANCE:" << endl;
                Student s1;
                s1.setStudentInfo("John", 20, "S123");
                s1.display_student_info();
                
                // Multilevel
                cout << "\n2. MULTILEVEL INHERITANCE:" << endl;
                Manager m1;
                m1.setManagerInfo("Ahmed", 35, "E456", "IT");
                m1.display_manager();
                
                // Hierarchical
                cout << "\n3. HIERARCHICAL INHERITANCE:" << endl;
                Developer d1;
                Designer ds1;
                d1.setDeveloperInfo("Maria", 60000, "Python");
                ds1.setDesignerInfo("Tom", 55000, "Figma");
                d1.display_developer();
                cout << "---" << endl;
                ds1.display_designer();
                
                // Multiple
                cout << "\n4. MULTIPLE INHERITANCE:" << endl;
                Photocopier pc1;
                pc1.photocopy();
                break;
            }
            
            case 0:
                cout << "Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    
    return 0;
}