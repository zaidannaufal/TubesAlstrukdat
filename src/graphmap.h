#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include "matriks.h"
#include "point.h"

typedef struct{
    MATRIKS Map;
    int Number;
    POINT NextGate;
    POINT PrevGate;
    POINT PlayerPosition;
} Vertices;

typedef struct{
    int Origin;
    int Succ;
} Edge;

typedef struct{
    Vertices Wilayah[4];
    Edge Lorong[8];
} GraphMap;

#define Wilayah(G,i) (G).Wilayah[(i)]
#define Lorong(G) (G).Lorong

MATRIKS MakeMAP();
//Buat Base Map per wilayah
void GateIdentifier(int NWilayah , GraphMap * G);
//Menginisiasi nilai nextgate, prevgate, lorong
GraphMap BacaMapTXT();
//Baca Map txt
// void InitiateLorong(GraphMap * G);

// void InitiatePlayerPosition(GraphMap * G);

#endif