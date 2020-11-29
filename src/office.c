#include <stdio.h>
#include <string.h>
#include "office.h"

void Office(ListBangunan* LB)
{
    // Memasuki office mode //
    char Command[10];
    do
    {
        printf("Masukkan perintah (Details / Report / Exit):\n");
        scanf("%s", Command);
        getchar();
        if (strcmp(Command, "Details") == 0) // Details
        {
            if (!IsEmptyBangunan(*LB))
            {
                // Tampilkan list wahana //
                printf("\nList wahana:\n");
                addressbangunan Current = First(*LB);
                while (Current != NULL)
                {
                    printf("- ");
                    puts(nama(Current));
                    Current = Next(Current);
                }

                // Pilih wahana //
                printf("\nPilih salah satu wahana:\n");
                char NamaBangunan[50];
                int idxNBangunan = 0;
                do {
                    scanf("%c", NamaBangunan + idxNBangunan);
                } while (NamaBangunan[idxNBangunan++] != '\n');
                NamaBangunan[--idxNBangunan] = '\0';

                // Tampilkan detailnya //
                addressbangunan CurrentDetail = First(*LB);
                while (CurrentDetail != NULL && (strcmp(nama(CurrentDetail),NamaBangunan)) != 0)
                {
                    CurrentDetail = Next(CurrentDetail);
                }

                if (CurrentDetail != NULL)
                {
                    printf("\n");
                    printDetails(CurrentDetail);
                    printf("\n");
                }
                else printf("Wahana tidak ditemukan.\n\n");
            }
            else printf("Belum ada wahana yang dibangun.\n");
        }
        else if (strcmp(Command, "Report") == 0) // Report
        {
            if (!IsEmptyBangunan(*LB))
            {
                // Tampilkan list wahana //
                printf("\nList wahana:\n");
                addressbangunan Current = First(*LB);
                while (Current != NULL)
                {
                    printf("- ");
                    puts(nama(Current));
                    Current = Next(Current);
                }

                // Pilih wahana //
                printf("\nPilih salah satu wahana:\n");
                char NamaBangunan[50];
                int idxNBangunan = 0;
                do {
                    scanf("%c", NamaBangunan + idxNBangunan);
                } while (NamaBangunan[idxNBangunan++] != '\n');
                NamaBangunan[--idxNBangunan] = '\0';

                // Tampilkan reportnya //
                
                addressbangunan CurrentReport = First(*LB);
                while (CurrentReport != NULL && (strcmp(nama(CurrentReport),NamaBangunan)) != 0)
                {
                    CurrentReport = Next(CurrentReport);
                }

                if (CurrentReport != NULL)
                {
                    printf("\n");
                    printReport(CurrentReport);
                    printf("\n");
                }
                else printf("Wahana tidak ditemukan.\n\n");
            }
            else printf("Belum ada wahana yang dibangun.\n");
        }
        else if (strcmp(Command, "Exit") != 0) // Selain Exit
        {
            printf("Perintah tidak terdefinisi di Office.\n");
        }
    } while (strcmp(Command, "Exit") != 0);
    printf("\n");
}

void printReport(addressbangunan wahana)
{
	printf("Wahana telah dinaiki %d kali.\n", JmlPakaiTotal(wahana));
	printf("Total penghasilan: %d\n", HasilTotal(wahana));
    printf("Untuk hari ini,\n");
    printf("Wahana telah dinaiki %d kali.\n", JmlPakaiToday(wahana));
    printf("Total penghasilan: %d\n", HasilToday(wahana));
}

void printDetails(addressbangunan wahana){
	printf("Nama: ");
	puts(nama(wahana));
	printf("Tipe: %d\n",tipe(wahana));
    printf("Harga : %d\n",Harga(wahana));
	printf("Lokasi: ");
	TulisPOINT(point(wahana));
	printf("\n");
	printf("Deskripsi: Wahana ini bukan sebuah instrumen.\n");
	printf("Kapasitas : %d\n",KapasitasBang(wahana));
	printf("History Upgrade: %d\n",history(wahana));
    printf("Durasi (dalam satuan menit): %d\n",durasibangunan(wahana));
}

boolean IsinOffice(GraphMap G){
    return SearchWilayahPlayer(G) == 0 && 
    Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) == 8 && 
    Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) == 8;
}