#include "build.h"
#include "stdio.h"
#include "string.h"

// bangunan dobuild(posisi,arrayofapa,bangunan,stack bahan){
//     movebottom{}
//     edit itu pos jadi w
//     kurangin bahan
// }

void build(BinTree* wahana, BAHAN bb,BAHAN* bbs,GraphMap *G, ListBangunan *bg,int *durasi,int money,int *bill){
    char input[50];
    char forstack[50];
    int i = 0;
    printf("Ingin membangun apa? \n");
    printf("list:\n");
    for(i=0;i<=2;i++){
        printf("[%d] ",i+1);
        puts(tipe(wahana[i]));
    }
    printf("Pilih tipe yang diinginkan :");
    scanf("%d",&i);
    printf("tipe yang dipilih : ");
    puts(tipe(wahana[i-1]));
    if(BBcukup(bb,*bbs,(wahana[i-1]->info).resource.resource)){
        infotypeW X;
        addressbangunan P = Alokasi(X);
        int idxInput = 0;
        getchar(); //buffer
        printf("Masukkan nama bangunan :");
        
        do {
                scanf("%c", input + idxInput);
        } while (input[idxInput++] != '\n');
        input[--idxInput] = '\0';
        
        puts(input);

        printf("\n");
        strcpy(nama(P),input);
        tipe(P) = i-1;
        wilayah(P) = SearchWilayahPlayer(*G);
        point(P) = (Wilayah(*G,wilayah(P))).PlayerPosition;
        durability(P) = 10; //sementara
        status(P) = true;
        HUpgrade(P) =  HUpgrade(wahana[i-1]);
        Harga(P) = harga(wahana[i-1]);
        durasibangunan(P) = durasibt(wahana[i-1]);
        KapasitasBang(P) = kapasitas(wahana[i-1]);
        JmlPakaiToday(P) = 0;
        JmlPakaiTotal(P) = 0;
        HasilToday(P) = 0;
        HasilTotal(P) = 0;
        MakeEmptyAntrian(&Antrian(P),KapasitasBang(P));
        (*durasi) += 60;
        tambahBBS(bbs,(wahana[i-1]->info).resource.resource);
        (*bill) += 2*HUpgrade(P);
        // TulisPOINT(point(*P));
        // printf("\n\n");
        char move [2];
        if(Ordinat(point(P))==1){
            
            strcpy(move,"s");
            
        }else{
            strcpy(move,"w");
        }
        Move(G,move);
        Elmt((Wilayah(*G,wilayah(P))).Map,Ordinat(point(P)),Absis(point(P))) ='W';
        InsertLast(bg,P);    
        // printf("ssss");
    } else {
        printf("bahan atau uang tidak cukup ");
    }
} 

   boolean BBcukup(BAHAN BB,BAHAN BBS, int* R){
       return (wood(BB)>=R[0]+wood(BBS) && stone(BB)>=R[1]+stone(BBS) && gold(BB)>=R[2]+gold(BBS));
   }

    boolean Moneycukup(int money,int bill, int hargawahana){
        return(money-(bill+ 2*hargawahana));
    }
    void tambahBBS(BAHAN *BBS, int* R){
        wood(*BBS) += R[0];
        stone(*BBS) += R[1];
        gold(*BBS) += R[2];
    }
// char inttochar(int d){
//     switch (d)
//     {
//     case 0:
//         return '0';
//     case 1:
//         return '1';
//     case 2:
//         return '2';
//     case 3:
//         return '3';
//     case 4:
//         return '4';
//     case 5:
//         return '5';
//     case 6:
//         return '6';
//     case 7:
//         return '7';
//     case 8:
//         return '8';
//     case 9:
//         return '9';
//     }
// }