#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int ID;
    float GPA;

public:
    void setName(string studentName) { name = studentName; }
    void setID(int studentID) { ID = studentID; }
    void setGPA(float studentGPA) { GPA = studentGPA; }

    void printInfo() {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << "\nID: " << ID << "\nGPA: " << GPA << endl;
    }
};

int main() {
    int arr[15] = {0}; 
    arr[0] = 10;
    arr[14] = 150;

    Student student;
    string name;
    int id;
    float gpa;

    cout << "Enter student's name: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "Enter student ID: ";
    while (!(cin >> id)) {
        cout << "Invalid input! Enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter student GPA: ";
    while (!(cin >> gpa)) {
        cout << "Invalid input! Enter a number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    student.setName(name);
    student.setID(id);
    student.setGPA(gpa);
    student.printInfo();

    return 0;
}
