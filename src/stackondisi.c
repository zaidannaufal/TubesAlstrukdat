#include "stackondisi.h"
#include <stdio.h>
void CreateEmptyKondisi (StackCond *S){
    Top(*S) = NilStack;
    // waktuStack(*S) = 0;
    // bahanStack(*S).wood = 100000;
    // bahanStack(*S).gold = 100000;
    // bahanStack(*S).stone = 100000;
    // uangStack(*S) = 0;
    // WilayahStack(*S) = -1;
}
void PushKond (StackCond *S, Kondisi X){
    Top(*S)++;
    WaktuCond(Cond(*S)) = WaktuCond(X);
    wood(BahanCond(Cond(*S))) = wood(BahanCond(X));
    stone(BahanCond(Cond(*S))) = stone(BahanCond(X));
    gold(BahanCond(Cond(*S))) = gold(BahanCond(X));
    WilayahCond(Cond(*S)) = WilayahCond(X);
    UangCond(Cond(*S)) = UangCond(X);
    CopyMATRIKS(MapCond(X), &MapCond(Cond(*S)));
    printf("sampai sini berhasil push :)\n");
}

void PopKond (StackCond *S,Kondisi *X){
    WaktuCond((*X))= WaktuCond(Cond(*S));
    wood(BahanCond((*X))) = wood(BahanCond(Cond(*S)));
    stone(BahanCond((*X))) = stone(BahanCond(Cond(*S)));
    gold(BahanCond((*X))) = gold(BahanCond(Cond(*S)));
    WilayahCond((*X)) = WilayahCond(Cond(*S));
    UangCond((*X)) = UangCond(Cond(*S));
    CopyMATRIKS(MapCond(Cond(*S)), &MapCond((*X)));
    Top(*S)--;
}
