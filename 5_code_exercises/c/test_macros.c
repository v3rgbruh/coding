#include <stdio.h>

#if 0
#define HELLO(x) #x ", hi!"
#define CONCAT(a, b) a##b
#define TEST_STR(args...) printf((#args == "MON, DAY") ? "YA\n" : "NO\n")
#endif

#define STRINGIZE(a) #a
#define TEST_STR(x, y) STRINGIZE(x ## y)

int main(){
	// printf("%s\n", HELLO(John));
	// printf("'%d'+'%d'='%d'\n", 123, 456, CONCAT(123, 456));
	// printf("%s\n", TEST_STR(MON, DAY));
	printf("%s\n", TEST_STR(MON, DAY));
	return 0;
}
