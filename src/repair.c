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
    
 	boolean nextPosition = false;
    int w = SearchWilayahPlayer(G);
    boolean sameWilayah = false;
    if (w == wilayah(P)){
        sameWilayah = true;
    }
    if (Absis(Wilayah(G,w).PlayerPosition) == Absis(point(P)) + 1 &&  Ordinat(Wilayah(G,w).PlayerPosition) == Ordinat(point(P))){
        nextPosition = true;
    }
 	return  sameWilayah && nextPosition;
    

}

void repair(int uang, int aksi, JAM jam, GraphMap G, ListBangunan Wahana){

    addressbangunan P = brokenWahana(Wahana);
    JAM durasi = MakeJAM(0,40,0);
    if (!isNextWahana(G, P))){
        printf("Anda tidak berada disebelah kiri Wahana %c\n", nama(P));
    }
    else{
        status(P) = true;
        aksi += 1;
        uang -= 1000;
        jam = JPlus(jam, durasi);
    }

}


