#ifndef UPGRADE_H
#define UPGRADE_H

#include "bangunan.h"
#include "bintreebangunan.h"
#include "build.h"

int TipeRootWahana(char* NamaWahana, ListBangunan * LB);

void Upgrade(ListBangunan * LB, BinTree* BT, BAHAN* bb, int * Bill, int * Aksi, int CurrentMoney, int TambahanWaktu);

#endif