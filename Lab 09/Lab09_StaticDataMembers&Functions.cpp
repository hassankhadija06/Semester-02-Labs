#include <iostream>
using namespace std;

class Student {
private:
    string name;
    // Static data member - shared by all objects
    static int count;

public:
    Student(string n) {
        name = n;
        count++;  // Increment count when object is created
    }
    
    // Static function to access static member
    static void print() {
        cout << "Total objects created: " << count << endl;
    }
};

// Static member definition (required)
int Student::count = 0;

int main() {
    cout << "=== Static Data Member Demo ===" << endl;
    
    // Create objects and show count increases
    Student s1("Ali");
    cout << "After s1 - ";
    Student::print();
    
    Student s2("Ahmed");
    cout << "After s2 - ";
    Student::print();
    
    Student s3("Sara");
    cout << "After s3 - ";
    Student::print();
    
    // Demonstrate static member is shared
    cout << "\n=== Static Function Demo ===" << endl;
    cout << "Calling static function without object: ";
    Student::print();
    
    return 0;
}