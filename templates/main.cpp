#include <iostream>

#include "myTemp.hpp"


class Thisshouldmessup {
};

int main() {

  // we have to tell the compiler what data type we want to use with our variable
  MyTemp<int> mt(12);
  mt.print_data();
  std::cout << std::endl;
  MyTemp<double> dm(3.45);
  dm.print_data();
  std::cout << std::endl;
  Thisshouldmessup t;
  MyTemp<Thisshouldmessup> tm(t);
  tm.print_data();
  std::cout << std::endl;
  
}
