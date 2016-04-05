#include "vector.hpp"
#include "string.hpp"

#include <iostream>
#include <cassert>

Vector::Vector(int cap) 
{
  // make sure we have a positive capacity request
  assert(cap >= 0);
  reserve(cap);
}

Vector::Vector(const Vector& v) {
  reserve(v.size());
  for (String* temp = v.base; temp < v.last; new (last++) String(*(temp++)));  
}

Vector::~Vector() {
  clear();
  deallocate();
}

void* Vector::allocate(int capacity) {
  // takes the number of bytes that need to be allocated
  return ::operator new(capacity * sizeof(String));
}

void Vector::deallocate() {
  // make sure there are no initialized elements
  clear();
  // call the global delete operator on the beginninbg of the storage area
  ::operator delete(base);
}

void Vector::clear() {
  while(last > base)
    (--last)->~String();
}

void Vector::display() const {
  std::cout << "\n-------------------------------------"
	    << "\nSize: " << size()
	    << "\nCapacity: " << capacity()
	    << "\nElements: ";
  for(String* temp = base; temp < last; std::cout << "[\"" << *(temp++) << "\"]"); 
  std::cout << "\n-------------------------------------\n";
}

void Vector::reserve(int cap) {
  // check if there is no storage
  if (base == limit) {
    last = base = reinterpret_cast<String*>(allocate(cap));
    limit = base + cap;
  // if we dont have enough storage
  } else if (capacity() < cap) {
    // allocate new
    String* new_base = reinterpret_cast<String*>(allocate(cap));
    String* new_last = new_base;
    limit = new_base + cap;

    // copy elements
    // using the last section of the for loop with placement new
    for (String* temp = base; temp < last; new (new_last++) String(*(temp++)));
 
    // destroy old elements
    clear();
    // deallocate
    deallocate();
    // move pointers
    base = new_base;
    last = new_last;
    // limit was set before
  }

}

void Vector::push_back(String s) {
  if (last == limit) // no capacity
    reserve(capacity() == 0 ? 8 : capacity() * 2);

  new (last++) String(s);
}

void Vector::push_back(const char* c) {
  if (last == limit) // no capacity
    reserve(capacity() == 0 ? 8 : capacity() * 2);

  new (last++) String(c);
}

void Vector::pop_back() {
  // make sure there is at least one element to pop off the back
  assert(last != base);

  // destroys the last element
  (--last)->~String();
}

// return a copy of the last elemnt in the vector
String Vector::back() {
  assert(base != last);
  return *(last - 1);
}
