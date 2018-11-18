/*
Exercise 4.1 
Using the program point.cpp, add a member function print to the class Point so that it prints out coordinates as: 
    (2, 3)
for a point with coordinates (2, 3). Test it in main(). 
*/
/*
Exercise 4.2
Write a definition of a class Rectangle using the Point class. A rectangle is specified by two corner points (bottom left and top right). The sides of the rectangle are parallel to the coordinate axes. The implementation of the class should be as follows: 
The private data members of the class include all 4 corner points of the rectangle. 
There are two constructors: one takes two points as arguments and creates a rectangle with the first point as the bottom left corner and the second as the top right corner, the other (default) constructor creates a rectangle with the corners (0,0), (1,0), (0,1), (1,1). 
Hint: use functions Set_X, Set_Y from the class Point to set the values of the corner points. 
The print member function prints all 4 corners of the rectangle, using the member function print of the class Point. 
Test the class Rectangle in main(), demonstrate that all member functions work as specified.
*/
/*
Exercise 4.3 
Add two private member functions side1, side2 to the class Rectangle to compute the lengths of the two sides. Using this function, write a public member function to compute the area of the rectangle. 
*/

#include <iostream>
using namespace std;

//Declaration of class Point


// class Point represents a two-dimensional point
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 

  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);

  
// member function for moving a point by dx, dy:
  void Move(int dx, int dy);

  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;

  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);

//Add declaration of member function Print here:
	void Print(int x,int y);
// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  


//Methods for class Point

// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}

// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
    

//Lab 7 exercise 4.1. Add definition of member function print:
void Point::Print(int x,int y)
{
cout<<"coordinates r ("<<x<<","<<y<<")"<<endl;

}


//  Declaration of class Rectangle

class Rectangle : public Point
{
//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 
  Point p1,p2,p3,p4;
  int s1,s2;
public:
    Rectangle(Point c1,Point c2);
    Rectangle ();
    int area();
};
Rectangle::Rectangle(Point c1, Point c2)
{
    p1=c1;
    p2=c2;
	//using loops 
    while(c1.Get_X()<p2.Get_X())
    {
        c1.Move(1,0);
    }
    p3=c1;
	//using loops
    while(c2.Get_X()>p1.Get_X())
    {
        c2.Move(-1,0);
    }
    p4=c2;
    cout<<" third point of the rect & ";
    p3.Print(p3.Get_X(),p3.Get_Y());
	cout<<endl;
    cout<<" fourth point of the rect & ";
    p4.Print(p4.Get_X(),p4.Get_Y());
    s1=p4.Get_Y()-p1.Get_Y();
    s2=p3.Get_X()-p1.Get_X();
	cout<<endl;
}



//  Methods for class Rectangle
//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE: 
int Rectangle::area()
{
    int area=s1*s2;
    return area;
}


//  main() function for testing classes Point and Rectangle
// Testing classes Point and Rectangle
int main()
{
// Declaring a point using default class constructor (x = y = 0):
  Point p1;
  cout<< "The x value for p1 is " << p1.Get_X() << endl;
  cout<< "The y value for p1 is " << p1.Get_Y() << endl;
  cout<<endl;

// Declaring a point with coordinates X = 2, Y = 3:
  Point p2(2, 3);
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;
  cout<<endl;

// Moving point p2 by (1, -1):
  p2.Move(1, -1);
  cout<< "After the move:" << endl;
  cout<< " x value for p2 is " << p2.Get_X() << endl;
  cout<< " y value for p2 is " << p2.Get_Y() << endl;
  cout<<endl;

//Lab 7 exercise 4.1. Test member function print on points p1, p2:
  cout<<"The 1st pt. of ";
  p1.Print(p1.Get_X(),p1.Get_Y());
  cout<<endl;
  cout<<"The 2nd pt. of ";
  p2.Print(p2.Get_X(),p2.Get_Y());
  cout<<endl;

//Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here:  

  cout<<" 1st point of the rect & ";
  p1.Print(p1.Get_X(),p1.Get_Y());
  cout<<endl;
  cout<<" 2nd point of the rect & ";
  p2.Print(p2.Get_X(),p2.Get_Y());
  cout<<endl;

  Rectangle rec(p1,p2);
  cout<<"hence,the Area of the rect is "<<rec.area()<<endl;
  return 0;
}



