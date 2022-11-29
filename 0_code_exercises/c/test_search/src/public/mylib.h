#pragma once
#include <stdio.h>
#include <stdarg.h>

FILE* read(const char* pFileIn);
FILE* write(const char* pFileOut);
void close(FILE* pFile);

void print(const char* fmt, ...);
void cprint(const char* fmt, ...);
