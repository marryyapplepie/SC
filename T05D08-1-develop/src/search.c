/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int *input(int *a, int *n, int *flag);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double meansq(int *a, int n);
double variance(double Msq, double M);
int check(int *a, int n, double mean, double variance);

void output_result(int value);

int main() {
    int n, data[NMAX];
    int flag = 0;
    if (input(data, &n, &flag) == &flag) {
        return 1;
    } else {
        output_result(check(data, n, mean(data, n), variance(mean(data, n), meansq(data, n))));
    }
    return 0;
}

int *input(int *a, int *n, int *flag) {
    // проверка n

    if (scanf("%d", n) != 1) {
        printf("n/a\n");
        return flag;
    }

    char t = getchar();
    if (t != '\0' && t != '\n') {
        printf("n/a\n");
        return flag;
    }

    if (*n > NMAX || *n <= 0) {
        printf("n/a\n");
        return flag;
    }

    // создаём указатель на int, по его адресу передаём а
    // далее арифметика указателей  -  p-a - количество ячеек между указателями
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            return flag;
        };

        char k = getchar();
        if ((k != ' ' && (p - a) != *n - 1)) {
            printf("n/a\n");
            return flag;
        }

        if ((p - a) == *n - 1 && (k != '\n')) {
            printf("n/a\n");
            return flag;
        }
        a[p - a] = *p;
    }
    return a;
}

double mean(int *a, int n) {
    double pos = (double)1 / n;
    double M = 0;
    for (int i = 0; i < n; i++) {
        M = M + pos * *(a + i);
    }
    return M;
}

double meansq(int *a, int n) {
    double pos = (double)1 / n;
    double Msq = 0;
    for (int i = 0; i < n; i++) {
        Msq = Msq + pos * *(a + i) * *(a + i);
    }
    return Msq;
}

double variance(double M, double Msq) {
    double var = Msq - M * M;
    return var;
}

int abs(int value) { return -value; }

void output_result(int value) { printf("%d", value); }

int check(int *a, int n, double mean, double variance) {
    int value = 0;
    int i = 0;
    while (i < n) {
        if ((*(a + i) % 2 == 0) && (*(a + i) >= mean) &&
            (*(a + i) <= (mean + 3 * sqrt(variance)) && (*(a + i) != 0))) {
            value = *(a + i);
            break;
        }
        i++;
    }
    if (value < 0) {
        value = abs(value);
    }
    return value;
}
