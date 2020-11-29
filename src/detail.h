#include "jam.h"
#include "build.h"

addressbangunan searchByLokasi(ListBangunan Wahana, int x, int y, GraphMap G);

boolean isKiriWahana(GraphMap G, int x, int y, int w);
 
boolean isKananWahana(GraphMap G, POINT P, int x, int y, int w);
    
boolean isAtasWahana(GraphMap G, int x, int y, int w);

boolean isBawahWahana(GraphMap G, int x, int y, int w);

void printDetail(addressbangunan wahana);

void detail(GraphMap G, ListBangunan Wahana);