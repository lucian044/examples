#ifndef VECTOR_HPP
#define VECTOR_HPP

// a custom vector clas for Strings
#include <cassert>
#include "string.hpp"

class Vector {
private:

  // the beginning of the String storage
  String* base = nullptr;

  // after! the last String element in the storage
  String* last = nullptr;

  // after! the end of the storage area
  String* limit = nullptr;

  // create the storage area for 'capacity' elements
  // this returns a pointer to the void type at the beginning of the storage
  void* allocate(int capacity);

  // deallocate the storage area;
  // we will call clear to make sure the storage area is clear
  // then we will release the storage area memory
  void deallocate();


public:

  //constructors
  Vector() {}
  Vector(int cap);
  Vector(const Vector& v);

  // iterators
  // we need to be able to use something like this:
  // Vector::iterator it = v.begin();

  using iterator = String*;
  using const_iterator = String*;
  // the function to return a pointer to the first element
  iterator begin() { return base; }
  iterator end() { return last; }
  
  // Vector::const_iterator it begin()
  const_iterator begin() const { return base; }
  const_iterator end() const { return last; }

  // destructor
  ~Vector();

  // the number of initialied elements
  size_t size() const { return last - base; }

  // the number of possible elements in the storage area
  size_t capacity() const { return limit - base; }

  // show the contents and information about the vector
  void display() const;

  // make sure there are no initialized elements
  void clear();

  // reserve at kleast the givenb amount of storage
  void reserve(int cap);

  void push_back(String s);
  void push_back(const char*);
  void pop_back();
  String back();

};

#endif
