#include "undo.h"
void undo(BAHAN* bbs,GraphMap *G, int *durasi,int *bill,StackCond *sc){
    Kondisi kond;

    PopKond(sc, &kond);
    // PopKond(sc, &kond);
    *durasi = WaktuCond(kond);
    *bill = UangCond(kond);

    wood(*bbs) = wood(BahanCond(kond));
    stone(*bbs) = stone(BahanCond(kond));    
    gold(*bbs) = gold(BahanCond(kond));
    CopyMATRIKS(MapCond(kond),&(Wilayah((*G),WilayahCond(kond)).Map));
    
}

void inputbefore(BAHAN bbs,GraphMap G, int durasi,int bill,StackCond *sc){
    Kondisi Buildbefore;
    WaktuCond(Buildbefore) = durasi;
    UangCond(Buildbefore) = bill;
    wood(BahanCond(Buildbefore)) = wood(bbs);
    stone(BahanCond(Buildbefore)) = stone(bbs);
    gold(BahanCond(Buildbefore)) = gold(bbs);
    WilayahCond(Buildbefore) = SearchWilayahPlayer(G);
    Elmt(Wilayah(G,SearchWilayahPlayer(G)).Map,Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition),Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition)) = '-';
    CopyMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map, &MapCond(Buildbefore));
    PushKond(sc,Buildbefore);
}

                