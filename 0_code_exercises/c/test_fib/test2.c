#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char* argv[]){
  int n = atoi(argv[1]);
  int numbers[n];

  for (int i = 0; i <= n; i++){
    if (i < 2){
      numbers[i] = i;
      continue;
    }

    numbers[i] = numbers[i-2] + numbers[i-1];
  }
  printf("%d\n", numbers[n]);

  return 0;
}
