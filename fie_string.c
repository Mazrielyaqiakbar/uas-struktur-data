#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char filename[100], wordToFind[50], buffer[BUFFER_SIZE];
    FILE *fp;
    int found = 0;

    printf("Masukkan nama file: ");
    scanf("%s", filename);

    printf("Masukkan kata yang ingin dicari: ");
    scanf("%s", wordToFind);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        char *token = strtok(buffer, " \t\n");
        while (token != NULL) {
            if (strcmp(token, wordToFind) == 0) {
                found = 1;
                break;
            }
            token = strtok(NULL, " \t\n");
        }
        if (found) {
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Kata '%s' ditemukan dalam file.\n", wordToFind);
    } else {
        printf("Kata '%s' tidak ditemukan dalam file.\n", wordToFind);
    }

    return 0;
}