// CSD1121 11/23/2022
// Problem being solved: Reading an unknown number of quiz grades from a
// file for an unknown number of students and then performing simple
// anlaysis on these grades USING A  DYNAMICALLY ALLOCATED ONE-DIMENSIONAL ARRAY.
// Review of following topics:
// - addressing a two-dimensional matrix using one-dimensional array
// - arrays and pointers

#include <stdio.h>
#include <stdlib.h>

// return a pointer to the first element of a dynamically allocated array
// of int elements with the array size specified by the product of the
// starting two integer values in file header;
int* read_grades(char const *file_name, int *student_count, int *quiz_count);

// return a pointer to the first element of a dynamically allocated array
// of double elements; the number of elements in this array is specified by
// parameter quiz_count
double* quiz_avg_grades(int *grades, int student_count, int quiz_count);

// return a pointer to the first element of a dynamically allocated array
// of double elements; the number of elements in this array is specified by
// parameter student_count
double* student_avg_grades(int *grades, int student_count, int quiz_count);
void print_grades(int *grades, int student_count, int quiz_count);

int main(int argc, char *argv[]) {
 if (argc < 2) {
    fprintf(stderr, "Usage: grades.exe grades-text-file\n");
    return 0;
  }

  int student_count, quiz_count;
  int *grades = read_grades(argv[1], &student_count, &quiz_count);
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

  free(grades);

  return 0;
}

int* read_grades(char const *file_name, int *student_count, int *quiz_count) {
  FILE *ifs = fopen(file_name, "r");
  if (!ifs) {
    return NULL;
  }

  fscanf(ifs, "%d %d", student_count, quiz_count);

  int total_grades = *student_count * *quiz_count;
  int *grades = (int*) malloc(sizeof(int*) * total_grades);
  if (!grades) {
    return NULL;
  }

  for (int i = 0; i < total_grades; ++i) {
    if (1 != fscanf(ifs, "%d", &grades[i])) {
      free(grades);
      return NULL;
    }
  }
  fclose(ifs);

  return grades;
}

double* quiz_avg_grades(int *grades, int student_count, int quiz_count) {
  if (!grades) { return NULL; }
  double *quiz_avg = (double*) malloc(sizeof(double) * quiz_count);
  if (!quiz_avg) { return NULL; }
  for (int i = 0; i < quiz_count; ++i) {
    int sum = 0;
    for (int j = 0; j < student_count; ++j) {
      sum += grades[j * quiz_count + i];
    }
    quiz_avg[i] = (double)sum/(double)student_count;
  }
  return quiz_avg;
}

double* student_avg_grades(int *grades, int student_count, int quiz_count) {
  if (!grades) { return NULL; }
  double *student_avg = (double*) malloc(sizeof(double) * student_count);
  if (!student_avg) { return NULL; }
  for (int i = 0; i < student_count; ++i) {
    int sum = 0;
    for (int j = 0; j < quiz_count; ++j) {
      sum += grades[i * quiz_count + j];
    }
    student_avg[i] = (double)sum/(double)quiz_count;
  }
  return student_avg;
}

void print_grades(int *grades, int student_count, int quiz_count) {
  if (!grades) { return; }
  for (int i = 0; i < student_count; ++i) {
    fprintf(stdout, "Quiz grades for Student ID %d: ", i);
    for (int j = 0; j < quiz_count; ++j) {
      fprintf(stdout, "%d%s", grades[i*quiz_count + j], (j==quiz_count-1 ? "\n" : " "));
    }
  }
}

