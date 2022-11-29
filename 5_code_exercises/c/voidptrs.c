#include <stdio.h>

enum ValueType {
	INT,
	FLOAT,
	STRING,
	CHAR
};

void PrintValue(void* p, enum ValueType type){
	switch(type){
		case INT:
			printf("Integer: %d\n", *(int*)p);
			break;
		case FLOAT:
			printf("Float: %f\n", *(float*)p);
			break;
		case CHAR:
			printf("Char: %c\n", *(char*)p);
			break;
		case STRING:
			printf("String: %s\n", (char*)p);
			break;
		default:
			printf("Unexpected ValueType used\n");
			break;
	}
}

void main(){
	int a=100;
	float pi=3.14f;
	char b='b';

	PrintValue(&a, INT);
	PrintValue(&pi, FLOAT);
	PrintValue(&b, CHAR);
	PrintValue("Hello from void ptr", STRING);
}
