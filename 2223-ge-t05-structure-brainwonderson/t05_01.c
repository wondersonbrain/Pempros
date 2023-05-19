//12S22016-Desri Stevie Natalie Dabukke
//12S22035-Brain Wonderson Sitorus
#include <stdio.h>
#include <string.h>

#define maksimal_kata 5
#define maksimal_panjang_kata 20
#define maksimal_panjang_arti 80

typedef struct {
    char kata[maksimal_panjang_kata];
    char arti[maksimal_panjang_arti];
} kata;

typedef enum {
    perintah,
    mencari,
    keluaran,
} Command;

int print_kata(kata kata) {
    printf("%s#%s\n", kata.kata, kata.arti);
    return 0;
}

int main() {
    kata kamus[maksimal_kata];
    int jumlah_kata = 0;
    Command command;
    char input[20];

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "register") == 0) {
            if (jumlah_kata >= maksimal_kata) {
                continue;
            }

            scanf("%s %[^\n]", kamus[jumlah_kata].kata, kamus[jumlah_kata].arti);
            jumlah_kata++;
        } else if (strcmp(input, "find") == 0) {
            char word_to_find[maksimal_panjang_kata];
            scanf("%s", word_to_find);

            for (int i = 0; i < jumlah_kata; i++) {
                if (strcmp(word_to_find, kamus[i].kata) == 0) {
                    print_kata(kamus[i]);
                    break;
                }
            }
        }

        command = strcmp(input, "---") == 0 ? keluaran : perintah;
        if (command == keluaran) {
            break;
        }
    }

    return 0;
}