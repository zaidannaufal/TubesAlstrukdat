#include <stdio.h>
#include "repair.h"
#include <stdlib.h>


/* Random Pick Wahana untuk di Rusak */
// int randomPickInt(int rangeawal, int rangeakhir)
// {
//     int r,a,b;
//     srand((unsigned)time(NULL));
//     for(a=0;a<20;a++){
//         for(b=0;b<5;b++){
//             r = rand()% rangeakhir+rangeawal;
//         }
//     }
//     return r;
// }

addressbangunan randomWahana(ListBangunan Wahana){
    int count = rand()%(NbElmtBangunan(Wahana)-1);
    addressbangunan P = First(Wahana);
    while (count != 0){
        P = Next(P);
        count -= 1;
    }
    return P;
}

void breakWahana(ListBangunan *Wahana, JAM jam){
    int limit = 0;
    if (brokenWahana(*Wahana) == Nil){
        if (Minute(jam) > 5 || Hour(jam) > 12){
            addressbangunan P = randomWahana(*Wahana);
            while (!IsAntrianEmpty(Antrian(P))&&limit<10){
                P = randomWahana(*Wahana);
                limit++;
            }
            if (limit!=10){
            status(P) = false;
            }
        }

    }
}

/* Mencari address wahana yang rusak */
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


/* Mencari tau apakah player ada di sebelah wahana */
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

BinTree resourceWahana (BinTree *InfoWahana, int Tipe, addressbangunan Wahana)
{
    BinTree P = InfoWahana[Tipe];
    if (history(Wahana) == 1){
        P = Left(P);
    }
    else if (history(Wahana) == 2){
        P = Left(P);
        P = Left(P);
    }
    return P;
}

/* Mengurangi kebutuhan bahan untuk repair sebanyak setengah dari kebutuhan build */
int setengahResource (BinTree P, int i){
    return resource(P,i)/2;
}

boolean bahanCukup(BAHAN BB, int* R){
       return (wood(BB)>=R[0] && stone(BB)>=R[1] && gold(BB)>=R[2]);
}

/* Prosedur repair */
void repair(int *uang, JAM *JAM, GraphMap G, ListBangunan *Wahana, BinTree *InfoWahana, BAHAN *b){

    addressbangunan P = brokenWahana(*Wahana);
    if (P != Nil){
        if (!isNextWahana(G, P)){
            printf("Anda tidak berada disebelah Wahana %s.\n", nama(P));
        }
        else{
            BinTree T = resourceWahana(InfoWahana, tipe(P), P);
            int butuhbahan[3];
            butuhbahan[0] = setengahResource(T,0);
            butuhbahan[1] = setengahResource(T,1);
            butuhbahan[2] = setengahResource(T,2);
            if (bahanCukup(*b, butuhbahan) && *uang>=1000){
                wood(*b) -= butuhbahan[0];
                stone(*b) -= butuhbahan[1];
                gold(*b) -= butuhbahan[2];
                status(P) = true;
                *uang -= 1000;
                *JAM = NextNDetik((*JAM),40*60);
            }
            else{
                printf("Anda tidak memiliki bahan/uang yang cukup");

            }
        }
    }
    else{
        printf("Tidak ada wahana yang rusak.\n");
    }
}


