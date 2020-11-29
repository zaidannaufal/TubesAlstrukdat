#ifndef MEKANISMEPERMAINAN_H
#define MEKANISMEPERMAINAN_H

#include "antrian.h"
#include "bangunan.h"

void NgosonginAntrian(Antrian * A, int i);

void MekanismeGaSabar(Antrian * A, int IntervalWaktu);

void MekanismeNaikWahana(Antrian * A, ListBangunan * LB, int IntervalWaktu);
#endif