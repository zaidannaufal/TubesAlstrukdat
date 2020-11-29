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

void build(BinTree* wahana, BAHAN bb,BAHAN* bbs,GraphMap *G, ListBangunan *bg,int *durasi,int money,int *bill);
boolean BBcukup(BAHAN BB,BAHAN BBS, int* R);
boolean Moneycukup(int money,int bill, int hargawahana);
void tambahBBS(BAHAN *BBS, int* R);
#endif