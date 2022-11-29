#include <stdio.h>

void RemoveVowels(char* pSrc, char* pDest, int size){
	int skipped = 0;

	for (int i = 0; i < size; ++i){
		switch(pSrc[i]){
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'U':
			case 'u':
			case 'O':
			case 'o':
			case 'Y':
			case 'y':
				++skipped;
				continue;
			default:
				pDest[i-skipped] = pSrc[i];
		}
	}
}

void main(){
	char str[] = "Hello, world! What a beautiful duwang";
	int size = sizeof(str)/sizeof(str[0]);
	char dest[size];
	RemoveVowels(str, dest, size);
	printf("%s\n", dest);
}
