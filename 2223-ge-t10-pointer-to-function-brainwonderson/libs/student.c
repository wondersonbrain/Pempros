#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

void assign_student(struct student_t *student, struct dorm_t *dorm)
{
    if (dorm->capacity > dorm->residents_num && student->gender == dorm->gender)
    {
        student->dorm = dorm;
        dorm->residents_num+= 1;
    }
}


void move_student(struct student_t *student, struct dorm_t *dorm, struct dorm_t *_dorm)
{
    if (dorm->capacity > dorm->residents_num && student->gender == dorm->gender)
    {
        student->dorm = dorm;
        dorm->residents_num += 1;
        _dorm->residents_num -= 1;
    }
    
}

void addStudent(struct student_t *murid, int *banyak_murid, char *input) {
    char *id = strtok(NULL, "#");
    char *name = strtok(NULL, "#");
    char *year = strtok(NULL, "#");
    char *gender = strtok(NULL, "#");

    strcpy(murid[*banyak_murid].id, id);
    strcpy(murid[*banyak_murid].name, name);
    strcpy(murid[*banyak_murid].year, year);

    if (strcmp(gender, "male") == 0) {
        murid[*banyak_murid].gender = 0;
    } else if (strcmp(gender, "female") == 0) {
        murid[*banyak_murid].gender = 1;
    }

    (*banyak_murid)++;
}

void printAllStudents(struct student_t *murid, int banyak_murid) {
    for (int i = 0; i < banyak_murid; i++) {
        if (murid[i].gender != 1) {
            printf("%s|%s|%s|male\n", murid[i].id, murid[i].name, murid[i].year);
        } else {
            printf("%s|%s|%s|female\n", murid[i].id, murid[i].name, murid[i].year);
        }
    }
}

void printAllStudentDetails(struct student_t *murid, int banyak_murid) {
    for (int i = 0; i < banyak_murid; i++) {
        if (murid[i].gender != 1) {
            printf("%s|%s|%s|male|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
        } else {
            printf("%s|%s|%s|female|unassigned\n", murid[i].id, murid[i].name, murid[i].year);
        }
    }
}