#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S)
{
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime(TIME *T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME(TIME *T)
{
    int h, m, s;

    scanf("%d %d %d", &h, &m, &s);
    if (!IsTIMEValid(h, m, s))
    {
        printf("Jam tidak valid\n");
    }

    while (!IsTIMEValid(h, m, s))
    {
        scanf("%d %d %d", &h, &m, &s);
        if (!IsTIMEValid(h, m, s))
        {
            printf("Jam tidak valid\n");
        }
    }
    CreateTime(T, h, m, s);
}
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */

void TulisTIME(TIME T)
{
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik(TIME T)
{
    return (3600 * Hour(T) + 60 * Minute(T) + Second(T));
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME(long N)
{
    int h, m, s;
    TIME T;
    TIME *t = &T;

    if (N >= 86400)
    {
        N %= 86400;
    }
    h = N / 3600;
    m = (N % 3600) / 60;
    s = N % 60;
    CreateTime(t, h, m, s);
    return (*t);
}

/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ(TIME T1, TIME T2)
{
    return ((Hour(T1) == Hour(T2)) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ(TIME T1, TIME T2)
{
    return (!TEQ(T1, T2));
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
/* Mengirimkan true jika T1<T2, false jika tidak */

boolean TGT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
    return (DetikToTIME(TIMEToDetik(T) + 1));
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik(TIME T, int N)
{
    return (DetikToTIME(TIMEToDetik(T) + N));
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik(TIME T)
{
    if (TIMEToDetik(T) - 1 < 0)
    {
        return (DetikToTIME(TIMEToDetik(T) - 1 + 86400));
    }
    else
    {
        return (DetikToTIME(TIMEToDetik(T) - 1));
    }
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik(TIME T, int N)
{
    if (TIMEToDetik(T) - N < 0)
    {
        return (DetikToTIME(TIMEToDetik(T) - N % 86400 + 86400));
    }
    else
    {
        return (DetikToTIME(TIMEToDetik(T) - N));
    }
}

/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi(TIME TAw, TIME TAkh)
{
    long durasi = (TIMEToDetik(TAw) > TIMEToDetik(TAkh)) ? (86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw)) : (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    return durasi;
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */