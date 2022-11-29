#include "../public/mylib.h"
#include <string.h>

int main(const int argc, const char* argv[]){
	if (argc != 3) { printf("Usage: test <in_file> <search_string>\n"); return -1; }

	const char* filename = argv[1];
	FILE* file = read(filename);
	if (NULL == file) { printf("Failed to read %s\n", filename); return -2; }

	const char* string = argv[2];
	const int len = strlen(string);

	while (!feof(file)){
		int c = fgetc(file);
		if (EOF == c) break;

		if (c == string[0]){
			char word[1000];
			int idx = 0;
			do {
				word[idx++] = c;
				c = fgetc(file);
			} while (!feof(file) && idx < len && idx < 1000);
			word[idx] = '\0';
			if (0 == strcmp(word, string)){
				cprint("%s", word);
			} else
				printf("%s", word);
		}

		printf("%c", c);
	}
	close(file);

	return 0;
}
