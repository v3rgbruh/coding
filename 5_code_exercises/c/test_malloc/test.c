#include <stdio.h>
#include <malloc.h>
#include <string.h>

char* CombineStrings(const char* p1, const char* p2){
	if (NULL == p1 || NULL == p2)
		return NULL;

	int len = strlen(p1) + strlen(p2);

	char* str = (char*)malloc(sizeof(char) * len + 1);
	if (NULL == str)
		return NULL;

	sprintf(str, "%s%s", p1, p2);

	return str;
}

int main(){
	const char* str1 = "This is a first string!";
	const char* str2 = " And this is a second";
	char* res = CombineStrings(str1, str2);
	if (NULL == res)
		return -1;

	printf("%s\n", res);
	free(res);
	res = NULL;

	return 0;
}
