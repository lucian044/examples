// Contains class examples for structures
// Initializing a structure with starting values
// Partially initalizing
// Array Structures
// Nested Structures

#include <iostream>
#include <string>

// an example structure for intializing with values
struct Example {
  
  int a;
  std::string b;
  int c, d; // you CAN define multiple members of the same type on the same line
  
};

// a structure that contains an Example
// the struct contains another struct
struct Nested {
  int a;
  Example b;
};


int main() {

  // create an instance of Example with values
  // we use whats called an initializer list
  Example ex = { 1, "t", 3, 4  };
  
  // output the values from ex
  std::cout << ex.a << " " << ex.b << " " << ex.c << " " << ex.d << std::endl;


  // initialize with the first two member variables
  Example ex2{42, "ex2"};
  std::cout << ex2.a << " " << ex2.b << " " << ex2.c << " " << ex2.d << std::endl;

  // initialize with the last two member variables
  // you cant
  
  // Arrays of structures

  int x[10]; // gives us an array of 10 integers

  // array of 10 Examples
  Example examples[10];

  std::cout << " - array values for a " << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 10; ++i) {
    std::cout << examples[i].a << std::endl; 
  }

  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 10; ++i) {
    examples[i].a = i;
  }

  std::cout << " - after initializing values for a " << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 10; ++i) {
    std::cout << examples[i].a << std::endl; 
  }

  // use an initializer to give values to an array of Examples
  // you can use less initialiers than the size of the array but the remaining will not be
  // initialized
  Example e[5] = { 
    {1, "a", 2, 3},
    {1, "b", 2, 3},
    {1, "c", 2, 3},
    {1, "d", 2, 3},
    {1, "e", 2, 3},
  };
    
  std::cout << " - after initializing with initializer lists " << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 5; ++i) {
    std::cout << e[i].b << std::endl; 
  }

  // using initializer lists with less items in each list
  Example e2[5] = { 
    {1, "a"},
    {1, "b", 2, 3},
    {1},
    {1, "d", 2},
    {1, "e", 2, 3},
  };
    
  std::cout << " - after initializing with partial initializer lists " << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 5; ++i) {
    std::cout << e2[i].b << std::endl; 
  }

// using initializer lists with no inner curlys in each list
  Example e3[5] = { 
    1, "a", 3, 4, 5, "b", 6, 7
  };
    
  std::cout << " - after initializing with no curly initializer lists " << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 5; ++i) {
    std::cout << e3[i].b << std::endl; 
  }

  // using Nested structures

  // create a Nested instance
  Nested n; // this will not be initialized

  // set the values for n
  // n's a member set to 10
  n.a = 10;
  n.b.a = 12;
  
  

}
