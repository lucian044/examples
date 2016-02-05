// always include the hpp file first
#include "Rational.hpp"

#include <sstream>
#include <cassert>
#include <iostream>

// when implementing functions for classes, you must tell the compiler
// which class the functions belongs to using the scope resolution operator ::


// the default constructor handles what happens when no parameters are passed
// we MUST make one if we plan to create instances with no parameters becasue we
// have also defined a parameterized constructor below
Rational::Rational() {
  num = den = 1;
}

// we will use an initialization list within out constructors
// they appear after the parentheses and before the opening brace
// this constructor will set num to n and den to d, then run the code inside
// the block
Rational::Rational(int n, int d) : num{n}, den{d} {
  assert(d != 0);
  reduce();
}

// the parameterized constructor for a whole number
Rational::Rational(int n) : num{n}, den{1} {
}


// the implementation of reduce
void Rational::reduce() {
  //calculate the gcd
  int g = gcd(num, den);

  // adjust the num and den values in the current instance
  num /= g;
  den /= g;

  // check for incorrect signage
  if (den <0 && num > 0) {
    num *= -1;
    den *= -1;
  }
}

// the implementation of str
// we use a stringstream object because it handles conversions to string much
// easier than we could do at this point
// stringstream acts just like cout with regards to the << operator
std::string Rational::str() {
  std::stringstream strm;
  if (num < 0) {
    strm << "-" << operator-().str();
  }
  if (den == 1) {
    strm << num;
  } 
  else if (num > den) {
    int whole = num / den;
    int rem = num % den;
    strm << whole << " " << rem << "/" << den;
  } 
  else {
    strm << num << "/" << den;
  }
  return strm.str();
}

// binary operator implementations
Rational Rational::operator+(Rational r) {
  int cd = den * r.den;
  int new_num = (num * r.den) + (r.num * den);
  return Rational(new_num, cd);
}


// unary operator implementations
Rational Rational::operator-() {
  return Rational(-num, den);
}


// the implementation of the overloaded << operator
// this puts the str representation of a Rational onto the ostream on the left side
// to allow chained << we MUST return a reference to the stream
std::ostream& operator<<(std::ostream& strm, Rational r) {
  strm << r.str();
  return strm;
} 

// the implementation of the + operator for int on the left side of the operator
// we will use the implementation for Rational + i that we have already created
Rational operator+(int i, Rational r) {
  return r + i;
}

// gcd using recursion
// technically this is not the gcd if both numbers are negative, this works out for us though
// we will cover this later
int Rational::gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
