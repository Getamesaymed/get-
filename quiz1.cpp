#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;
    double gpa;

public:
   
    void setName(string n) { name = n; }
    void setID(int i) { id = i; }
    void setGPA(double g) { gpa = g; }

   
    void printInfo() {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    
    int arr[15] = {0};  
    arr[0] = 10;        
    arr[14] = 150;      

    
    Student student;
    string name;
    int id;
    double gpa;

    cout << "\nEnter student's name: ";
    getline(cin, name);
    cout << "Enter student's ID: ";
    cin >> id;
    cout << "Enter student's GPA: ";
    cin >> gpa;

    student.setName(name);
    student.setID(id);
    student.setGPA(gpa);

    student.printInfo();

    return 0;
}
