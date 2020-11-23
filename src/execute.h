#ifndef EXECUTE_H
#define EXECUTE_H

#include "stackt.h"
#include "perintah.h"
#include <stdio.h> // selagi .c masih placeholder

void runCommand(char* strcmd);
void execute(Stack stackawal, Stack stacktarget);

#endif