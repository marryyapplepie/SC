#include <stdio.h>
#define NMAX 10

int *input(int *a, int *n, int *flag);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double meansq(int *a, int n);
double variance(double Msq, double M);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int flag = 0;
    if (input(data, &n, &flag) == &flag) {
        return 1;
    } else {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(mean(data, n), meansq(data, n)));
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
    // int i = 0;

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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
}

int max(int *a, int n) {
    int max = *a;

    for (int i = 1; i < n; i++) {
        if (*(a + i) > max) {
            max = *(a + i);
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;

    for (int i = 1; i < n; i++) {
        if (*(a + i) < min) {
            min = *(a + i);
        }
    }
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
