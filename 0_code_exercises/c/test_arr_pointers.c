#include <stdio.h>

void main(){
	int arr[] = {1,2,3,4,9,5,6,7};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; ++i){
		printf("[%p]=%d\n", &arr[i], arr[i]);
	}
	int* p = &arr[size-4];
	printf("%d\n", *p);
	++p;
	printf("%d\n", *p);
}
