// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <l>\n", argv[0]);
        exit(1);
    }

    int l = atoi(argv[1]);
    char input[MAX_LEN + 1];
    char output[MAX_LEN + 1];
    int len;

    while (fgets(input, MAX_LEN + 1, stdin) != NULL) {
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }
        if (len > 0 && input[len - 1] == '\r') {
            input[len - 1] = '\0';
            len--;
        }
        if (len == 0) {
            printf("\n");
            continue;
        }
        int num_boxes = len / l;
        if (len % l > 0) {
            num_boxes++;
        }
        for (int i = 0; i < num_boxes; i++) {
            int start = i * l;
            int end = start + l;
            if (end > len) {
                end = len;
            }
            strncpy(output, &input[start], end - start);
            output[end - start] = '\0';
            printf("%s", output);
            if (end - start < l) {
                for (int j = 0; j < l - (end - start); j++) {
                    printf("#");
                }
            }
            if (i < num_boxes - 1) {
                printf("\n");
            }
        }
        if (len % l == 0) {
            printf("#\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}