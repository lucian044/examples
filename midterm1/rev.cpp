#include <iostream>
#include <string>
#include "rev.hpp"

Rev::Rev() : x{25} {}

Rev::Rev(int data) : x{data} {}

void Rev::display_data() {
  std::cout << "this is x from inside a member function being called directly: " << x << std::endl;

  // equivalent to *(this.x)
  std::cout << "this is x from inside a member function being called using this: " << this->x << std::endl;
}

void show_data(Rev r) {
  r.set_x(50);
  std::cout << "this is x from outside a member function being called directly: " << r.get_x() << std::endl;
}

void say_hi() {
  std::cout << "I was told to say hi" << std::endl;
}

Rev make_rev() {
  Rev x;
  return x;
}
