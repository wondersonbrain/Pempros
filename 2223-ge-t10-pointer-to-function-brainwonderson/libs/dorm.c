#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

void addDorm(struct dorm_t *asrama, int *banyak_asrama, char *input) {
    char *name = strtok(NULL, "#");
    char *capacity = strtok(NULL, "#");
    char *gender = strtok(NULL, "#");

    strcpy(asrama[*banyak_asrama].name, name);
    asrama[*banyak_asrama].capacity = atoi(capacity);

    if (strcmp(gender, "male") == 0) {
        asrama[*banyak_asrama].gender = 0;
    } else if (strcmp(gender, "female") == 0) {
        asrama[*banyak_asrama].gender = 1;
    }

    asrama[*banyak_asrama].residents_num = 0;
    (*banyak_asrama)++;
}

void printAllDormDetails(struct dorm_t *asrama, int banyak_asrama) {
    for (int i = 0; i < banyak_asrama; i++) {
        if (asrama[i].gender != 1) {
            printf("%s|%d|male|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
        } else {
            printf("%s|%d|female|%d\n", asrama[i].name, asrama[i].capacity, asrama[i].residents_num);
        }
    }
}

void printAllDorms(struct dorm_t *asrama, int banyak_asrama) {
    for (int i = 0; i < banyak_asrama; i++) {
        if (asrama[i].gender != 1) {
            printf("%s|%d|male\n", asrama[i].name, asrama[i].capacity);
        } else {
            printf("%s|%d|female\n", asrama[i].name, asrama[i].capacity);
        }
    }
}