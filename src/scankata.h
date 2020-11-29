#ifndef scankata_H
#define scankata_H

#include "mesinkata.h"

typedef char str[50];

typedef str totalstr[1000];

typedef struct
{
	int Number;
	char* String;
}NumberAndString;

#define Int(N)	(N).Number
#define Str(N)	(N).String

char* ScanKata();

int ScanAngka();

NumberAndString ScanNumberAndString();

#endif