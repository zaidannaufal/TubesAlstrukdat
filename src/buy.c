
#include "buy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

boolean isEnoughMoney(int Harga, int Demand, int Uang){
    return Uang >= Harga*Demand;
}

void buy(int uang,int butuhuang, int aksi, int butuhjam, BAHAN BB){
    printf("Ingin membeli apa? ('Jumlah' 'Nama bahan')\n");
    printf("\n");
    printf("List: \n");
    printf("    - Wood\n");
    printf("    - Gold\n");
    printf("    - Stone\n");
    int demand;
    char* bahan;
    int durasi = 40;
    scanf("%d %s", &demand, &bahan);

    if (strcmp(bahan,"Wood") == 0){
        if (!isEnoughMoney(hargaWood, demand, uang)){
            printf("Uang Anda tidak cukup untuk permintaan tersebut.\n");
        }
        else{
            butuhuang += hargaWood;
            aksi += 1;
            butuhjam += durasi;
            wood(BB) += demand;
        }
    }
    else if (strcmp(bahan,"Gold") == 0){
        if (!isEnoughMoney(hargaGold, demand, uang)){
            printf("Uang Anda tidak cukup untuk permintaan tersebut.\n");
        }
        else{
            butuhuang += hargaGold;
            aksi += 1;
            butuhjam += durasi;
            gold(BB) += demand;
        }
    }
    else if (strcmp(bahan,"Stone") == 0){
        if (!isEnoughMoney(hargaStone, demand, uang)){
            printf("Uang Anda tidak cukup untuk permintaan tersebut.\n");
        }
        else{
            butuhuang += hargaStone;
            aksi += 1;
            butuhjam += durasi;
            stone(BB) += demand;
        }
    }



}