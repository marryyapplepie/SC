#include <stdio.h>

int fibonacci(int N) {
  if (N == 1 || N == 2)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
  int num;
  int fib;
  if (scanf("%d", &num) != 1) {
    printf("n/a\n");
    return 0;
  }
  char t = getchar();
  if (t != '\0' && t != '\n') {
    printf("n/a\n");
    return 0;
  }

  for (int i = 1; i <= num; i++) {
    fib = fibonacci(num);
  }
  printf("%d\n", fib);
  return 0;
}