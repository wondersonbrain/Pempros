#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) {
    int looping = 0;
    char command[100];
    struct student_t *murid = malloc(100 * sizeof(struct student_t));
    struct dorm_t *asrama = malloc(100 * sizeof(struct dorm_t));
    int banyak_murid = 0;
    int banyak_asrama = 0;

    while (looping != 1) {
        command[0] = '\0';
        short k = 0;
        while (1 == 1) {
            char i = getchar();
            if (i == '\n') {
                break;
            }
            if (i == '\r') {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';
        }

        char *input = strtok(command, "#");

        if (strcmp(input, "student-add") == 0) {
            addStudent(murid, &banyak_murid, input);
        } else if (strcmp(input, "student-print-all") == 0) {
            printAllStudents(murid, banyak_murid);
        } else if (strcmp(input, "student-print-all-detail") == 0) {
            printAllStudentDetails(murid, banyak_murid);
        } else if (strcmp(input, "dorm-add") == 0) {
            addDorm(asrama, &banyak_asrama, input);
        } else if (strcmp(input, "dorm-print-all-detail") == 0) {
            printAllDormDetails(asrama, banyak_asrama);
        } else if (strcmp(input, "dorm-print-all") == 0) {
            printAllDorms(asrama, banyak_asrama);
        } else if (strcmp(input, "---") == 0) {
            looping = 1;
        }
    }

    free(murid);
    free(asrama);

    return 0;
}
