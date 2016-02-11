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
Rational::Rational() : num{1}, den{1} {}

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
  else if (den == 1) {
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
Rational& Rational::operator+=(Rational r) {
  // we need to add ourself to the parameter
  // create a new Rational with the result of addition
  // set *this equal to that new Rational
  // return a reference to ourself
  return (*this = *this + r);
}

Rational& Rational::operator-=(Rational r) {
  // see operator+= for 
  return (*this = *this - r);
}

Rational& Rational::operator*=(Rational r) {
  // see operator+= for 
  return (*this = *this * r);
}

Rational& Rational::operator/=(Rational r) {
  // see operator+= for 
  return (*this = *this / r);
}

Rational& Rational::operator+=(int i) {
  // we need to add ourself to the parameter
  // create a new Rational with the result of addition
  // set *this equal to that new Rational
  // return a reference to ourself
  return (*this = *this + i);
}

Rational& Rational::operator-=(int i) {
  // see operator+= for 
  return (*this = *this - i);
}

Rational& Rational::operator*=(int i) {
  // see operator+= for 
  return (*this = *this * i);
}

Rational& Rational::operator/=(int i) {
  // see operator+= for 
  return (*this = *this / i);
}



Rational operator+(Rational r1, Rational r2) {
  int cd = r1.get_denominator() * r2.get_denominator();  
  int new_num = (r1.get_numerator() * r2.get_denominator()) + (r2.get_numerator() * r1.get_denominator());
  return Rational(new_num, cd);
}

Rational operator+(Rational r, int i) {
  return r + Rational(i);
}

Rational operator+(int i, Rational r) {
  return r + i;
}

// other math operations
// these are outside the class so you dont need scope resolution, but you need two operands
Rational operator-(Rational r1, Rational r2) {
  return r1 + -r2;
}

Rational operator-(Rational r, int i) {
  return r - Rational(i);
}

Rational operator-(int i, Rational r) {
  return Rational(i) - r;
}

Rational operator*(Rational r1, Rational r2) {
  return Rational(r1.get_numerator() * r2.get_numerator(), r1.get_denominator() * r2.get_denominator());
}

Rational operator*(Rational r, int i) {
  return r * Rational(i);
}

Rational operator*(int i, Rational r) {
  return r * i;
}

Rational operator/(Rational r1, Rational r2) {
  return r1 * Rational(r2.get_denominator(), r2.get_numerator());
}

Rational operator/(Rational r, int i) {
  return r / Rational(i);
}

Rational operator/(int i, Rational r) {
  return Rational(i) / r;
}

bool operator<(Rational r1, Rational r2) {
  return (r1 - r2).get_numerator() < 0;
}

bool operator<=(Rational r1, Rational r2) {
  return (r1 - r2).get_numerator() <= 0;
}

bool operator>(Rational r1, Rational r2) {
  return (r1 - r2).get_numerator() > 0;
}

bool operator>=(Rational r1, Rational r2) {
  return (r1 - r2).get_numerator() >= 0;
}

bool operator==(Rational r1, Rational r2) {
  return (r1 - r2).get_numerator() == 0;
}

bool operator!=(Rational r1, Rational r2) {
  return !(r1 == r2);
}

// unary operator implementations
Rational Rational::operator-() {
  return Rational(-num, den);
}

// prefix ++
Rational Rational::operator++() {
  *this = *this + Rational(1);
  return *this;
}

// postfix
Rational Rational::operator++(int) {
  Rational temp = *this;
  *this = *this + Rational(1);
  return temp;
}

// the implementation of the overloaded << operator
// this puts the str representation of a Rational onto the ostream on the left side
// to allow chained << we MUST return a reference to the stream
std::ostream& operator<<(std::ostream& strm, Rational r) {
  strm << r.str();
  return strm;
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
