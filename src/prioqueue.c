/* NIM : 13519101
   Nama : Stefanus
   Tanggal : 7-10-2020
   Topik : ADT prioQueue 
   Deskripsi : prioqueue */
#include <stdio.h>
#include "prioqueuechar.h"
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == Nil) && (Tail(Q)== Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q){   
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
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
