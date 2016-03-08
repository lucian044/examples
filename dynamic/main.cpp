#include "string.hpp"
#include <iostream>

int main() {

  String empty; // default constructor
  std::cout << "This is an empty string --->" << empty << "<--- it ended here. " << std::endl;

  String x("Tony"); // regular constructor
  std::cout << "This is a non-empty string --->" << x << "<--- it ended here. " << std::endl;

  String x2 = x; // copy constructor
  std::cout << "This is the x2 String: " << x2 << std::endl;

  x.set_first('P');
  std::cout << "This is the x String after set_first: " << x << std::endl;
  std::cout << "This is the x2 String after set_first: " << x2 << std::endl;

  // creating a new String that is empty
  String x3;
  x3 = x;
  x.set_first('S');
  std::cout << "This is the x String after set_first: " << x << std::endl;
  std::cout << "This is the x3 String after set_first: " << x3 << std::endl;

  String t1 = "Tony";
  String t2 = "Deeter";
  t1 += t2;
  std::cout << t1 << std::endl;


  String t3 = "TonyDeeter";
  String t4 = "TonyDeeeter";
  std::cout << "t1 is " << (t1 == t3 ? "" : "not ") << "equal to t3" << std::endl;
  std::cout << "t3 is " << (t4 == t3 ? "" : "not ") << "equal to t4" << std::endl;
  std::cout << "t3 is " << (t4 != t3 ? "" : "not ") << "NOT equal to t4" << std::endl;

  std::cout << concat(String("con"), String("cat"), " ") << std::endl;

  String arrayTest("hocuspocus");
  std::cout << "The third character of " << arrayTest << " is " << arrayTest[2] << std::endl;
  // set the third character to something else
  arrayTest[2] = 'k';
  std::cout << "The third character of " << arrayTest << " is NOW " << arrayTest[2] << std::endl;

  const String arrayTestConst(arrayTest);
  std::cout << "The third character of " << arrayTestConst << " is " << arrayTestConst[2] << std::endl;

}
