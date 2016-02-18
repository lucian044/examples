#include "string.hpp"
#include <cstring>
#include <iostream>

String::String() {
  chars = new char[0];
}

String::String(const char* c) {
  len = strlen(c);
  chars = new char[len + 1];
  strcpy(chars, c);
  chars[0] = 'r';
}

char* String::get_chars() {
  return chars;
}

std::ostream& operator<<(std::ostream& strm, String s) {
  return strm << s.get_chars();
}
