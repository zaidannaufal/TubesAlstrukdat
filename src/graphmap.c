#include "graphmap.h"
#include "mesinkata.h"
#include "matriks.h"
#include "point.h"
#include <stdio.h>
#include <string.h>
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
		case 0 : //Ga masuk sini
			Wilayah(*G,NWilayah).NextGate = MakePOINT(9,4);
			Wilayah(*G,NWilayah).PrevGate = MakePOINT(4,9);
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).PrevGate),Absis(Wilayah(*G,NWilayah).PrevGate)) = 'v';
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).NextGate),Absis(Wilayah(*G,NWilayah).NextGate)) = '>';
			Lorong(*G)[0].Origin = NWilayah;
			Lorong(*G)[3].Succ = NWilayah;
			break;
		case 1 :
			Wilayah(*G,NWilayah).NextGate = MakePOINT(4,9);
			Wilayah(*G,NWilayah).PrevGate = MakePOINT(0,4);
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).PrevGate),Absis(Wilayah(*G,NWilayah).PrevGate)) = '<';
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).NextGate),Absis(Wilayah(*G,NWilayah).NextGate)) = 'v';
			Lorong(*G)[0].Succ = NWilayah;
			Lorong(*G)[1].Origin = NWilayah;
			break;
		case 2 :
			Wilayah(*G,NWilayah).NextGate = MakePOINT(0,4);
			Wilayah(*G,NWilayah).PrevGate = MakePOINT(4,0);
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).PrevGate),Absis(Wilayah(*G,NWilayah).PrevGate)) = '^';
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).NextGate),Absis(Wilayah(*G,NWilayah).NextGate)) = '<';
			Lorong(*G)[1].Succ = NWilayah;
			Lorong(*G)[2].Origin = NWilayah;
			break;
		case 3 :
			Wilayah(*G,NWilayah).NextGate = MakePOINT(4,0);
			Wilayah(*G,NWilayah).PrevGate = MakePOINT(9,4);
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).PrevGate),Absis(Wilayah(*G,NWilayah).PrevGate)) = '>';
			Elmt(Wilayah(*G,NWilayah).Map,Ordinat(Wilayah(*G,NWilayah).NextGate),Absis(Wilayah(*G,NWilayah).NextGate)) = '^';
			Lorong(*G)[2].Succ = NWilayah;
			Lorong(*G)[3].Origin = NWilayah;
			break;
	}
}

GraphMap BacaMapTXT() //Formatnya NamaWilayah,AbsisPlayer,OrdinatPlayer
{
	GraphMap G;
	STARTKATA("../external/map.txt");
	while(CC != MARK)
	{
		ADVKATA();
		char Number = CKata.TabKata[0];
		int NWilayahInt = Number - '0';
		Wilayah(G,NWilayahInt).Number = NWilayahInt;
		char AbsisPlayer = CKata.TabKata[2];
		char OrdinatPlayer = CKata.TabKata[4];
		Absis(Wilayah(G,NWilayahInt).PlayerPosition) = AbsisPlayer - '0';
		Ordinat(Wilayah(G,NWilayahInt).PlayerPosition) = OrdinatPlayer - '0';
		Wilayah(G,NWilayahInt).Map = MakeMAP();
		GateIdentifier(NWilayahInt,&G);
	}
	return G;
}

void InitiatePlayerPosition(GraphMap * G)
{
	Wilayah(*G,0).PlayerPosition = MakePOINT(1,1);
	Elmt(Wilayah(*G,0).Map,1,1) = 'P';
}

int SearchWilayahPlayer(GraphMap G)//error disini
{
	int i;
	for (i = 0; i < 4; ++i)
	{
		if (!IsOrigin(Wilayah(G,i).PlayerPosition))
		{
			return i;
		}
	}
	return -1;
}

boolean IsPindahWilayahAtas(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	return (Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition)-1,Absis(Wilayah(G,N).PlayerPosition)) == '^');
}

boolean IsPindahWilayahBawah(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	return (Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition)+1,Absis(Wilayah(G,N).PlayerPosition)) == 'v');
}

boolean IsPindahWilayahKanan(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	return (Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition),Absis(Wilayah(G,N).PlayerPosition)+1) == '>');
}

boolean IsPindahWilayahKiri(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	return (Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition),Absis(Wilayah(G,N).PlayerPosition)-1) == '<');
}

boolean IsPindahLokalAtas(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	char Atas = Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition)-1,Absis(Wilayah(G,N).PlayerPosition));
	return (Atas == '-' || Atas == 'O');
}

boolean IsPindahLokalBawah(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	char Bawah = Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition)+1,Absis(Wilayah(G,N).PlayerPosition));
	return ( Bawah == '-' || Bawah == 'O');
}

boolean IsPindahLokalKanan(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	char Kanan = Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition),Absis(Wilayah(G,N).PlayerPosition)+1);
	return (Kanan == '-' || Kanan == 'O');
}

boolean IsPindahLokalKiri(GraphMap G)
{
	int N = SearchWilayahPlayer(G);
	char Kiri = Elmt(Wilayah(G,N).Map,Ordinat(Wilayah(G,N).PlayerPosition),Absis(Wilayah(G,N).PlayerPosition)-1)
	return (Kiri == '-' || Kiri == 'O');
}


POINT LokasiEntranceSucc(int Succ , GraphMap G) //Dari 0 ke 1, 1 ke 2, 2 ke 3, 3 ke 1
{
	POINT P;
	int X = Absis(Wilayah(G,Succ).PrevGate);
	int Y = Ordinat(Wilayah(G,Succ).PrevGate);
	if (Succ == 0)
	{
		P = MakePOINT(X,Y-1);
	}else if (Succ == 1)
	{
		P = MakePOINT(X+1,Y);
	}else if (Succ == 2)
	{
		P = MakePOINT(X,Y+1);
	}else if (Succ == 3)
	{
		P = MakePOINT(X-1,Y);
	}
	return P;
}

POINT LokasiEntranceOrigin(int Origin, GraphMap G)
{
	POINT P;
	int X = Absis(Wilayah(G,Origin).NextGate);
	int Y = Ordinat(Wilayah(G,Origin).NextGate);
	if (Origin == 0)
	{
		P = MakePOINT(X-1,Y);
	}else if (Origin == 1)
	{
		P = MakePOINT(X,Y-1);
	}else if (Origin == 2)
	{
		P = MakePOINT(X+1,Y);
	}else if (Origin == 3)
	{
		P = MakePOINT(X,Y+1);
	}
	return P;
}


void PindahWilayahSucc(GraphMap * G)
{
	int CurrentWilayah = SearchWilayahPlayer(*G);
	int Succ,i;
	for (i = 0; i < 4; ++i)
	{
		if (Lorong(*G)[i].Origin == CurrentWilayah)
		{
			Succ = Lorong(*G)[i].Succ;
		}
	}
	POINT P = LokasiEntranceSucc(Succ,*G);
	Elmt(Wilayah(*G,CurrentWilayah).Map,Ordinat(Wilayah(*G,CurrentWilayah).PlayerPosition),Absis(Wilayah(*G,CurrentWilayah).PlayerPosition)) = '-';
	Wilayah(*G,CurrentWilayah).PlayerPosition = MakePOINT(0,0);
	Elmt(Wilayah(*G,Succ).Map,Ordinat(P),Absis(P)) = 'P';
	Wilayah(*G,Succ).PlayerPosition = P;
}

void PindahWilayahOrigin(GraphMap * G)
{
	int CurrentWilayah = SearchWilayahPlayer(*G);
	int Origin,i;
	for (i = 0; i < 4; ++i)
	{
		if (Lorong(*G)[i].Succ == CurrentWilayah)
		{
			Origin = Lorong(*G)[i].Origin;
		}
	}
	POINT P = LokasiEntranceOrigin(Origin,*G);
	Elmt(Wilayah(*G,CurrentWilayah).Map,Ordinat(Wilayah(*G,CurrentWilayah).PlayerPosition),Absis(Wilayah(*G,CurrentWilayah).PlayerPosition)) = '-';
	Wilayah(*G,CurrentWilayah).PlayerPosition = MakePOINT(0,0);
	Elmt(Wilayah(*G,Origin).Map,Ordinat(P),Absis(P)) = 'P';
	Wilayah(*G,Origin).PlayerPosition = P;
}


void Move(GraphMap * G, char* C)
{
	int N = SearchWilayahPlayer(*G);
	if (strcmp(C,"w")==0)
	{
		if (IsPindahLokalAtas(*G))
		{
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)) = '-';
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition)-1,Absis(Wilayah(*G,N).PlayerPosition)) = 'P';
			Wilayah(*G,N).PlayerPosition = MakePOINT(Absis(Wilayah(*G,N).PlayerPosition), Ordinat(Wilayah(*G,N).PlayerPosition)-1);
		}else if (IsPindahWilayahAtas(*G))
		{
			if (N == 2)
			{
				PindahWilayahOrigin(G);
			}else if (N == 3)
			{
				PindahWilayahSucc(G);
			}
		}
	}else if (strcmp(C,"s")==0)
	{
		if (IsPindahLokalBawah(*G))
		{
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)) = '-';
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition)+1,Absis(Wilayah(*G,N).PlayerPosition)) = 'P';
			Wilayah(*G,N).PlayerPosition = MakePOINT(Absis(Wilayah(*G,N).PlayerPosition), Ordinat(Wilayah(*G,N).PlayerPosition)+1);
		}else if (IsPindahWilayahBawah(*G))
		{
			if (N == 0)
			{
				PindahWilayahOrigin(G);
			}else if (N == 1)
			{
				PindahWilayahSucc(G);
			}
		}
	}else if (strcmp(C,"a")==0)
	{
		if (IsPindahLokalKiri(*G))
		{
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)) = '-';
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)-1) = 'P';
			Wilayah(*G,N).PlayerPosition = MakePOINT(Absis(Wilayah(*G,N).PlayerPosition)-1, Ordinat(Wilayah(*G,N).PlayerPosition));
		}else if (IsPindahWilayahKiri(*G))
		{
			if (N == 1)
			{
				PindahWilayahOrigin(G);
			}else if (N == 2)
			{
				PindahWilayahSucc(G);
			}
		}
	}else if (strcmp(C,"d")==0)
	{
		if (IsPindahLokalKanan(*G))
		{
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)) = '-';
			Elmt(Wilayah(*G,N).Map,Ordinat(Wilayah(*G,N).PlayerPosition),Absis(Wilayah(*G,N).PlayerPosition)+1) = 'P';
			Wilayah(*G,N).PlayerPosition = MakePOINT(Absis(Wilayah(*G,N).PlayerPosition)+1, Ordinat(Wilayah(*G,N).PlayerPosition));
		}else if (IsPindahWilayahKanan(*G))
		{
			if (N == 0)
			{
				PindahWilayahSucc(G);
			}else if (N == 3)
			{
				PindahWilayahOrigin(G);
			}
		}
	}
}

void TulisPos(GraphMap *G){
	for (int i=0;i <4; ++i){
		TulisPOINT(Wilayah(*G,i).PlayerPosition);
	}
}

void PrintMap(){

}