// HLP2
// 02/06/2022
// VERSION 1
// Implementation file for a Student type that is used to introduce ADT 
// development with classes as in handout+intro+classes.pdf
#include "student.hpp"
#include <iostream>

int main() {
  Student s3;
  set_age(s3, -5);
  set_gpa(s3, 12.9);
  set_login(s3, "rumplestiltzkin");
  set_year(s3, 150);
  display(s3);

  Student s4;
  display(s4); // error: displaying uninitialized values!!!
  set_age(s4, 21);
  set_gpa(s4, 3.4);
  set_login(s4, "jdoe");
  set_year(s4, 3);
}
