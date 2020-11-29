

#include "jam.h"
#include "build.h"




int randomPickInt(int rangeawal, int rangeakhir);

addressbangunan randomWahana(ListBangunan Wahana);

void breakWahana(ListBangunan Wahana);

address brokenWahana(ListBangunan Wahana);

boolean isNextWahana (GraphMap G, addressbangunan P);

BinTree resourceWahana (BinTree InfoWahana[4], int Tipe, ListBangunan Wahana);

int setengahResource (BinTree P, int i);

void repair(int *uang, int *aksi, int *jam, int *remaining, GraphMap G, ListBangunan *Wahana);
