#include "vector.hpp"

int main() {

  // create an empty Vector
  Vector v;

  v.display();

  Vector v2(1);
  v2.push_back("Tony");
  v2.display();

  Vector v3;
  v3.push_back("Tony");
  v3.display();

  v2.push_back("is");
  v2.display();
  v2.push_back("awesome!");
  v2.display();

  Vector v4(v2);
  v4.display();

  v4.pop_back();
  v4.display();
  v4.push_back("amazing!");
  v4.display();

  Vector::iterator it = v4.begin();
  std::cout << "the first element is: " << *it << " and its address is: " << it << std::endl; 

  // using the vector for a for loop
  for (Vector::iterator  myit = v4.begin(); myit != v4.end(); ++myit)
    std::cout << "[[" << *myit << "]]";
  std::cout << std::endl;

  // using range-based for loops
  for (auto x : v4) 
    std::cout << "[[" << x << "]]";
  std::cout << std::endl;
}
