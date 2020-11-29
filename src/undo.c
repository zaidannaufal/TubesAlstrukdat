#include "undo.h"
void undo(BAHAN* bbs,GraphMap *G, int *durasi,int *bill,StackCond *sc){
    Kondisi kond;

    PopKond(sc, &kond);
    // PopKond(sc, &kond);

    durasi = WaktuCond(kond);
    bill = UangCond(kond);

    wood(*bbs) = wood(BahanCond(kond));
    stone(*bbs) = stone(BahanCond(kond));    
    gold(*bbs) = gold(BahanCond(kond));

    CopyMATRIKS(MapCond(kond),&(Wilayah((*G),WilayahCond(kond)).Map));
    
}