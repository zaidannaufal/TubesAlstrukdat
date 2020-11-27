#ifndef GRAPHMAP_H
#define GRAPHMAP_H

#include "matriks.h"
#include "point.h"
#include "boolean.h"

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
    Edge Lorong[4];
} GraphMap;

#define Wilayah(G,i) (G).Wilayah[(i)]
#define Lorong(G) (G).Lorong

MATRIKS MakeMAP();
//Buat Base Map per wilayah
void GateIdentifier(int NWilayah , GraphMap * G);
//Menginisiasi nilai nextgate, prevgate, lorong
GraphMap BacaMapTXT();
//Baca Map txt
void InitiatePlayerPosition(GraphMap * G);

int SearchWilayahPlayer(GraphMap G);

boolean IsPindahWilayahAtas(GraphMap G);

boolean IsPindahWilayahBawah(GraphMap G);

boolean IsPindahWilayahKanan(GraphMap G);

boolean IsPindahWilayahKiri(GraphMap G);

boolean IsPindahLokalAtas(GraphMap G);

boolean IsPindahLokalBawah(GraphMap G);

boolean IsPindahLokalKanan(GraphMap G);

boolean IsPindahLokalKiri(GraphMap G);

void Move(GraphMap * G, char* C);

POINT LokasiEntranceSucc(int Succ , GraphMap G);

POINT LokasiEntranceOrigin(int Origin, GraphMap);

void PindahWilayahSucc(GraphMap * G);

void PindahWilayahOrigin(GraphMap * G);

#endif