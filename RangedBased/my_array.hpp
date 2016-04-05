// this will show you how to use range based for loops
#ifndef RANGE_BASED_HPP
#define RANGE_BASED_HPP

#include <iostream>

template <class T> // template prefix 
struct MyArray {
  T* data;
  size_t _size = 0;

  // the array will have length size;
  MyArray(size_t size);

  using iterator = T*;
  using const_iterator = T*;
  iterator begin() { return data; }
  iterator end() { return data + _size; }
  const_iterator begin() const { return data; }
  const_iterator end() const { return data + _size; }

};

template <class T>
MyArray<T>::MyArray(size_t x) {
  _size = x;
  data = new T[_size];
} 


#endif
