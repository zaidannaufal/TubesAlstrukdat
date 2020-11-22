#include "graphmap.h"
#include "mesinkata.h"
#include "matriks.h"
#include "point.h"
#include <stdio.h>

MATRIKS MakeMAP() //Udah Bener Ini Mah
{
	MATRIKS M;
	MakeMATRIKS(10,10,&M);
	int i,j;
	for (i = 0; i < NBrsEff(M); ++i)
	{
		for (j = 0; j < NKolEff(M); ++j)
		{
			if (i == 0 || i == GetLastIdxBrs(M) || j == 0 || j == GetLastIdxKol(M))
			{
				Elmt(M,i,j) = '*';
			}else
			{
				Elmt(M,i,j) = '-';
			}
		}
	}
	return M;
}

void GateIdentifier(int NWilayah , GraphMap * G)
{
	switch(NWilayah)
	{
		case 1 :
			Wilayah(*G,NWilayah-1).NextGate = MakePOINT(9,4);
			Wilayah(*G,NWilayah-1).PrevGate = MakePOINT(4,9);
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).PrevGate),Absis(Wilayah(*G,NWilayah-1).PrevGate)) = 'v';
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).NextGate),Absis(Wilayah(*G,NWilayah-1).NextGate)) = '>';
			Lorong(*G)[0].Origin = NWilayah;
			Lorong(*G)[1].Succ = NWilayah;
			Lorong(*G)[6].Succ = NWilayah;
			Lorong(*G)[7].Origin = NWilayah;
			break;
		case 2 :
			Wilayah(*G,NWilayah-1).NextGate = MakePOINT(4,9);
			Wilayah(*G,NWilayah-1).PrevGate = MakePOINT(0,4);
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).PrevGate),Absis(Wilayah(*G,NWilayah-1).PrevGate)) = '<';
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).NextGate),Absis(Wilayah(*G,NWilayah-1).NextGate)) = 'v';
			Lorong(*G)[0].Succ = NWilayah;
			Lorong(*G)[1].Origin = NWilayah;
			Lorong(*G)[2].Origin = NWilayah;
			Lorong(*G)[3].Succ = NWilayah;
			break;
		case 3 :
			Wilayah(*G,NWilayah-1).NextGate = MakePOINT(0,4);
			Wilayah(*G,NWilayah-1).PrevGate = MakePOINT(4,0);
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).PrevGate),Absis(Wilayah(*G,NWilayah-1).PrevGate)) = '^';
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).NextGate),Absis(Wilayah(*G,NWilayah-1).NextGate)) = '<';
			Lorong(*G)[2].Succ = NWilayah;
			Lorong(*G)[3].Origin = NWilayah;
			Lorong(*G)[4].Origin = NWilayah;
			Lorong(*G)[5].Succ = NWilayah;
			break;
		case 4 :
			Wilayah(*G,NWilayah-1).NextGate = MakePOINT(4,0);
			Wilayah(*G,NWilayah-1).PrevGate = MakePOINT(9,4);
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).PrevGate),Absis(Wilayah(*G,NWilayah-1).PrevGate)) = '>';
			Elmt(Wilayah(*G,NWilayah-1).Map,Ordinat(Wilayah(*G,NWilayah-1).NextGate),Absis(Wilayah(*G,NWilayah-1).NextGate)) = '^';
			Lorong(*G)[4].Succ = NWilayah;
			Lorong(*G)[5].Origin = NWilayah;
			Lorong(*G)[6].Origin = NWilayah;
			Lorong(*G)[7].Succ = NWilayah;
			break;
	}
}

GraphMap BacaMapTXT() //Formatnya NamaWilayah,AbsisPlayer,OrdinatPlayer
{
	GraphMap G;
	STARTKATA("map.txt");
	while(CC != MARK)
	{
		ADVKATA();
		char Number = CKata.TabKata[0];
		int NWilayahInt = Number - '0';
		Wilayah(G,NWilayahInt-1).Number = NWilayahInt;
		char AbsisPlayer = CKata.TabKata[2];
		char OrdinatPlayer = CKata.TabKata[5];
		Absis(Wilayah(G,NWilayahInt-1).PlayerPosition) = AbsisPlayer - '0';
		Ordinat(Wilayah(G,NWilayahInt-1).PlayerPosition) = OrdinatPlayer - '0';
		Wilayah(G,NWilayahInt-1).Map = MakeMAP();
		GateIdentifier(NWilayahInt,&G);
	}
	return G;
}

// void InitiatePlayerPosition(GraphMap * G)
// {
// 	Wilayah(*G,0).PlayerPosition = MakePOINT(0,0);
// 	Wilayah(*G,0).Map[0][0] = 'P';
// }

// void InitiateLorong(GraphMap * G)
// {
// 	Lorong(*G)[0].Origin = 1;
// 	Lorong(*G)[0].Succ = 2;
// 	Lorong(*G)[1].Origin = 2;
// 	Lorong(*G)[1].Succ = 1;
// 	Lorong(*G)[2].Origin = 2;
// 	Lorong(*G)[2].Succ = 3;
// 	Lorong(*G)[3].Origin = 3;
// 	Lorong(*G)[3].Succ = 2;
// 	Lorong(*G)[4].Origin = 3;
// 	Lorong(*G)[4].Succ = 4;
// 	Lorong(*G)[5].Origin = 4;
// 	Lorong(*G)[5].Succ = 3;
// 	Lorong(*G)[6].Origin = 4;
// 	Lorong(*G)[6].Succ = 1;
// 	Lorong(*G)[7].Origin = 1;
// 	Lorong(*G)[7].Succ = 4;
// }