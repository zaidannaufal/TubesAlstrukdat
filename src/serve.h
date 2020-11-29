#ifndef SERVE_H
#define SERVE_H

// #include "bangunan.h"
// #include "antrian.h"
#include "boolean.h"
#include "initantri.h"

boolean CompareTujuan(tujuan T, char* NamaWahana);

void CreateEmptySemuaWahana(ListBangunan * ListWahana);

void Serve(Antrian * Antrian, ListBangunan * ListWahana, int * Uang);

void NgosonginWahanaPrep(ListBangunan * LB);
#endif