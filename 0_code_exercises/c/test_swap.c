#include <stdio.h>

void swap(short* a, short* b)
{
	short temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	short a = 10;
	short b = 20;

	printf("a is %d\n", a);
	printf("b is %d\n", b);

	swap(&a, &b);

	printf("a now is %d\n", a);
	printf("b now is %d\n", b);
}
