// Contains in class examples of structure pointers
// Creating a pointer to a structure
// Dynamically allocating a new structure
// . vs ->
// s->m      access a member from a structure pointer
// *a.p      dereference a pointer from a variable
// (*s).m    access a member from a structure pointer
// *s->p     dereference a member pointr from a pointer
// *(*s).p   same as above

// -> then . then *

#include <iostream>

struct X {
  int a;
  int* b;
};

int main() {

  int z = 10; // for use later

  // define a variable for the structure X
  X x1{42, &z};

  // create a pointer to the instance of X for use with accessing members from a pointer to a structure
  X* xp = &x1;
  
  // print out the a member of xp
  // the parentheses force the * operator to derefence xp, then the dot operator accesses the member a
  std::cout << "(*xp).a = " << (*xp).a << std::endl;
  
  // xp->a == (*xp).a
  // the -> shorthand operator is equivalent and easier to use
  std::cout << "xp->a = " << xp->a << std::endl;

  // *a.p dereference a pointer from a variable
  // the dot operator accesses the member b, which is a pointer
  // the * operator then dereferences it
  *x1.b = 30;

  // output what z is now
  std::cout << "z = " << z << std::endl;

  //*s->p dereferences a member pointer from a pointer to the structure
  // order of operations -> happens first

  // s->p , dereferences s, and gives access to the member p
  // at this point, * deferences that pointer p
  *xp->b = 50;

  // output what z is now
  std::cout << "z = " << z << std::endl;

  // if we want to do the same thing without the shorthand
  *(*xp).b = 70;

  // output z with the new value
  std::cout << "z = " << z << std::endl;

}
