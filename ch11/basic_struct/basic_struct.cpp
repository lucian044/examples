// Contains a basic structure
// Declaration and Definition of a structure
// Accessing member variables
// Outputing member variables
// The dot operator
// Initializing member variables

#include <iostream>
#include <string>

// The declaration of a structure named 'Student' 
// The name of the struct is also called the tag
// The declaration tells the compiler what the structure is composed of
struct Student {

  // each member variable of the structure is declared using the data type and a name

  int age; // the age of the student
  std::string name; // the name of the student
  std::string ID; // the ID of the student

}; // do not forget this semi colon, ever!

int main() {
  
  // Defining an instance of the Student data type
  // It is important to remember the member variables are not initialized
  // The instance, named 'st', has its own copy of each of the member variables
  Student st;
 
  // the dot operator . is used to access structure members
  // st.age will access the age member of the instance of Student named 'st'
  
  // output the Student information using the dot operator before initialization
  std::cout << "The age of our student is " << st.age << "." << std::endl;
  std::cout << "The name of our student is " << st.name << "." << std::endl;
  std::cout << "The ID of our student is " << st.ID << "." << std::endl;
  
  std::cout << "------------ after initilization ------------ " << slizedtd::endl;

  // Initialize the member variables for the st variable using the dot operator
  // set the age to 35, name to "Tony Deeter" an ID to "12345678"
  st.age = 35;
  st.name = "Tony Deeter";
  st.ID = "12345678";

  // output the Student information using the dot operator after initialization
  std::cout << "The age of our student is " << st.age << "." << std::endl;
  std::cout << "The name of our student is " << st.name << "." << std::endl;
  std::cout << "The ID of our student is " << st.ID << "." << std::endl;  
}



