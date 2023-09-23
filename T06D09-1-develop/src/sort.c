
#include <stdio.h>
#define NMAX 10

void swap(int *xp, int *yp);
void bubbleSort(int *arr);
void output(int *a);
int *input(int *a, int *flag);

int main() {
    int data[NMAX];
    int flag = 0;
    if (input(data, &flag) == &flag) {
        return 1;
    } else {
        bubbleSort(data);
        output(data);
    }
    return 0;
}
//готово
int *input(int *a, int *flag) {
    //создаём указатель на int, по его адресу передаём а
    //далее арифметика указателей  -  p-a - количество ячеек между указателями
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            return flag;
        };

        char k = getchar();
        if ((k != ' ' && (p - a) != NMAX - 1)) {
            printf("n/a\n");
            return flag;
        }

        if ((p - a) == NMAX - 1 && (k != '\n')) {
            printf("n/a\n");
            return flag;
        }

        a[p - a] = *p;
    }

    return a;
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", *(a + i));
    }
}

//готово
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int *arr) {
    int i, j, swapped;
    for (i = 0; i < NMAX - 1; i++) {
        swapped = 1;
        for (j = 0; j < NMAX - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 0;
            }
        }
        if (swapped == 1) break;
    }
}