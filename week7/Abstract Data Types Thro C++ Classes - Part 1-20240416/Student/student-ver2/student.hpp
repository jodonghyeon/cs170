// HLP2
// 02/06/2022
// VERSION 2
// Interface file for a Student type that is used to introduce ADT
// development with classes as in handout+intro+classes.pdf

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

struct Student {
public:
  // mutators
  void init(char const *log, int a, int y, double g) {
    set_login(log); set_age(a); set_year(y); set_gpa(g);
  }
  void set_login(char const *log);
  void set_age(int a);
  void set_year(int y);
  void set_gpa(double g);
  void display();

  // accessors
  int get_age()           { return age;}
  int get_year()          { return year; }
  double get_gpa()        { return gpa; }
  char const* get_login() { return login; }

private:  
  enum {MAXLENGTH = 10}; 
  char login[MAXLENGTH];
  int age, year;
  double gpa;
};

#endif
