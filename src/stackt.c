/* NIM : 13519101 */
/* Nama : Stefanus */
/* Tanggal : 22 Oktober 2020 */
/* Topik : ADT Stack */
/* Deskripsi : Realisasi ADT Stackt uWu */

#include <stdio.h>
#include "stackt.h"
#include <stdlib.h>
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
    return (Top(S)==NilStack);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S){
    return (Top(S)==MaxElStack-1);

}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypestack X){
    Top(*S)++;
    InfoTop(*S)=X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypestack* X){
    *X = InfoTop(*S);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
