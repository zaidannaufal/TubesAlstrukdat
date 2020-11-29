#include <stdio.h>
#include "bangunan.h"
#include "jam.h"
#include "graphmap.h"
#include "repair.h"
#include <stdlib.h>

void buatRusak(ListBangunan Wahana, JAM jam){
    if (Minute(jam)  ||)
}


addressbangunan brokenWahana(ListBangunan Wahana){
    addressbangunan P;
 	boolean Found;
 	P = First(Wahana);
 	Found = false;
 	while (P != Nil && !Found)
 	{
 		if (status(P) == false)
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


boolean isNextWahana (GraphMap G, addressbangunan P){
    
 	int w = SearchWilayahPlayer(G);
    boolean sameWilayah = false;
    if (w == wilayah(P)){
        if (Absis(Wilayah(G,w).PlayerPosition) == Absis(point(P)) + 1 && Ordinat(Wilayah(G,w).PlayerPosition) == Ordinat(point(P))){
            return true;
        }
        else if (Absis(Wilayah(G,w).PlayerPosition) == Absis(point(P)) - 1 && Ordinat(Wilayah(G,w).PlayerPosition) == Ordinat(point(P))){
            return true;
        }
        else if (Absis(Wilayah(G,w).PlayerPosition) == Absis(point(P)) && Ordinat(Wilayah(G,w).PlayerPosition) == Ordinat(point(P)) + 1){
            return true;
        }
        else if (Absis(Wilayah(G,w).PlayerPosition) == Absis(point(P)) &&  Ordinat(Wilayah(G,w).PlayerPosition) == Ordinat(point(P)) - 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}

void repair(int *uang, int *aksi, int *jam, GraphMap G, ListBangunan *Wahana){

    addressbangunan P = brokenWahana(*Wahana);
    int durasi = 40;
    if (!isNextWahana(G, P))){
        printf("Anda tidak berada disebelah Wahana %c\n", nama(P));
    }
    else{
        status(P) = true;
        *aksi += 1;
        *uang -= 1000;
        *jam += durasi;
    }

}


