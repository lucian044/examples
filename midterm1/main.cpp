#include <iostream>
#include "rev.hpp"

int main() {

  Rev r;
  int t = 100;
  r.pass_by_value(t);
  std::cout << "t after pbv" << t << std::endl;
  
  r.pass_by_reference(t);
  std::cout << "t after pbr" << t << std::endl;

}
