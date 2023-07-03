#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Coordinates
{
public:
    int x;
    int y;

    Coordinates(int input_1 = 0, int input_2 = 0) //Constructor
    {
        x = input_1;
        y = input_2;
    }
    //Get methods
    int getX(){ return x; }
    int getY(){ return y; }

    bool operator==(const Coordinates& other) const {
        // Return true if the objects are equal, otherwise false
        return (x == other.x && y == other.y);
    }
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
        if (sign) {
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

class Shape
{
public:
    Coordinates point;
    int sides;
    Shape(Coordinates input_1, int input_2)  //Constructor
    {
        point = input_1;
        sides = input_2;
    }
    bool operator==(const Shape& other) const {
        // Implement your logic to compare Shape objects
        // Return true if the objects are equal, otherwise false
        return (point == other.point);
    }

    virtual void translate(int dx, int dy){};
    virtual void scale(int scale, bool sign){};
    virtual double getArea(){};
    virtual double getParameter(){};
    virtual string display(){};

};

class Rectangle : public Shape
{
public:
    int width;
    int length;
    Rectangle(int w, int l, Coordinates p):Shape(p, 4){ width = w; length = l; } //Constructor
    double getArea()
    {
        return length * width;
    }
    double getParameter()
    {
        return (2 * length) + (2 * width);
    }
    void scale(int factor, bool sign)
    {
        if (sign)
        {
            width *= factor;
            length *= factor;
        }
        else
        {
            width /= factor;
            length /= factor;
        }
    }
    string display()
    {
        return "Name: Rectangle \nLength: " + to_string(length) + "\nWidth: " + to_string(width) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Square : public Shape
{
public:
    int side;
    Square(int s, Coordinates p):Shape(p, 4){ side = s; } //Constructor
    double getArea(){ return side * side; }
    double getParameter(){ return 4 * side; }
    void scale(int factor, bool sign)
    {
        if (sign)
        {
            side *= factor;
        }
        else
        {
            side /= factor;
        }
    }
    string display()
    {
        return "Name: Square \nSide: " + to_string(side) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Circle : public Shape
{
public:
    int radius;
    Circle(int r, Coordinates p):Shape(p, 0){ radius = r; } //Constructor
    double getArea(){ return 3.14 * radius * radius; }
    double getParameter(){ return 2 * 3.14 * radius; }
    void scale(int factor, bool sign)
    {
        if (sign)
        {
            radius *= factor;
        }
        else
        {
            radius /= factor;
        }
    }
    string display()
    {
        return "Name: Circle \nRadius: " + to_string(radius) + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class Triangle : public Shape
{
public:
    Coordinates p2, p3;
    Triangle(Coordinates input_1, Coordinates input_2, Coordinates input_3):Shape(input_1, 3)  //Constructor
    {
        p2 = input_2;
        p3 = input_3;
    }
    double getArea(){}
    double getParameter(){}
    void translate(int dx, int dy){}
    void scale(int factor, bool sign){}
    string display()
    {
        //return "Name: Triangle \nLength of vertex 1: " + to_string() + "\nLength of vertex 2: " + to_string() + "\nLength of vertex 3: " + to_string() + "\nArea: " + to_string(getArea()) + "\nParameter: " + to_string(getParameter());
    }
};

class ShapeList
{
public:
    vector<Shape*>listofShapes;

    void addShape(Shape s){
        listofShapes.push_back(&s);
        cout<<"Shape Successfully Added at "<< "("<<s.point.x<<","<<s.point.y<<")"<<endl;

    }


    void translateShapes(int dx, int dy){}
/*
    void getShape(int index){
        if (index >=0 && index<listofShapes.size()){
            cout<<listofShapes[index]->;
          }
          else {
            cout<<"Index Out of Range, Type again!";
          }

    }
*/

    void removeShape(int index) {
          if (index >=0 && index<listofShapes.size()){
            listofShapes.erase(listofShapes.begin() + index);
            cout<<"Successfully removed the shape!"<<endl;
          }
          else {
            cout<<"Index Out of Range, Type again!";
          }

        }

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
    /*
    //Creating Objects
    Coordinates p1(2,5);
    Coordinates p2(2,7);

    cout<<p2.distance(p1);

    //Creating the shapes
    Rectangle r1(10, 15, Coordinates(100, 20));
    Circle c1(25, Coordinates(80,100));
    Square s1(20, Coordinates(90,40));

    cout<<r1.display()<<endl;
    cout<<c1.display()<<endl;
    cout<<s1.display()<<endl;

    ShapeList shapeList;
    ShapeManagement shapeManagement;

    //Variables
    int option, x, y, coor[3][2], index;
    int width, length, side, radius;
    char shapeType;
    shapeManagement.showMenu();

    do{
    cout<<"Enter your option: ";
    cin>>option;
    switch (option) {
case 1 :
    do{
        cout<<"\nWhat shape do you want to add?\nType 'r' for rectangle, 's' for square, 'c' for circle, 't' for triangle. 'p' to stop adding shapes. \nYour answer: ";
    cin>>shapeType;

    if (shapeType == 'r' || shapeType == 's' || shapeType == 'c' || shapeType == 't' || shapeType == 'p'){
        if (shapeType == 't'){
        for (int i=1; i<=3; ++i){
        cout<<"Enter x coordinate for vertex "<<i<<": ";
        cin>>coor[i][0];
        cout<<"Enter y coordinate for vertex "<<i<<": ";
        cin>>coor[i][1];
        }
        Coordinates p1(coor[0][0], coor[0][1]);
        Coordinates p2(coor[1][0], coor[1][1]);
        Coordinates p3(coor[2][0], coor[2][1]);

        shapeList.addShape(Triangle(p1, p2, p3));
        break;
    }
    else if (shapeType == 'r' || shapeType == 's' || shapeType == 'c') {

        cout<<"Enter x coordinate: ";
        cin>>x;
        cout<<"Enter y coordinate: ";
        cin>>y;


    }
    else if (shapeType == 'p'){

    }
    else {
        cout<<"Invalid Shape Type! Try again!"<<endl;
    }

    switch (shapeType){

    case 'r':
{
    Coordinates p(x, y);
    cout<<"Enter the width of the rectangle: ";
        cin>>width;
        cout<<"Enter the length of the rectangle: ";
        cin>>length;
        shapeList.addShape(Rectangle(width, length, p));

        break;
}


    case 's':

       {Coordinates p(x, y);
        cout<<"Enter the side length of the square: ";
        cin>>side;

        shapeList.addShape(Square(side, p));
        break;
       }

    case 'c':

        {Coordinates p(x, y);
        cout<<"Enter the radius length of the circle: ";
        cin>>radius;

        shapeList.addShape(Circle(radius, p));
        break;
        }

     case 't':

        {
        break;

        }

    case 'p':
        break;

    default:
       {
        cout<<"Invalid Shape! Type the letter again!"<<endl;
        break;
       }
        }

    }
    else {
        cout<<"Invalid Shape! Try again!"<<endl;
    }
    } while (shapeType != 'p');

    break;

case 2 :
    {

    cout<<"Enter the index number to remove: ";
    cin>>index;
    shapeList.removeShape(index);
    break;
    }

case 3 :
   {

    cout<<"Enter the index number to get information: ";
    cin>>index;
    shapeList.getShape(index);

    break;
   }

case 4 :
    break;

case 5 :
    break;

case 6 :
    break;

case 7 :
    break;

case 0 :
    break;

default:
    break;

    }



    } while (option != 0);


    vector<Shape*> listofShapes;
    listofShapes.push_back(new Circle(10, Coordinates(1,2)));
   listofShapes.push_back(new Square(20, Coordinates(2,5)));
    cout<<listofShapes[0];
    */

    int pi = 3.21151415;
    cout<<round(pi, 1);




    return 0;
}
