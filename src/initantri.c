#include "initantri.h"
#include <stdlib.h>
#include <time.h>

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

char generaterandomchar()
{
	int numalfabet = generaterandomint(0,25);
	char alphabet[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	return alphabet[numalfabet];
}

infoantrian GenerateRandomPeople(int pilihanwahana , semuawahana Array, int urutanantrian)
{
	infoantrian Orang;
	MaxTujuan(Orang) = generaterandomint(1,5); //generate ada 1 - 5 tujuan wahana
	CurrentTujuan(Orang) = 0;
	Kesabaran(Orang) = 5;
	DurasiNaikWahana(Orang) = 0;
	DurasiKesabaran(Orang) = 10000;
	InfoAntrian(Orang) = generaterandomchar(); //random nama
	prio(Orang) = urutanantrian;
	int i;
	for (i = 0; i < MaxTujuan(Orang)-1; ++i)  //random wahana yang mau dinaikin
	{
		int indeksrandom = generaterandomint(0,pilihanwahana-1);
		namawahana TujuanRandomize = Array[indeksrandom];
		ArrayTujuan(Orang,i) = TujuanRandomize;
	}
	return Orang;
}


void InitAntrian(Antrian * A, ListBangunan LB)
{
	MakeEmptyAntrian(A,5);
	semuawahana Array;
	int i = 0;
	addressbangunan Current = First(LB);
	while(Current != Nil)
	{
		Array[i] = nama(Current);
		Current = Next(Current);
		i++;
	}
	int jumlahpengunjung = generaterandomint(1,5); //pasti ada pengunjung
	int j;
	for (j = 0; j < jumlahpengunjung; ++j)
	{
		infoantrian Pengunjung = GenerateRandomPeople(i,Array,j+1);
		Enqueue(A,Pengunjung);
	}
}