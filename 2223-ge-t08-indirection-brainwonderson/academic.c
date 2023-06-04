// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade){
char *text = malloc(8);
  text[0] = '\0';
  switch(_grade){
    case GRADE_A: strcpy(text, "A");
    break;
    case GRADE_AB: strcpy(text, "AB");
    break;
    case GRADE_B: strcpy(text, "B");
    break;
    case GRADE_BC: strcpy(text, "BC");
    break;
    case GRADE_C: strcpy(text, "C");
    break;
    case GRADE_D: strcpy(text, "D");
    break;
    case GRADE_E: strcpy(text, "E");
    break;
    case GRADE_T: strcpy(text, "T");
    break;
    default: strcpy(text, "None");
  }

  return text; 
  }

   float calculate_performance(enum grade_t _grade, unsigned short _credit) {

  float performance='\0';
  switch(_grade){
    case GRADE_A: performance =4.0 * _credit;
    break;
    case GRADE_AB: performance = 3.5 * _credit;
    break;
    case GRADE_B: performance = 3.0* _credit;
    break;
    case GRADE_BC: performance = 2.5* _credit;
    break;
    case GRADE_C: performance = 2.0* _credit;
    break;
    case GRADE_D: performance = 1.0* _credit;
    break;
    case GRADE_E: performance = 0.0;
    break;
    case GRADE_T: performance = 0.0;
    break;
    default: performance = 0.0;
    }
  return performance;
  }

void print_course(struct course_t _course) {
     char *text = grade_to_text(_course.passing_grade);
  printf("%s|%s|%d|%s\n" , _course.code, _course.name, _course.credit, grade_to_text(_course.passing_grade));
}

void print_student(struct student_t _student) {
         printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
}


void print_enrollment(struct enrollment_t _enrollment) {
     char *text = grade_to_text(_enrollment.grade);
  float calculate = calculate_performance(_enrollment.grade,_enrollment.course.credit);
  printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, text, calculate);
}

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size) {
 int a;
 for(a = 0; a < _enrollment_size; a++){        
    char *text = grade_to_text(_enrollments[a].grade);
    float performance = calculate_performance(_enrollments[a].grade,_enrollments[a].course.credit);
    printf("%s|%s|%s|%.2f\n", _enrollments[a].course.code,_enrollments[a].student.id,
    text, performance);
}     
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
  std.gpa=0;
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

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)
{
    int a;
int creditt = 0;
float Tot_performance = GRADE_NONE;
a = 0;
while(a < _enrollment_size){
    Tot_performance += calculate_performance(_enrollments[a].grade,_enrollments[a].course.credit);
    creditt += _enrollments[a].course.credit;
    a++;
}

      _student -> gpa = Tot_performance / creditt;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{
   int a = 0;
while(a < _enrollment_size) {
    if(strcmp(_enrollments[a].course.code, _course.code) == 0 && strcmp(_enrollments[a].student.id, _student.id) == 0){
      _enrollments[a].grade = _grade;
    }
    a++;
}

}