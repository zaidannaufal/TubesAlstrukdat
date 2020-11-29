#include <stdio.h>
#include <stdlib.h>
#include "detail.h"

addressbangunan searchByLokasi(ListBangunan Wahana, int x, int y, GraphMap G){
    addressbangunan P;
    boolean Found;
    P = First(Wahana);
    Found = false;
    while (P != Nil && !Found)
    {
        if (Absis(point(P)) == x && Ordinat(point(P)) == y && wilayah(P) == SearchWilayahPlayer(G))
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

// boolean KiriWahana(GraphMap G, int x, int y, ListBangunan Wahana){
//     return Absis(Wilayah(G,w).PlayerPosition) == x-1 && Ordinat(Wilayah(G,w).PlayerPosition) == y;
// }

// boolean KananWahana(GraphMap G, int x, int y, ListBangunan Wahana){
//     return Absis(Wilayah(G,w).PlayerPosition) == x+1 && Ordinat(Wilayah(G,w).PlayerPosition) == y;
// }

// boolean AtasWahana(GraphMap G, int x, int y, ListBangunan Wahana){
//     return Absis(Wilayah(G,w).PlayerPosition) == x && Ordinat(Wilayah(G,w).PlayerPosition) == y+1;
// }

// boolean BawahWahana(GraphMap G, int x, int y, ListBangunan Wahana){
//     return Absis(Wilayah(G,w).PlayerPosition) == x && Ordinat(Wilayah(G,w).PlayerPosition) == y-1;
// }

void printDetail(addressbangunan wahana){
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

void detail(GraphMap G, ListBangunan Wahana, JAM *jam){
    int w = SearchWilayahPlayer(G);
    int x = Absis(Wilayah(G,w).PlayerPosition);
    int y = Ordinat(Wilayah(G,w).PlayerPosition);
    boolean found = false;

    if (searchByLokasi(Wahana,x+1,y,G) != Nil){
        addressbangunan Pleft = searchByLokasi(Wahana,x+1,y,G);
        printf("Kanans:\n");
        printDetail(Pleft);
        printf("\n");
        *jam = NextNDetik(*jam,60*100);
        found = true;
    }
    if (searchByLokasi(Wahana,x-1,y,G) != Nil){
        addressbangunan PRight = searchByLokasi(Wahana,x-1,y,G);
        printf("Kiri:\n");
        printDetail(PRight);
        printf("\n");
        *jam = NextNDetik(*jam,60*100);
        found = true;
    }
    if (searchByLokasi(Wahana,x,y-1,G) != Nil){
        addressbangunan PAtas = searchByLokasi(Wahana,x,y-1,G);
        printf("Atas:\n");
        printDetail(PAtas);
        printf("\n");
        *jam = NextNDetik(*jam,60*100);
        found = true;
    }
    if (searchByLokasi(Wahana,x,y+1,G) != Nil){
        addressbangunan PBawah = searchByLokasi(Wahana,x,y+1,G);
        printf("Bawah:\n");
        printDetail(PBawah);
        printf("\n");
        *jam = NextNDetik(*jam,60*100);
        found = true;
    }
    else{
        if (!found){
            printf("Tidak ada wahana di sebelah Anda.\n");
        }
    }
}

