#include <stdio.h>



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
        int c = a + b;
        printf("%d ", c);
        int d = a - b;
        printf("%d ", d);
        int e = a * b;
        printf("%d ", e);
        if (b == 0) {
        printf("n/a\n");
        return 0;
    }
        int f = a / b;
        printf("%d\n", f);
    
    
    return 0;
}

