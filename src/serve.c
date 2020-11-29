#include "serve.h"
#include <stdio.h>


boolean CompareTujuan(tujuan T, char* NamaWahana)
{
    int i = 0;
    while (T[i] != '\0')
    {
        if (T[i] != NamaWahana[i])
        {
            return false;
        }
    }
    return false;
}

void CreateEmptySemuaWahana(ListBangunan * ListWahana)
{
    addressbangunan Current = First(*ListWahana);
    while (Current != NULL)
    {
        MakeEmptyAntrian(Antrian(Current),KapasitasBang(Current));
        Current = Next(Current);
    }
}

void Serve(Antrian * A, ListBangunan * ListWahana)
{
    if (!IsAntrianEmpty(*A))
    {
        infoantrian Pengunjung;
        Dequeue(A,&Pengunjung);
        int NoTujuan = Pengunjung.CurrentTujuan;
        tujuan TujuanSekarang = Pengunjung.ArrayTujuan[NoTujuan]; //string ini tuh , TujuanSekarang >= 0
        addressbangunan Current = First(*ListWahana);
        while (Current != NULL)
        {
            if (CompareTujuan(TujuanSekarang,nama(Current)))
            {
                if (status)
                {
                    if (!IsAntrianFull(Antrian(Current)))
                    {
                        Prio(Pengunjung) = 1;
                        DurasiNaikWahana(Pengunjung) = durasibangunan(Current); //Buat mekanisme permainan nanti bakal berkurang trus ininya
                        Pengunjung.CurrentTujuan++;
                        Enqueue(Info(Current).pengunjung,Pengunjung); // ini kenapa
                        JmlPakaiToday(Current) += 1; // apakah ini salah secara pointer? saya tak tahu;
                        JmlPakaiTotal(Current) += 1;
                        HasilToday(Current) += Harga(Current); // pas reset hari yang today2 di reset juga
                        HasilTotal(Current) += Harga(Current);
                    }else printf("Wahana masih penuh, tunggu terlebih dahulu!\n");
                }else printf("Harap memperbaiki wahana yang rusak terlebih dahulu!\n");
            }
            Current = Next(Current);
        }
    }
}