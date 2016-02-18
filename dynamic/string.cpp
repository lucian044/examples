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
  size = x.size;
  // make a new array of the correct size
  chars = new char[size];
  // copy each character into the new array
  for (int i = 0; i < size; ++i)
    chars[i] = x.chars[i];
}

void String::set_first(char c) {
  assert(size > 0);
  chars[0] = c;
}

std::ostream& operator<<(std::ostream& strm, String s) {
  char* chars = s.get_chars();
  for (int i = 0; i < s.get_size(); ++i) {
    strm << chars[i];
  }
  return strm;
}

