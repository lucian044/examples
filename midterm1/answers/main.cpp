#include <iostream>
#include "Triangle.hpp"

int main() {
  
  Triangle t1(10, 5.5);
  Triangle t2(10, -10);

  std::cout << t1.get_area() << std::endl;
  std::cout << t2.get_area() << std::endl;
  std::cout << (t1 == t2) << std::endl;
}
