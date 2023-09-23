#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_srting_test.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();

int main() {
#ifdef Q1
    s21_strlen_test();
#endif
#ifdef Q2
    s21_strcmp_test();
#endif
#ifdef Q3
    s21_strcpy_test();
#endif
#ifdef Q4
    s21_strcat_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char s_1[] = "Hello ";
    printf("%s", s_1);
    size_t result_1 = s21_strlen(s_1);
    printf("%ld ", result_1);
    if (result_1 == 6)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char s_2[] = "\0";
    printf("%s", s_2);
    size_t result_2 = s21_strlen(s_2);
    printf("%ld ", result_2);
    if (result_2 == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char s_3[] = "Heyyy\t s";
    printf("%s ", s_3);
    size_t result_3 = s21_strlen(s_3);
    printf("%ld ", result_3);
    if (result_3 == 8)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcmp_test() {
    char s_compare_1[] = "abc";
    char s_compare_2[] = "acb";
    printf("%s %s ", s_compare_1, s_compare_2);
    int result_1 = s21_strcmp(s_compare_1, s_compare_2);
    printf("%d ", result_1);
    if (result_1 == -1)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char s_compare_3[] = "abc";
    char s_compare_4[] = "abc";
    printf("%s %s ", s_compare_3, s_compare_4);
    int result_2 = s21_strcmp(s_compare_3, s_compare_4);
    printf("%d ", result_2);
    if (result_2 == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char s_compare_5[] = "\0";
    char s_compare_6[] = "abc";
    printf("%s %s ", s_compare_5, s_compare_6);
    int result_3 = s21_strcmp(s_compare_5, s_compare_6);
    printf("%d ", result_3);
    if (result_3 == -97)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcpy_test() {
    char src_1[] = "abc";
    char dest_1[4];
    printf("%s ", src_1);
    s21_strcpy(dest_1, src_1);
    printf("%s ", dest_1);
    if (s21_strcmp(dest_1, src_1) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char src_2[] = "\0";
    char dest_2[1];
    printf("%s ", src_2);
    s21_strcpy(dest_2, src_2);
    printf("%s ", dest_2);
    if (s21_strcmp(dest_2, src_2) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char src_3[] = "I want to eat(\t";
    char dest_3[17];
    printf("%s ", src_3);
    s21_strcpy(dest_3, src_3);
    printf("%s ", dest_3);
    if (s21_strcmp(dest_3, src_3) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcat_test() {
    char src_1[] = "hello, ";
    char dest_1[] = "world";
    char expected_1[] = "hello, world";
    printf("%s%s ", src_1, dest_1);
    char *result_1 = s21_strcat(src_1, dest_1);
    printf("%s ", result_1);
    if (s21_strcmp(expected_1, result_1) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char src_2[] = "";
    char dest_2[] = "world";
    char expected_2[] = "world";
    printf("%s ", expected_2);
    printf("%s%s ", src_2, dest_2);
    char *result_2 = s21_strcat(src_2, dest_2);
    printf("%s ", result_2);
    if (s21_strcmp(expected_2, result_2) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char src_3[] = "\0";
    char dest_3[] = "\0";
    char expected_3[] = "\0";
    printf("%s%s ", src_3, dest_3);
    char *result_3 = s21_strcat(src_3, dest_3);
    printf("%s ", result_3);
    if (s21_strcmp(expected_3, result_3) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
