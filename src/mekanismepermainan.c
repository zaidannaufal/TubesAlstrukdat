#include "mekanismepermainan.h"
#include <stdio.h>

void NgosonginAntrian(Antrian * A)
{
	int i;
	int count = NBElmtAntrian(*A);
	for (i = 0; i < count; ++i)
	{
		infoantrian X;
		Dequeue(A,&X);
	}
}

void MekanismeGaSabar(Antrian * A, int IntervalWaktu)
{
	if (!IsAntrianEmpty(*A))
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
		MakeEmptyAntrian(&Antriansementara , count);
		for (k = 0; i < count; ++i)
		{
			if (Kesabaran(ElmtAntrian(*A,k)) > 0)
			{
				Enqueue(&Antriansementara,ElmtAntrian(*A,k));
			}
		}
		NgosonginAntrian(A);
		for (j = 0; i < count - jumlahgasabar; ++i)
		{
			Enqueue(A,ElmtAntrian(Antriansementara,j));
		}
	}
}

void MekanismeNaikWahana(Antrian * A, ListBangunan * LB, int IntervalWaktu)
{
	addressbangunan Current = First(*LB);
	Antrian AntrianTemp;
	int count = NBElmtAntrian(*A);
	MakeEmptyAntrian(&AntrianTemp , count);
	Antrian AntrianBaru;
	while (Current != NULL)
	{
		int count =  NBElmtAntrian(Antrian(Current));
		int i;
		for (i = 0; i < count; ++i) // Masukin ke Antrian Temporary
		{
			infoantrian Orang;
			Dequeue(&Antrian(Current) , &Orang);
			Enqueue(&AntrianTemp , Orang);
		}
		int j;
		for (j = 0; j < count; ++j) // Untuk Semua Pengunjung Dikurangin Trus Dicek Yang Udah Harus Keluar Wahana
		{
			infoantrian Orang2;
			int WaktuSisa = DurasiNaikWahana(ElmtAntrian(AntrianTemp,j)) - IntervalWaktu;
			DurasiNaikWahana(ElmtAntrian(AntrianTemp,j)) = WaktuSisa;
			Dequeue(&AntrianTemp , &Orang2);
			if (WaktuSisa <= 0)
			{
				if (CurrentTujuan(ElmtAntrian(AntrianTemp,j)) < MaxTujuan(ElmtAntrian(AntrianTemp,j))) // Untuk Yang Keluar Wahana Tapi Masih Mau Main
				{
					Enqueue(A,Orang2);
				}
			}else //Dibalikin lagi ke wahananya
			{
				Enqueue(&Antrian(Current),Orang2);
			}
		}
		Current = Next(Current);
	}
}