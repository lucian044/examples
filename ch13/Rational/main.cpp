#include "Rational.hpp"
#include <iostream>

int main () {

  // use the default constructor
  std::cout << "\nCreate a Rational using the default constructor, print with accessors." << std::endl;
  Rational def;
  std::cout << def.get_numerator() << "/" << def.get_denominator() << std::endl;

  // call the parameterized constructor for these values
  std::cout << "\nCreate a Rational using the parameterized constructor (-11, -33), print with accessors." << std::endl;
  Rational par(-11, -33);
  std::cout << par.get_numerator() << "/" << par.get_denominator() << std::endl;

  // call the parameterized constructor for these values
  std::cout << "\nCreate a Rational using the parameterized constructor (11, -33), print with accessors." << std::endl;
  Rational par2(11, -33);
  std::cout << par2.get_numerator() << "/" << par2.get_denominator() << std::endl;

  /*
  std::cout << "\nCreate a Rational using the parameterized constructor (18), print with accessors." << std::endl;

  /*
  std::cout << "\nCreate a Rational using the parameterized constructor (12, 144), print with cout." << std::endl;

  /*
  std::cout << "\nPrint the result of 1/12 + 1/12." << std::endl;

  /*
  std::cout << "\nPrint the result of 1/12 + 4." << std::endl;

  /*
  std::cout << "\nPrint the result of 4 + 1/12." << std::endl;

  /*
  std::cout << "\nPrint the result of ++ prefix for 1/12" << std::endl;

  /*
  std::cout << "\nPrint the result of ++ postfix for 1 1/12" << std::endl;

  /*
  std::cout << "\nPrint the result of unary - operator on 2 1/12" << std::endl;

  /*
  std::cout << "\nPrint the result of 2 1/12 - 2/12." << std::endl;

  /*
  std::cout << "\nPrint the result of 2 1/12 - 1." << std::endl;

  /*
  std::cout << "\nPrint the result of 2 1/12 * 2 1/12." << std::endl;

  /*
  std::cout << "\nPrint the result of 2 1/12 * 2." << std::endl;

  /*
  std::cout << "\nPrint the result of (2 1/12) / (1/12)." << std::endl;

  /*
  std::cout << "\nPrint the result of (2 1/12) / 25." << std::endl;

  */
}
