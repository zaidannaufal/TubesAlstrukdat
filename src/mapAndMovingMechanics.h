#ifndef MAPANDMOVINGMECHANICS_H
#define MAPANDMOVINGMECHANICS_H

#include "matriks.h"
#include <stdio.h>
#include "point.h"


MATRIKS renderMap();
void initiatePlayerPosition(MATRIKS * M , POINT * P);
void movePlayer(MATRIKS * M , POINT * P, char C);

#endif