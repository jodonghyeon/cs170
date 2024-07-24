// HLP2
// 02/06/2022
// VERSION 1
// Interface file for a Student type that is used to introduce ADT
// development with classes as in handout+intro+classes.pdf
#ifndef STUDENT_HPP_
#define STUDENT_HPP_

struct Student {
  enum {MAXLENGTH = 10};
  char login[MAXLENGTH];
  int age, year;
  double gpa;
};

void set_login(Student& student, char const *log);
void set_year(Student& student, int y);
void set_age(Student &student, int a);
void set_gpa(Student& student, double g);
void display(Student const& student);

#endif 
