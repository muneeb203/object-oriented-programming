#include<iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double xcoord, double ycoord)
    {
        x = xcoord;
        y = ycoord;
    }

    double getterX() const
    {
        return x;
    }
    double getterY() const
    {
        return y;
    }
    
    void setterX(double X)
    {
        x = X;
    }
    void setterY(double Y)
    {
        y = Y;
    }
};


Point operator+(const Point& point1, const Point& point2) {
    double x = point1.getterX() + point2.getterX();
    double y = point1.getterY() + point2.getterY();
    return Point(x, y);
}

Point operator-(const Point& p1, const Point& p2) {
    double x = p1.getterX() - p2.getterX();
    double y = p1.getterY() - p2.getterY();
    return Point(x, y);
}

Point operator*(const Point& point, double scalar) {
    double x = point.getterX() * scalar;
    double y = point.getterY() * scalar;
    return Point(x, y);
}

Point operator/(const Point& point, double scalar) {
    double x = point.getterX() / scalar;
    double y = point.getterY() / scalar;
    return Point(x, y);
}

ostream& operator<<(ostream& output, const Point& pt)
{
    output << "(" << pt.getterX() << ", " << pt.getterY() << ")";
    return output;
}

istream& operator>>(istream& input, Point& pt)
{
    double a, b;
    input >> a >> b;
    pt.setterX(a);
    pt.setterY(b);
    return input;
}

int main()
{
    Point p1(2, 4);
    Point p2(1, 6);
    Point p3 = p1 + p2;
    Point p4 = p1 - p2;
    Point p5 = p1 * 4;
    Point p6 = p2 / 2;

    cout << "p1= " << p1 << endl;
    cout << "p2= " << p2 << endl;
    cout << "p3 = p1 + p2: " << p3 << endl;
    cout << "p4 = p1 - p2: " << p4 << endl;
    cout << "p5 = p1 * 2: " << p5 << endl;
    cout << "p6 = p2 / 2: " << p6 << endl;

    return 0;

}