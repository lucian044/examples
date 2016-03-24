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

}
