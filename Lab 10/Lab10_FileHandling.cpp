#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Task 1: Create, Write, Read, and Append a File
void task1() {
    cout << "=== TASK 1: Create, Write, Read, and Append ===" << endl;
    
    // Create and write to file
    ofstream writeFile;
    writeFile.open("notes.txt");
    
    writeFile << "This is line 1" << endl;
    writeFile << "This is line 2" << endl;
    writeFile << "This is line 3" << endl;
    
    writeFile.close();
    cout << "File created and 3 lines written!" << endl;
    
    // Read the file
    ifstream readFile;
    readFile.open("notes.txt");
    
    cout << "\nReading file contents:" << endl;
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
    
    // Append to file
    ofstream appendFile;
    appendFile.open("notes.txt", ios::app);
    
    appendFile << "Name: Student Name" << endl;
    appendFile << "Roll No: 12345" << endl;
    
    appendFile.close();
    cout << "\nName and roll number appended!" << endl;
    
    // Read again to show appended content
    readFile.open("notes.txt");
    cout << "\nFinal file contents:" << endl;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
}

// Task 2: Count Number of Lines in a File
void task2() {
    cout << "\n=== TASK 2: Count Lines in File ===" << endl;
    
    ifstream file;
    file.open("notes.txt");
    
    if (!file) {
        cout << "File not found! Run Task 1 first." << endl;
        return;
    }
    
    string line;
    int count = 0;
    
    while (getline(file, line)) {
        count++;
    }
    file.close();
    
    cout << "Total lines in notes.txt: " << count << endl;
}

// Task 3: Copy Content from One File to Another
void task3() {
    cout << "\n=== TASK 3: Copy File Content ===" << endl;
    
    ifstream sourceFile;
    ofstream destFile;
    
    sourceFile.open("notes.txt");
    if (!sourceFile) {
        cout << "Source file not found! Run Task 1 first." << endl;
        return;
    }
    
    destFile.open("copy_notes.txt");
    
    string line;
    int copied = 0;
    
    while (getline(sourceFile, line)) {
        destFile << line << endl;
        copied++;
    }
    
    sourceFile.close();
    destFile.close();
    
    cout << "Copied " << copied << " lines to copy_notes.txt" << endl;
    
    // Show copied content
    ifstream showFile;
    showFile.open("copy_notes.txt");
    
    cout << "\nCopied file content:" << endl;
    while (getline(showFile, line)) {
        cout << line << endl;
    }
    showFile.close();
}

// Task 4: Write Student Details and Read Them
void task4() {
    cout << "\n=== TASK 4: Student Details ===" << endl;
    
    // Write student details
    ofstream writeFile;
    writeFile.open("students.txt");
    
    writeFile << "Ali, Roll No: 101" << endl;
    writeFile << "Ahmed, Roll No: 102" << endl;
    writeFile << "Sara, Roll No: 103" << endl;
    
    writeFile.close();
    cout << "Student details written to students.txt" << endl;
    
    // Read student details
    ifstream readFile;
    readFile.open("students.txt");
    
    cout << "\nStudent Details:" << endl;
    cout << "----------------" << endl;
    
    string line;
    int studentNumber = 1;
    
    while (getline(readFile, line)) {
        cout << studentNumber << ". " << line << endl;
        studentNumber++;
    }
    readFile.close();
}

int main() {
    int choice;
    
    cout << "FILE HANDLING PROGRAM" << endl;
    cout << "=====================" << endl;
    
    while (true) {
        cout << "\nChoose task:" << endl;
        cout << "1. Create, Write, Read, Append" << endl;
        cout << "2. Count Lines in File" << endl;
        cout << "3. Copy File Content" << endl;
        cout << "4. Student Details" << endl;
        cout << "5. Run All Tasks" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task1();
                task2();
                task3();
                task4();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    
    return 0;
}