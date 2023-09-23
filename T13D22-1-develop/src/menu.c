#include "menu.h"

#include <stdio.h>
#include <string.h>

// если файл существует, exit = 0, иначе 1
// если файл непустой, empty = 0, иначе 1

int file_check(char *filename, int *exit, int *empty) {
    // FILE *file = fopen(filename, "r");
    if (fopen(filename, "r")) {
        file_empty(filename, empty);
        *exit = 0;
    } else
        *exit = 1;
    return *empty;
}

void file_empty(char *filename, int *empty) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);
    if (size == 0)
        *empty = 1;
    else
        *empty = 0;
}

void input(char *filename, int *exit, int file_flag, int *empty) {
    fgets(filename, 100, stdin);
    filename[strlen(filename) - 1] = '\0';
    if (file_flag == 1) file_check(filename, exit, empty);
}

void file_open(char *filename) {
    char arr[1000];
    FILE *file;
    int i = 0;
    file = fopen(filename, "r");
    while ((arr[i] = fgetc(file)) != EOF) {
        if (arr[i] == '\n') {
            arr[i] = '\0';
            printf("%s\n", arr);
            i = 0;
        } else
            i++;
    }
    arr[i] = '\0';
    printf("%s\n", arr);

    fclose(file);
}

void file_write(char *filename, char *str) {
    FILE *file;
    file = fopen(filename, "a+");
    fseek(file, 0, SEEK_END);
    fputs(str, file);
    fclose(file);
}
