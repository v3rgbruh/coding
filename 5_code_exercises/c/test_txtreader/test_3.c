#include <stdio.h>

int ThrowErr(int error, char filename[]){
	switch(error){
		case -1:
			printf("Usage: readfile <filename>\n");
			break;
		case -2:
			printf("Failed to open %s\n", filename);
			break;
	}
	return error;
}

int main(int argc, char* argv[]){
	if (argc != 2)
		return ThrowErr(-1, NULL);

	FILE* fp = fopen(argv[1], "r");
	if (NULL == fp)
		return ThrowErr(-2, argv[1]);

	char buff[1000];
	int index = 0;

	while (!feof(fp)){
		if (NULL == fgets(buff, sizeof(buff)/sizeof(buff[0]), fp))
			break;
		printf("[%d]-%s", index++, buff);
	}

	fclose(fp);
	fp = NULL;

	return 0;
}
