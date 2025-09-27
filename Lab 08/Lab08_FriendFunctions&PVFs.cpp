#include <iostream>
using namespace std;

// Forward declaration
class Circle;

class Rectangle {
private:
    double length, width;
    
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    double area() {
        return length * width;
    }
    
    // Friend function declaration
    friend double totalArea(Rectangle r, Circle c);
};

class Circle {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() {
        return 3.14159 * radius * radius;
    }
    
    // Friend function declaration
    friend double totalArea(Rectangle r, Circle c);
};

// Friend function definition - can access private members of both classes
double totalArea(Rectangle r, Circle c) {
    return r.length * r.width + 3.14159 * c.radius * c.radius;
}

// Task 2: Pure Virtual Functions
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

class RectangleShape : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

class CircleShape : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

int main() {
    cout << "=== Task 1: Friend Function ===" << endl;
    Rectangle rect(5, 3);
    Circle circ(2);
    
    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Circle area: " << circ.area() << endl;
    cout << "Total area (using friend function): " << totalArea(rect, circ) << endl;
    
    cout << "\n=== Task 2: Pure Virtual Function ===" << endl;
    Shape* shapes[2];
    shapes[0] = new RectangleShape();
    shapes[1] = new CircleShape();
    
    for(int i = 0; i < 2; i++) {
        shapes[i]->draw();
    }
    
    // Clean up
    delete shapes[0];
    delete shapes[1];
    
    return 0;
}