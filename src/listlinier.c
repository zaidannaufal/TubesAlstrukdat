/* File : listlinier.c
NIM : 13519137
Nama : Siti Iedrania Azzariyat Akbar
Tanggal : 3 November 2020
Topik praktikum : Prak 9
Deskripsi : List */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return(First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if (P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	boolean Found;
	P = First(L);
	Found = false;
	while (P != Nil && !Found)
	{
		if (Info(P) == X)
		{
			Found = true;
		}
		else
		{
			P = Next(P);
		}
	}
	return P;
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	address PT;
	boolean Found;
	PT = First(L);
	Found = false;
	while (PT != Nil && !Found)
	{
		if (PT == P)
		{
			Found = true;
		}
		else
		{
			PT = Next(PT);
		}
	}
	return Found;
}
address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	address P, Prec;
	P = Search (L, X);
	Prec = First(L);
	if (P == Prec)
	{
		P = Nil;
	}
	else if (P != Nil)
	{
		while (Next(Prec) != P)
		{
			Prec = Next(Prec);
		}
		P = Prec;
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertFirst(L, P);
	}
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(L, P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty(*L))
	{
		First(*L) = P;
	}
	else
	{
		if (P != Nil)
		{
			address Prec;
			Prec = First(*L);
			while (Next(Prec) != Nil)
			{
				Prec = Next(Prec);
			}
			InsertAfter(L, P, Prec);
		}
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if (!IsEmpty(*L))
	{
		address Prec;
		Prec = First(*L);
		if (Info(Prec) == X)
		{
			First(*L) = Next(Prec);
		}
		else
		{
			address P;
			P = Search(*L, X);
			if (P != Nil)
			{
				while (Next(Prec) != P)
				{
					Prec = Next(Prec);
				}
				Next(Prec) = Next(P);
				Dealokasi(&P);
			}
		}
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
	address Prec;
	Prec = First(*L);
	if (Next(Prec) == Nil)
	{
		*P = Prec;
		First(*L) = Nil;
	}
	else
	{
		while (Next(Next(Prec)) != Nil)
		{
			Prec = Next(Prec);
		}
		*P = Next(Prec);
		Next(Prec) = Nil;
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if (!IsEmpty(L))
	{
		address P;
		P = First(L);
		while (Next(P) != Nil)
		{
			printf("%d,", Info(P));
			P = Next(P);
		}
		printf("%d", Info(P));
	}
	printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	address P;
	int count;
	P = First(L);
	count = 0;
	while (P != Nil)
	{
		count++;
		P = Next(P);
	}
	return count;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L)
/* Mengirimkan nilai Info(P) yang minimum */
{
	address P;
	infotype min;
	P = First(L);
	min = Info(P);
	while (Next(P) != Nil)
	{
		P = Next(P);
		if (min > Info(P))
		{
			min = Info(P);
		}
	}
	return min;
}

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	address P;
	infotype max;
	P = First(L);
	max = Info(P);
	while (Next(P) != Nil)
	{
		P = Next(P);
		if (max < Info(P))
		{
			max = Info(P);
		}
	}
	return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
	infotype max;
	address P;
	max = Max(L);
	P = Search(L, max);
	return P;
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
	infotype min;
	address P;
	min = Min(L);
	P = Search(L, min);
	return P;
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
	infotype jml = 0;
	int count = 0;
	float avg = 0;
	count = NbElmt(L);
	if (!IsEmpty(L))
	{
		address P;
		P = First(L);
		while (Next(P) != Nil)
		{
			jml += Info(P);
			P = Next(P);
		}
		jml += Info(P);
		avg = (float) jml / count;
	}
	return avg;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	if (IsEmpty(*L))
	{
		return;
	}
	else
	{
		address P;
		P = First(*L);
		while (Next(P) != Nil)
		{
			address Prec;
			Prec = P;
			P = Next(P);
			Dealokasi(&Prec);
		}
		First(*L) = Nil;
		Dealokasi(&P);
	}
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
	address P;
	P = First(*L);
	int data[NbElmt(*L)];
	if (!IsEmpty(*L))
	{
		for (int i = 0; i < NbElmt(*L); i++)
		{
			data[i] = Info(P);
			P = Next(P);
		}
		P = First(*L);
		for (int i = NbElmt(*L) - 1; i > -1; i--)
		{
			Info(P) = data[i];
			P = Next(P);
		}
	}
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	List LC;
	address P, PC;
	LC = FCopyList(L);
	P = First(L);
	PC = First(LC);
	int data[NbElmt(L)];
	if (!IsEmpty(L))
	{
		for (int i = 0; i < NbElmt(L); i++)
		{
			data[i] = Info(P);
			P = Next(P);
		}
		for (int i = NbElmt(L) - 1; i > -1; i--)
		{
			Info(PC) = data[i];
			PC = Next(PC);
		}
	}
	return LC;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	address P, PC, Prec;
	List LC;
	if (!IsEmpty(L))
	{
		P = First(L);
		PC = Alokasi(Info(P));
		First(LC) = PC;
		Next(PC) = Nil;
		Prec = PC;
		P = Next(P);
		PC = Next(PC);
		while (P != Nil)
		{
			PC = Alokasi(Info(P));
			Next(Prec) = PC;
			Next(PC) = Nil;
			P = Next(P);
			PC = Next(PC);
			Prec = Next(Prec);
		}
	}
	else
	{
		First(LC) = Nil;
	}
	return LC;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    address last;

    if (IsEmpty(L1)) {
        CpAlokList(L2, L3);
    }
    else {
        CpAlokList(L1, L3);
        last = First(*L3);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = First(L2);
    }
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    int i;
    address(P);

    CpAlokList(L, L1);
    CpAlokList(L, L2);
    if ((NbElmt(L) % 2) == 1)
	{
        for (i = 1; i <= ((NbElmt(L) + 1) /2); i++)
		{
            DelLast(L1, &P);
        }
        for (i = 1; i <= ((NbElmt(L) - 1) /2); i++)
		{
            DelFirst(L2, &P);
        }
    }
    else
	{
        for (i = 1; i <= ((NbElmt(L)) /2); i++)
		{
            DelLast(L1, &P);
            DelFirst(L2, &P);
        }
    }
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	if (IsEmpty(*L1))
	{
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    }
    else if (IsEmpty(*L2))
	{
        First(*L3) = First(*L1);
        First(*L1) = Nil;
    }
    else
	{
		address P;
		P = First(*L1);
		while (Next(P) != Nil)
		{
			P = Next(P);
		}
		Next(P) = First(*L2);
		First(*L3) = First(*L1);
		First(*L1) = Nil;
		First(*L2) = Nil;
	}
}
