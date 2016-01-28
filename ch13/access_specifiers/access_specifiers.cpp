// Contains code having to do with access specifiers
// public - can be accessed outside of the class member functions
// private - can only be accessed by class members
// By default, all class members are private
// By default, all stuct members are public
// Accessors
// Mutators
// Assertions

#include <iostream>
#include <cassert>

// create a definition of a class
// this class will represent a rectangle
class Rectangle {
  
  // define a member variable using the default access specification
  double length;

private:
  // everything is private until another access specificatino is given
  double width;

public:
  double calculateArea();  // function declaration

  // accessors
  // use const to ensure the instance of the class will not be changed
  // inline function
  double getLength() const { return length; }
  double getWidth() const { return width; }

  // mutators
  void setLength(double l);
  void setWidth(double width);

};

double Rectangle::calculateArea() {
  return length * width;
}

// this is the definition for setLength that was declared in the class
void Rectangle::setLength(double l) {
  // assert will end the program if the statement inside the parentheses returns false
  assert(l > 0); // make sure the l parameter is greater than 0

  length = l; // sets the instances length member to l
}

// this is the definition for setWidth that was declared in the class
void Rectangle::setWidth(double width) {
  

  // make sure the width parameter is greater than 0
  // assert will end the program if the statement inside the parentheses returns false
  assert(width > 0); 

  // the keyword 'this' is a pointer to the current object
  // dereference it and modify with member variable using the ->
  this->width = width; // sets the instances width member to the width parameter
}

int main() {

  // create a Rectangle
  Rectangle rect;

  // we cannot do this
  // this ia private mamber
  // rect.width = 10;
  
  // assert will make sure the mutators do not send negative values so you cannot do this
  // rect.setLength(-1);

  // set the length to 10 an the width to 20 using the mutators
  rect.setLength(10);
  rect.setWidth(20);

  // display the currenbt length and width
  std::cout << " The current width = " << rect.getWidth() << std::endl;
  std::cout << " The current length = " << rect.getLength() << std::endl;

  // call the calculateArea function using the dot operator
  // which will will display the calculated area
  std::cout << " The current area = " << rect.calculateArea() << std::endl;
}
