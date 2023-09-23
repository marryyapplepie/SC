#define MAX_LENGTH 100
#include <stdio.h>
#include <string.h>

#include "menu.h"

int main() {
    char filename[MAX_LENGTH];
    char str[MAX_LENGTH];
    int exit = 0;
    int choose;
    int empty = 0;
    char tmp;
    int file_flag = 0;
    while (1) {
        if (scanf("%d%c", &choose, &tmp) != 2 || (tmp != '\n')) {
            printf("n/a\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (choose == -1) {
            break;
        }
        switch (choose) {
            case 1:
                file_flag = 1;
                input(filename, &exit, file_flag, &empty);
                if (exit == 1 || empty == 1) {
                    printf("n/a\n");
                    break;
                } else {
                    file_open(filename);
                    break;
                }
            case 2:
                if (file_flag == 1) {
                    file_flag = 0;
                    input(str, &exit, file_flag, &empty);
                    // неважно, пуст ли файл
                    if (exit == 0) {
                        file_write(filename, str);
                        file_open(filename);
                    } else
                        // если не сущетсвует
                        printf("n/a\n");
                } else {
                    // если не заходили в 1
                    input(str, &exit, file_flag, &empty);
                    printf("n/a\n");
                }
                file_flag = 1;
                break;

            default:
                printf("n/a\n");
                choose = 1;
                break;
        }
    }
    return 0;
}
