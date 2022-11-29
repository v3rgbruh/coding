#include <stdio.h>
#include <string.h> // for strcmp
#include <stdlib.h> // for atoi

int main(int argc, char* argv[]){
	if (argc < 3){
		printf("Usage: calc [sum | avg] 1 2 3\r\n");
		return -1;
	}
	
	const char* arg = argv[1];

	if (strcasecmp(arg, "sum") == 0){
		int sum = 0;
		
		for (int i = 2; i < argc; ++i)			
			sum += atoi(argv[i]);

		printf("trying to sum up, sum is: %d\r\n", sum);
	} else if (strcasecmp(arg, "avg") == 0){
		int sum = 0;

		for (int i = 2; i < argc; ++i)
			sum += atoi(argv[i]);

		printf("trying to get avg, avg is: %f\r\n", (float)sum / (argc - 2));
	} else {
		printf("Usage: calc [sum | avg] 1 2 3\r\n");
		return -2;
	}

	return 0;
}
