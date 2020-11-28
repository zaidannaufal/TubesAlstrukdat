#include "stdio.h"
#include "bintreebangunan.h"
#include "bangunan.h"
#include "boolean.h"
#include "graphmap.h"
#ifndef BUILD_H
#define BUILD_H

typedef struct {
  int Wood;
  int Gold;
  int Stone;
} BAHAN;


#define wood(b) (b).Wood
#define stone(b) (b).Stone
#define gold(b) (b).Gold

int build(BinTree* wahana, BAHAN* bb,GraphMap *G,addressbangunan *P);
boolean BBcukup(BAHAN BB, int* R);

#endif