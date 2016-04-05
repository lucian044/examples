// write and use a min function for integers
// min(1, 2)  -> 1
// min(5, 2)  -> 2
// min(2.3, 3.6) -> 2.3
// min('a', 'b') -> 'a'
#include <iostream>

struct Foo {
  int x;
  Foo(int xi) : x{xi} {}
  bool operator<(Foo f) { return x > f.x; }
};

// the T acts as a palceholder for a generic data type
// this function will work for all data types that have operator< implemented
template <class T> // i have a placeholder for an unknown class and im calling it T
T min(T a, T b) {
  return a < b ? a : b;
}



int main() {
  std::cout << min(1, 2) << std::endl;
  std::cout << min(5, 2) << std::endl;
  std::cout << min(2.3, 3.6) << std::endl;
  std::cout << min(1, 2) << std::endl;
  std::cout << min('a', 'b') << std::endl;
  std::cout << min(Foo(1), Foo(2)).x << std::endl;
  std::cout << min(Foo(1), Foo(2)).x << std::endl;
}
