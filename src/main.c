#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "stdlib.h"

void makeemptykata(Kata *perintah);
int parser_perintah(Kata perintah);

int main(){
    boolean gamestart = false; // kalo true berarti game jalan
    Kata input; //cuma dipake si tab katanya doang lenght nya belum dipake
    int i;
    /* tab katanya diisi oleh . sebagai mark*/
    makeemptykata(&input); // diisi '.' sebagai mark empty ketika semua isi tab kata '.'
    printf("Willy Wangky's World\n");
    printf("// Welcome to Willy wangky's fun factory!!//\n");
    printf(" New game / load game / exit? //\n");

    scanf("%s",input.TabKata);
    printf("%c",input.TabKata[4]);
    // if (input == "New"){
    //     gamestart = true;
    // }
    // while (gamestart)
    // {
    //  printf("ini map");   
        
    // }

    return 0;
}
void makeemptykata(Kata *input){
    boolean found = false;
    int i = 0;
    while ((i < NMax) && ((*input).TabKata[i] != '.')){
        (*input).TabKata[i] = '.';
        i++;
    }
}

int parser_perintah(Kata input){
    // boolean perintah = false;
    // new
    // load
    // exit
    // build
    // upgrade
    // buy
    // undo
    // execute
    // main
    // serve
    // repair
    // detail
    // office
    // Details
    // Report
    // Exit
    // prepare
}
