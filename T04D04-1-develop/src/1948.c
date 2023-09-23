#include <stdio.h>

//целочисленное деление
//a - делимое
//b - делитель

 int sub(int a, int b) {
    int num;
    int dev;
    if (a > 0) {
        num = a;
    } else {
        num = -a;
    }

    if (b > 0) {
        dev = b;
    } else {
        dev = -b;
    }
    int counter = 0;

    while (num > 0) {

        if((num - dev) >= 0) {
            counter++;

        }
        num = num - dev;
    }

    if (a * b > 0) {
        return counter;
    } else return -counter;

} 

//остаток от деления
//a - делимое
//b - делитель

int res(int a, int b) {
    int num;
    int dev;
    if (a >= 0) {
        num = a;
    } else {
        num = -a;
    }

    if (b >= 0) {
        dev = b;
    } else {
        dev = -b;
    }
    int counter = 0;

    while (num > 0) {

        if((num - dev)  < dev) {
            counter = num - dev;

        }
        num = num - dev;
    }

    if (a * b > 0) {
        return counter;
    } else return -counter;

}

//проверка на простоту
//a - потенциально простое число
// 0 - число не простое 
// 1 - число простое

int prime(int a) {
    int num = a;
    for (int i = 2; i <= sub(num, 2); i++) {
        if(res(a, i) == 0) {
            return 0;
        }
    }
    return 1;
}



int main() {

    int num;

    if (scanf("%d", &num) != 1) {
            printf("n/a\n");
            return 0;
    }
    char t = getchar();
    if(t != '\0' && t != '\n') {
        printf("n/a\n");
        return 0;
    }
    
    int max = 0;
    int counter = 0;


    if (num >= 0) {
        counter = num;
    } else {
        counter = -num;
    }
    for (int i = 2; i <= sub(counter, 2); i++) {
        if(prime(i) == 0) {
            continue;;
        }
        if (res(num, i) != 0) {
            continue;
        } 
        if (res(num, i) == 0) {
            if(i > max) {
                max = i;
            }
        }

    }

    if (max == 0) {
        printf("n/a\n");
        return 0;
    }

    printf("%d\n", max);
    return 0;

}