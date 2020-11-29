#include "undo.h"
void undo(BAHAN* bbs,GraphMap *G, int *durasi,int *bill){
    Kondisi kond;

    PopKond(StackCond, kond);
    PopKond(StackCond, kond);

    durasi = WaktuCond(kond);
    bill = UangCond(kond);

    wood(bbs) = wood(BahanCond(kond));
    stone(bbs) = stone(BahanCond(kond));    
    gold(bbs) = gold(BahanCond(kond));

    CopyMATRIKS(MapCond(kond),(Wilayah(G,WilayahCond(x)).Map));
    Wilayah(G) = WilayahCond(kond);