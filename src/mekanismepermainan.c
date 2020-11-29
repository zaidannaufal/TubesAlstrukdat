#include "mekanismepermainan.h"
#include <stdio.h>

void NgosonginAntrian(Antrian * A, int i)
{
	for (i = 0; i < count; ++i)
	{
		infoantrian X;
		Dequeue(A,X);
	}
}

void MekanismeGaSabar(Antrian * A, int IntervalWaktu)
{
	int count = NBElmtAntrian(*A);
	int i;
	int jumlahgasabar = 0;
	for (i = 0; i < count; ++i)
	{
		infoantrian pengunjunggasabar;
		int DurasiKesabaranBaru = ElmtAntrian(*A,i).DurasiKesabaran - IntervalWaktu;
		int KesabaranBaru = DurasiKesabaranBaru / 2000; //kalau intervalnya 0 berarti kan nanti 10000 - 0 / 2000 jadinya tetep 5
		Kesabaran(ElmtAntrian(*A,i)) = KesabaranBaru;
		if (KesabaranBaru <= 0)
		{
			jumlahgasabar++;
			printf("Kamu kehilangan satu pengunjung!\n");
		}
	}
	int j,k;
	Antrian Antriansementara;
	for (k = 0; i < count; ++i)
	{
		if (Kesabaran(ElmtAntrian(*A,k)) > 0)
		{
			Enqueue(&Antriansementara,Elmt(*A,k));
		}
	}
	NgosonginAntrian(A,5);
	for (j = 0; i < count - jumlahgasabar; ++i)
	{
		Enqueue(A,Elmt(Antriansementara,j));
	}

}