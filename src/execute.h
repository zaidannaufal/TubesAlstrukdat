#ifndef EXECUTE_H
#define EXECUTE_H

#include "build.h"
#include "bangunan.h"
#include "stackt.h"
// #include "perintah.h"
// #include "office.h"
#include <stdio.h> // selagi .c masih placeholder

void runCommand(char* strcmd,ListBangunan *nonex,ListBangunan *ex);
void execute(Stack stackawal, Stack stacktarget,ListBangunan *nonex,ListBangunan *ex);

#endif