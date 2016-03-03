// the in-class version of string
// this will show dynamic memory allocation,
// copy constructors, and destructors

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
private:

  size_t size; // the number of elements in the array
  char* chars;  // this points to the beginning of the array after we make it
  void swap(String& s2);
public:

  String(); // the default constructor
  String(const char*); // creating a String from a cstring
  String(const String& s); // the copy constructor!
  String(const String& s1, const String& s2); // concatenation constructor
  String(const String& s1, const char*); // concatenation for strings

  // destructor
  // takes no arguments
  // no return type
  // called whenevr a String is destroyed
  ~String();

  // member becuse it changes itself
  String& operator+=(String s);
  String& operator+=(const char* c);

  // equal should return a ref to ourself
  String& operator=(String s);

  // size accessor
  int get_size() { return size; }
  char* get_chars() const { return chars; }
  void set_first(char c);
};

// overloaded operators
String operator+(const String& s1, const String& s2);

bool operator==(String s1, String s2);


// otream overload declaration
std::ostream& operator<<(std::ostream& strm, const String& s);

#endif
