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
 		if (Absis(P) == Absis(lokasi(Wahana)) && Ordinat(P) == Ordinat(lokasi(Wahana)) && wilayah(Wahana) == SearchWilayahPlayer(G))
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

boolean isKiriWahana(GraphMap G, int x, int y, int w){
    return Absis(Wilayah(G,w).PlayerPosition) == x-1 && Ordinat(Wilayah(G,w).PlayerPosition) == y;
}

boolean isKananWahana(GraphMap G, POINT P, int x, int y, int w){
    return Absis(Wilayah(G,w).PlayerPosition) == x)+1 && Ordinat(Wilayah(G,w).PlayerPosition) == y;
}

boolean isAtasWahana(GraphMap G, int x, int y, int w){
    return Absis(Wilayah(G,w).PlayerPosition) == x && Ordinat(Wilayah(G,w).PlayerPosition) == y+1;
}

boolean isBawahWahana(GraphMap G, int x, int y, int w){
    return Absis(Wilayah(G,w).PlayerPosition) == x && Ordinat(Wilayah(G,w).PlayerPosition) == y-1;
}

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

void detail(GraphMap G, ListBangunan Wahana){
    int w = SearchWilayahPlayer(G);
    int x = Absis(Wilayah(G,w).PlayerPosition);
    int y = Ordinat(Wilayah(G,w).PlayerPosition);

    if (isKiriWahana(G, x, y, w)){
        addressbangunan Pleft = searchByLokasi(Wahana,x-1,y,G);
        printDetail(Pleft);
    }
    if (isKananWahana(G, x, y, w)){
        addressbangunan PRight = searchByLokasi(Wahana,x+1,y,G);
        printDetail(PRight);
    }
    if (isAtasWahana(G, x, y, w)){
        addressbangunan PAtas = searchByLokasi(Wahana,x,y+1,G);
        printDetail(PAtas);
    }
    if (isKiriWahana(G, x, y, w)){
        addressbangunan PBawah = searchByLokasi(Wahana,x,y-1,G);
        printDetail(PBawah);
    }
    else{
        printf("Tidak ada wahana di sebelah Anda.\n")
    }


}
