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
#include "build.h"
// #include "execute.h"

int main() {
    boolean gamestart = false; // kalo true berarti game jalan
    List BangunanNonEx;
    List BangunanEx;
    char nama[100];
    char menu[100];
    char input[100];
    BAHAN bb;
    bb.Wood = 100000;
    bb.Stone = 100000;
    bb.Gold = 100000;
    Menu();
    printf("\n");
    Menuawal();

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
        gamestart = true;
    }
    printf("\n");
    
    MATRIKS map;
    POINT playerpos;
    // Stack stackawal, stacktarget;
    BinTree wahana[4];
    bacatree(wahana);
    // CreateEmpty(&stackawal);
    // CreateEmpty(&stacktarget);
    JAM waktu = MakeJAM(0,0,0);
    JAM waktubuka = MakeJAM(9,0,0);
    int money = 100000;
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
        printf("Total waktu yang dibutuhkan: %d\n",totalwaktu);
        printf("Total uang yang dibutuhkan: %d\n",totaluang);
        printf("command:");
        
        int idxInput = 0;
        do {
            scanf("%c", input + idxInput);
        } while (input[idxInput++] != '\n');
        input[--idxInput] = '\0';
		printf("\n");
        
        puts(input);
        if((strcmp(input,"w")==0)||(strcmp(input,"a")==0)||(strcmp(input,"s")==0)||(strcmp(input,"d")==0)){
            Move(&G,input);
        }else if (strcmp(input,"Build")==0){
            int buildsuccess;
            infotypeW X;
            address P = Alokasi(X);
            buildsuccess = build(wahana,&bb,&G,&P);
            if (buildsuccess==1){
                InsertLast(&BangunanEx,P);
            }
            // tinggal si address p nya kemanain
        // }else if (strcmp(input,"Execute")) // execute
        // {
        //     execute(stackawal, stacktarget);
        }else
        {
            printf("inputsalah\n");
        }
          

    }while (gamestart);
    // printf("%d",compare_string(input,Command(per,0)));
    // if(compare_string(input,Command(per,0))){ //kalo dimasukkin command 1 bakal gamestart
    //     printf("sampaisini");
    //     gamestart= true;
    // }
    
    // fgets(nama, 20, stdin);
    // printf()
    // while (gamestart)
    // {
    //     printf("sampai sini");
    //     printf("\n");
    //     TulisMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map);
    //     printf("\n");

    //     printf("Name: ");
    //     tulisstr(nama);
    //     printf("\n");
    //     printf("Money:\n");
    //     printf("Current Time: \n");
    //     printf("Opening Time: \n");
    //     printf("Time Remaining: \n");
    //     printf("Total aksi yang akan dilakukan: \n");
    //     printf("Total waktu yang dibutuhkan: \n");
    //     printf("Total uang yang dibutuhkan: \n");
        
        // scanf("%s",input.TabKata);
        // // printf("%c %c",input.TabKata[0],input.TabKata[1]);
        // if(compare_string(input.TabKata,Command(per,2))){ //kalo dimasukkin command 2 (exit) bakal ke exit
        //     gamestart = false;
        // } else if (compare_string(input.TabKata,Command(per,16))||compare_string(input.TabKata,Command(per,17))
        //         || compare_string(input.TabKata,Command(per,18)) || compare_string(input.TabKata,Command(per,19))) // ini liat commandnya di fungsi siapkan perintah yah
        // {
        //     movePlayer(&map,&playerpos,input.TabKata[0]);
        // }
        

        /* setiap input pengguna di preparation phase akan di-push atau di-pop ke stackawal
        run-nya dari execute
        ini bentuknya tapi masih bingung masuknya kemana, maybe nanti pas udah dipisah preparation sama main phase
        Push(&stackawal, "buy");
        Push(&stackawal, "upgrade");
        Push(&stackawal, "build");
        [build, upgrade, buy] */
        
        // }else if(isalpha(input.TabKata)) {
        //     movePlayer(&map,&playerpos,input.TabKata[0]);
        // }
    // }

    return 0;
}
