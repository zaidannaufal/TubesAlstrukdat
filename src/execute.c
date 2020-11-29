#include "execute.h"

#include <string.h>
void runCommand(char* strcmd,ListBangunan *nonex,ListBangunan *ex) {
    
}

void execute(Stack stackawal, Stack stacktarget,ListBangunan *nonex,ListBangunan *ex) {
    char* strcmd;
    while (!IsEmptyStack(stackawal))
    {
        Pop(&stackawal, &strcmd);
        Push(&stacktarget, strcmd);
    }
    while (!IsEmptyStack(stacktarget))
    {
        Pop(&stacktarget, &strcmd);
        if (strcmp(strcmd,"build")==0) {
            addressbangunan wahana;
            DelFirst(nonex,&wahana);
            InsertLast(ex,wahana);
        } else if (strcmp(strcmd,"upgrade")==0) {
            printf("upgrade dijalankan\n"); // masih placeholder
        } else if (strcmp(strcmd,"buy")==0) {
        // printf("buy dijalankan\n"); // masih placeholder
    }
    }
}


