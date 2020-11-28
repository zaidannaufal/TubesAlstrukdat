#include "graphmap.h"
#include "boolean.h"
#include "build.h"
#define NilStack -1
#define MaxElStack 20 

typedef struct {
    Kondisi T[MaxElStack];
    int TOP;
} addressTOP;

typedef struct {
    int waktu;
    int uang;
    BAHAN bahan;
    MATRIKS Map;
    int Wilayah;
} Kondisi;

#define Top(S) (S).TOP
#define waktuStack(S) (S.T[Top]).waktu 
#define bahanStack(S) (S.T[Top]).bahan
#define MapStack(S) (S.T[Top]).Map
#define WilayahStack(S) (S.T[Top]).Wilayah
#define uangStack(S) (S.T[Top]).uang

#endif