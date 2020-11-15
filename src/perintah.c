#include "perintah.h"
#include <stdio.h>

boolean compare_string(char *a, char *b){
    boolean same = true;
    while (*a != '\0' && *b != '\0' && same){
        same = (*a == *b) ? true : false ;
        a++;
        b++;
        }
    if (same && *a == '\0' && *b == '\0' )
        return 1;
    else {
        return 0;
    }

}
void copystr(Kata *destination, const char source[]) {
    (*destination).Length = 0;
    int i;
    for (i = 0 ; source[i] != '\0'; i++) {
        (*destination).TabKata[i] = source[i];
        (*destination).Length++;
    }
    for(i;i != NMax-1;i++){
        (*destination).TabKata[i] = '\0';
    }
}

void tulisstr(char string[]){
    for (int i = 0; string[i] != '\0'; i++){
        printf("%c",string[i]);
    }
}

PERINTAH siapkan_perintah(){ //cara naif siap kan perintah
    PERINTAH per;
    per.total = 0; 
    copystr( &(per.command[0]), "new\0");
    copystr( &(per.command[1]), "load\0");
    copystr( &(per.command[2]), "exit\0");
    copystr( &(per.command[3]), "build\0");
    copystr( &(per.command[4]), "upgrade\0");
    copystr( &(per.command[5]), "buy\0");
    copystr( &(per.command[6]), "undo\0");
    copystr( &(per.command[7]), "execute\0");
    copystr( &(per.command[8]), "main\0");
    copystr( &(per.command[9]), "serve\0");
    copystr( &(per.command[10]), "repair\0");
    copystr( &(per.command[11]), "detail\0");
    copystr( &(per.command[12]), "office\0");
    copystr( &(per.command[13]), "Details\0");
    copystr( &(per.command[14]), "Report\0");
    copystr( &(per.command[15]), "Exit\0");
    copystr( &(per.command[16]), "prepare\0");
    per.total = 17;
    return per;
}
