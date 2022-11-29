#include <stdio.h>

void FlushInput(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		/* skips */;
}

int main(){
	char name[6];
	int ret = scanf("%5s", name);
	if (ret != 1 || ret == EOF || feof(stdin) || ferror(stdin))
	{
		printf("Something went wrong\n");
		return -1;
	}
	printf("%s\n", name);

	char name2[21];
	printf("Enter your name: ");

	FlushInput(); // fseek(stdin, 0, SEEK_END); //< Not working

	if (NULL == fgets(name2, 21, stdin))
	{
		printf("Something wrong\n");
		return -2;
	}
	printf("%s\n", name2);
}
