#include "string.hpp"
#include <cstring>
#include <iostream>
#include <cassert>

String::String() : size{1}, chars{strcpy(new char[1], "")} {}

String::String(const char* c) : size{strlen(c)}, chars{strcpy(new char[strlen(c) + 1], c)} {}

String::String(const String& x) : size{x.size}, chars{strcpy(new char[x.size + 1], x.chars)} {
  std::cout << "copy constructor called" << std::endl;
}

String::String(const String& s1, const String& s2)
  : size{s1.size + s2.size},
    chars{strcpy(strcpy(new char[size], s1.chars) + s1.size, s2.chars) - s1.size} {}

String::String(const String& s1, const char* c)
    : size{s1.size + strlen(c)}, chars{strcpy(strcpy(new char(size), s1.chars) + s1.size, c) - s1.size} {}

String::~String() {
  delete [] chars;
}

void String::set_first(char c) {
  assert(size > 0);
  chars[0] = c;
}

String& String::operator+=(const String& s) {
  String temp(*this, s);
  swap(temp);
  return *this;
}

String& String::operator+=(const char* c) {
  String temp(*this, c);
  swap(temp);
  return *this;
}

String& String::operator=(String s) {
  String temp(s);
  swap(temp);
  return *this;
}

void String::swap(String& s2) {
  std::swap(size, s2.size);
  std::swap(chars, s2.chars);
}

String operator+(const String& s1, const String& s2) {
  return String(s1, s2);
}

std::ostream& operator<<(std::ostream& strm, const String& s) {
  return strm << s.get_chars();
}
