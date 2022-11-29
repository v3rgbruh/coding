#include <stdio.h>
#include <stdlib.h>

int fib(const int n, int** arr){
  if (n < 2){
    *arr[n] = n;
    return n;
  }

  return fib(n-1, arr) + fib(n-2, arr);
}

int main(const int argc, const char* argv[]){
  int n = atoi(argv[1]);
  int* numbers[n];

  printf("%d\n", fib(n, numbers));

  return 0;
}
