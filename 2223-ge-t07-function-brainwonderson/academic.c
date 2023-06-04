// NIM - Name
// NIM - Name

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) {
  char *text = malloc(8);
  switch(_grade){
    case GRADE_A:
      strcpy(text, "A");
      break;
    case GRADE_AB:
      strcpy(text, "AB");
      break;
    case GRADE_B:
      strcpy(text, "B");
      break;
    case GRADE_BC:
      strcpy(text, "BC");
      break;
    case GRADE_C:
      strcpy(text, "C");
      break;
    case GRADE_D:
      strcpy(text, "D");
      break;
    case GRADE_E:
      strcpy(text, "E");
      break;
    case GRADE_T:
      strcpy(text, "T");
      break;
    default:
      strcpy(text, "None");
  }

  return text; 
}


float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    float performance;
  switch(_grade){
    case GRADE_A:
    performance = _credit*4.0;
    break;
    case GRADE_AB:
    performance = _credit*3.5;
    break;
    case GRADE_B:
    performance = _credit*3.0;
    break;
    case GRADE_BC:
    performance = _credit*2.5;
    break;
    case GRADE_C:
    performance = _credit*2.0;
    break;
    case GRADE_D:
    performance = _credit*1.0;
    break;
    case GRADE_E:
    performance = _credit*0.0;
    break;
    case GRADE_T:
    performance = _credit*0.0;
    break;
    default:
    performance = _credit*0.0;
  }

  return performance;
}
    

void print_course(struct course_t _course)
{
    char *text = grade_to_text(_course.passing_grade);
  printf("%s|%s|%d|%s\n" , _course.code, _course.name, _course.credit, text);
}

void print_student(struct student_t _student)
{
     printf("%s|%s|%s|%s\n", _student.id, _student.name, _student.year, _student.study_program);
}

void print_enrollment(struct enrollment_t _enrollment)
{
   char *text = grade_to_text(_enrollment.grade);
  float performance = calculate_performance(_enrollment.grade,_enrollment.course.credit);
  printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, text, performance);
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
    struct course_t crs;

  strcpy(crs.code,_code);
  strcpy(crs.name,_name);
  crs.credit = _credit;
  crs.passing_grade = _passing_grade;


    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
    struct student_t std;

    strcpy(std.id,_id);
  strcpy(std.name,_name);
  strcpy(std.year,_year);
  strcpy(std.study_program,_study_program);

    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester)
{
    struct enrollment_t emt;

    emt.course = _course;
  emt.student = _student;
  strcpy(emt.year, _year);
  emt.semester = _semester;
  emt.grade = GRADE_NONE;

    return emt;
}
