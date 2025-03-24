#include <iostream>
#include <cmath>  // For M_PI in Circle area calculation

using namespace std;


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

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }
    delete[] matrix;  
}

class Shape {
public:
    virtual double area() const = 0;  
};


class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

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
    
    int rows = 3, cols = 4;
    int** matrix = createMatrix(rows, cols);

    cout << "Dynamically Allocated Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    deleteMatrix(matrix, rows);  

   
    Shape* rect = new Rectangle(5.0, 4.0);
    Shape* circ = new Circle(3.0);

    cout << "\nRectangle Area: " << rect->area() << endl;
    cout << "Circle Area: " << circ->area() << endl;

   
    delete rect;
    delete circ;

    return 0;
}
