/* NIM : 13519101
   Nama : Stefanus
   Tanggal : 7-10-2020
   Topik : ADT prioQueue 
   Deskripsi : prioqueue */
#include <stdio.h>
#include "prioqueuechar.h"
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsAntrianEmpty (Antrian Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == NilPrio) && (Tail(Q)== NilPrio));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsAntrianFull (Antrian Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (Antrian Q){   
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    int elmt;
    if (IsAntrianEmpty(Q))
    {
        elmt = 0;
    }
    else
    {
        if (Q.TAIL >= Q.HEAD){
            elmt = Q.TAIL - Q.HEAD + 1;
        }
        else{
            elmt = Q.MaxEl - Q.HEAD + 1 + Q.TAIL;
        }  
    }
    return elmt;
}

/* *** Kreator *** */
void MakeEmptyAntrian (Antrian * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infoantrian *) malloc (Max * sizeof(infoantrian));
    if ((*Q).T == NULL)
    {
        Q->MaxEl = 0;
    }
    else
    {
        Q->MaxEl = Max;
        Q->HEAD = NilPrio;
        Q->TAIL = NilPrio;
    }
    
}

/* *** Destruktor *** */
void DeAlokasi(Antrian * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    Q->MaxEl = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Antrian * Q, infoantrian X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
 	if (IsAntrianEmpty(*Q)){
		Head(*Q)=0;
		Tail(*Q)=0;
	} 
    else {
		if(Tail(*Q) == MaxEl(*Q)) Tail(*Q) = 1;
		else Tail(*Q)++;
	}

	int i = Head(*Q);
	boolean flag = false;
	while(i != Tail(*Q)){
		if(!flag && (Elmt(*Q, i).prio > X.prio)){ 
            flag = true;
        }
		if (flag){ 
            infoantrian tmp; 
            tmp = X; 
            X = Elmt(*Q, i); 
            Elmt(*Q, i) = tmp;
        }
		if(i == MaxEl(*Q)){ 
            i = 1;
        }
		else(i++);
	}
	InfoTail(*Q)=X;
}
       
void Dequeue (Antrian * Q, infoantrian * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	*X = InfoHead(*Q);
	if (Head(*Q)==Tail(*Q)) {
		Head(*Q)=NilPrio;
		Tail(*Q)=NilPrio;

	} 
    else {
		if (Head(*Q) == MaxEl(*Q)){ 
            Head(*Q) = 0;
        }
		else {
            Head(*Q)++;
        }
	}
}      


/* Operasi Tambahan */
void PrintPrioQueueChar (Antrian Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
	for(int i = Head(Q); i!=Tail(Q); i++){
		printf("%d %c\n", Elmt(Q, i).prio, Elmt(Q, i).info);
	}

	if(!IsAntrianEmpty(Q)){
		int i = Tail(Q);
		printf("%d %c\n", Elmt(Q, i).prio, Elmt(Q, i).info);	
	}
    printf("%c", '#');
    printf("\n");
}
