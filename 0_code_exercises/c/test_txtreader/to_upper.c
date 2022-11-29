#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	if (argc != 3){
		printf("Usage: to_upper <in_file> <out_file>");
		return -1;
	}
	char* pInFile = argv[1];
	char* pOutFile = argv[2];

	FILE* fpR = fopen(pInFile, "r");
	if (NULL == fpR){
		printf("Failed to open %s\n", pInFile);
		return -2;
	}
	FILE* fpW = fopen(pOutFile, "w");
	if (NULL == fpW){
		printf("Failed to write to %s\n", pOutFile);
		fclose(fpR);
		return -3;
	}

	while (!feof(fpR)){
		int c = fgetc(fpR);
		if (EOF != c)
			fputc(toupper(c), fpW);
	}

	fclose(fpR);
	fclose(fpW);

	return 0;
}
