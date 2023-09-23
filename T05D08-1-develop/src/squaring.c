#include <stdio.h>
#define NMAX 10

int *input(int *a, int *n, int *flag);
void output(int *a, int n);
int *squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int flag;
    if (input(data, &n, &flag) == &flag) {
        return 1;
    } else {
        squaring(data, n);
        output(data, n);
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

int *squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) = *(a + i) * *(a + i);
    }
    return a;
}
