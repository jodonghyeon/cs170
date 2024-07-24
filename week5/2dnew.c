// CSD1121 11/21/2022
// 2dnew.c
// Problem being solved: Reading an unknown number of quiz grades from a
// file for an unknown number of students and then performing simple
// anlaysis on these grades
// Review of following topics:
// - two-dimensional arrays (aka array of arrays)
// - pointer to an array [of certain specified number of elements]
// - shortcoming of static two-dimensional arrays [compiler needs to know at
//   compile-time the size of rows and columns - thereby allowing us to only
//   solve the problem of reading grades from a file for a pre-specified
//   number of quizzes for a pre-specified number of students]
// - using a variable of type int** to solve the problem of reading an unknown
//   number of quiz grades from an unknown number of students by modifying
//   quiz data files to include a file header of 2 integer values that will
//   specify the number of students and the number of quiz grades per student
// Usage: use with data files quiz0304.txt, quiz0405.txt, and quiz0605.txt

#include <stdio.h>
#include <stdlib.h>

// return a pointer to the first element of a dynamically allocated array
// of int* elements with the array size specified by the first integer value
// in header of file; each int* element points to the first element of a
// dynamically allocated array of int elements with the array size specified by
// the second integer value in file header:
// file_name: full path to text file containing grades
// student_count: pointer to variable defined by caller that will be assigned
// the first integer value in file header; also the number of elements in
// dynamically allocated array of int* elements
// quiz_count: pointer to variable defined by caller that will be assigned
// the second integer value in file header; also the number of elements in
// dynamically allocated array of int elements
int** read_grades(char const *file_name, int *student_count, int *quiz_count);

void print_grades(int **grades, int student_count, int quiz_count);

// return a pointer to the first element of a dynamically allocated array
// of double elements; the number of elements in this array is specified by
// parameter quiz_count
double* quiz_avg_grades(int **grades, int student_count, int quiz_count);

// return a pointer to the first element of a dynamically allocated array
// of double elements; the number of elements in this array is specified by
// parameter student_count
double* student_avg_grades(int **grades, int student_count, int quiz_count);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: grades.exe grades-text-file\n");
    return 0;
  }

  int student_count, quiz_count;
  int **grades = read_grades(argv[1], &student_count, &quiz_count);
  print_grades(grades, student_count, quiz_count);
  double *quiz_avg = quiz_avg_grades(grades, student_count, quiz_count);
  if (quiz_avg) {
    for (int i = 0; i < quiz_count; ++i) {
      fprintf(stdout, "Average grade for Quiz %d: %.2f\n", i, quiz_avg[i]);
    }
  }
  free(quiz_avg);

  double *student_avg = student_avg_grades(grades, student_count, quiz_count);
  if (student_avg) {
    for (int i = 0; i < student_count; ++i) {
      fprintf(stdout, "Average quiz grade for Student ID %d: %.2f\n", i, student_avg[i]);
    }
  }
  free(student_avg);

  // return memory that stores grades ...
  for (int i = student_count-1; i >= 0; --i) {
    free(grades[i]);
  }
  free(grades);

  return 0;
}

int** read_grades(char const *file_name, int *student_count, int *quiz_count) {
  FILE *ifs = fopen(file_name, "r");
  if (!ifs) {
    return NULL;
  }

  fscanf(ifs, "%d %d", student_count, quiz_count);

  int **grades = (int**) malloc(sizeof(int*) * *student_count);
  if (!grades) {
    return NULL;
  }

  for (int i = 0; i < *student_count; ++i) {
    grades[i] = (int*) malloc(sizeof(int) * *quiz_count);
    if (!grades[i]) {
      return NULL;
    }
    for (int j = 0; j < *quiz_count; ++j) {
      fscanf(ifs, "%d", &grades[i][j]);
    }
  }
  fclose(ifs);

  return grades;
}

double* quiz_avg_grades(int **grades, int student_count, int quiz_count) {
  if (!grades) { return NULL; }
  double *quiz_avg = (double*) malloc(sizeof(double) * quiz_count);
  if (!quiz_avg) { return NULL; }
  for (int i = 0; i < quiz_count; ++i) {
    int sum = 0;
    for (int j = 0; j < student_count; ++j) {
      sum += grades[j][i];
    }
    quiz_avg[i] = (double)sum/(double)student_count;
  }
  return quiz_avg;
}

double* student_avg_grades(int **grades, int student_count, int quiz_count) {
  if (!grades) { return NULL; }
  double *student_avg = (double*) malloc(sizeof(double) * student_count);
  if (!student_avg) { return NULL; }
  for (int i = 0; i < student_count; ++i) {
    int sum = 0;
    for (int j = 0; j < quiz_count; ++j) {
      sum += grades[i][j];
    }
    student_avg[i] = (double)sum/(double)quiz_count;
  }
  return student_avg;
}

void print_grades(int **grades, int student_count, int quiz_count) {
  if (!grades) { return; }
  for (int i = 0; i < student_count; ++i) {
    fprintf(stdout, "Quiz grades for Student ID %d: ", i);
    for (int j = 0; j < quiz_count; ++j) {
      fprintf(stdout, "%d%s", grades[i][j], (j==quiz_count-1 ? "\n" : " "));
    }
  }
}
