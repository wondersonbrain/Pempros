#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_block(int l, char *s) {
    int n = (strlen(s)-2) / l + ((strlen(s)-2) % l != 0);
    int i, j;
    for ( i =0; i <n; i++){
        for (j=0; j<l; j++){
            if (i * l + j < (strlen(s)-2)){
                printf("%c",s[i * l + j]);
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void transpose_block(int l, char *s) {
    int n = (strlen(s)-2) / l + ((strlen(s)-2) % l != 0);
    char kata [n][l];
    int i, j, k=0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < l; j++) {
            if (k < (strlen(s)-2)) {
                kata[i][j] = s[k++];
            } else {
                kata [i][j] = '#';
            }
        }
    }
    for (j=0; j < l; j++){
        for (i = 0; i < n; i++){
            printf("%c", kata[i][j]);
        }
    }  
    printf("\n");
}

int main(int argc, char *argv[]) {
    int l = atoi(argv[1]);
    char s[120];
    fgets(s, sizeof(s), stdin);

    print_block(l, s);
    transpose_block(l, s);
}