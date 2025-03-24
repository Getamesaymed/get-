#include <iostream>
#include <cmath>  // For M_PI

using namespace std;

// Function to create a dynamically allocated matrix
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;  
        }
    }
    return matrix;
}

// Function to delete a dynamically allocated matrix
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Abstract base class
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Shape() {}  
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    // Task 1: Matrix Allocation and Display
    int rows = 3, cols = 4;
    int** matrix = createMatrix(rows, cols);
    
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    deleteMatrix(matrix, rows);  

    // Task 2: Polymorphism Demonstration
    Shape* shapes[2];
    shapes[0] = new Rectangle(5, 10);
    shapes[1] = new Circle(7);

    cout << "\nRectangle Area: " << shapes[0]->area() << endl;
    cout << "Circle Area: " << shapes[1]->area() << endl;

    delete shapes[0];
    delete shapes[1];

    return 0;
}
