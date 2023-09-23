#include <stdio.h>

#include "shared.h"

void menu_main();
void menu_file_select();
void menu_file_insert();
void menu_file_update();
// void menu_file_delete();

int main() {
    /* menu

    Please choose one operation:
            1. SELECT
            2. INSERT
            3. UPDATE
            4. DELETE
            5. Get all active additional modules (last module status is 1)
            6. Delete modules by ids
            7. Set protected mode for module by id
            8. Move module by id to specified memory level and cell
            9. Set protection flag of the specified memory level
    */

    menu_main();
}

void menu_main() {
    while (1) {
        printf("Please choose one operation:\n");
        printf("1. SELECT\n");
        printf("2. INSERT\n");
        printf("3. UPDATE\n");
        printf("4. DELETE\n");
        printf("5. Get all active additional modules (last module status is 1\n");
        printf("6. Delete modules by ids\n");
        printf("7. Set protected mode for module by id\n");
        printf("8. Move module by id to specified memory level and cell\n");
        printf("9. Set protection flag of the specified memory level\n");
        int choice;
        scanf("%d", &choice);
        if (choice == -1) break;

        switch (choice) {
            case 1:
                menu_file_select();
                break;
            case 2:
                menu_file_insert();
                break;
            case 3:
                menu_file_update();
                break;
            case 4:
                // menu_file_delete();
                printf("оно не работает:(\n");
                break;
            case 5:
                printf("и оно тоже:(\n");
                break;
            case 6:
                printf("а начиная с этого я  даже не пыталась))\n");
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                break;
        }
    }

    /*

Please choose a table:
        1. Modules
        2. Levels
        3. Status events
*/
}

void menu_file_select() {
    printf("Please choose a table:\n");
    printf("1. Modules\n");
    printf("2. Levels\n");
    printf("3. Status events\n");
    int choice;
    scanf("%d", &choice);
    char filename_1[] = "./../materials/master_modules.db";
    char filename_2[] = "./../materials/master_levels.db";
    char filename_3[] = "./../materials/master_status_events.db";

    switch (choice) {
        case 1:
            select(filename_1);
            break;
        case 2:
            select(filename_2);
            // filename = L;
            break;
        case 3:
            select(filename_3);
            // filename = S;
            break;
        default:
            break;
    }
}

void menu_file_insert() {
    printf("Please choose a table:\n");
    printf("1. Modules\n");
    printf("2. Levels\n");
    printf("3. Status events\n");
    int choice;
    scanf("%d", &choice);
    char filename_1[] = "./../materials/master_modules.db";
    char filename_2[] = "./../materials/master_levels.db";
    char filename_3[] = "./../materials/master_status_events.db";
    struct modules door;
    // struct level level;
    // struct status_event event;

    switch (choice) {
        case 1:
            read(&door);
            insert(filename_1, &door);

            break;
        case 2:
            insert(filename_2, &door);
            break;
        case 3:
            insert(filename_3, &door);
            break;
        default:
            break;
    }
}

void menu_file_update() {
    printf("Please choose a table:\n");
    printf("1. Modules\n");
    printf("2. Levels\n");
    printf("3. Status events\n");
    int choice;
    scanf("%d", &choice);
    char filename_1[] = "./../materials/master_modules.db";
    char filename_2[] = "./../materials/master_levels.db";
    char filename_3[] = "./../materials/master_status_events.db";

    switch (choice) {
        case 1:
            update(filename_1);
            break;
        case 2:
            update(filename_2);
            break;
        case 3:
            update(filename_3);
            break;
        default:
            break;
    }
}
/*
void menu_file_delete() {
    printf("Please choose a table:\n");
    printf("1. Modules\n");
    printf("2. Levels\n");
    printf("3. Status events\n");
    int choice;
    scanf("%d", &choice);
    char filename_1[] = "./../materials/master_modules.db";
    char filename_2[] = "./../materials/master_levels.db";
    char filename_3[] = "./../materials/master_status_events.db";

    switch (choice) {
        case 1:
            delete (filename_1);
            break;
        case 2:
            delete (filename_2);
            break;
        case 3:
            delete (filename_3);
            break;
        default:
            break;
    }
}*/
