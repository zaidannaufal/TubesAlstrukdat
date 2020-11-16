#include <stdio.h>
#include "matriks.h"
#include <math.h>
//Randy Zakya Suchrady
//13519061
//K01 Alstrukdat


void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

indeks GetIdxBrsMin ()
{
	return BrsMin;
}

indeks GetIdxKolMin ()
{
	return KolMin;
}

indeks GetIdxBrsMax ()
{
	return BrsMax;
}

indeks GetIdxKolMax ()
{
	return KolMax;
}

boolean IsIdxValid (int i, int j)
{
	if (i >= BrsMin &&  i <= BrsMax && j >= KolMin && j <= KolMax)
	{
		return true;
	}
	return false;
}

indeks GetFirstIdxBrs (MATRIKS M)
{
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
{
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
{
	return NBrsEff(M)-1;
}

indeks GetLastIdxKol (MATRIKS M)
{
	return NKolEff(M)-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
{
	if (IsIdxValid(i,j) && i <= GetLastIdxBrs(M) && j <= GetLastIdxKol(M))
	{
		return true;
	}
	return false;
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
{
	return Elmt(M,i,i);
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
{
	NBrsEff(*MHsl) = NBrsEff(MIn);
	NKolEff(*MHsl) = NKolEff(MIn);
	indeks i,j;
	for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++)
	{
		for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++)
		{
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK)
{
	MakeMATRIKS(NB,NK,M);
	indeks i,j;

	for (i = GetFirstIdxBrs(*M); i <= NBrsEff(*M)-1; i++)
	{
		for (j = GetFirstIdxKol(*M); j <= NKolEff(*M)-1; j++)
		{
			scanf("%d", &Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M)
{
	indeks i,j;
	for (i = GetFirstIdxBrs(M); i <= NBrsEff(M)-1; i++)
	{
		for (j = GetFirstIdxKol(M); j <= NKolEff(M)-1; j++)
		{
			if (j != NKolEff(M)-1)
			{
				printf("%c", Elmt(M,i,j) );
			}else printf("%c", Elmt(M,i,j) );
		}
		if (i != (NBrsEff(M)-1))
		{
			printf("\n");
		}
	}
}

MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
	indeks i,j;
	for (i = GetFirstIdxBrs(M3); i <= GetLastIdxBrs(M3); i++)
	{
		for (j = GetFirstIdxKol(M3); j <= GetLastIdxKol(M3); j++)
		{
			Elmt(M3,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
		}
	}

	return M3;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
	indeks i,j;
	for (i = GetFirstIdxBrs(M3); i <= GetLastIdxBrs(M3); i++)
	{
		for (j = GetFirstIdxKol(M3); j <= GetLastIdxKol(M3); j++)
		{
			Elmt(M3,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
		}
	}

	return M3;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS M3;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
	indeks i,j;
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
	{
		for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++)
		{
			indeks k;
			ElType sum = 0;
			for (k = 0; k <= NKolEff(M1)-1; k++)
			{
				sum = sum + (Elmt(M1,i,k)*Elmt(M2,k,j));
			}
			Elmt(M3,i,j) = sum;
		}
	}
	return M3;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
{
	MATRIKS N;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&N);
	indeks i,j;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			Elmt(N,i,j) = X*Elmt(M,i,j);
		}
	}

	return N;
}

void PKaliKons (MATRIKS * M, ElType K)
{
	indeks i,j;
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			Elmt(*M,i,j) = K*Elmt(*M,i,j);
		}
	}
}

boolean EQ (MATRIKS M1, MATRIKS M2)
{
	if (GetLastIdxBrs(M1) == GetLastIdxBrs(M2) && GetLastIdxKol(M1) == GetLastIdxKol(M2))
	{
		indeks i,j;
		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		{
			for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
			{
				if (Elmt(M1,i,j) != Elmt(M2,i,j))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
{
	return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
{
	if (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2))
	{
		return true;
	}
	return false;
}

int NBElmt (MATRIKS M)
{
	return NBrsEff(M)*NKolEff(M);
}

boolean IsBujurSangkar (MATRIKS M)
{
	if ((NBrsEff(M) == NKolEff(M)))
	{
		return true;
	}
	return false;
}

boolean IsSimetri (MATRIKS M)
{
	if (IsBujurSangkar(M))
	{
		indeks i,j;
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				if (Elmt(M,i,j) != Elmt(M,j,i))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

boolean IsSatuan (MATRIKS M)
{
	if (IsBujurSangkar(M))
	{
		indeks i,j;
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				if (i == j)
				{
					if (Elmt(M,i,j) != 1)
					{
						return false;
					}
				}else{
					if (Elmt(M,i,j) != 0)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	return false;
}

boolean IsSparse (MATRIKS M)
{
	int n = 0;
	indeks i,j;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			if (Elmt(M,i,j) != 0)
			{
				n++;
			}
		}
	}
	int batas = NBElmt(M)/20;
	if (n <= batas)
	{
		return true;
	}
	return false;
}

MATRIKS Inverse1 (MATRIKS M)
{
	return KaliKons(M,-1);
}

float Determinan (MATRIKS M)
{
	if (NBElmt(M) == 1)
	{
		return Elmt(M,0,0);
	}
	else if (NBElmt(M) == 4)
	{
		return (Elmt(M,0,0)*Elmt(M,1,1))-(Elmt(M,0,1)*Elmt(M,1,0));
	}
	else
	{
		float sum = 0;
		indeks i;
		for (i = 0; i <= GetLastIdxKol(M); i++)
		{
			MATRIKS minor;
			MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&minor);
			indeks j,k;
			for (j = 1; j <= GetLastIdxBrs(M); j++)
			{
				for (k = 0; k <= GetLastIdxKol(M)-1; k++)
				{
					if (k < i)
					{
						Elmt(minor,j-1,k) = Elmt(M,j,k);
					}
					else
					{
						Elmt(minor,j-1,k) = Elmt(M,j,k+1);
					}

				}
			}
			sum = sum + pow(-1,i)*Elmt(M,0,i)*Determinan(minor);
		}
		return sum;
	}
}

void PInverse1 (MATRIKS * M)
{
	PKaliKons(M,-1);
}

void Transpose (MATRIKS * M)
{
    MATRIKS Mtemp;
    MakeMATRIKS(M->NBrsEff,M->NKolEff,&Mtemp);
    CopyMATRIKS(*M,&Mtemp);
    if (IsBujurSangkar(*M)){
        int i;
        int j;
        i = 0;
        j = 0;
        while (i<M->NBrsEff){   
            j = 0;
            while  (j<M->NKolEff){
                M->Mem[i][j] = Mtemp.Mem[j][i];
                j = j+1;
                
            }
            i = i+1;
        }
    }
}


/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	indeks j;
	ElType sum = 0;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		sum = sum + Elmt(M,i,j);
	}
	return (sum/(float)NKolEff(M)); //Ralat untuk (float)NKolEff , sebelumnya tidak ada namun
	//soal nomor 1 meloloskannya
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	indeks i;
	ElType sum = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		sum = sum + Elmt(M,i,j);
	}
	return (sum/(float)NBrsEff(M)); //Ralat untuk (float)NBrsEff , sebelumnya tidak ada namun
	//soal nomor 1 meloloskannya
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	indeks j;
	*max = Elmt(M,i,GetFirstIdxKol(M));
	*min = Elmt(M,i,GetFirstIdxKol(M));
	for (j = GetFirstIdxKol(M)+1; j <= GetLastIdxKol(M); j++)
	{
		if (Elmt(M,i,j) > *max)
		{
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min)
		{
			*min = Elmt(M,i,j);
		}
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	indeks i;
	*max = Elmt(M,GetFirstIdxBrs(M),j);
	*min = Elmt(M,GetFirstIdxBrs(M),j);
	for (i = GetFirstIdxBrs(M)+1; i <= GetLastIdxBrs(M); i++)
	{
		if (Elmt(M,i,j) > *max)
		{
			*max = Elmt(M,i,j);
		}
		if (Elmt(M,i,j) < *min)
		{
			*min = Elmt(M,i,j);
		}
	}
}
int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	int occ = 0;
	indeks j;
	for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		if (Elmt(M,i,j) == X)
		{
			occ++;
		}
	}
	return occ;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	int occ = 0;
	indeks i;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if (Elmt(M,i,j) == X)
		{
			occ++;
		}
	}
	return occ;
}