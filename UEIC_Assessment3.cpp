#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Coordinates
{
public:
    int x, y;
    Coordinates(int input_1 = 0, int input_2 = 0)
    {
        x = input_1;
        y = input_2;
    }

    bool operator ==(const Coordinates& other) const
    {
        return (x == other.x && y == other.y);
    }

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
        if (sign)
        {
            x *= factor;
            y *= factor;
        }
        else
        {
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
    Coordinates center;
    int sides;
    Shape(Coordinates input_1, int input_2)
    {
        center = input_1;
        sides = input_2;
    }
    bool operator ==(const Shape& other) const
    {
        return (center == other.center);
    }
    void translate(int dx, int dy)
    {
        center.translate(dx, dy);
    };
    virtual void scale(int factor, bool sign) {};
    virtual double getArea() {};
    virtual double getParameter() {};
    virtual void display(string position) {};
};

class Rectangle : public Shape
{
public:
    int width;
    int length;
    double area, parameter;
    Rectangle(int w, int l, Coordinates p):Shape(p, 4)
    {
        width = w;
        length = l;
    }
    double getArea()
    {
        area = length * width;
        return area;
    }
    double getParameter()
    {
        parameter = (2 * length) + (2 * width);
        return parameter;
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
    void display(string position)
    {
        cout<<"Name: Rectangle"<<endl;
        cout<<"Position: "<< position <<endl;
        cout<<"Length: " << length << "\nWidth: " << width << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Square : public Shape
{
public:
    int side;
    double area, parameter;
    Square(int s, Coordinates p):Shape(p, 4)
    {
        side = s;
    }
    double getArea()
    {
        area = side * side;
        return area;
    }
    double getParameter()
    {
        parameter = 4 * side;
        return parameter;
    }
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
    void display(string position)
    {
        cout<<"Name: Square"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Side: " << side << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Circle : public Shape
{
public:
    int radius;
    double area, parameter;
    Circle(int r, Coordinates p):Shape(p, 0)
    {
        radius = r;
    }
    double getArea()
    {
        area = 3.14 * radius * radius;
        return area;
    }
    double getParameter()
    {
        parameter = 2 * 3.14 * radius;
        return parameter;
    }
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
    void display(string position)
    {
        cout<<"Name: Circle"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Radius: " << radius << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Triangle : public Shape
{
public:
    Coordinates p1, p2, p3;
    double a, b, c, s;
    double area, parameter;
    Triangle(Coordinates input_1, Coordinates input_2, Coordinates input_3, Coordinates input_4):Shape(input_4, 3)
    {
        p1 = input_1;
        p2 = input_2;
        p3 = input_3;
        a = p1.distance(p2);
        b = p2.distance(p3);
        c = p3.distance(p1);
    }
    double getArea()
    {
        s = (a + b + c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    double getParameter()
    {
        parameter = a + b + c;
        return parameter;
    }
    void translate(int dx, int dy)
    {
        p1.translate(dx, dy);
        p2.translate(dx, dy);
        p3.translate(dx, dy);
        center.x = (p1.x + p2.x + p3.x)/3;
        center.y = (p1.y + p2.y + p3.y)/3;
    }
    void scale(int factor, bool sign)
    {
        p1.scale(factor, sign);
        p2.scale(factor, sign);
        p3.scale(factor, sign);
        center.x = (p1.x + p2.x + p3.x)/3;
        center.y = (p1.y + p2.y + p3.y)/3;
        a = p1.distance(p2);
        b = p2.distance(p3);
        c = p3.distance(p1);
    }
    void display(string position)
    {
        cout<<"Name: Triangle"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Length of side 1: "<< a <<"\nLength of side 2: "<< b << "\nLength of side 3: "<<c<<endl;
        cout<<"Area: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class ShapeList
{
public:
    vector <Shape*> listofShapes;
    int shapeNum;
    float x,y, coor[3][2], center_x, center_y;
    int width, length, side, radius;
    char ans;
    bool deleted, found = false;
    void addShape()
    {
        do
        {
            cout<<"\nWhat shape do you want to add?\nType '1' for rectangle, '2' for square, '3' for circle, '4' for triangle. '0' to stop adding shapes. \nYour answer: ";
            cin>>shapeNum;
            if (shapeNum == 1 || shapeNum == 2 || shapeNum == 3 )
            {
                cout<<"Enter x coordinate of center: ";
                cin>>x;
                cout<<"Enter y coordinate of center: ";
                cin>>y;
                Coordinates center(x,y);
                switch (shapeNum)
                {
                case 1:
                {
                    do
                    {
                        cout<<"Enter the width of the rectangle: ";
                        cin>>width;
                        if (width<=0)
                        {
                            cout<<"Width must be greater than 0"<<endl;
                        }
                    }
                    while(width<=0);
                    do
                    {
                        cout<<"Enter the length of the rectangle: ";
                        cin>>length;
                        if (length<=0)
                        {
                            cout<<"Length must be greater than 0"<<endl;
                        }
                    }
                    while(length<=0);

                    listofShapes.push_back(new Rectangle(width, length, center));
                    cout<<"Shape Successfully Added!"<<endl;
                    break;
                }
                case 2:
                {
                    do
                    {
                        cout<<"Enter the side of the square: ";
                        cin>>side;
                        if (side<=0)
                        {
                            cout<<"Side must be greater than 0"<<endl;
                        }
                    }
                    while(side<=0);
                    listofShapes.push_back(new Square(side, center));
                    cout<<"Shape Successfully Added!"<<endl;
                    break;
                }
                case 3:
                {
                    do
                    {
                        cout<<"Enter the radius of the circle: ";
                        cin>>radius;
                        if (radius<=0)
                        {
                            cout<<"Radius must be greater than 0"<<endl;
                        }
                    }
                    while(radius<=0);
                    listofShapes.push_back(new Circle(radius, center));
                    cout<<"Shape Successfully Added!"<<endl;
                    break;
                }
                default:
                {
                    cout<<"Error"<<endl;
                    break;
                }

                }
            }

            else if (shapeNum == 4)
            {
                for (int i=1; i<=3; ++i)
                {
                    cout<<"Enter x coordinate for vertex "<<i<<": ";
                    cin>>coor[i-1][0];
                    cout<<"Enter y coordinate for vertex "<<i<<": ";
                    cin>>coor[i-1][1];
                }
                Coordinates p1(coor[0][0], coor[0][1]);
                Coordinates p2(coor[1][0], coor[1][1]);
                Coordinates p3(coor[2][0], coor[2][1]);
                center_x = (coor[0][0] + coor[1][0] + coor[2][0])/3;
                center_y = (coor[0][1] + coor[1][1] + coor[2][1])/3;
                Coordinates center(center_x, center_y);
                listofShapes.push_back(new Triangle(p1, p2, p3, center));
                cout<<"Shape Successfully Added!"<<endl;
                cout<<"The center of the triangle: "<<round(center_x)<<" , "<<round(center_y)<<endl;
            }

            else if (shapeNum == 0)
            {
                break;
            }

            else
            {
                cout<<"Invalid Number! Type the number again!"<<endl;
            }

        }
        while(shapeNum != 0);

    }
    void removeShape()
    {
        do
        {
            cout<<"Enter the x coordinate (center) of the shape: ";
            cin>>x;
            cout<<"Enter the y coordinate (center) of the shape: ";
            cin>>y;
            Coordinates center_f(x,y);
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if (center_f == (*pObj)->center)
                {
                    listofShapes.erase(pObj);
                    cout<<"Successfully Deleted!"<<endl;
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                cout << "There is no shape at this location!" << endl;
            }
            deleted = false;
            cout<<"Do you want to continue removing shapes? If yes, type 'y', if no, type 'n'. Your answer: ";
            cin>>ans;
        }
        while (ans != 'n');

    }
    void getShape()
    {
        do
        {
            cout<<"Enter the x coordinate (center) of the shape: ";
            cin>>x;
            cout<<"Enter the y coordinate (center) of the shape: ";
            cin>>y;
            Coordinates center_f(x,y);
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if (center_f == (*pObj)->center)
                {
                    string position = "(" + to_string((*pObj)->center.x) + ", " + to_string((*pObj)->center.y) + ")";
                    (*pObj)->display(position);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "There is no shape at this location!" << endl;
            }
            found = false;

            cout<<"Do you want to continue finding shapes? If yes, type 'y', if no, type 'n'. Your answer: ";
            cin>>ans;
        }
        while (ans != 'n');

    }

    void areaNpara()
    {
        do
        {
            cout<<"Enter the x coordinate (center) of the shape: ";
            cin>>x;
            cout<<"Enter the y coordinate (center) of the shape: ";
            cin>>y;
            Coordinates center_f(x,y);
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if (center_f == (*pObj)->center)
                {
                    cout<<"Area of the shape: "<<(*pObj)->getArea()<<endl;
                    cout<<"Perimeter of the shape: "<<(*pObj)->getParameter()<<endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "There is no shape at this location!" << endl;
            }
            found = false;

            cout<<"Do you want to continue finding shapes? If yes, type 'y', if no, type 'n'. Your answer: ";
            cin>>ans;
        }
        while (ans != 'n');


    }
    void translateShapes()
    {
        cout<<"Enter the translation of x coordinate: ";
        cin>>x;
        cout<<"Enter the translation of y coordinate: ";
        cin>>y;
        for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
        {

            (*pObj)->translate(x, y);

        }
        cout<<"\nSuccessfully Translated all shapes!"<<endl;
    }

    void scaleShapes()
    {
        bool sign;
        do
        {
            cout<<"If you want to increase the shape, type 1. If you want to decrease the shape, type 0. Your answer: ";
            cin>>x;
            if (x!= 1 && x!=0)
            {
                cout<<"Invalid Number, Type 1 or 0."<<endl;
            }
        }
        while (x!= 1 && x!=0);
        cout<<"Enter the scale factor: ";
        cin>>y;
        if (x == 1)
        {
            sign = true;
        }
        else if (x == 0)
        {
            sign = false;
        }
        for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
        {

            (*pObj)->scale(y, sign);

        }
        cout<<"\nSuccessfully Scaled all shapes!"<<endl;
        cout<<"Note: Only triangles change their centers."<<endl;
    }


    void displayAll()
    {
        for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
        {
            string position = "(" + to_string((*pObj)->center.x) + ", " + to_string((*pObj)->center.y) + ")";
            cout<<"\nShape at position "<<position<<endl;
            (*pObj)->display(position);
        }
    }

};

class ShapeManagement
{
public:
    void showMenu()
    {
        cout<<endl;
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
    int shapeNum, option;


    ShapeList shapeList;
    ShapeManagement menu;
    menu.showMenu();
    do
    {

        cout<<"\nEnter your option: ";
        cin>>option;
        switch (option)
        {
        case 1:
        {
            shapeList.addShape();
            break;
        }
        case 2:
        {
            shapeList.removeShape();
            break;
        }
        case 3:
        {
            shapeList.getShape();
            break;
        }
        case 4:
        {
            shapeList.areaNpara();
            break;
        }
        case 5:
        {
            shapeList.displayAll();
            break;
        }
        case 6:
        {
            shapeList.translateShapes();
            break;
        }
        case 7:
        {
            shapeList.scaleShapes();
            break;
        }
        default:
        {
            cout<<"Invalid Number. Type again!"<<endl;
            break;
        }
        }

    }
    while (option != 0);


    return 0;
}
