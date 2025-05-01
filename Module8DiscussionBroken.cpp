//*********************************************************************
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: M8 Broken Code
//*********************************************************************
#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int studentID;

    Student(std::string n, int id) : name(n), studentID(id) {}

    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << studentID << std::endl;
    }
};

class Course {
public:
    std::string courseName;
    int courseNumber;

    Course(std::string cName, int cNum) : courseName(cName), courseNumber(cNum) {}

    void printCourseInfo() {
        std::cout << "Course: " << courseName << std::endl;
        std::cout << "Number: " courseNumber << std::endl;
    }
};

int main() {
    Student student1 = Student("Justyce", 1);
    Course course1 = Course("Programming with C++", 310);

    student1.displayInfo;
    course1.printCourseInfo();

    return 0;
}