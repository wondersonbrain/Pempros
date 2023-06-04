#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) 
{
  int looping = 0;
  char command[100];
  unsigned short int student_size = 0;
  struct student_t *student = malloc(100 * sizeof(struct student_t));

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
    else if (strcmp(janring, "---") == 0)
    {
      looping = 1;
    }
  }
  return 0;
}