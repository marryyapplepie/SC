#include <stdio.h>
#include <math.h>
 
int main() {
    float x;
    if (scanf("%f", &x) != 1) {
         printf("n/a\n");
         return 0;
    }
    char t = getchar();
    if(t != '\0' && t != '\n') {
        printf("n/a\n");
            
    return 0; 
}
    if (x == 0) {
        printf("n/a\n");
        return 0;
    }
double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, (float) 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * pow((10 + x), ((float)2/x)) - 1.01;
printf("%lf\n", y);


}