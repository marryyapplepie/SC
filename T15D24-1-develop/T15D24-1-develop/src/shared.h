#ifndef SHARED_H
#define SHARED_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct modules {
    int id;
    char name[30];
    int mem_num;
    int num;
    int delete_flag;
};
struct level {
    int mem_lev;
    int data_num;
    int protect_flag;
};
struct status_event {
    int id_event;
    int id_module;
    int new_stat;
    char date[10 + 1];
    char time[8 + 1];
};

int insert(char *filename, struct modules *p);
int load(char *filename);
void read(struct modules *door);
int select(char *filename);
int update(char *filename);

#endif
