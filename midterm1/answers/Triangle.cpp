#include "Triangle.hpp"

Triangle::Triangle(double h, double b) 
  : height{h}, base{b}
{
    if (height < 0)
      height *= -1; 

    if (base < 0)
      base *= -1;
}

double Triangle::get_height() const { return height; }
double Triangle::get_base() const { return base; }
void Triangle::set_height(double h) { height = h; }
void Triangle::set_base(double b) { base = b; }

double Triangle::get_area() const {
  return (base * height) / 2;
}

bool operator==(Triangle t1, Triangle t2) {
  if (t1.get_base() != t2.get_base())
    return false;
  if (t1.get_height() != t2.get_height())
    return false;
  return true;
}
