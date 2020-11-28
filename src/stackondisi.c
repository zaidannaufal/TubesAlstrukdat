#include "stackondisi.h"

void CreateEmptyKondisi (Kondisi *S){
    Top(*S) = NilStack;
    waktuStack(*S) = 0;
    bahanStack(*S).wood = 100000;
    bahanStack(*S).gold = 100000;
    bahanStack(*S).stone = 100000;
    uangStack(*S) = 0;
    WilayahStack(*S) = -1;
}
void Push (Stack * S, Kondisi X){
    Top(*S)++;
    waktuStack(*S) = waktuStack(X);
    bahanStack(*S) = bahanStack(X);
    WilayahStack(*S) = WilayahStack(X);
    uangStack(*S) = uangStack(X);
    CopyMATRIKS(MapStack(X), MapStack(*S));
}

void Pop (Stack* S, Kondisi* X){
    waktuStack(*X) = waktuStack(S);
    bahanStack(*X) = bahanStack(S);
    WilayahStack(*X) = WilayahStack(S);
    uangStack(*X) = uangStack(S);
    CopyMATRIKS(MapStack(S), MapStack(*X));
    Top(*S)--;
}
