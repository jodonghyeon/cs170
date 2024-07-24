// HLP2
// 02/06/2022
// VERSION 2
// Implementation file for a Student type that is used to introduce ADT 
// development with classes as in handout+intro+classes.pdf
#include "student.hpp"
#include <iostream>

int main() {
  Student s0; // define but not initialize a Student object
  s0.set_login("jdoe"); // using the public member functions
  s0.set_age(22);
  s0.set_year(4);
  s0.set_gpa(3.8);   
  s0.display(); // tell the object to display itself

  Student s1;
  s1.display(); // error: s1 is uninitialized!!!
  s1.init("jsmith", 20, 3, 2.8); // call set_ functions
  s1.display(); // tell the object to display itself
	
#if 0 // This code illustrates the use of keyword private in
      // the definition of Student
      // Because the data members are private, clients cannot directly manipulate them!!!
      // To get this code to compile, make data members of Student public.
	std::cout << "***** Begin *****\n";
  Student john {"jdoe", 20, 3, 3.10};
  Student jane {"jsmith", 19, 2, 3.95};
  Student jim  {"jbob", 22, 4, 2.76};
    
  john.set_age(21);   // Modify john
  john.set_gpa(3.25);

  jane.set_age(24);   // Modify jane
  jane.set_gpa(4.0);

  jim.set_age(23);    // Modify jim
  jim.set_gpa(2.98);

  john.display();     // Display all
  jane.display();
  jim.display();
  std::cout << "***** End *****\n";
#endif
}
