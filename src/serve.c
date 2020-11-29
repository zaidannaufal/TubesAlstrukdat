#include "serve.h"
#include <stdio.h>
#include <string.h>

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
        MakeEmptyAntrian(&(Antrian(Current)),KapasitasBang(Current));
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
        tujuan TujuanSekarang; 
        strcpy(TujuanSekarang,Pengunjung.ArrayTujuan[NoTujuan]); //string ini tuh , TujuanSekarang >= 0
        addressbangunan Current = First(*ListWahana);
        while (Current != NULL)
        {
            MakeEmptyAntrian(&Antrian(Current),KapasitasBang(Current));
            if (strcmp(TujuanSekarang,nama(Current))==0)
            {
                if (status(Current)==true)
                {
                    if (!IsAntrianFull(Antrian(Current)))
                    {
                        Prio(Pengunjung) = 1;
                        DurasiNaikWahana(Pengunjung) = durasibangunan(Current);
                        Pengunjung.CurrentTujuan++;
                        Enqueue(&Antrian(Current),Pengunjung);
                        JmlPakaiToday(Current) += 1; 
                        JmlPakaiTotal(Current) += 1;
                        HasilToday(Current) += Harga(Current); 
                        HasilTotal(Current) += Harga(Current);
                    }else printf("Wahana masih penuh, tunggu terlebih dahulu!\n");

                }else printf("Harap memperbaiki wahana yang rusak terlebih dahulu!\n");
            }
            Current = Next(Current);  
        }
    }
}