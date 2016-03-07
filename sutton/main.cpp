#include <iostream>
#include "string.hpp"

int main() {
  String x("Tony");
  std::cout << x << std::endl; 

  String copy(x);
  std::cout << "The copied String is: "<< copy << std::endl; 

  x.set_first('P');
  std::cout << "The original String is: "<< x << std::endl; 
  std::cout << "The copied String is: "<< copy << std::endl; 

  String not_copy;
  not_copy = x;
  x.set_first('S');
  std::cout << "The original String is: "<< x << std::endl; 
  std::cout << "The not copy String is: "<< not_copy << std::endl; 

  std::cout << x + not_copy << std::endl;
}
