#include "execute.h"
#include <string.h>
void runCommand(char* strcmd) {
    if (strcmp(strcmd,"build")==0) {
        printf("build dijalankan\n"); // masih placeholder
    } else if (strcmp(strcmd,"upgrade")==0) {
        printf("upgrade dijalankan\n"); // masih placeholder
    } else if (strcmp(strcmd,"buy")==0) {
        printf("buy dijalankan\n"); // masih placeholder
    }
}

void execute(Stack stackawal, Stack stacktarget) {
    char* strcmd;
    while (!IsEmpty(stackawal))
    {
        Pop(&stackawal, &strcmd);
        Push(&stacktarget, strcmd);
    }
    while (!IsEmpty(stacktarget))
    {
        Pop(&stacktarget, &strcmd);
        runCommand(strcmd);
    }
}


