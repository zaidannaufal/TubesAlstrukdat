// #include "graphmap.h"
// #include "boolean.h"
// #include "build.h"
#include "upgrade.h"
#define NilStack -1
#define MaxElStack 20 

#ifndef STACKTKONDISI_H
#define STACKTKONDISI_H

typedef struct {
    Kondisi T[MaxElStack];
    int TOP;
} StackCond;

typedef struct {
    int waktu;
    int uang;
    BAHAN bahan;
    MATRIKS Map;
    int Wilayah;
} Kondisi;

#define Top(S) (S).TOP
#define Cond(S) (S).T[(S).TOP]
#define WaktuCond(K) K.waktu
#define UangCond(K) K.uang
#define BahanCond(K) K.bahan
#define MapCond(K) K.Map
#define WilayahCond(K) K.Wilayah  

void CreateEmptyKondisi (StackCond *S);
void Push (StackCond *S, Kondisi X);
void Pop (StackCond *S, Kondisi *X);
#endif