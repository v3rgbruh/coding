#include <stdio.h>
#include <string.h>

int WordCount(const char* pStr, const char* pWord){
	if (NULL == pStr || NULL == pWord) return 0;
	int count = 0;

	char* pS = strstr(pStr, pWord);
	if (NULL != pS)
	{
		count++;
		while (*pS)
		{
			pS = strstr(pS + 1, pWord);
			if (NULL == pS)
				break;
			++count;
		}
	}

	return count;
}

int main(){
	char str[] = "Test stringis";
	printf("Trying to find letters 'i' inside %s\n", str);

	char* pI = strchr(str, 'i');
	if (NULL != pI)
	{
		int count = 1;
		printf("Found first at location %d\n", pI - str);
		pI++;
		while (*pI)
		{
			pI = strchr(pI, 'i');
			if (NULL == pI)
				break;
			++count;
			printf("Fount another 'i' at location %d\n", pI - str);
			pI++;
		}
		printf("Total of 'i' letters is %d\n", count);
	}

	printf("strstr total of 'i': %d\n", WordCount(str, "i"));
}
