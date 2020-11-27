/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#include "bintreebangunan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bacatree(BinTree* aowahana){
    int i=0;
    EndKata = false;
    BinTree wahana=Niltree;
    infotypetree X;
    // wahana = AlokNode(X);
    STARTKATA("../external/wahana.txt");
    
    while (!EndKata){
        int x = 0;
        if (CKata.TabKata[0]=='-'){
            aowahana[i] = wahana;
            i++;
            wahana = Niltree;
        } else{
            wahana = parsing(CKata);
            ADVKATA();
            Left(wahana) = parsing(CKata);
            ADVKATA(); 
            Left(Left(wahana)) = parsing(CKata);
        }
        ADVKATA();
    }
}
// void wahanatree(BinTree *T){
//     BinTree temp = parsing(CKata);
//     if (CKata.TabKata[0]!='-'){

//     }else {
//         ADVKATA();
//         wahanatree(&Left(temp));
//         *T = temp;
//         printtree(*T);
//     }
// }

BinTree parsing(Kata CKata){
    infotypetree X;
    BinTree wahana = AlokNode(X);
    int count = 0;
    int i = 0, begin = 0;
    for (i=0;i<CKata.Length;i++){
        if (CKata.TabKata[i]==','){
            // printf("count ke -%d\n",count);
            switch (count)
            {
            case 0:
                copystringtree(tipe(wahana),CKata.TabKata,begin,i);
                // printstring(tipe(wahana));
                // printf("\n");
                break;
            case 1:
                copyinttree(&(harga(wahana)),CKata.TabKata,begin,i);
                // printf("%d",harga(wahana));
                // printf("\n");
                break;
            case 2:
                copyinttree(&(kapasitas(wahana)),CKata.TabKata,begin,i);
                break;
            case 3:
                copyinttree(&(durasi(wahana)),CKata.TabKata,begin,i);
                break;
            case 4: //deskripsi wahana
                copystringtree(deskripsi(wahana),CKata.TabKata,begin,i);
                break;
            case 5:
                copyinttree(&(HUpgrade(wahana)),CKata.TabKata,begin,i);
                break;
            case 6:
                copyinttree(&(resource(wahana,0)),CKata.TabKata,begin,i);
                break;
            case 7:
                copyinttree(&(resource(wahana,1)),CKata.TabKata,begin,i);
                break;
            case 8:
                copyinttree(&(resource(wahana,2)),CKata.TabKata,begin,i);
                break;
            case 9:
                // copyinttree(&(resource(wahana,3)),CKata.TabKata,begin,i);
                break;
            }
            // printf("%d\n",begin);
            // printf("%c\n",CKata.TabKata[begin]);
            begin = i+1;
            count++;
        }
        

    }
    return wahana;

}

void copystringtree(char* dest,char* sumber,int begin,int last)
{
    int j = 0;
    for(int i = begin; i<last;i++){
        dest[j] = sumber[i];
        j++; 
    }
    for(j;j != 100-1;j++){
        dest[j] = '\0';
    }
}

void copyinttree(int * dest, char* sumber,int begin,int last){
    int count = 0;
    for (int i = begin; i<last;i++){
        // printf("%c",sumber[i]);
        switch (sumber[i])
        {
        case '0':
            count = 10*count + 0;
            break; 
        case '1':
            count = 10*count + 1;
            break; 
        case '2':
            count = 10*count + 2;
            break; 
        case '3':
            count = 10*count + 3;
            break; 
        case '4':
            count = 10*count + 4;
            break; 
        case '5':
            count = 10*count + 5;
            break; 
        case '6':
            count = 10*count + 6;
            break; 
        case '7':
            count = 10*count + 7;
            break; 
        case '8':
            count = 10*count + 8;
            break; 
        case '9':
            count = 10*count + 9;
            break; 
        }
    }
    // printf("%d\n",count);
    *dest = count;
}

void printstring(char* string){
    int i=0;
    while (string[i]!='\0')
    {
        printf("%c",string[i]);
        i++;
    }
    
}
void printtree(BinTree wahana){
    printf("tipe wahana = ");
    printstring(tipe(wahana));
    printf("\n");
    printf("harga = %d\n",harga(wahana));
    printf("deksripsi = ");
    printstring(deskripsi(wahana));
    printf("\n");
    printf("kapasitas = %d\n",kapasitas(wahana));
    printf("durasi = %d\n",durasi(wahana));
    printf("bahan 0 = %d\n",resource(wahana,0));
    printf("bahan 1 = %d\n",resource(wahana,1));
    printf("bahan 2 = %d\n",resource(wahana,2));
}

/* *** Konstruktor *** */
BinTree Tree (infotypetree Akar, BinTree L, BinTree R) {
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
  BinTree P;
  P = AlokNode(Akar);
  if (P != Niltree) {
    Left(P) = L;
    Right(P) = R;
  }
  return P;
}

// /* Manajemen Memory */
addrNode AlokNode (infotypetree X) {
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
  addrNode P;
  P = (addrNode) malloc (sizeof(Node));
  if (P!= Niltree) {
    Akar(P) = X;
    Left(P) = Niltree;
    Right(P) = Niltree;
  }
  return P;
}

void DealokNode (addrNode P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
  free(P);
}

int searchtipetree(BinTree* aowahana, char* string,int jmlhwahana){ //error njirrr
    int i =0;
    while (i<jmlhwahana);
    {
        if(strcmp(string,tipe(aowahana[i]))==0){
            return i;
        }
        i++;
    }
    return -1;
};  