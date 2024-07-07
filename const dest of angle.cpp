

#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    // Constructors
    Point() {
        x = 0;
        y = 0;
    }

    Point(int xCord, int yCord) {
        x = xCord;
        y = yCord;
    }

    // Getter and Setter methods for x
    int getX() {
        return x;
    }

    void setX(int newX) {
        x = newX;
    }

    // Getter and Setter methods for y
    int getY() {
        return y;
    }

    void setY(int newY) {
        y = newY;
    }

    // Display method
    void display() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(5, 10);
    Point p2(3, 8);
    p1.display();
    p2.display();
    p1.setX(2);
    p1.setY(7);
    p2.setX(4);
    p2.setY(6);

    int sumX = p1.getX() + p2.getX();
    int sumY = p1.getY() + p2.getY();

    cout << "Sum of x coordinates: " << sumX << endl;
    cout << "Sum of y coordinates: " << sumY << endl;

    return 0;
}
