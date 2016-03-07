#include <iostream>
#include <cstring>
#include "string.hpp"

String::String() 
  : size{0}, str{strcpy(new char[1], "")}
{}

String::String(const char* c)
  : size{strlen(c)}, str{strcpy(new char[size + 1], c)} 
{}

String::String(const String& s)
  : size{s.size}, str{strcpy(new char[s.size + 1], s.str)}
{}


// similar to how we did it in class but this is a little mroe strait forward
String::String(const String& s1, const String& s2) 
  : size{s1.size + s2.size}, str{strcat(strcpy(new char[size + 1], s1.str), s2.str)}
{} 

String::~String() {
  delete [] str;
}

String& String::operator=(const String& s) {
  String temp(s);
  swap(temp);
  return *this;
} 

void String::swap(String& s) {
  std::swap(size, s.size);
  std::swap(str, s.str);
}

String operator+(String s1, String s2) {
  return String(s1, s2);
}

std::ostream& operator<<(std::ostream& strm, const String& s) {
  return strm << s.get_str();
}


