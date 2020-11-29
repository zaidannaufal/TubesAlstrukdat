#ifndef scankata_H
#define scankata_H

#include "mesinkata.h"

typedef char str[50];

typedef str totalstr[1000];

char* ScanKata();

int ScanAngka();

void ScanNumberAndString(int * Angka, char* String);

void Stringcopy(char* Destination, char* Source);

int Comparestr(char* Str1 , char* Str2);

#endif