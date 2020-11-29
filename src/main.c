#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"
#include "asset.c"
#include "matriks.h"
#include "bintreebangunan.h"
#include "graphmap.h"
#include "jam.h"
// #include "buy.h"
// #include "stackt.h"
// #include "stackondisi.h"
#include "undo.h"

int main() {
    int gamestart = 0; // kalo 0 berarti game belum jalan
    ListBangunan BangunanNonEx, BangunanEx;
    char nama[100];
    char menu[100];
    char input[100];
    BAHAN bb,bbs;
    wood(bb) = 100000;
    stone(bb) = 100000;
    gold(bb) = 100000;
    wood(bbs) = 0;
    stone(bbs) = 0;
    gold(bbs) = 0;
    Menu();
    printf("\n");
    Menuawal();
    CreateEmptyBangunan(&BangunanEx);
    CreateEmptyBangunan(&BangunanNonEx);
    //sudah pake mesin kata sort of :( 
    int idxMenu = 0;
    do {
        scanf("%c", menu + idxMenu);
    } while (menu[idxMenu++] != '\n');
    menu[--idxMenu] = '\0';

    if(strcmp(menu,"New")==0||strcmp(menu,"new")==0){
        int idxNama = 0;
        printf("Memulai permainan baru...\n");
        printf("Masukkan Nama: ");
        do {
            scanf("%c", nama + idxNama);
        } while (nama[idxNama++] != '\n');
        nama[--idxNama] = '\0';
        gamestart = 1;
    }
    printf("\n");
    
    MATRIKS map;
    POINT playerpos;
    Stack stackawal, stacktarget;
    StackCond Conawal;
    CreateEmptyKondisi(&Conawal);
    BinTree wahana[4];
    bacatree(wahana);
    CreateEmptyStack(&stackawal);
    CreateEmptyStack(&stacktarget);
    JAM waktu = MakeJAM(0,0,0);
    JAM waktubuka = MakeJAM(9,0,0);
    JAM waktututup = MakeJAM(21,0,0);
    int sisawaktu = 720;
    int money = 50000;
    int totalaksi = 0 ;
    int totalwaktu = 0; 
    int totaluang=0;
    GraphMap G = BacaMapTXT();    
    InitiatePlayerPosition(&G);

    do{
        TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
        printf("\n");
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");
        printf("\n");
        
        printf("Name: ");
        puts(nama);
        printf("Money: %d\n",money);
        printf("Current Time: ");TulisJAM(waktu);printf("\n");
        printf("Opening Time: ");TulisJAM(waktubuka);printf("\n");
        printf("Time Remaining: ");TulisJAM(DetikToJAM(Durasi(waktu,waktubuka))); printf("\n");
        printf("Total aksi yang akan dilakukan: %d\n",totalaksi);
        printf("Total waktu yang dibutuhkan: ");
        printSisaWaktu(totalwaktu);
        printf("\n");
        printf("Total uang yang dibutuhkan: %d\n",totaluang);
        printf("\n");
        printbahan(bb);
        printbahan(bbs);
        printf("\n");
        printf("command:");
        
        int idxInput = 0;
        do {
            scanf("%c", input + idxInput);
        } while (input[idxInput++] != '\n');
        input[--idxInput] = '\0';
		printf("\n");
        
        if((strcmp(input,"w")==0)||(strcmp(input,"a")==0)||(strcmp(input,"s")==0)||(strcmp(input,"d")==0)){
            if (isWaktuCukup(waktu,waktubuka,totalwaktu,5)){
                Move(&G,input);
                waktu = NextNDetik(waktu,5*60);
            }
        }else if (strcmp(input,"Build")==0){
            if (isWaktuCukup(waktu,waktubuka,totalwaktu,15)){
                
                inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                // build(wahana, bb,&bbs,&G,&BangunanNonEx,&totalwaktu,money,&totaluang);
                build(wahana, bb,&bbs,&G,&BangunanEx,&totalwaktu,money,&totaluang);
                totalaksi++;
                char B[20];
                strcpy(B,"build");
                Push(&stackawal,B);
                   
            }else{
                printf("waktu tidak mencukupi");
            }
            // tinggal si address p nya kemanain
        // }else if (strcmp(input,"Execute")) // execute
        // {
        //     execute(stackawal, stacktarget);
        }else if (strcmp(input,"Upgrade")==0){
            if (!IsEmptyBangunan(BangunanEx)){
                inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                Upgrade(&BangunanEx,wahana,bb,&bbs,&totaluang,&totalaksi,money,&totalwaktu);
                char B[20];
                strcpy(B,"upgrade");
                Push(&stackawal,B);
                printwahana(First(BangunanEx));
            }else {
                printf("tidak ada wahana yang bisa diupgrade");
            }
        }else if(strcmp(input,"Execute")==0){
            execute(stackawal,stacktarget,&BangunanNonEx,&BangunanEx);
            wood(bb) -= wood(bbs);
            stone(bb) -= stone(bbs);
            gold(bb) = gold(bb);
            money -= totaluang;
            totalwaktu = 0;
            totaluang = 0;
            wood(bbs) = 0;
            stone(bbs) = 0;
            gold(bbs) = 0;
            totalaksi = 0;
        }else if (strcmp(input,"Buy")==0){
            if (isWaktuCukup(waktu,waktubuka,totalwaktu,15)){
                inputbefore(bbs,G,totalwaktu,totaluang,&Conawal,BangunanEx);
                buy(money,&totaluang,&totalaksi,&totalwaktu,&bbs);
                char bu[20];
                strcpy(bu,"buy");
                Push(&stackawal,bu);
            }else {
            printf("waktu tidak mencukupi");
            }
        }else if (strcmp(input,"Undo")==0){
            if (!IsEmptyKondisi(Conawal)){
                POINT Pbefore; 
                Absis(Pbefore) = Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                Ordinat(Pbefore) = Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition);
                char* buffer;
                Pop(&stackawal, &buffer);
                if (strcmp(buffer,"build")==0){
                    addressbangunan bufferP;
                    DelLast(&BangunanNonEx,&bufferP);
                    Dealokasi(&bufferP);
                }// }else if(strcmp(buffer,"upgrade")==0){

                // }
                undo(&bbs,&G,&totalwaktu,&totaluang,&Conawal,&BangunanEx);
                Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Absis(Pbefore);
                Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition) = Ordinat(Pbefore);
                Elmt(Wilayah(G,SearchWilayahPlayer(G)).Map,Ordinat(Pbefore),Absis(Pbefore)) = 'P';
                totalaksi--;
            }else{
                printf("ga ada yg bisa di undo\n");
            }
            
        }else if (strcmp(input,"Main")==0){
            DelAll(&BangunanNonEx);
            char* buffer;
            while (!IsEmptyStack(stackawal)){
                Pop(&stackawal,buffer);    
            }
            Kondisi X;
            while(!IsEmptyKondisi){
                PopKond (&Conawal,&X);   
            }
            totalwaktu = 0;
            totaluang = 0;
            wood(bbs) = 0;
            stone(bbs) = 0;
            gold(bbs) = 0;
            totalaksi = 0;
            gamestart = 2;

        }else if (strcmp(input,"Exit")==0){
            gamestart = 0;
        }else{
            printf("Input salah, silakan coba lagi.\n");
        }

    }while (gamestart == 1);


    JAM waktututup = MakeJAM(21,0,0);
    int sisawaktu = 720;
    Antrian QueueAntrian;    
    do {
        printf("Main phase day berapa gitu\n"); // HAHAHAHAHAHAHAHAHAHHA
        TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
        printf("\n");
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");
        printf("\n");
        
        printf("Name: ");
        puts(nama);
        printf("Money: %d\n",money);
        printf("Current Time: ");TulisJAM(waktu);printf("\n");
        printf("Closing Time: ");TulisJAM(waktututup);printf("\n");
        printf("Time Remaining: ");TulisJAM(DetikToJAM(Durasi(waktubuka,DetikToJAM(sisawaktu*60)))); printf("\n");
        printf("Antrian [%d/5]:\n", NBElmtAntrian(QueueAntrian)); // HAHAHAHAHAHAHAHAHHA
        
        printf("\n");
        printf("command:");

        int idxInput = 0;
        do {
            scanf("%c", input + idxInput);
        } while (input[idxInput++] != '\n');
        input[--idxInput] = '\0';
		printf("\n");
        
        if((strcmp(input,"w")==0)||(strcmp(input,"a")==0)||(strcmp(input,"s")==0)||(strcmp(input,"d")==0)){
            if (isWaktuCukup(waktu,waktubuka,totalwaktu,5)){
                Move(&G,input);
                waktu = NextNDetik(waktu,5*60);
            }
        } else if (strcmp(input,"serve")==0){ 
        
        } else if (strcmp(input,"repair")==0){ 
            
        } else if (strcmp(input,"detail")==0){ 
            
        } else if(strcmp(input,"office")==0){ 
            Office(&BangunanEx);
        } else if (strcmp(input,"prepare")==0){
            addressbangunan P;
            P = First(BangunanEx);
            while (Info(BangunanEx) != NULL)
            { 
                JmlPakaiToday(P) = 0;
                HasilToday(P) = 0;
                
            }
        } else if(strcmp(input,"exit")==0){ // HAHAHHAHAHAHDAKWFBHGWFUIGFBMEJGFUW
            Office(&BangunanEx);
        } else{
            printf("Input salah, silakan coba lagi.\n");
        } 

    } while (gamestart == 2);

    return 0;
}
