#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
  // Initialize the object here
  this->x = x;
  this->y = y;
  this->r = r;
}

double Circle::area() const {
  // Return the area of a circle

  return M_PI * pow(r,2); 
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles  
  return this->area() + c.area();

}

Circle & Circle::operator++()
{
  // Increment the radius by 1
  this->r++;
  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  
  //increment the radius by 1
  this->r++;

  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  // print a circle in the out stream (the format is the same as print())
  c.print();
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
 
 // Read a circle information from the in stream

  Circle n = c;

  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);
  Circle c(3,4,5.0); // added another just to test 

  a.print();
  b.print();
  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> c;
  cout << c;

  return 0;

}
