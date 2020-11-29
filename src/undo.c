#include "undo.h"
void undo(BAHAN* bbs,GraphMap *G, int *durasi,int *bill,StackCond *sc,ListBangunan *ex){
    Kondisi kond;

    PopKond(sc, &kond);
    // PopKond(sc, &kond);
    *durasi = WaktuCond(kond);
    *bill = UangCond(kond);

    wood(*bbs) = wood(BahanCond(kond));
    stone(*bbs) = stone(BahanCond(kond));    
    gold(*bbs) = gold(BahanCond(kond));
    CopyMATRIKS(MapCond(kond),&(Wilayah((*G),WilayahCond(kond)).Map));
    First(*ex) = First(ListB(kond));
}

void inputbefore(BAHAN bbs,GraphMap G, int durasi,int bill,StackCond *sc,ListBangunan lB){
    Kondisi Buildbefore;
    WaktuCond(Buildbefore) = durasi;
    UangCond(Buildbefore) = bill;
    wood(BahanCond(Buildbefore)) = wood(bbs);
    stone(BahanCond(Buildbefore)) = stone(bbs);
    gold(BahanCond(Buildbefore)) = gold(bbs);
    WilayahCond(Buildbefore) = SearchWilayahPlayer(G);
    Elmt(Wilayah(G,SearchWilayahPlayer(G)).Map,Ordinat(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition),Absis(Wilayah(G,SearchWilayahPlayer(G)).PlayerPosition)) = '-';
    CopyMATRIKS(Wilayah(G,SearchWilayahPlayer(G)).Map, &MapCond(Buildbefore));
    ListB(Buildbefore) = FCopyList(lB);
    PushKond(sc,Buildbefore);
}

                