#include <iostream>

class Shape {
private:
    int id;
public:
    Shape(int i) : id(i) {}

    void printId() {
        std::cout << "ID: " << id << std::endl;
    }
};

// Child class 1
class Circle : public Shape {
public:
    Circle(int i) : Shape(i) {}

    void show() {
        std::cout << "Circle ID: " << id << std::endl;
    }
};

// Child class 2
class Square : public Shape {
public:
    Square(int i) : Shape(i) {}

    void display() {
        printId(); // Correctly uses public base class method
    }
} 

int main() {
    Circle c(1);
    Square s(2);

    c.show();
    s.display();

    return 0;
}
