#ifndef INITANTRI_H
#define INITANTRI_H

#include "antrian.h"
#include "bangunan.h"

typedef char namawahana[50];

typedef namawahana semuawahana[50];

int generaterandomint(int rangeawal, int rangeakhir);

char generaterandomchar();

infoantrian GenerateRandomPeople(int pilihanwahana , semuawahana Array, int urutanantrian);

void InitAntrian(Antrian * A, ListBangunan LB);


#endif