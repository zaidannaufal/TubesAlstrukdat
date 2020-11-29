// #include "graphmap.h"
// #include "boolean.h"
// #include "build.h"
#include "execute.h"
#define NilStack -1
#define MaxElStack 20 

#ifndef STACKTKONDISI_H
#define STACKTKONDISI_H

typedef struct {
    int waktu; //totalwaktu 
    int uang; //totaluang
    BAHAN bahan;//bbs
    MATRIKS Map;//Wilayah(G,WilayahCond(x)).Map)
    int Wilayah;
    ListBangunan ListEx;
} Kondisi;

typedef struct {
    Kondisi T[MaxElStack];
    int TOP;
} StackCond;



#define Top(S) (S).TOP
#define Cond(S) (S).T[(S).TOP]
#define WaktuCond(K) K.waktu
#define UangCond(K) K.uang
#define BahanCond(K) K.bahan
#define MapCond(K) K.Map
#define WilayahCond(K) K.Wilayah 
#define ListB(K) K.ListEx 

boolean IsEmptyKondisi(StackCond S);
void CreateEmptyKondisi (StackCond *S);
void PushKond (StackCond *S, Kondisi X);
void PopKond (StackCond *S, Kondisi *X);
void printKond(Kondisi X);
#endif