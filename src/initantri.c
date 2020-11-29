#include "initantri.h"
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include "randomizer.c"

int generaterandomint(int rangeawal, int rangeakhir)
{
	// int r,a,b;
	// srand((unsigned)time(NULL));
	// for(a=0;a<20;a++)
	// {
	// 	for(b=0;b<5;b++)
	// 	{
	// 		r = rand()% rangeakhir+rangeawal;
	// 	}
	// }
	// return r;
	int a;
	do{
		a =rdmint();
		a = a % rangeakhir+1;
	}while (a<rangeawal&&a>rangeakhir);
	return a;
}

char generaterandomchar()
{
	int numalfabet = generaterandomint(0,25);
	char alphabet[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
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
	Prio(Orang) = urutanantrian;
	int i;
	for (i = 0; i < MaxTujuan(Orang); ++i)  //random wahana yang mau dinaikin
	{
		int indeksrandom = generaterandomint(0,pilihanwahana-1);
		namawahana TujuanRandomize;
		strcpy(TujuanRandomize,Array[indeksrandom]);
		strcpy(ArrayTujuan(Orang,i),TujuanRandomize);
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
		strcpy(Array[i],nama(Current));
		Current = Next(Current);
		i++;
	}
	int jumlahpengunjung = generaterandomint(1,5); //pasti ada pengunjung
	int j;
	for (j = 0; j < jumlahpengunjung; ++j)
	{
		infoantrian Pengunjung = GenerateRandomPeople(NbElmtBangunan(LB),Array,j+1);
		Enqueue(A,Pengunjung);
	}
}

void PrintPengunjung(infoantrian Orang)
{
	printf("Nama : %c | Kesabaran : %d | ", InfoAntrian(Orang), Kesabaran(Orang));
	int count = MaxTujuan(Orang);
	int i;
	printf("(", );
	for (i = CurrentTujuan(Orang); i < count-1; ++i)
	{
		printf("%s,", ArrayTujuan(Orang,i) );
	}
	printf("%s)", ArrayTujuan(Orang,count-1));
}

void PrintAntrian(Antrian A)
{
	int i = Head(A);
	while (i != Tail(A))
	{
		PrintPengunjung(ElmtAntrian(A,i));
		printf("\n");
		i++;
	}
}