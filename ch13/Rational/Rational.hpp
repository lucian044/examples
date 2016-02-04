/*
  A class definition representing a rational number

  The #ifndef / #define / #endif are an include guard
  They are used to make suire the class is not defined more than once
  Even if it is included more than once
*/

#ifndef RATIONALL_HPP
#define RATIONALL_HPP

#include <string>

class Rational {

private:
  // the numerator and denominator
  // these are private so non members do not have access to them
  int num, den;

  // the declaration of a reduce function
  // this will be implemented in the Rational.cpp file
  void reduce();

public:
  // accessors
  // they are defined inline
  // inline functions are faster because they do not need to push and pop off the stack
  // they increase the size of the binary, however
  int get_numerator() { return num; }
  int get_denominator() { return den; }

  // mutators will not be included, once a Rational object is created there
  // will be no need to modify it without using operators

  // constructors
  // these functions are what we use to create an instance of a Rational object
  // constructors are functions that have no return type and are named the name of the class
  // their use will replace using initializer lists like we did with structs
  // there are multiple kinds of constructors, we will focus on default, and parameterized
  // a default constructor is created for every class by the compiler unless a parameterized
  // constructor has been defined.  you will have to create your own default constructor if
  // you create a parameterized constructor

  // default constructor
  // this is what is called if you create a Rational with no parameters
  Rational();

  // parameterized constructor
  Rational(int n, int d);

  // return a string version of the Rational number

  // this function returns the greatest common denominator of two integers
  int gcd(int a, int b);

};

#endif
