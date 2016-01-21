// Contains a basic structure
// Declaration and Definition of a structure
// Accessing member variables
// Outputing member variables

#include <iostream>
#include <string>

// The declaration or
// a structure named student (tag)
struct Student {

  int age; // the age of the student
  std::string name; // the name of the student
  std::string ID; // the ID of the student

}; // do not forget this, ever

int main() {

  // declaration was handle above
  
  // definition
  // an instance of the Student data type
  Student st;
 
  // the dot operator . is used to access structure members
  // st.age
  
  // output some student information
  // out the age of our instance of st
  std::cout << "The age of our student is " << st.age << "." << std::endl;
  std::cout << "The name of our student is " << st.name << "." << std::endl;
  std::cout << "The ID of our student is " << st.ID << "." << std::endl;

  std::cout << "------------ after initilization ------------ " << std::endl;

  // initilization
  // set the age to 35, name to "Tony Deeter" an ID to "12345678"
  st.age = 35;
  st.name = "Tony Deeter";
  st.ID = "12345678";

  std::cout << "The age of our student is " << st.age << "." << std::endl;
  std::cout << "The name of our student is " << st.name << "." << std::endl;
  std::cout << "The ID of our student is " << st.ID << "." << std::endl;  
}



