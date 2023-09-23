
#include <stdio.h>
#define NMAX 10

int *input(int *buffer, int *length, int *flag);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int *find_numbers(int *buffer, int length, int number, int *numbers);
int lengthOfArray(int *buffer, int length, int number);

int main() {
    int length, data[NMAX], numbers[NMAX];
    int flag = 0;
    if (input(data, &length, &flag) == &flag) {
        return 1;
    } else {
        int number = sum_numbers(data, length);
        if (number == 0) {
            printf("n/a\n");
            return 0;
        } else {
            printf("%d\n", number);
            find_numbers(data, length, number, numbers);
            int newLength = lengthOfArray(data, length, number);
            if (newLength == 0) {
                printf("n/a\n");
                return 0;
            }
            output(numbers, newLength);
        }
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

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i] != 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

int lengthOfArray(int *buffer, int length, int number) {
    int counter = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            counter++;
        }
    }
    return counter;
}

int *find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            *(numbers + j) = buffer[i];
            j++;
        }
    }
    return numbers;
}
