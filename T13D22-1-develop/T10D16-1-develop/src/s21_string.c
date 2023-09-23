#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *s) {
    size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int s21_strcmp(const char *p1, const char *p2) {
    const char *s1 = (const char *)p1;
    const char *s2 = (const char *)p2;
    char c1, c2;
    do {
        c1 = *s1++;
        c2 = *s2++;
        if (c1 == '\0') return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}

char *s21_strcpy(char *dst, const char *src) {
    int i = 0;
    while (*(src + i) != '\0') {
        *(dst + i) = *(src + i);
        i++;
    }
    return dst;
}

char *s21_strcat(char *dest, const char *src) {
    s21_strcpy(dest + s21_strlen(dest), src);
    return dest;
}
