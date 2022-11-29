#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int fib(const int n, int memo[]){	
	if (0 != memo[n]) return memo[n];
	if (n < 2) return 1;

	return memo[n] = (fib(n-2, memo) + fib(n-1, memo));
}

int main(const int argc, const char* argv[]){
	if (argc != 2) { printf("%s\n", "Usage: test <count>\n"); return -1; }

	int n = atoi(argv[1]) + 1;
	int empty[n-1];

	memset(empty, NULL, sizeof(empty));
	printf("%d\n", empty[n-1]);
	printf("%d\n", fib(n, empty));

	return 0;
}
