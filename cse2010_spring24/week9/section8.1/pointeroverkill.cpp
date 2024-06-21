#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;

public:
    Rectangle(int width, int height) {
        // Use 'this->' to refer to the member variables when the parameter names are the same.
        this->width = width;
        this->height = height;
    }

    int area() {
        // No need to use 'this->' here since there are no name conflicts, but it's still valid.
        return this->width * this->height;
    }

    void display() {
        cout << "Width: " << this->width << ", Height: " << this->height << ", Area: " << this->area() << endl;
    }
};

int main() {
    int width, height;

    cout << "Enter width of the rectangle: ";
    cin >> width;

    cout << "Enter height of the rectangle: ";
    cin >> height;

    Rectangle myRectangle(width, height);
    myRectangle.display();

    return 0;
}
