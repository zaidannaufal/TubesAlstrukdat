#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"
#include "perintah.h"
#include "mapAndMovingMechanics.h"
// void makeemptykata(Kata *perintah);


int main(){
    boolean gamestart = false; // kalo true berarti game jalan
    Kata input; //cuma dipake si tab katanya doang lenght nya belum dipake
    PERINTAH per;
    MATRIKS map;
    POINT playerpos;
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
    
    while (gamestart)
    {
        TulisMATRIKS(map);
        printf("\n");
        printf("ini game\n");
        if(compare_string(input.TabKata,Command(per,2))){ //kalo dimasukkin command 2 bakal ke exit
            gamestart = false;
        }
    }
    return 0;
}
