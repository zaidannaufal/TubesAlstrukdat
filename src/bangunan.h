/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotypeW adalah integer */

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"
#include "antrian.h"
#define Nil NULL


// typedef struct {
//    char item[20];  // untuk string //
// } String;

// typedef struct {
//    int resource[3];  // untuk membuat list of int //
// } ArrayInt;

// typedef struct {
//    infotypeP pengunjung;  // untuk membuat list of ElmtQueue //
// } ArrayQ;

typedef struct {
   int wilayah;  // Nama wilayah
   POINT point; // POINT 
} Lokasi;

typedef struct {
        char nama[50];
        int tipe;
        Lokasi lokasi;
        int Harga;
        int Durasi;
        int Kapasitas;
        int history; // 0 itu blom diupgrade , 1 itu upgradean ke-1 , 2 itu upgradean ke2
        int durability;
        boolean status;
        Antrian pengunjung;
      //   ArrayQ pengunjung;
        int HUpgrade;
        // int builded;
        int JmlPakaiTotal;
        int JmlPakaiToday;
        int HasilTotal;
        int HasilToday;
} infotypeW;

typedef struct tElmtlist *addressbangunan;
typedef struct tElmtlist { 
	infotypeW info;
	addressbangunan next;

} ElmtList;
typedef struct {
	addressbangunan First;
} ListBangunan;




/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First
#define nama(P) (P)->info.nama
#define tipe(P) (P)->info.tipe
#define wilayah(P) (P)->info.lokasi.wilayah
#define point(P) (P)->info.lokasi.point
#define history(P) (P)->info.history
#define durability(P) (P)->info.durability
#define durasibangunan(P) (P)->info.Durasi
#define KapasitasBang(P) (P)->info.Kapasitas
#define status(P) (P)->info.status
#define Harga(P) (P)-> info.Harga
#define HUpgrade(P) (P)->info.HUpgrade
#define JmlPakaiToday(P) (P)->info.JmlPakaiToday
#define JmlPakaiTotal(P) (P)->info.JmlPakaiTotal
#define HasilToday(P) (P)->info.HasilToday
#define HasilTotal(P) (P)->info.HasilTotal
#define Antrian(P)  (P)->info.pengunjung

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyBangunan (ListBangunan L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyBangunan (ListBangunan *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressbangunan Alokasi (infotypeW X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressbangunan *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

// /****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
// address Search (List L, String X);
// /* Mencari apakah ada elemen list dengan info(P)= X */
// /* Jika ada, mengirimkan address elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */
// boolean FSearch (List L, address P);
// /* Mencari apakah ada elemen list yang beralamat P */
// /* Mengirimkan true jika ada, false jika tidak ada */
// address SearchPrec (List L, infotypeW X);
// /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
// /* Mencari apakah ada elemen list dengan Info(P)=X */
// /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
// /* Jika tidak ada, mengirimkan Nil */
// /* Jika P adalah elemen pertama, maka Prec=Nil */
// /* Search dengan spesifikasi seperti ini menghindari */
// /* traversal ulang jika setelah Search akan dilakukan operasi lain */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
// void InsVFirst (List *L, infotypeW X);
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
// void InsVLast (List *L, infotypeW X);
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
// /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

// /*** PENGHAPUSAN ELEMEN ***/
// void DelVFirst (List *L, infotypeW *X);
// /* I.S. List L tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen pertama di-dealokasi */
// void DelVLast (List *L, infotypeW *X);
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen terakhir di-dealokasi */

// /****************** PRIMITIF BERDASARKAN ALAMAT ******************/
// /*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (List *L, address P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (ListBangunan *L, addressbangunan P, addressbangunan Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListBangunan *L, addressbangunan P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListBangunan *L, addressbangunan *P);
// /* I.S. List tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
// // void DelP (List *L, infotypeW X);
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
// /* List mungkin menjadi kosong karena penghapusan */
void DelLast (ListBangunan *L, addressbangunan *P);
// /* I.S. List tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// // void DelAfter (List *L, address *Pdel, address Prec);
// /* I.S. List tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
// void PrintInfo (List L);
// /* I.S. List mungkin kosong */
// /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtBangunan (ListBangunan L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
// infotypeW Max (List L);
// /* Mengirimkan nilai info(P) yang maksimum */
// address AdrMax (List L);
// /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
// infotypeW Min (List L);
// /* Mengirimkan nilai info(P) yang minimum */
// address AdrMin (List L);
// /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
// float Average (List L);
// /* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
void DelAll (ListBangunan *L);
/* Delete semua elemen list dan alamat elemen di-dealokasi */

// void InversList (List *L);
// /* I.S. sembarang. */
// /* F.S. elemen list dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

// List FInversList (List L);
// /* Mengirimkan list baru, hasil invers dari L */
// /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
// /* Jika alokasi gagal, hasilnya list kosong */
// /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

// void CopyList (List *L1, List *L2);
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

ListBangunan FCopyList (ListBangunan L);
void copyInfotypew(addressbangunan *dest, addressbangunan source);
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

// void CpAlokList (List Lin, List *Lout);
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

// void Konkat (List L1, List L2, List * L3);
// /* I.S. L1 dan L2 sembarang */
// /* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
// /* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
// /* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
// /* harus di-dealokasi dan L3=Nil*/
// /* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
// /* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
// /* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
// /* dan semua elemen yang pernah dialokasi didealokasi */

// void Konkat1 (List *L1, List *L2, List *L3);
// /* I.S. L1 dan L2 sembarang */
// /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
// /* Konkatenasi dua buah list : L1 dan L2    */
// /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
// /* dan L1 serta L2 menjadi list kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */

// void PecahList (List *L1, List *L2, List L);
// /* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */


// FUNGSI TAMBAHAN

// String GetTipeWahana(List L, String Nama);
// /* Untuk mendapatkan tipe dari wahana tertenru */

// String GetHistoryWahana(List L, String Nama);
// /* Untuk mendapatkan history dari wahana tertenru */

// Vertices GetLokasiWahana(List L, String Nama);
// /* Untuk mendapatkan lokasi dari wahana tertenru */

// int GetDurabWahana(List L, String Nama);
// /* Untuk mendapatkan durability dari wahana tertenru */

// Array GetResourceWahana(List L, String Nama);
// /* Untuk mendapatkan resource dari wahana tertenru */

// boolean GetStatusWahana(List L, String Nama);
// /* Untuk mendapatkan status dari wahana tertenru */

// int GetPengunWahana(List L, String Nama);
// /* Untuk mendapatkan jumlah pengunjung dari wahana tertenru */

// int GetHUpgradeWahana(List L, String Nama);
// /* Untuk mendapatkan harga upgrade dari wahana tertenru */

#endif
