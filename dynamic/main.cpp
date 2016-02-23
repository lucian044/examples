#include "string.hpp"
#include <iostream>

int main() {

  String empty; // default constructor
  std::cout << "This is an empty string --->" << empty << "<--- it ended here. " << std::endl;

  String x("Tony"); // regular constructor
  std::cout << "This is a non-empty string --->" << x << "<--- it ended here. " << std::endl;

  String x2 = x; // copy constructor
  std::cout << "This is the x2 String: " << x2 << std::endl;

  x.set_first('P');
  std::cout << "This is the x String after set_first: " << x << std::endl;
  std::cout << "This is the x2 String after set_first: " << x2 << std::endl;

  // creating a new String that is empty
  String x3;
  x3 = x; 
  x.set_first('S');
  std::cout << "This is the x String after set_first: " << x << std::endl;
  std::cout << "This is the x3 String after set_first: " << x3 << std::endl;

}
