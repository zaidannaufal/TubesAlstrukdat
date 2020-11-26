/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#include "bintreebangunan.h"
#include <stdio.h>
#include <stdlib.h>


void bacatree(BinTree* aowahana){
    int i=0;
    EndKata = false;
    BinTree wahana=Nil;
    infotype X;
    // wahana = AlokNode(X);
    STARTKATA("../external/wahana.txt");
    
    while (!EndKata){
        int x = 0;
        if (CKata.TabKata[0]=='-'){
            aowahana[i] = wahana;
            i++;
            printtree(aowahana[0]);
            wahana = Nil;
        } else{
            wahana = parsing(CKata);
            ADVKATA();
            Left(wahana) = parsing(CKata);
            ADVKATA(); 
            Left(Left(wahana)) = parsing(CKata);
        }
        ADVKATA();
    }
    return aowahana;
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
    infotype X;
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
BinTree Tree (infotype Akar, BinTree L, BinTree R) {
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
  BinTree P;
  P = AlokNode(Akar);
  if (P != Nil) {
    Left(P) = L;
    Right(P) = R;
  }
  return P;
}
// void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P) {
// /* I.S. Akar, L, R terdefinisi. P Sembarang */
// /* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
// 		jika alokasi berhasil. P = Nil jika alokasi gagal. */
//   *P = AlokNode(Akar);
//   if (*P!= Nil) {
//     Left(*P) = L;
//     Right(*P) = R;
//   } else {
//     *P = Nil;
//   }
// }

// /* Manajemen Memory */
addrNode AlokNode (infotype X) {
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
  addrNode P;
  P = (addrNode) malloc (sizeof(Node));
  if (P!= Nil) {
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
  }
  return P;
}

void DealokNode (addrNode P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
  free(P);
}
// /* *** Predikat-Predikat Penting *** */
// boolean IsTreeEmpty (BinTree P) {
// /* Mengirimkan true jika P adalah pohon biner kosong */
//   return (P == Nil);
// }
// boolean IsTreeOneElmt (BinTree P) {
// /* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
//   return (P != Nil && Right(P) == Nil && Left(P) == Nil);
// }
// boolean IsUnerLeft (BinTree P) {
// /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
//   return (Left(P) != Nil && Right(P) == Nil);
// }
// boolean IsUnerRight (BinTree P) {
// /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
//   return (Left(P) == Nil && Right(P) != Nil);
// }
// boolean IsBiner (BinTree P) {
// /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
//   return (Left(P) != Nil && Right(P) != Nil);
// }
// /* *** Traversal *** */
// void PrintPreorder (BinTree P) {
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (A()()) adalah pohon dengan 1 elemen dengan akar A
//    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
//    if (IsTreeEmpty(P)) {
//      printf("()");
//    } else {
//      printf("(");
//      printf("%d",tipe(P));
//      PrintPreorder(Left(P));
//      PrintPreorder(Right(P));
//      printf(")");
//    }
// }
// void PrintInorder (BinTree P) {
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (()A()) adalah pohon dengan 1 elemen dengan akar A
//    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
//    if (IsTreeEmpty(P)) {
//      printf("()");
//    } else {
//      printf("(");
//      PrintInorder(Left(P));
//      printf("%d",Akar(P));
//      PrintInorder(Right(P));
//      printf(")");
//    }
// }
// void PrintPostorder (BinTree P) {
// /* I.S. P terdefinisi */
// /* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
//    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
//    Pohon kosong ditandai dengan ().
//    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
// /* Contoh:
//    (()()A) adalah pohon dengan 1 elemen dengan akar A
//    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
//    if (IsTreeEmpty(P)) {
//      printf("()");
//    } else {
//      printf("(");
//      PrintPostorder(Left(P));
//      PrintPostorder(Right(P));
//      printf("%d",Akar(P));
//      printf(")");
//    }
// }
// void PrintTreeL (BinTree P, int h, int CLevel) {
//   int i;
//   if (IsTreeEmpty(P)) {

//   } else {
//     for (i = 1; i<=h*(CLevel-1); i++) {
//       printf(" ");
//     }
//     printf("%d\n",Akar(P));
//     if (Left(P) != Nil) {
//       PrintTreeL(Left(P),h,CLevel+1);
//     }
//     if (Right(P) != Nil) {
//       PrintTreeL(Right(P),h,CLevel+1);
//     }
//   }
// }
// void PrintTree (BinTree P, int h) {
// /* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
// /* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
// /* Penulisan akar selalu pada baris baru (diakhiri newline) */
// /* Contoh, jika h = 2:
// 1) Pohon preorder: (A()()) akan ditulis sbb:
// A
// 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
// A
//   B
//   C
// 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
// A
//   B
//   C
//     E
// */
//   PrintTreeL(P,h,1);
// }
// /* *** Searching *** */
// boolean SearchTree (BinTree P, char* X) {
// /* Mengirimkan true jika ada node dari P yang bernilai X */
//   if (IsTreeEmpty(P)) {
//     return false;
//   } else {
//     if (tipe(P) == X) {
//       return true;
//     } else {
//       return (SearchTree(Left(P),X) || SearchTree(Right(P),X) );
//     }
//   }
// }
// /* *** Fungsi-Fungsi Lain *** */
// int NbElmt (BinTree P) {
// /* Mengirimkan banyaknya elemen (node) pohon biner P */
//   if (IsTreeEmpty(P)) {
//     return 0;
//   } else {
//     return ( 1 + NbElmt(Left(P)) + NbElmt(Right(P)));
//   }
// }
// int NbDaun (BinTree P) {
// /* Mengirimkan banyaknya daun (node) pohon biner P */
// /* Prekondisi: P tidak kosong */
//   if (IsTreeEmpty(P)) {
//     return 0;
//   } else if (IsTreeOneElmt(P)) {
//     return 1;
//   } else {
//     return (NbDaun(Left(P)) + NbDaun(Right(P)));
//   }
// }
// // Aneh
// boolean IsSkewLeft (BinTree P) {
// /* Mengirimkan true jika P adalah pohon condong kiri */
// /* Pohon kosong adalah pohon condong kiri */
//   if (IsTreeEmpty(P)) {
//     return true;
//   } else if (IsTreeOneElmt(P)) {
//     return true;
//   } else {
//     if (IsUnerLeft(P)) {
//       return (IsSkewLeft(Left(P)));
//     } else {
//       return (false);
//     }
//   }
// }
// //Aneh
// boolean IsSkewRight (BinTree P) {
// /* Mengirimkan true jika P adalah pohon condong kanan */
// /* Pohon kosong adalah pohon condong kanan */
//   if (IsTreeEmpty(P)) {
//     return true;
//   } else if (IsTreeOneElmt(P)) {
//     return true;
//   } else {
//     if (IsUnerRight(P)) {
//       return (IsSkewRight(Right(P)));
//     } else {
//       return false;
//     }
//   }
// }
// int Level (BinTree P, infotype X) {
// /* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
//    Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
//    if (SearchTree(P,X.tipe)) {
//      if (IsTreeOneElmt(P)) {
//        return 1;
//      } else {
//        return (Level(Left(P),X) + 1 + Level(Right(P),X));
//      }
//    } else {
//      return 0;
//    }
// }
// int Tinggi (BinTree P) {
// /* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
//    Mengirim "height" yaitu tinggi dari pohon */
//    if (IsTreeEmpty(P)) {
//      return 0;
//    } else {
//      if (Tinggi(Left(P)) > Tinggi(Right(P))) {
//        return (1 + Tinggi(Left(P)));
//      } else {
//        return (1 + Tinggi(Right(P)));
//      }
//    }
// }
// /* *** Operasi lain *** */
// void AddDaunTerkiri (BinTree *P, infotype X) {
// /* I.S. P boleh kosong */
// /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
//   if (IsTreeEmpty(*P)) {
//     *P = AlokNode(X);
//   } else {
//     AddDaunTerkiri(&Left(*P),X);
//   }
// }
// void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri) {
// /* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
// /* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
//         sebagai anak Kanan X (jika Kiri = false) */
// /*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
//   if (IsTreeOneElmt(*P)) {
//     if (Kiri) {
//       Left(*P) = AlokNode(Y);
//     } else {
//       Right(*P) = AlokNode(Y);
//     }
//   } else if (SearchTree(Left(*P),X.tipe)){
//     AddDaun(&Left(*P),X,Y,Kiri);
//   } else {
//     AddDaun(&Right(*P),X,Y,Kiri);
//   }
// }
// void DelDaunTerkiri (BinTree *P, infotype *X) {
// /* I.S. P tidak kosong */
// /* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
//         disimpan pada daun terkiri yang dihapus */
//     addrNode N;
//     if (IsTreeOneElmt(*P)) {
//       *X = Akar(*P);
//       N = *P;
//       *P = Nil;
//       DealokNode(N);
//     } else {
//       if (IsUnerRight(*P)) {
//         DelDaunTerkiri(&Right(*P),X);
//       } else {
//         DelDaunTerkiri(&Left(*P),X);
//       }
//     }
// }
// void DelDaun (BinTree *P, char* X) {
// /* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
// /* F.S. Semua daun bernilai X dihapus dari P. */
//   if (IsTreeEmpty(*P)) {

//   } else if (IsTreeOneElmt(*P)) {
//     if (tipe(*P) == X) {
//       *P = Nil;
//       DealokNode(*P);
//     }
//   } else {
//     DelDaun(&Left(*P),X);
//     DelDaun(&Right(*P),X);
//   }
// }
// List MakeListDaun (BinTree P) {
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
//    jika semua alokasi list berhasil.
//    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
//    address E;
//    if (IsTreeEmpty(P)) {
//      return Nil;
//    } else if (IsTreeOneElmt(P)){
//      E = Alokasi(Akar(P));
//      return (E);
//    } else {
//       E = MakeListDaun(Left(P));
//       return (Concat(E,MakeListDaun(Right(P))));
//    }
// }
// List MakeListPreorder (BinTree P) {
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    dengan urutan preorder, jika semua alokasi berhasil.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
//    address E;
//    if (IsTreeEmpty(P)) {
//      return Nil;
//    } else {
//      E = AlokNode(Akar(P));
//      if (E != Nil) {
//        Next(E) = MakeListPreorder(Left(P));
//        return (Concat(E,MakeListPreorder(Right(P))));
//      } else {
//        return Nil;
//      }
//    }
// }
// List MakeListLevel (BinTree P, int N) {
// /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
// /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
//    yang levelnya=N, jika semua alokasi berhasil.
//    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
//    Menghasilkan list kosong jika ada alokasi yang gagal. */
//    address E;
//    if (IsTreeEmpty(P)) {
//      return Nil;
//    } else if (N == 1) {
//      return (AlokNode(Akar(P)));
//    } else {
//      E = MakeListLevel(Left(P),N-1);
//      return (Concat(E,MakeListLevel(Right(P),N-1)));
//    }
// }
