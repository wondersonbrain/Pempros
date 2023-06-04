#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) 
{
  int looping = 0;
  char command[100];
  unsigned short int student_size = 0;
  unsigned short int course_size = 0;
  struct student_t *student = malloc(100 * sizeof(struct student_t));
  struct course_t *course = malloc (100 * sizeof(struct course_t));

  while (looping != 1)
  {
    command[0] = '\0';
    short k = 0;
    while (1 == 1)
    {
      char i = getchar();
      if (i == '\n')
      {
        break;
      }
      if (i == '\r')
      {
        continue;
      }
      command[k] = i;
      command[++k] = '\0';
    }
    
    char *janring = strtok(command, "#");
    
    if (strcmp(janring, "create-student") == 0)
    {
      janring = strtok(NULL, "#");
      strcpy(student[student_size].id, janring);
      janring = strtok(NULL, "#");
      strcpy(student[student_size].name, janring);
      janring = strtok(NULL, "#");
      strcpy(student[student_size].year, janring);
      janring = strtok(NULL, "#");
      strcpy(student[student_size].study_program, janring);
      student[student_size].gpa = 0;
      student_size++;
    }
    else if (strcmp(janring, "print-students") == 0)
    {
      print_students(student, student_size);
    }

    if (strcmp(janring, "create-course")==0)
    {
      janring = strtok(NULL, "#");
      strcpy(course[course_size].code, janring);
      janring = strtok(NULL, "#");
      strcpy(course[course_size].name, janring);
      janring = strtok(NULL, "#");
      course[course_size].credit = atoi(janring);
      janring = strtok(NULL, "#");
      if (strcmp(janring, "A") == 0)
      {
        course[course_size].passing_grade = 8;
      }
      else if (strcmp(janring, "AB")==0)
      {
        course[course_size].passing_grade = 7;
      }
      else if (strcmp(janring, "B")==0)
      {
        course[course_size].passing_grade = 6;
      }
      else if (strcmp(janring, "BC")==0)
      {
        course[course_size].passing_grade = 5;
      }
      else if (strcmp(janring, "C")==0)
      {
        course[course_size].passing_grade = 4;
      }
      else if (strcmp(janring, "D")==0)
      {
        course[course_size].passing_grade = 3;
      }
      else if (strcmp(janring, "E")==0)
      {
        course[course_size].passing_grade = 2;
      }
      else if (strcmp(janring, "T")==0)
      {
        course[course_size].passing_grade = 1;
      }
      else if (strcmp(janring, "NONE")==0)
      {
        course[course_size].passing_grade = 0;
      }
      course_size++;
    }
    
    else if (strcmp(janring, "print-courses")==0)
    {
      print_courses(course, course_size);
    }

    else if (strcmp(janring, "---") == 0)
    {
      looping = 1;
    }
  }
  return 0;
}