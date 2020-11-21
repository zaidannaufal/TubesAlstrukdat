#include "graphmap.h"

short FindPLayerWilayah(GraphMap G)
{
    short i;
    for (i = 0; i < 4; i++)
    {
        int a,b;
        MATRIKS W = Wilayah(G,i).Map;
        for ( a = 0; a <= GetLastIdxBrs(W); a++)
        {
            for ( b = 0; b <= GetLastIdxKol(W); b++)
            {
                if (Elmt(W,a,b) == 'P')
                {
                    return i;
                }
                
            }
            
        }
        
    }
    return -1;
}

POINT FindPLayerPosition(GraphMap G , short N)
{
    POINT P = MakePOINT(-1,-1);
    MATRIKS W = Wilayah(G,N).Map;
    int i,j;
    for ( i = 0; i <= GetLastIdxBrs(W); i++)
    {
        for ( j = 0; j <= GetLastIdxKol(W); j++)
        {
            if (Elmt(W,i,j) == 'P')
            {
                Absis(P) = j;
                Ordinat(P) = i;
            }
            
        }
        
    }
    return P;
}

void PlayerMove(GraphMap * G, char C)
{
    POINT P = Wilayah(*G,NumberWilayah).PlayerPosition;
    MATRIKS W = Wilayah(*G,NumberWilayah).Map;
    if (C == 'w' && Elmt(W,Ordinat(P)-1,Absis(P)) == '-')
    {
        Ordinat(P)--;
    }else if (C == 'a' && Elmt(W,Ordinat(P),Absis(P)-1) == '-')
    {
        Absis(P)--;
    }else if (C == 's' && Elmt(W,Ordinat(P)+1,Absis(P) == '-'))
    {
        Ordinat(P)++;
    }else if (C == 'd' && Elmt(W,Ordinat(P),Absis(P)+1) == '-')
    {
        Absis(P)++;
    }
    Wilayah(*G,NumberWilayah).PlayerPosition = P;
}