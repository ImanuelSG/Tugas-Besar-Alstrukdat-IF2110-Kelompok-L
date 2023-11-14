#include <stdio.h>
#include "../boolean.h"
#include <time.h>
#include "datetime.h"

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int DD;   /* integer [1..31] */
    int MM;   /* integer [1..12] */
    int YYYY; /* integer [1900..2030] */
    TIME T;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y) {
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */
    if (M == 2) {
        if ((Y % 400 == 0 || Y % 4 == 0) && Y % 100 != 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (M == 4 || M == 6 || M == 9 || M == 11) {
        return 30;
    } else {
        return 31;
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
    return ((D >= 1 && D <= GetMaxDay(M,Y)) && (M >= 1 && M <= 12) && (Y >= 1900 && Y <= 2030) && (h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59));
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
    TIME T;
    CreateTime(&T,hh,mm,ss);

    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D) {
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid berdasarkan waktu lokal */
/* Proses : membaca waktu lokal yang ada pada perangkat */
    time_t Waktu_Lokal;     // time_t dalam bentuk detik
    struct tm *Time_Info;   // struct tm untuk menyimpan informasi waktu

    time(&Waktu_Lokal);                     // mendapatkan waktu lokal dari sistem
    Time_Info = localtime(&Waktu_Lokal);    // konversi dari bentuk detik ke struct tm

    if (Time_Info) {    // jika konversi berhasil, ada kemungkinan gagal
        int year = Time_Info->tm_year + 1900;   // Tahun dimulai dari 1900, sehingga ditambah 1900
        int month = Time_Info->tm_mon + 1;      // Januari dimulai dari 0, sehingga ditambah 1
        int day = Time_Info->tm_mday;
        int hour = Time_Info->tm_hour;
        int minute = Time_Info->tm_min;
        int second = Time_Info->tm_sec;

        CreateDATETIME(D,day,month,year,hour,minute,second);
    }
}

void TulisDATETIME(DATETIME D) {
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    printf("%02d/%02d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2) {
/* Mengirimkan true jika D1=D2, false jika tidak */
    return ((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(Time(D1)) == Minute(Time(D2))) && (Second(Time(D1)) == Second(Time(D2))));
}

boolean DNEQ(DATETIME D1, DATETIME D2) {
/* Mengirimkan true jika D1 tidak sama dengan D2 */
    return ((Day(D1) != Day(D2)) || (Month(D1) != Month(D2)) || (Year(D1) != Year(D2)) || (Hour(Time(D1)) != Hour(Time(D2))) || (Minute(Time(D1)) != Minute(Time(D2))) || (Second(Time(D1)) != Second(Time(D2))));
}

boolean DLT(DATETIME D1, DATETIME D2) {
/* Mengirimkan true jika D1<D2, false jika tidak */
    if (Year(D1) < Year(D2)) {
        return true;
    } else if (Year(D1) == Year(D2)) {
        if (Month(D1) < Month(D2)) {
            return true;
        } else if (Month(D1) == Month(D2)) {
            if (Day(D1) < Day(D2)) {
                return true;
            } else if (Day(D1) == Day(D2)) {
                if (TIMEToDetik(Time(D1)) < TIMEToDetik(Time(D2))) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            } 
        } else {
            return false;
        }
    } else {
        return false;
    }
}

boolean DGT(DATETIME D1, DATETIME D2) {
/* Mengirimkan true jika D1>D2, false jika tidak */
    return (!DLT(D1,D2) && !DEQ(D1,D2));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N) {
/* Mengirim salinan D dengan detik ditambah N */
    int i = 1;

    for (i = 1; i <= N; i++) {
        if (Second(Time(D)) == 59) {
            if (Minute(Time(D)) == 59) {
                if (Hour(Time(D)) == 23) {
                    if (Day(D) == GetMaxDay(Month(D),Year(D))) {
                        if (Month(D) == 12) {
                            Day(D) = 1;
                            Month(D) = 1;
                            Year(D)++;
                        } else {
                            Day(D) = 1;
                            Month(D)++;
                        }
                    } else {
                        Day(D)++;
                    }
                    Hour(Time(D)) = 0;
                } else {
                    Hour(Time(D))++;
                }
                Minute(Time(D)) = 0;
            } else {
                Minute(Time(D))++;
            }
            Second(Time(D)) = 0;
        } else {
            Second(Time(D))++;
        }
    }

    return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
    int i = 1;

    for (i = 1; i <= N; i++) {
        if (Second(Time(D)) == 0) {
            if (Minute(Time(D)) == 0) {
                if (Hour(Time(D)) == 0) {
                    if (Day(D) == 1) {
                        if (Month(D) == 1) {
                            Day(D) = GetMaxDay(12,Year(D)-1);
                            Month(D) = 12;
                            Year(D)--;
                        } else {
                            Day(D) = GetMaxDay(Month(D)-1,Year(D));
                            Month(D)--;
                        }
                    } else {
                        Day(D)--;
                    }
                    Hour(Time(D)) = 23;
                } else {
                    Hour(Time(D))--;
                }
                Minute(Time(D)) = 59;
            } else {
                Minute(Time(D))--;
            }
            Second(Time(D)) = 59;
        } else {
            Second(Time(D))--;
        }
    }

    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
    long int count_hari, tahun, bulan, count_detik;
    long int durasi1, durasi2;

    if (Year(DAw) != Year(DAkh)) {
        count_hari = 0;
        tahun = Year(DAw);
        bulan = Month(DAw) + 1;

        while (tahun <= Year(DAkh) && bulan < Month(DAkh)) {
            count_hari += GetMaxDay(bulan,tahun);
            bulan++;
            if (bulan == 13) {
                bulan = 1;
                tahun++;
            }
        }

        count_hari += (GetMaxDay(Month(DAw),Year(DAw)) - Day(DAw));
        count_hari += (Day(DAkh) - 1);

        count_detik = count_hari*86400;
        count_detik += (86400 - TIMEToDetik(Time(DAw)));
        count_detik += TIMEToDetik(Time(DAkh));
    } else {
        durasi1 = (Year(DAw) * 31536000) + (Month(DAw) * 2592000) + (Day(DAw) * 86400) + TIMEToDetik(Time(DAw));
        durasi2 = (Year(DAkh) * 31536000) + (Month(DAkh) * 2592000) + (Day(DAkh) * 86400) + TIMEToDetik(Time(DAkh));
        count_detik = durasi2 - durasi1;
    }

    return count_detik;
}