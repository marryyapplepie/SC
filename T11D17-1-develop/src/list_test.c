#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

void test_add();
void test_remove();

int main() {
#ifdef TEST
    test_add();
    test_remove();
#endif
}

void test_add() {
    struct node* root = init(&(struct door){.id = 0, .status = 0});
    root = add_door(root, &(struct door){.id = 1, .status = 0});
    root = add_door(root, &(struct door){.id = 2, .status = 0});
    root = add_door(root, &(struct door){.id = 3, .status = 0});
    if (root->door->id == 3 && root->door->status == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destroy(root);
}

void test_remove() {
    struct node* root = init(&(struct door){.id = 0, .status = 0});
    struct node* root_1 = NULL;
    root_1 = add_door(root, &(struct door){.id = 1, .status = 0});
    if (find_door(root_1->door->id, root)) {
        root = remove_door(root_1, root);
        if (root->door->id == 0 && root->door->status == 0)
            printf("SUCCESS\n");
        else
            printf("FAIL\n");

    } else {
        printf("FAIL\n");
    }
    free(root);
}
