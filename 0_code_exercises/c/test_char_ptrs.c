#include <stdio.h>

void printChars(char* p, int size){
	if (NULL == p) return;

	for (int i = 0; i < size; ++i){
		printf("%c\n", *p);
		p++;
	}
}

int main(){
	char s[] = "Hello world!";
	
	printChars(&s[0], 5);
}
