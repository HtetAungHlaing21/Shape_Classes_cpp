#include <iostream>
using namespace std;

class Coordinates
{
private:
    int x;
    int y;
public:
    Coordinates(int x, int y){}  //Constructor
    int getX(){}
    int getY(){}
    double distance(Coordinates p){}
    void translate(int dx, int dy){}
    void scale(int factor, bool sign){}
    string display(){}
};

class Shape
{
private:
    Coordinates position;
    int sides;
public:
    Shape(int noOfSides, Coordinates &coord){} //Constructor
    Coordinates getCoordinates(){}
    int getSides(){}
    void setCoordinates(Coordinates &newcoord){}
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
    Rectangle(){} //Constructor
    double getArea(){}
    double getParameter(){}
    void scale(int factor, bool sign){}
    string display(){}
};

class Square : public Shape
{
private:
    int side;
public:
    Square(){} //Constructor
    double getArea(){}
    double getParameter(){}
    void scale(int factor, bool sign){}
    string display(){}
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(){} //Constructor
    double getArea(){}
    double getParameter(){}
    void scale(int factor, bool sign){}
    string display(){}
};

class Triangle : public Shape
{
private:
    int firstPoint[2];
    int secondPoint[2];
    int thirdPoint[2];
public:
    Triangle(){} //Constructor
    double getArea(){}
    double getParameter(){}
    void translate(int dx, int dy){}
    void scale(int factor, bool sign){}
    string display(){}
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

int main()
{
    //Creating Objects
    Coordinates coordinates;
    Shape shape;
    ShapeList shapelist;
    ShapeManagement shapeManagement;

    //Variables
    int option;

    shapeManagement.showMenu();
    cout<<"Enter your option."
    cin>>option;
    return 0;
}
