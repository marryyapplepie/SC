#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <string.h>

void input(char *filename, int *exit, int file_flag, int *empty);
int file_check(char *filename, int *exit, int *empty);
void file_open(char *filename);
void file_write(char *filename, char *str);
void file_empty(char *filename, int *empty);

#endif
