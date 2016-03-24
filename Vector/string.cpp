#include "string.hpp"

#include <cstring>
#include <iostream>
#include <cassert>

// using the initializer list now, give a nul ptr to the char array
String::String() 
  : size{0}, chars{strcpy(new char[1], "")} {}

// copy the cstring into a new char array and set chars equal to it
String::String(const char* c) 
  : size{strlen(c)}, chars{strcpy(new char[size + 1], c)} 
{}

// copy the String into the newly allocated array
String::String(const String& x) 
  : size{x.size}, chars{strcpy(new char[size + 1], x.chars)}
{}

// constructor with two parameters
String::String(const String& s1, const String& s2) 
  : size{s1.size + s2.size}, chars{strcpy(strcpy(new char[size + 1], s1.chars) + s1.size, s2.chars) - s1.size}
{}

String::~String() {
  delete [] chars;
}

void String::set_first(char c) {
  assert(size > 0);
  chars[0] = c;
}

String& String::operator=(String& s) {
  String temp(s);
  swap(temp);
  return *this;
}

String& String::operator+=(String s) {
  //String temp(*this, s);
  //swap(temp);
  size += s.size;
  strncat(chars, s.chars, s.size);
  return *this;
}

void String::swap(String& s1) {
  std::swap(size, s1.size);
  std::swap(chars, s1.chars);
}

String operator+(const String& s1, const String& s2) {
  String temp(s1, s2);
  return temp;
}

String concat(const String& s1, const String& s2, const char* c)
{
  return String(strncat(strncat(s1.get_chars(), c, strlen(c)), s2.get_chars(), s2.get_size()));
}

bool operator==(const String& s1, const String& s2) {
  // check the size, if they arent equal, they cannot be equal strings
  if (s1.get_size() != s2.get_size())
    return false;
  
  // grab the pointers to the char arrays
  char* test1 = s1.get_chars(), * test2 = s2.get_chars();
  for (int i = 0; i < s1.get_size(); ++i) {
    if (test1[i] != test2[i])
      // if any of them are not equal return false
      return false;
  }
  // it has to be equal if it made it this far
  return true;
}

// return the negation of the == operator
bool operator!=(const String& s1, const String& s2) {
  return !(s1 == s2);
}


std::ostream& operator<<(std::ostream& strm, const String& s) {
  return strm << s.get_chars();
}
