#include "matriks.h"
#include <stdio.h>
#include "point.h"

MATRIKS renderMap()
{
	MATRIKS M;
	MakeMATRIKS(10,20,&M);
	int i,j;
	for (i = 0; i <= GetLastIdxBrs(M); ++i)
	{
		for (j = 0; j <= GetLastIdxKol(M); ++j)
		{
			if (i == 0 || j == 0 || i == GetLastIdxBrs(M) || j == GetLastIdxKol(M))
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

void initiatePlayerPosition(MATRIKS * M , POINT * P)
{
	Absis(*P) = GetLastIdxKol(*M)/2;
	Ordinat(*P) = GetLastIdxBrs(*M)/2;
	Elmt(*M,(int)Ordinat(*P),(int)Absis(*P)) = 'P';
}

void movePlayer(MATRIKS * M , POINT * P, char C)
{
	Elmt(*M,(int)Ordinat(*P),(int)Absis(*P)) = '-';
	if (C == 'w' && Ordinat(*P) != 1)
	{
		Ordinat(*P)--;
	}else if (C == 'a' && Absis(*P) != 1)
	{
		Absis(*P)--;
	}else if (C == 's' && Ordinat(*P) != GetLastIdxBrs(*M)-1)
	{
		Ordinat(*P)++;
	}else if (C == 'd' && Absis(*P) != GetLastIdxKol(*M)-1)
	{
		Absis(*P)++;
	}
	Elmt(*M,(int)Ordinat(*P),(int)Absis(*P)) = 'P';
}