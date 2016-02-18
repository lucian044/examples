// the beginning of our string class

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
private:
  int len;
  char* chars;
public:

  String();
  String(const char *);
  ~String() {}
  char* get_chars();
  int length() { return len; }
};

std::ostream& operator<<(std::ostream& os, String s);

#endif
