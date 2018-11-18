
#include <iostream>
using namespace std;
class Rectangle
{
	public:
	double length;
	double breadth;
	Rectangle(double len,double bre)
	{
		length=len;
		breadth=bre;
	}
	double area()
	{
		return length*breadth;
	}
	double perimeter()
	{
		return 2*(length+breadth);
	}
};
int main()
{
	double l,b=0.0;
	cout<<"provide the length of 1st rect\n";
	cin>>l;
	cout<<"provide the breadth of 1st rect\n";
	cin>>b;
	Rectangle rect1(l,b);
	cout<<"provide the length of 2nd rect\n";
	cin>>l;
	cout<<"Enter the breadth of the second rectangle\n";
	cin>>b;
	Rectangle rect2(l,b);
	cout<<"Area of 1st rect is "<<rect1.area()<<" square units\n";
	cout<<"Area of 2nd rect"<<rect2.area()<<" square units\n";
	if(rect1.area()>rect2.area())
	cout<<"Area of 1st rect>area of 2nd rect\n";
	else if(rect1.area()<rect2.area())
	cout<<"Area of 2nd rect > 1st rect\n";
	else
	cout<<"Both  have the same area\n";
	cout<<"Perimeter of 1sr rect is "<<rect1.perimeter()<<" units\n";
	cout<<"Perimeter of 2nd rect "<<rect2.perimeter()<<" units\n";
	if(rect1.perimeter()>rect2.perimeter())
	cout<<"Perimeter of 1st reactangle is greater than 2nd rectangle\n";
	else if(rect1.perimeter()<rect2.perimeter())
	cout<<"perimeter of 1st rect<perimeter of 2nd rect\n";
	else
	cout<<"Both of them have the same perimeter.\n";
	return 0;
}

