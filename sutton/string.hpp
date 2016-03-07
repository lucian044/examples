#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
private:
  size_t size;
  char* str;

public:
  String();
  String(const char*);
  String(const String&);
  String(const String&, const String&);

  ~String();

  String& operator=(const String&);
  void swap(String&);

  char* get_str() const { return str; }
  size_t get_size() { return size; }
  void set_first(char c) { str[0] = c; }
};

String operator+(String s1, String s2);

// overloaded ostream
std::ostream& operator<<(std::ostream&, const String&); 


#endif
