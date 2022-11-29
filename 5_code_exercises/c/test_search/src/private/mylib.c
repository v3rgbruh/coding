#include "../public/mylib.h"

#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#endif

FILE* read(const char* pFileIn){ return fopen(pFileIn, "r"); }
FILE* write(const char* pFileOut){ return fopen(pFileOut, "w"); }
void close(FILE* pFile){
	fclose(pFile);
	*&pFile = NULL;
}

void cprint(const char* fmt, ...){
	va_list args;
	va_start(args, fmt);
#if defined(_WIN32) || defined(__CYGWIN__)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 206);
#elif defined(__linux__)
	printf(fmt, "\x1B[32m");
#endif

	vprintf(fmt, args);

#if defined(_WIN32) || defined(__CYGWIN__)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
#elif defined(__linux__)
	printf(fmt, "\033[0m");
#endif

	va_end(args);
}
