#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FilePointerDemo {
private:
    string filename;

public:
    FilePointerDemo(string fname = "demo.txt") : filename(fname) {}

    // Task 1: Demonstrate tellp() - Get current write pointer position
    void demonstrateTellp() {
        cout << "\n=== TASK 1: Demonstrating tellp() ===" << endl;
        
        fstream out(filename, ios::out);
        if (!out) {
            cout << "Error creating file!" << endl;
            return;
        }

        cout << "Position of write pointer before writing: " << out.tellp() << endl;
        
        out << "A"; // Write a single character
        cout << "Position of write pointer after writing a single character: " << out.tellp() << endl;
        
        out.close();
        cout << "File '" << filename << "' created and written successfully!" << endl;
    }

    // Task 2: Demonstrate tellg() - Get current read pointer position
    void demonstrateTellg() {
        cout << "\n=== TASK 2: Demonstrating tellg() ===" << endl;
        
        fstream in(filename, ios::in);
        if (!in) {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        cout << "Position of read pointer before reading: " << in.tellg() << endl;
        
        char ch;
        in.get(ch); // Read a single character
        cout << "Character read: '" << ch << "'" << endl;
        cout << "Position of read pointer after reading a single character: " << in.tellg() << endl;
        
        in.close();
    }

    // Task 3: Demonstrate seekp() - Move write pointer
    void demonstrateSeekp() {
        cout << "\n=== TASK 3: Demonstrating seekp() ===" << endl;
        
        fstream file("student.txt", ios::in | ios::out | ios::trunc);
        if (!file) {
            cout << "Error creating student file!" << endl;
            return;
        }

        // Write student records
        file << "01,Awais_3.5 ";
        file << "02,Kashif_3.8 ";
        file << "03,Zahid_2.5 ";
        file << "04,Ahmed_4.0 ";
        
        cout << "Position of write pointer after writing 4 records: " << file.tellp() << endl;
        
        // Display current content
        file.seekg(0, ios::beg);
        string content;
        getline(file, content);
        cout << "Current file content: " << content << endl;
        
        // Move write pointer back to overwrite the last record
        file.seekp(-13, ios::cur); // Move 13 characters back from current position
        cout << "Position after seekp(-13, ios::cur): " << file.tellp() << endl;
        
        // Overwrite the last record
        file << "05,Madir_2.78";
        
        // Display modified content
        file.seekg(0, ios::beg);
        getline(file, content);
        cout << "Modified file content: " << content << endl;
        
        file.close();
    }

    // Task 4: Demonstrate seekg() - Move read pointer
    void demonstrateSeekg() {
        cout << "\n=== TASK 4: Demonstrating seekg() ===" << endl;
        
        fstream file("student.txt", ios::in);
        if (!file) {
            cout << "Error opening student file!" << endl;
            return;
        }

        cout << "Position of read pointer before seeking: " << file.tellg() << endl;
        
        // Move read pointer to position 10
        file.seekg(10, ios::beg);
        cout << "Position after seekg(10, ios::beg): " << file.tellg() << endl;
        
        // Read and display from position 10 onwards
        cout << "Reading from position 10:" << endl;
        char ch;
        while (file.get(ch)) {
            cout << "Character Read: '" << ch << "' | Position: " << file.tellg() << endl;
        }
        
        file.close();
    }

    // Bonus: Demonstrate all seek directions
    void demonstrateSeekDirections() {
        cout << "\n=== BONUS: Seek Directions Demonstration ===" << endl;
        
        fstream file("seek_demo.txt", ios::in | ios::out | ios::trunc);
        file << "0123456789ABCDEFGHIJ"; // 20 characters
        
        cout << "File content: 0123456789ABCDEFGHIJ" << endl;
        
        // ios::beg - from beginning
        file.seekg(5, ios::beg);
        cout << "seekg(5, ios::beg) -> Position: " << file.tellg() << endl;
        
        // ios::cur - from current position
        file.seekg(3, ios::cur);
        cout << "seekg(3, ios::cur) -> Position: " << file.tellg() << endl;
        
        // ios::end - from end
        file.seekg(-4, ios::end);
        cout << "seekg(-4, ios::end) -> Position: " << file.tellg() << endl;
        
        char buffer[10];
        file.read(buffer, 3);
        buffer[3] = '\0';
        cout << "Reading 3 characters from current position: " << buffer << endl;
        
        file.close();
    }

    // Menu function
    void runDemo() {
        int choice;
        
        cout << "=== FILE POINTER DEMONSTRATION PROGRAM ===" << endl;
        
        do {
            cout << "\nChoose a task to demonstrate:" << endl;
            cout << "1. tellp() - Get write pointer position" << endl;
            cout << "2. tellg() - Get read pointer position" << endl;
            cout << "3. seekp() - Move write pointer" << endl;
            cout << "4. seekg() - Move read pointer" << endl;
            cout << "5. All tasks in sequence" << endl;
            cout << "6. Seek directions demonstration" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    demonstrateTellp();
                    break;
                case 2:
                    demonstrateTellg();
                    break;
                case 3:
                    demonstrateSeekp();
                    break;
                case 4:
                    demonstrateSeekg();
                    break;
                case 5:
                    demonstrateTellp();
                    demonstrateTellg();
                    demonstrateSeekp();
                    demonstrateSeekg();
                    break;
                case 6:
                    demonstrateSeekDirections();
                    break;
                case 0:
                    cout << "Exiting program. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    FilePointerDemo demo;
    demo.runDemo();
    return 0;
}