#include <stdio.h>
#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S) {
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS) {
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
   Hour(*T) = HH;
   Minute(*T) = MM;
   Second(*T) = SS;
}
   
void TulisTIME (TIME T) {
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
   printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T) {
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
   long jumlahdetik;
   jumlahdetik = 3600*Hour(T) + 60*Minute(T) + Second(T);
   return jumlahdetik;
}

TIME DetikToTIME (long N) {
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
   long N1;
   int h,m,s;
   TIME T;

   if (N >= 86400) {
      N1 = N % 86400;
   } else {
      N1 = N;
   }

   h = N1/3600;
   m = (N1%3600)/60;
   s = (N1%3600)%60;

   CreateTime(&T,h,m,s);

   return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1=T2, false jika tidak */
   return ((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)));
}

boolean TNEQ (TIME T1, TIME T2) {
/* Mengirimkan true jika T1 tidak sama dengan T2 */
   return ((Hour(T1) != Hour(T2)) || (Minute(T1) != Minute(T2)) || (Second(T1) != Second(T2)));
}

boolean TLT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1<T2, false jika tidak */
   long detikT1, detikT2;
   detikT1 = TIMEToDetik(T1);
   detikT2 = TIMEToDetik(T2);
   return (detikT1<detikT2);
}

boolean TGT (TIME T1, TIME T2) {
/* Mengirimkan true jika T1>T2, false jika tidak */
   long detikT1, detikT2;
   detikT1 = TIMEToDetik(T1);
   detikT2 = TIMEToDetik(T2);
   return (detikT1>detikT2);
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T) {
/* Mengirim 1 detik setelah T dalam bentuk TIME */
   long detikNext;
   detikNext = TIMEToDetik(T) + 1;
   return DetikToTIME(detikNext);
}

TIME NextNDetik (TIME T, int N) {
/* Mengirim N detik setelah T dalam bentuk TIME */
   long detikNext;
   detikNext = TIMEToDetik(T) + N;
   return DetikToTIME(detikNext);
}

TIME PrevDetik (TIME T) {
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
   long detikPrev;
   detikPrev = TIMEToDetik(T) + (86400 - 1);
   return DetikToTIME(detikPrev);
}

TIME PrevNDetik (TIME T, int N) {
/* Mengirim N detik sebelum T dalam bentuk TIME */
   long detikPrev;
   detikPrev = TIMEToDetik(T) + (86400 - (N%86400));
   return DetikToTIME(detikPrev);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh) {
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
   long detikTAw, detikTAkh;
   detikTAw = TIMEToDetik(TAw);
   detikTAkh = TIMEToDetik(TAkh);

   if (detikTAkh >= detikTAw) {
      return (detikTAkh - detikTAw);
   } else {
      return (86400 - (detikTAw - detikTAkh));
   }
}