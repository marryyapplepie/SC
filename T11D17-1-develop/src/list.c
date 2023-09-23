#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* n = malloc(sizeof(struct node));
    n->door = door;
    n->next = NULL;
    return n;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* newElem = init(door);
    if (elem->next == NULL) {
        elem->next = newElem;
    } else {
        struct node* tmp_next = elem->next;
        elem->next = newElem;
        newElem->next = tmp_next;
    }

    return newElem;
}

struct node* find_door(int door_id, struct node* root) {
    // struct node* tmp_next = root->next;
    while (root) {
        if (root->door->id == door_id) return root;
        root = root->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* tmp_next = NULL;
    if (root->door != elem->door) {
        tmp_next = root;
    } else {
        tmp_next = root->next;
    }
    while (root) {
        if (root->door == elem->door && (root->next)) {
            root->next = elem->next;
            free(root);
        }
        if (root->door == elem->door && !(root->next)) {
            free(root);
            break;
        }
        root = root->next;
    }
    return tmp_next;
}

void destroy(struct node* root) {
    while (root) {
        struct node* current = root;
        root = root->next;
        free(current);
    }
}
