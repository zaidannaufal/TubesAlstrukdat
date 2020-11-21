#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include "matriks.h"
#include "point.h"

typedef struct{
    MATRIKS Map;
    short Number;
    POINT NextGate;
    POINT PrevGate;
    POINT PlayerPosition;
} Vertices;

typedef struct{
    short Prec;
    short Succ;
} Edge;

typedef struct{
    Vertices Wilayah[4];
    Edge Lorong[8];
} GraphMap;

#define Wilayah(G,i) (G).Wilayah[(i)]
#define Lorong(G) (G).Lorong


short FindPLayerWilayah(GraphMap G);
//Kalau di vertice itu gaada player berarti
//player position di vertice itu (-1,-1)

void PlayerMove(GraphMap * G, char C);

#endif