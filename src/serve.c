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

void Serve(Antrian * Antrian, List * ListWahana)
{
    if (!IsAntrianEmpty(*Antrian))
    {
        infoantrian Pengunjung;
        Dequeue(Antrian,&Pengunjung);
        int NoTujuan = Pengunjung.CurrentTujuan;
        tujuan TujuanSekarang = Pengunjung.ArrayTujuan[NoTujuan]; //string ini tuh , TujuanSekarang >= 0
        address Current = First(*ListWahana);
        while (Current != Nil)
        {
            if (CompareTujuan(TujuanSekarang,nama(Current)))
            {
                Prio(Pengunjung) = 1;
                Pengunjung.CurrentTujuan++;
                Enqueue(Info(Current).pengunjung,Pengunjung);
            }
            Current = Next(Current);
        }
    }
}