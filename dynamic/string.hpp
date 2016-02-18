// the in-class version of string
// this will show dynamic memory allocation, 
// copy constructors, and destructors

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
private:

  int size; // the number of elements in the array
  char* chars;  // this points to the beginning of the array after we make it

public:

  String(); // the default constructor
  String(const char*); // creating a String from a cstring
  String(const String& s); // the copy constructor!

  // member becuse it changes itself
  String& operator+=(String s);
  
  // size accessor
  int get_size() { return size; }
  char* get_chars() { return chars; }
  void set_first(char c);
};

// overloaded operators
String operator+(String s1, String s2);

bool operator==(String s1, String s2);


// otream overload declaration
std::ostream& operator<<(std::ostream& strm, String s); 

#endif

