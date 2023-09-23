#include <stdio.h>
#include <math.h>
 
int main() {
    float x;
    float y;
    if (scanf("%f %f", &x, &y) != 2) {
         printf("n/a\n");
         return 0;
    }
    char t = getchar();
    if(t != '\0' && t != '\n') {
        printf("n/a\n");      
        return 0; 
    }
    if ((x < 5 && x > -5) && (y < 5 && y > -5)) {
        printf("GOTCHA\n");
        return 0;
    
    }
    else {
        printf("MISS\n");
        return 0;
    }

}