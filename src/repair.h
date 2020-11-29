

#include "jam.h"
#include "build.h"




int randomPickInt(int rangeawal, int rangeakhir);

addressbangunan randomWahana(ListBangunan Wahana);

void breakWahana(ListBangunan *Wahana, JAM jam);

addressbangunan brokenWahana(ListBangunan Wahana);

boolean isNextWahana (GraphMap G, addressbangunan P);

addrNode resourceWahana (BinTree *InfoWahana, int Tipe, addressbangunan Wahana);

int setengahResource (BinTree P, int i);

void repair(int *uang, int *aksi, int *remaining, GraphMap G, ListBangunan *Wahana, BinTree InfoWahana, BAHAN b);
