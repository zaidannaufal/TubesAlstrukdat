#include <stdio.h>
#include <stdlib.h>

int generaterandomint()
{
	FILE* f;
	system("gcc randomint.c -o random");
	system("random");
	f = fopen("../external/random.txt" , "r");
	char str[50];
	fgets(str , 50 , f);
	fclose(f);
	int Angka;
	sscanf(str , "%d" , &Angka);
	return Angka;
}