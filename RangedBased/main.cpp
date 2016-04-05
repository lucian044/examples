#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "my_array.hpp"

template <class T>
void display(MyArray<T> ma) {
  for (auto i : ma)
    std::cout << "[" << i << "]";
  std::cout << std::endl; 
}

int main() {

  srand(time(0));

  MyArray<int> ma(10);
  display(ma);

  int count = 0;
  for (auto i : ma)
    i = ++count;

  display(ma);
  
  count = 0;
  for (auto& i : ma)
    i = ++count;

  display(ma);

  // create a MyArray with doubles
  MyArray<double> md(3);
  for (auto& x : md)
    x = rand() * 10;

  display(md);

  // create a MyArray with strings
  MyArray<std::string> ms(6);
  auto temp = ms.begin();
  *(temp++) = "tony";
  *(temp++) = "deeter";
  *(temp++) = "is";
  *(temp++) = "done";
  *(temp++) = "teaching";
  *(temp++) = "today.";
  
  display(ms);
}
