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

  std::cout << "\nCreate a Rational using the parameterized constructor (18), print with str() member function." << std::endl;
  Rational par3(18);
  std::cout << par3.str() << std::endl;

  std::cout << "\nCreate a Rational using the parameterized constructor (12, 144), print with cout." << std::endl;
  Rational test(12, 144);
  std::cout << test << std::endl;

  std::cout << "\nPrint the result of 1/12 + 1/12." << std::endl;
  std::cout << test + test << std::endl;

  std::cout << "\nPrint the result of 1/12 + 4." << std::endl;
  std::cout << test + 4 << std::endl;

  std::cout << "\nPrint the result of 4 + 1/12." << std::endl;
  std::cout << 4 + test << std::endl;

  
  std::cout << "\nPrint the result of ++ prefix for 1/12" << std::endl;
  Rational inc(1,12);
  std::cout << ++inc << std::endl;
  std::cout << "The value of inc is now: " << inc << std::endl;
  
  std::cout << "\nPrint the result of ++ postfix for 1 1/12" << std::endl;
  std::cout << inc++ << std::endl;
  std::cout << "The value of inc is now: " << inc << std::endl;
  
  std::cout << "\nPrint the result of unary - operator on 2 1/12" << std::endl;
  Rational test2(25, 12);
  std::cout << -test2 << std::endl;
  
  std::cout << "\nPrint the result of 2 1/12 - 2/12." << std::endl;
  std::cout <<  test2 - Rational(2, 12) << std::endl;
  /*
  std::cout << "\nPrint the result of 2 1/12 - 1." << std::endl;
  */
  
  std::cout << "\nPrint the result of 2 1/12 * 2 1/12." << std::endl;
  std::cout <<  test2 * test2 << std::endl;
  /*
  std::cout << "\nPrint the result of 2 1/12 * 2." << std::endl;
  */
  
  std::cout << "\nPrint the result of (2 1/12) / (1/12)." << std::endl;
  std::cout <<  test2 / Rational(1, 12) << std::endl;
  /*
  std::cout << "\nPrint the result of (2 1/12) / 25." << std::endl;

  */

  std::cout << "\nPrint the result of (2 1/12) < (1/12)." << std::endl;
  std::cout << (Rational(25, 12) < Rational(1,12) ? "true" : "false") << std::endl;

  std::cout << "\nPrint the result of (1/12) < (2 1/12)." << std::endl;
  std::cout << (Rational(1, 12) < Rational(25,12) ? "true" : "false") << std::endl;

  std::cout << "\nPrint the result of (0/12) == (0/13)." << std::endl;
  std::cout << (Rational(0, 12) == Rational(0,13) ? "true" : "false") << std::endl;

  std::cout << "\nPrint the result of (0/12) != (0/13)." << std::endl;
  std::cout << (Rational(0, 12) != Rational(0,13) ? "true" : "false") << std::endl;

  std::cout << "\nPrint the result of (1/12) += (2/12)." << std::endl;
  Rational t(1, 12);
  t += Rational(2,12);
  std::cout << t << std::endl;

  std::cout << "\nPrint the result of (1/4) -= (16/1)." << std::endl;
  t -= Rational(16, 1);
  std::cout << t << std::endl;

  std::cout << "\nPrint the result of -(15 3/4) *= (2/1)." << std::endl;
  t *= Rational(2, 1);
  std::cout << t << std::endl;

  std::cout << "\nPrint the result of -(31 1/2) /= (1/2)." << std::endl;
  t /= Rational(1, 2);
  std::cout << t << std::endl;

  std::cout << "\nPrint the result of (2/3 *= ((1/2 + 4) + (2/3 / 4)))." << std::endl;
  t = Rational(2, 3);
  t *= ((Rational(1, 2) + 4) + (Rational(2, 3) / 4));
  std::cout << t << std::endl;
}
