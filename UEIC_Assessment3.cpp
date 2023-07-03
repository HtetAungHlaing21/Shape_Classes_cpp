//Assessment 3 (Managing Shapes in a C++ Program)

//Header Files
#include <iostream> //For basic input output stream
#include <cmath>  //For math functions
#include <vector> //For vectors (Storing the shapes)
using namespace std;

class Coordinates  //Coordinates Class
{
public:
    int x, y; //x and y attributes
    Coordinates(int input_1 = 0, int input_2 = 0) //Constructor
    {
        x = input_1;
        y = input_2;
    }
    double distance(Coordinates p) //Method to find the distance between two points
    {
        return sqrt(pow(p.x-x, 2) + pow(p.y-y, 2));
    }
    void translate(int dx, int dy) //Method to translate a point
    {
        x += dx;
        y += dy;
    }
    void scale(int factor, bool sign) //Method to scale a point
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
    string display() //Method to display x and y values
    {
        return "X = " + to_string(x) + "\nY = " + to_string(y);
    }
};

class Shape  //Shape Class
{
public:
    Coordinates center; //Center of a shape
    int sides; //Number of sides
    Shape(Coordinates input_1, int input_2) //Constructor
    {
        center = input_1;
        sides = input_2;
    }
    void translate(int dx, int dy) //Method to translate a shape
    {
        center.translate(dx, dy);
    };
    //Virtual methods to be overridden in the child classes
    virtual void scale(int factor, bool sign) = 0;
    virtual double getArea() = 0;
    virtual double getParameter() = 0;
    virtual void display(string position) = 0 ;
};

class Rectangle : public Shape //Rectangle class inherited from Shape class
{
public:  //Width, length attributes
    int width;
    int length;
    Rectangle(int w, int l, Coordinates p):Shape(p, 4) //Constructor
    {
        width = w;
        length = l;
    }
    double getArea() //Method to calculate the area of a rectangle
    {
        return length * width;
    }
    double getParameter() //Method to calculate the perimeter of a rectangle
    {
        return (2 * length) + (2 * width);
    }
    void scale(int factor, bool sign) //Method to scale a rectangle
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
    void display(string position) //Method to display the information of a rectangle
    {
        cout<<"Name: Rectangle"<<endl;
        cout<<"Position: "<< position <<endl;
        cout<<"Length: " << length << "\nWidth: " << width << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Square : public Shape //Square class inherited from Shape class
{
public: //Side attribute
    int side;
    Square(int s, Coordinates p):Shape(p, 4) //Constructor
    {
        side = s;
    }
    double getArea() //Method to calculate the area of a square
    {
        return side * side;
    }
    double getParameter() //Method to calculate the perimeter of a square
    {
        return 4 * side;
    }
    void scale(int factor, bool sign) //Method to scale a square
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
    void display(string position) //Method to display the information of a square
    {
        cout<<"Name: Square"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Side: " << side << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Circle : public Shape //Circle class inherited from Shape class
{
public: //Radius attribute
    int radius;
    Circle(int r, Coordinates p):Shape(p, 0) //Constructor
    {
        radius = r;
    }
    double getArea()//Method to calculate the area of a circle
    {
        return 3.14 * radius * radius;
    }
    double getParameter() //Method to calculate the perimeter of a circle
    {
        return 2 * 3.14 * radius;
    }
    void scale(int factor, bool sign) //Method to scale a circle
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
    void display(string position) //Method to display the information of a circle
    {
        cout<<"Name: Circle"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Radius: " << radius << "\nArea: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class Triangle : public Shape //Triangle class inherited from Shape class
{
public: //Attributes
    Coordinates p1, p2, p3; //Three vertexes
    double a, b, c; //Three lengths
    Triangle(Coordinates input_1, Coordinates input_2, Coordinates input_3, Coordinates input_4):Shape(input_4, 3) //Constructor
    {
        p1 = input_1;
        p2 = input_2;
        p3 = input_3;
        getCenter();
        cout<<"\nThe center of the triangle: "<<round(center.x)<<" , "<<round(center.y)<<endl;
        getLength();
    }
    void getLength() //Method to find the length of three sides
    {
        a = p1.distance(p2);
        b = p2.distance(p3);
        c = p3.distance(p1);
    }
    void getCenter() //Method to find the center of a triangle
    {
        center.x = (p1.x + p2.x + p3.x)/3;
        center.y = (p1.y + p2.y + p3.y)/3;
    }
    double getArea() //Method to find the area of a triangle
    {
        double s = (a + b + c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double getParameter() //Method to find the parameter of a triangle
    {
        return  a + b + c;
    }
    void translate(int dx, int dy) //Method to translate a triangle
    {
        p1.translate(dx, dy);
        p2.translate(dx, dy);
        p3.translate(dx, dy);
        getCenter();
    }
    void scale(int factor, bool sign) //Method to scale a triangle
    {
        p1.scale(factor, sign);
        p2.scale(factor, sign);
        p3.scale(factor, sign);
        getCenter();
        getLength();
    }
    void display(string position) //Method to display a triangle
    {
        cout<<"Name: Triangle"<<endl;
        cout<<"Position: " << position <<endl;
        cout<<"Length of side 1: "<< a <<"\nLength of side 2: "<< b << "\nLength of side 3: "<<c<<endl;
        cout<<"Area: " << getArea() << "\nParameter: " << getParameter() <<endl;
    }
};

class ShapeList //Shape List Class
{
public: //Attributes
    vector <Shape*> listofShapes; //A vector to store the shapes

    //Temporary variables to use in the methods
    int shapeNum, temp, width, length, side, radius;
    float x,y, coor[3][2], center_x, center_y;
    char ans;
    bool deleted, found = false;

    Coordinates askCoordinates() //Method to ask the coordinates of the center (used in adding, removing, finding shapes)
    {
        cout<<"Enter x coordinate of the center: ";
        cin>>x;
        cout<<"Enter y coordinate of the center: ";
        cin>>y;
        Coordinates center(x,y);
        return center;
    }
    int askDimensions(string feature) //Method to ask the dimensions of width, length, side and radius
    {
        do
        {
            cout<<"Enter the "<< feature <<": ";
            cin>>temp;
            if (temp<=0)
            {
                cout<<"The "<< feature <<" must be greater than 0"<<endl;
            }
        }
        while(temp<=0);
        return temp;
    }
    void addShape() //Method to add a shape into listofShapes
    {
        do
        {
            cout<<"\nWhat shape do you want to add?\nType '1' for rectangle, '2' for square, '3' for circle, '4' for triangle. \nYour answer: ";
            cin>>shapeNum;
            if (shapeNum == 1 || shapeNum == 2 || shapeNum == 3 )
            {
                Coordinates center = askCoordinates();
                switch (shapeNum)
                {
                case 1:
                {
                    width = askDimensions("width");
                    length = askDimensions("length");
                    listofShapes.push_back(new Rectangle(width, length, center));
                    cout<<"A rectangle Successfully Added!"<<endl;
                    break;
                }
                case 2:
                {
                    side = askDimensions("side");
                    listofShapes.push_back(new Square(side, center));
                    cout<<"A square Successfully Added!"<<endl;
                    break;
                }
                case 3:
                {
                    radius = askDimensions("radius");
                    listofShapes.push_back(new Circle(radius, center));
                    cout<<"A circle Successfully Added!"<<endl;
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
                for (int i=0; i<3; ++i)
                {
                    cout<<"Enter x coordinate for vertex "<<i+1<<": ";
                    cin>>coor[i][0];
                    cout<<"Enter y coordinate for vertex "<<i+1<<": ";
                    cin>>coor[i][1];
                }
                Coordinates p1(coor[0][0], coor[0][1]);
                Coordinates p2(coor[1][0], coor[1][1]);
                Coordinates p3(coor[2][0], coor[2][1]);
                listofShapes.push_back(new Triangle(p1, p2, p3, (0,0)));
                cout<<"A triangle Successfully Added!"<<endl;
            }
            else
            {
                cout<<"Invalid Number! Type the number again!"<<endl;
            }
            cout<<"Do you want to continue adding shapes? If yes, type 'y', if no, type 'n'. Your answer: ";
            cin>>ans;
        }
        while(ans != 'n');

    }
    void removeShape() //Method to remove a shape from the listofShapes
    {
        do
        {
            Coordinates center_f = askCoordinates();
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if (center_f.x == (*pObj)->center.x && center_f.y == (*pObj)->center.y)
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
    void getShape() //Method to find the shape by position and give the details
    {
        do
        {
            Coordinates center_f = askCoordinates();
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if (center_f.x == (*pObj)->center.x && center_f.y == (*pObj)->center.y)
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

    void areaNpara() //Method to find the shape by position and give the area and parameter
    {
        do
        {
            Coordinates center_f = askCoordinates();
            for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
            {
                if ((center_f.x == (*pObj)->center.x && center_f.y == (*pObj)->center.y))
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
    void translateShapes() //Method to translate all shapes
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

    void scaleShapes() //Method to scale all shapes
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


    void displayAll() //Method to display about all shapes
    {
        for (vector<Shape*>::iterator pObj = listofShapes.begin(); pObj != listofShapes.end(); ++pObj)
        {
            string position = "(" + to_string((*pObj)->center.x) + ", " + to_string((*pObj)->center.y) + ")";
            cout<<"\nShape at position "<<position<<endl;
            (*pObj)->display(position);
        }
    }

};

class ShapeManagement //Shape Management Class
{
public:
    void showMenu() //Method to display the menu
    {
        cout<<"Choose an action from the menu."<<endl;
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
    int option;
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
        case 0:
        {
            cout<<"Thanks for using this program."<<endl;
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
