#include <iostream>
#include <cmath>
using namespace std;

class Coordinates
{
private:
    int x;
    int y;
public:
    Coordinates(int input_1, int input_2) //Constructor
    {
        x = input_1;
        y = input_2;
    }
    //Get methods
    int getX(){ return x; }
    int getY(){ return y; }

    //Other methods
    double distance(Coordinates p)
    {
        return sqrt(pow(p.x-x, 2) + pow(p.y-y, 2));
    }
    void translate(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    void scale(int factor, bool sign)
    {
        if (sign == true) {
            x *= factor;
            y *= factor;
        }
        else {
            x /= factor;
            y /= factor;
        }
    }
    string display()
    {
        return "X = " + to_string(x) + "\nY = " + to_string(y);
    }
};
/*
class Shape
{
private:
    Coordinates position;
    int sides;
public:
    Shape(int noOfSides, Coordinates shapeCoord){} //Constructor
    Coordinates getCoordinates(){}
    int getSides(){}
    void setCoordinates(Coordinates newcoord){}
    void translate(int dx, int dy){}
    void scale(int scale, bool sign){}
    double getArea(){}
    double getParameter(){}
    string display(){}

};

class Rectange : public Shape
{
private:
    int width;
    int length;
public:
    Rectangle(int w, int l){ width = w; length = l; } //Constructor
    double getArea()
    {
        return length * width;
    }
    double getParameter()
    {
        return (2 * length) + (2 * width)
    }
    void scale(int factor, bool sign){}
    string display()
    {
        return "Name: Rectangle \nLength: " + to_string(length) + "\nWidth: " + to_string(width) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Square : public Shape
{
private:
    int side;
public:
    Square(int s){ side = s; } //Constructor
    double getArea(){ return side * side; }
    double getParameter(){ return 4 * side; }
    void scale(int factor, bool sign){}
    string display()
    {
        return "Name: Square \nSide: " + to_string(side) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int r){ radius = r; } //Constructor
    double getArea(){ return 3.14 * radius * radius; }
    double getParameter(){ return 2 * 3.14 * radius; }
    void scale(int factor, bool sign){}
    string display()
    {
        return "Name: Circle \nRadius: " + to_string(radius) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Triangle : public Shape
{
private:

public:
    Triangle(){} //Constructor
    double getArea(){}
    double getParameter(){}
    void translate(int dx, int dy){}
    void scale(int factor, bool sign){}
    string display()
    {
        return "Name: Triangle \nLength of vertex 1: " + to_string() + "\nLength of vertex 2: " + to_string() + "\nLength of vertex 3: " + to_string() + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class ShapeList
{
private:
    string listofShapes;
public:
    void addShape(Shape s){}
    void translateShapes(int dx, int dy){}
    Shape getShape(int pos){}
    Shape removeShape(int pos)
    double area(int pos){}
    void scale(int factor, bool sign){}
    double parameter(int pos){}
    string display(){}
};

class ShapeManagement
{
public:
    void showMenu()
    {
        cout<<"1. Add a shape"<<endl;
        cout<<"2. Remove a shape by position"<<endl;
        cout<<"3. Get information about a shape by position"<<endl;
        cout<<"4. Area and perimeter of a shape by position"<<endl;
        cout<<"5. Display information of all the shapes"<<endl;
        cout<<"6. Translate all the shapes"<<endl;
        cout<<"7. Scale all the shapes"<<endl;
        cout<<"0. Quit program"<<endl;
    }
};
*/
int main()
{
    //Creating Objects
    Coordinates p1(2,5);
    Coordinates p2(2,7);

    cout<<p2.distance(p1);
    /*
    Shape shape;
    ShapeList shapelist;
    ShapeManagement shapeManagement;

    //Variables
    int option;

    shapeManagement.showMenu();
    cout<<"Enter your option."
    cin>>option;
    */
    return 0;
}
