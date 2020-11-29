#include "jam.h"
// #include "build.h"
#include "repair.h"

addressbangunan searchByLokasi(ListBangunan Wahana, int x, int y, GraphMap G);

boolean isKiriWahana(GraphMap G, int x, int y, int w);
 
boolean isKananWahana(GraphMap G, int x, int y, int w);
    
boolean isAtasWahana(GraphMap G, int x, int y, int w);

boolean isBawahWahana(GraphMap G, int x, int y, int w);

void printDetail(addressbangunan wahana);

void detail(GraphMap G, ListBangunan Wahana);