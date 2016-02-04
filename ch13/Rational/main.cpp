#include "Rational.hpp"
#include <iostream>

int main () {
  
  // use the default constructpr
  Rational def;
  std::cout << def.get_numerator() << "/" << def.get_denominator() << std::endl;

  // call the parameterized constructor for these values
  Rational par(11, -33);
  std::cout << par.get_numerator() << "/" << par.get_denominator() << std::endl;

}
