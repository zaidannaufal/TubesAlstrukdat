/*
NIM             : 13518021
Nama            : Zaidan Naufal Sudrajat
Tanggal         : Rabu, 2 September 2021
Topik praktikum : ADT Sederhana
Deskripsi       : membuat ADT point dan jam
*/

#include <stdio.h>
#include "jam.h"

boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return((H>=0&&H<=23)&&(M>=0&&M<=59)&&(S>=0&&S<=59));
}
/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J1;
    Hour(J1) = HH;
    Minute(J1) = MM;
    Second(J1) = SS;
    return J1;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int H, M, S;
    while(1){
        scanf("%d %d %d", &H, &M, &S);
        if (IsJAMValid(H,M,S))
        {
            break;
        }
        else 
        {
            printf("Jam tidak valid\n");
        }
    }
    *J = MakeJAM(H,M,S);
}
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
{
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return (3600 * Hour(J) + 60 * Minute(J) + Second(J));
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
{
    int remainder, H, M , S;
    if (N < 0){
        N = N + 86400;
    }
    N = N % 86400;
    H = N / 3600;
    remainder = N % 3600;
    M = remainder / 60;
    S = remainder % 60;
    return MakeJAM(H, M, S);
}
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return (!(JEQ(J1,J2)));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    return (JAMToDetik(J1)<JAMToDetik(J2));
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
    return (JAMToDetik(J1)>JAMToDetik(J2));
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    return (DetikToJAM(JAMToDetik(J)+1));
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    return (DetikToJAM(JAMToDetik(J)+N));
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    return (DetikToJAM(JAMToDetik(J)-1));
}
JAM PrevNDetik (JAM J, int N)
{
    return (DetikToJAM(JAMToDetik(J)-N));
}
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    if (JGT(JAw, JAkh))
    {
        return (JAMToDetik(JAkh) + 86400 - JAMToDetik(JAw));
    } 
    else
    {
        return (JAMToDetik(JAkh)- JAMToDetik(JAw));
    }
    
}

/* tambahan yang engga ada */
void SetHour(JAM *J, int newHH)
/*mengubah nilai komponen HH dari J*/
{
    Hour(*J) = newHH;
}
void SetMinute(JAM *J, int newMM)
/*mengubah nilai komponen HMM dari J*/
{
    Minute(*J) = newMM;
}
void SetSecond(JAM *J, int newSS)
/*mengubah nilai komponen SS dari J*/
{
    Second(*J) = newSS;
}

JAM JPlus(JAM J1, JAM J2)
/* menambahkan jam 1 dan jam 2 */
{
    JAM J3;
    Hour(J3) = Hour(J1) + Hour(J2);
    Minute(J3) = Minute(J1) + Minute(J2);
    Second(J3) = Second(J1) + Second(J2);
    return J3;
}
JAM JMinus(JAM J1, JAM J2)
/* mengurangi jam 1 dan jam 2 */
{
    JAM J3;
    Hour(J3) = Hour(J1) - Hour(J2);
    Minute(J3) = Minute(J1) - Minute(J2);
    Second(J3) = Second(J1) - Second(J2);
    return J3;
}