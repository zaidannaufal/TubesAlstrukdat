#include "execute.h"

void runCommand(char* strcmd) {
    PERINTAH per = siapkan_perintah();
    if (compare_string(strcmd,Command(per,3))) {
        printf("build dijalankan\n"); // masih placeholder
    } else if (compare_string(strcmd,Command(per,4))) {
        printf("upgrade dijalankan\n"); // masih placeholder
    } else if (compare_string(strcmd,Command(per,5))) {
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


