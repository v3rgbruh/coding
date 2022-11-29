#include <stdio.h>

void GetMinMax(int arr[], int size, int* pMin, int* pMax){
	int min, max;
	max = min = arr[0];
	
	for (int i = 1; i < size; ++i){
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	
	*pMin = min;
	*pMax = max;
}

void main(){
	int array[] = {-5, -10, 0, 99, 44, 3};
	int size = sizeof(array) / sizeof(array[0]);
	int max = 0, min = 0;
	
	GetMinMax(array, size, &min, &max);
	printf("Max of array is %d\r\nMin of array is %d\r\n", max, min);
}
