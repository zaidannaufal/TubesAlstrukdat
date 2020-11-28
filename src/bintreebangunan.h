/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _BINTREE_H_
#define _BINTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"
#include "mesinkata.h"
#define Niltree NULL

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */

typedef struct {
   int resource[4];  // untuk membuat list of string //
} Resource;

typedef struct {
   char tipe[100];
   int  harga;
   char deskripsi[100];
   int kapasitas;
   int durasi;
   Resource resource;
   int HUpgrade;
} infotypetree;

typedef struct tNode *addrNode;
typedef struct tNode { 
	infotypetree info;
	addrNode left;
	addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;
 
/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define tipe(P) (P)->info.tipe
#define harga(P) (P)->info.harga
#define deskripsi(P) (P)->info.deskripsi
#define kapasitas(P) (P)->info.kapasitas
#define durasibt(P) (P)->info.durasi
#define resource(P,i) (P)->info.resource.resource[i]
#define HUpgrade(P)  (P)->info.HUpgrade

BinTree Tree (infotypetree Akar, BinTree L, BinTree R);
// void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
addrNode AlokNode (infotypetree X);
/* maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
void bacatree(BinTree* aowahana);
void printtree(BinTree wahana);
void copystringtree(char* string,char* CKata,int begin,int last);
BinTree parsing(Kata CKata);
void printstring(char* string);
void copyinttree(int * dest, char* sumber,int begin,int last);
int searchtipetree(BinTree* aowahana, char* string,int jmlhwahana);
   
#endif