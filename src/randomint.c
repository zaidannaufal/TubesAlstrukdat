#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef char apalah[50];

int generaterandomint(int rangeawal, int rangeakhir)
{
	int r,a,b;
	srand((unsigned)time(NULL));
	for(a=0;a<20;a++)
	{
		for(b=0;b<5;b++)
		{
			r = rand()% rangeakhir+rangeawal;
		}
	}
	return r;
}

void main()
{
	FILE* f;
	apalah Path = "../external/random.txt";
	f = fopen(Path , "w");
	int Rand = generaterandomint(0,100);
	apalah Hasil;
	sprintf(Hasil, "%d" , Rand);
	fputs(Hasil , f);
	fclose(f);
}