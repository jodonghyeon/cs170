// HLP2
// 02/06/2022
// VERSION 2
// Implementation file for a Student type that is used to introduce ADT 
// development with classes as in handout+intro+classes.pdf
#include "student.hpp"
#include <iostream>
#include <cstring>

void set_login(Student& student, char const *log) {
  int len = std::strlen(log);
  std::strncpy(student.login, log, Student::MAXLENGTH - 1);
  if (len >= Student::MAXLENGTH) {
    student.login[Student::MAXLENGTH - 1] = '\0';
  }
}

void set_year(Student& student, int y) {
  if ( (y < 1) || (y > 4) ) {
    std::cerr << "Error in year range!\n";
    student.year = 1;
  } else { student.year = y; }
}
void set_age(Student &student, int a) {
  if ( (a < 18) || (a > 100) ) {
    std::cout << "Error in age range!\n";
    student.age = 18;
  } else { student.age = a; }
}

void set_gpa(Student& student, double g) {
  if ( (g < 0.0) || (g > 4.0) ) {
    std::cout << "Error in GPA range!\n";
    student.gpa = 0.0;
  } else { student.gpa = g; }
}

void display(Student const& student) {
  std::cout << "login: " << student.login << "\n";
  std::cout << "  age: " << student.age << "\n";
  std::cout << " year: " << student.year << "\n";
  std::cout << "  GPA: " << student.gpa << "\n";
}
