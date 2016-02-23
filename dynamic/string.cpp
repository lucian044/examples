#include "string.hpp"

#include <cstring>
#include <iostream>
#include <cassert>

String::String() : size{0} {
  chars = new char[0];
}

String::String(const char* c) : size{strlen(c)} {
  // a new array of the right length
  chars = new char[size];

  // move everything into the array
  for (int i = 0; i < size; ++i)
    chars[i] = c[i];
}

String::String(const String& x) {
  std::cout << "copy constructor called" << std::endl;
  size = x.size;
  // make a new array of the correct size
  chars = new char[size];
  // copy each character into the new array
  for (int i = 0; i < size; ++i)
    chars[i] = x.chars[i];
}

String::~String() {
  delete [] chars;
}

void String::set_first(char c) {
  assert(size > 0);
  chars[0] = c;
}

String& String::operator=(String& s) {
  std::cout << "operator= called" << std::endl;
  size = s.size;
  // make a new array of the correct size
  chars = new char[size];
  // copy each character into the new array
  for (int i = 0; i < size; ++i)
    chars[i] = s.chars[i];

  // return a reference to ourself
  return *this;
}

String operator+(String s1, String s2) {
  String ret; 
  ret.set_size(s1.get_size() + s2.get_size());
  
  // add the arrays together
  ret.chars = new char[ret.get_size()];

  // copy the first array
  for (int i = 0; i < s1.get_size(); ++i)
    ret.get_chars()[i] = s1.get_chars()[i];

  // copy the second array
  for (int i = 0; i < s2.get_size(); ++i)
    ret.get_chars()[i + s1.get_size()] = s2.get_chars()[i];

  return ret;
}

std::ostream& operator<<(std::ostream& strm, String& s) {
  char* chars = s.get_chars();
  for (int i = 0; i < s.get_size(); ++i) {
    strm << chars[i];
  }
  return strm;
}
