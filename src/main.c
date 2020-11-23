#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"
#include "mapAndMovingMechanics.h"
#include "execute.h"
#include "matriks.h"

int main() {
    boolean gamestart = false; // kalo true berarti game jalan
    Kata input; //cuma dipake si tab katanya doang lenght nya belum dipake
    char nama[100];
    PERINTAH per;
    MATRIKS map;
    POINT playerpos;
    Stack stackawal, stacktarget;

    CreateEmpty(&stackawal);
    CreateEmpty(&stacktarget);

    per = siapkan_perintah();
    map = renderMap();
    initiatePlayerPosition(&map,&playerpos);

    printf("Willy Wangky's World\n");
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf(" New game / load game / exit? //\n");
    scanf("%s",input.TabKata);
    if(compare_string(input.TabKata,Command(per,0))){ //kalo dimasukkin command 1 bakal gamestart
        gamestart= true;
    }
    printf("Memulai permainan baru...\n");
    printf("Masukkan Nama: ");
    scanf("%s", nama);
    
    while (gamestart)
    {
        printf("\n");
        TulisMATRIKS(map);
        printf("\n");
        printf("Legend:\n");
        printf("A = Antrian\n");
        printf("P = Player\n");
        printf("W = Wahana\n");
        printf("O = Office\n");
        printf("<, ^, >, V = Gerbang\n");
        printf("\n");

        printf("Name: %s\n",nama);
        printf("Money:\n");
        printf("Current Time: \n");
        printf("Opening Time: \n");
        printf("Time Remaining: \n");
        printf("Total aksi yang akan dilakukan: \n");
        printf("Total waktu yang dibutuhkan: \n");
        printf("Total uang yang dibutuhkan: \n");
        
        scanf("%s",input.TabKata);
        // printf("%c %c",input.TabKata[0],input.TabKata[1]);
        if(compare_string(input.TabKata,Command(per,2))){ //kalo dimasukkin command 2 (exit) bakal ke exit
            gamestart = false;
        } else if (compare_string(input.TabKata,Command(per,16))||compare_string(input.TabKata,Command(per,17))
                || compare_string(input.TabKata,Command(per,18)) || compare_string(input.TabKata,Command(per,19))) // ini liat commandnya di fungsi siapkan perintah yah
        {
            movePlayer(&map,&playerpos,input.TabKata[0]);
        }
        else if (compare_string(input.TabKata,Command(per,7))) // execute
        {
            execute(stackawal, stacktarget);
        }

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
    }

    return 0;
}
