/* NIM : 13519101
   Nama : Stefanus
   Tanggal : 7-10-2020
   Topik : ADT Queue 
   Deskripsi : queue */

#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Q.HEAD == Nil) && (Q.TAIL== Nil));
}

boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
   return (NBElmt(Q) == Q.MaxEl);
}

int NBElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    int elmt;
    if (IsEmpty(Q))
    {
        elmt = 0;
    }
    else
    {
        if (Q.TAIL >= Q.HEAD)
        {
            elmt = Q.TAIL - Q.HEAD + 1;
        }
        else
        {
            elmt = Q.MaxEl - Q.HEAD + 1 + Q.TAIL;
        }  
    }
    return elmt;
}

/* *** Kreator *** */
void MakeEmpty (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T == NULL)
    {
        Q->MaxEl = 0;
    }
    else
    {
        Q->MaxEl = Max;
        Q->HEAD = Nil;
        Q->TAIL = Nil;
    }
    
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    Q->MaxEl = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    if (!IsEmpty(*Q))
    {
        Q->TAIL = (Q->TAIL + 1) % Q->MaxEl;   
    }
    else
    {
        Q->HEAD = 0;
        Q->TAIL = 0;
    }
    InfoTail(*Q) = X;
    
}
void Dequeue (Queue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1)
    {
        Q->HEAD = Nil;
        Q->TAIL = Nil;
    }
    else
    {
        Q->HEAD = (Q->HEAD + 1) % Q->MaxEl;   
    }
}