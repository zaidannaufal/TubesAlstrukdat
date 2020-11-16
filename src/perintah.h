#ifndef PERINTAH_H
#define PERINTAH_H

#include "boolean.h"
#include "mesinkata.h"
#define str_end '\0'

typedef struct { 
	Kata command[NMax]; // garrray of perintah
    int total; // total perintah yg ada di array
} PERINTAH;

#define Command(per,i) per.command[i].TabKata

// int parser_perintah(Kata perintah); belum jadi

void copystr(Kata *destination, const char source[]); 
/* jadiin dari const char ke char */

boolean compare_string(char *a, char *b); 
/* compare string 1 sama string 2 kalo */
void tulisstr(char string[]);
/* ngeprint string */

PERINTAH siapkan_perintah();
/* nge siapin semua command*/
#endif