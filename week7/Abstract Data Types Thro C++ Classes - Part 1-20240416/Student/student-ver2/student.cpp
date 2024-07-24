// HLP2
// 02/06/2022
// VERSION 2
// Implementation file for a Student type that is used to introduce ADT 
// development with classes as in handout+intro+classes.pdf
#include "student.hpp"
#include <iostream>
#include <cstring>

void Student::set_login(char const *log) {
  int len = std::strlen(log);
  std::strncpy(login, log, MAXLENGTH - 1);
  if (len >= MAXLENGTH) {
    login[MAXLENGTH - 1] = '\0';
  }
}

void Student::set_year(int y) {
  if ( (y < 1) || (y > 4) ) {
    std::cout << "Error in year range!\n";
    year = 1;
  } else { year = y; }
}

void Student::set_age(int a) {
  if ( (a < 18) || (a > 100) ) {
    std::cout << "Error in age range!\n";
    a = 18;
  } else { age = a; }
}

void Student::set_gpa(double g) {
  if ( (g < 0.0) || (g > 4.0) ) {
    std::cout << "Error in GPA range!\n";
    gpa = 0.0;
  } else { gpa = g; };
}

void Student::display() {
  std::cout << "login: " << login << "\n";
  std::cout << "  age: " << age << "\n";
  std::cout << " year: " << year << "\n";
  std::cout << "  GPA: " << gpa << "\n";
}
