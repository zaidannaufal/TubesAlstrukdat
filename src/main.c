#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"
#include "perintah.h"
#include "mapAndMovingMechanics.h"


int main(){
    boolean gamestart = false; // kalo true berarti game jalan
    Kata input; //cuma dipake si tab katanya doang lenght nya belum dipake
    PERINTAH per;
    MATRIKS map;
    POINT playerpos;
    printf("loading perintah....");
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
        scanf("%s",input.TabKata);
        // printf("%c %c",input.TabKata[0],input.TabKata[1]);
        if(compare_string(input.TabKata,Command(per,2))){ //kalo dimasukkin command 2 (exit) bakal ke exit
            gamestart = false;
        } else if (compare_string(input.TabKata,Command(per,16))||compare_string(input.TabKata,Command(per,17))
        || compare_string(input.TabKata,Command(per,18)) || compare_string(input.TabKata,Command(per,19))) // ini liat commandnya di fungsi siapkan perintah yah
        {
            movePlayer(&map,&playerpos,input.TabKata[0]);
        }
        
        // }else if(isalpha(input.TabKata)) {
        //     movePlayer(&map,&playerpos,input.TabKata[0]);
        // }

    }
    return 0;
}
