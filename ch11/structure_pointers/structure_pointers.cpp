// Contains in class examples of structure pointers
// Creating a pointer to a structure
// Dynamically allocating a new structure
// . vs ->
// s->m      access a member from a structure pointer
// *a.p      dereference a pointer from a variable
// (*s).m    access a member from a structure pointer
// *s->p     dereference a member pointr from a pointer
// *(*s).p   same as above

// . then *

#include <iostream>

struct X {
  int a;
  int* b;
};

struct Y {
  int c;
  X* d;
};

int main() {

  int z = 10; // for use later

  // define variables for both types of structures
  X x1{42, &z};
  Y y1{15, &x1};

  // accessing members from a pointer to a structure
  
  X* xp = &x1;

  // print our the a member of xp
  std::cout << "(*xp).a = " << (*xp).a << std::endl;
  
  // xp->a == (*xp).a
  std::cout << "xp->a = " << xp->a << std::endl;

  // *a.p dereference a pointer from a variable
  *x1.b = 30;

  // output what z is now
  std::cout << "z = " << z << std::endl;

  //*s->p dereference a member pointer from a pointer
  // order of operations -> happens first

  // s->p , dereference s, and give acces to the member p
  // at this point, * deferences that pointer p

  *x1->b = 50;
  // output what z is now
  std::cout << "z = " << z << std::endl;
}
