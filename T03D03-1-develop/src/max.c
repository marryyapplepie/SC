#include <stdio.h>

int max (int a, int b) {
    int max = a;
    if (b > max) {
        max = b;
    }
    return max;
}

int main()
{
    int a;
    int b;
    if (scanf("%d %d", &a, &b) != 2) {
         printf("n/a\n");
         return 0;
    }
    char t = getchar();
    if(t != '\0' && t != '\n') {
        printf("n/a\n");
            return 0;
        }
    int maxNum = max(a, b);
    printf("%d\n", maxNum);
    
    
    return 0;
}
