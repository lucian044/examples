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

  // you CAN define multiple members of the same type on the same line
  // separate each varibale name by a comma
  int c, d; 
  
};

// Structures can contain members that are also structures
// These are called nested structures

// a structure that contains a member of type Example (declared above) 
// the struct contains another struct
struct Nested {
  int a;
  Example b;
};


int main() {

  // create an instance of Example with values
  // we use whats called an initializer list
  // the members are assigned the values in the same order they are declared in the struct
  // a = 1, b = "t", c = 3, d = 4
  Example ex = { 1, "t", 3, 4  };
  
  // output the values from ex using the dot operator
  std::cout << ex.a << " " << ex.b << " " << ex.c << " " << ex.d << std::endl;


  // you do not have to initialie all the values
  // if you have supply less valus than needed, members are assigned values until there are none left
  // initialize with the first two member variables
  // a = 42, b = "ex2"
  // c and d are not initialized
  Example ex2{ 42, "ex2" };
  std::cout << "Output the member values from the ex2 Example" << std::endl;
  std::cout << ex2.a << " " << ex2.b << " " << ex2.c << " " << ex2.d << std::endl;

  // initialize with the last two member variables
  // for example, initialize c and d in our Example struct
  // you cant do it
  // you cannot skip members while initializing
  

  // Arrays of structures
  int x[10]; // gives us an array of 10 integers

  // array of 10 Examples
  // these instances are not initialized!!!
  Example examples[10];

  std::cout << "\n\nOutput the values for examples[i].a from the array of Examples" << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 10; ++i) {
    std::cout << "examples[" << i << "].a = " << examples[i].a << std::endl; 
  }

  // using a for lop to access the a member of each instance of Example in the array
  // initializing each a member to the current iteration of i
  for (int i = 0; i < 10; ++i) {
    examples[i].a = i;
  }

  std::cout << "\n\nOutput the values for examples[i].a from the array of Examples" << std::endl;
  // using a for lop to access the a member of each instance of Example in the array
  for (int i = 0; i < 10; ++i) {
    std::cout << "examples[" << i << "].a = " << examples[i].a << std::endl; 
  }

  // use an initializer list to give values to an array of Examples
  // each element in the list is itself an initializer list
  // you can use less initialiers than the size of the array but the remaining will not be
  // initialized
  Example e[5] = { 
    {1, "a", 2, 3},
    {1, "b", 2, 3},
    {1, "c", 2, 3},
    {1, "d", 2, 3},
    {1, "e", 2, 3},
  };
    
  // using a for lop to access the a member of each instance of Example in the array
  std::cout << "\n\nOutput the values for e[i].b from the 'e' array of Examples after using the initializer list" << std::endl;
  for (int i = 0; i < 5; ++i)
    std::cout << "e[" << i << "].b = " << e[i].b << std::endl;   

  // using initializer lists with less items in each list
  // each interior list can have be a partial list
  Example e2[5] = { 
    {1, "a"},
    {1, "b", 2, 3},
    {1},
    {1, "d", 2},
    {1, "e", 2, 3},
  };
    
  // using a for lop to access the a member of each instance of Example in the array
  std::cout << "\n\nOutput the values for e[i].b from the 'e2' array of Examples after using the partial initializer lists" << std::endl;
  for (int i = 0; i < 5; ++i)
    std::cout << "e2[" << i << "].b = " << e2[i].b << std::endl;   

  // using initializer lists with no inner curly braces
  // the members of each instance in the array will be initialized in the order they are declared
  // when all members of an instance are initialized, the next instane is initialized
  Example e3[5] = { 
    1, "a", 3, 4, 5, "b", 6, 7
  };
    
  // using a for lop to access the a member of each instance of Example in the array
  std::cout << "\n\nOutput the values for e[i].b from the 'e3' array of Examples after using the partial initializer lists" << std::endl;
  for (int i = 0; i < 5; ++i)
    std::cout << "e3[" << i << "].b = " << e3[i].b << std::endl;   

  // using Nested structures

  // create a Nested instance
  Nested n; // this will not be initialized

  // set the values for n
  // n's a member set to 10
  n.a = 10;

  // set the b member of n's a member to 12
  /*

    this is the same as the following:
    Example nb = n.b;
    nb.a = 12;

   */
  n.b.a = 12;
  n.b.b = "test";
  n.b.c = n.b.d = 10;

  // make another Nested structure
  // using an initializer list
 
  Nested init_list{ 10, { 2, "y", 5, 7 } };
  
  //output the init_list 
  std::cout << "a = " << init_list.a << std::endl
	    << "b.a" << init_list.b.a << std::endl
	    << "b.b" << init_list.b.b << std::endl
	    << "b.c" << init_list.b.c << std::endl
	    << "b.d" << init_list.b.d << std::endl;
}
