// Contains in class examplezs from chapter 11
// Structs as function arguments
// Pass by value, reference, constant reference
// Returning a structure from a function

#include <string>
#include <iostream>

struct Food {
  
  // scale from 1 to 10
  int amount_of_flavor;

  // the name of the food
  std::string name;

};

// pass by value
// any changes are temporary 
void cook(Food x) {
  x.amount_of_flavor += 2;
}

// pass by 
// any changes are temporary 
void cook_by_reference(Food& x) {
  x.amount_of_flavor += 2;
}

// this is pass by const reference
void print_food(const Food& f) {
  //  f.amount_of_flavor++;   <---- you cannot edit the const
  std::cout << f.name << ": " << f.amount_of_flavor << std::endl;
}

Food buy() {
  Food f{5, "burger"};
  return f;
}

int main() {

  // create a Food instance called a
  Food a{2, "food a"};
  print_food(a);
  
  // see how pass by value works
  cook(a);
  print_food(a);

  // see how pass by reference works
  cook_by_reference(a);
  print_food(a);

  Food bought = buy();
  print_food(bought);

}
