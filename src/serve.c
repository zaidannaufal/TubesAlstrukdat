#include "serve.h"

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

void Serve(Antrian * Antrian, ListBangunan * ListWahana)
{
    if (!IsAntrianEmpty(*Antrian))
    {
        infoantrian Pengunjung;
        Dequeue(Antrian,&Pengunjung);
        int NoTujuan = Pengunjung.CurrentTujuan;
        tujuan TujuanSekarang = Pengunjung.ArrayTujuan[NoTujuan]; //string ini tuh , TujuanSekarang >= 0
        addressbangunan Current = First(*ListWahana);
        while (Current != NULL)
        {
            if (CompareTujuan(TujuanSekarang,nama(Current)))
            {
                Prio(Pengunjung) = 1;
                Pengunjung.CurrentTujuan++;
                Enqueue(Info(Current).pengunjung,Pengunjung); // ini kenapa
                JmlPakaiToday(Current) += 1; // apakah ini salah secara pointer? saya tak tahu;
                JmlPakaiTotal(Current) += 1;
                HasilToday(Current) += Harga(Current); // pas reset hari yang today2 di reset juga
                HasilTotal(Current) += Harga(Current);
            }
            Current = Next(Current);
        }
    }
}