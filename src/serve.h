#ifndef SERVE_H
#define SERVE_H

#include "bangunan.h"
#include "antrian.h"
#include "boolean.h"


boolean CompareTujuan(tujuan T, char* NamaWahana);

void CreateEmptySemuaWahana(ListBangunan * ListWahana);

void Serve(Antrian * Antrian, List * ListWahana);
#endif