/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#ifndef DATETIME_H
#define DATETIME_H
#include <stdio.h>
#include "../boolean.h"
#include "time.h"
#include "math.h"

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
int GetMaxDay(int M, int Y)
{
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
    {
        return 31;
    }
    else if (M == 2)
    {
        if (Y % 400 == 0)
        {

            return 29;
        }
        else if (Y % 100 != 0)
        {
            if (Y % 4 == 0)
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 30;
    }
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return (D <= GetMaxDay(M, Y) && D >= 1 && M >= 1 && M <= 12 && Y >= 1900 && Y <= 2030 && IsTIMEValid(h, m, s));
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    TIME T;
    CreateTime(&T, hh, mm, ss);

    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = T;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
{
    int d, M, y, h, m, s;
    do
    {
        scanf("%d %d %d %d %d %d", &d, &M, &y, &h, &m, &s);
        if (!IsDATETIMEValid(d, M, y, h, m, s))
        {
            printf("DATETIME tidak valid\n");
        }
    } while (!IsDATETIMEValid(d, M, y, h, m, s));
    CreateDATETIME(D, d, M, y, h, m, s);
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D)
{
    printf("%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
{
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2)));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return (!DEQ(D1, D2));
}
/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean
DLT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) < Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) == Month(D2))
        {
            if (Day(D1) == Day(D2))
            {
                if (TLT(Time(D1), Time(D2)))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (Day(D1) < Day(D2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (Month(D1) < Month(D2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2)
{
    if (DLT(D1, D2))
    {
        return false;
    }
    else
    {
        if (DEQ(D1, D2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
/* Mengirimkan true jika D1>D2, false jika tidak */
DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    DATETIME newdate;
    TIME newtime;
    long sisa;

    while (TIMEToDetik(Time(D)) + N > 86400)
    {
        if (Day(D) < GetMaxDay(Month(D), Year(D)))
        {
            Day(D) += 1;
            N -= 86400;
        }
        else if (Month(D) < 12)
        {
            Month(D) += 1;
            Day(D) = 1;
            N -= 86400;
        }
        else
        {
            Year(D) += 1;
            Month(D) = 1;
            Day(D) = 1;
            N -= 86400;
        }
    }
    sisa = TIMEToDetik(Time(D)) + N;
    newtime = DetikToTIME(sisa);
    CreateDATETIME(&newdate, Day(D), Month(D), Year(D), Hour(newtime), Minute(newtime), Second(newtime));
    return (newdate);
}
/* Mengirim salinan D dengan detik ditambah N */
DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    DATETIME newdate;
    TIME newtime;
    long sisa;
    sisa = TIMEToDetik(Time(D)) - N;
    while (sisa < 0)
    {
        if (Day(D) > 1)
        {
            Day(D) -= 1;
            sisa += 86400;
        }
        else if (Month(D) > 1)
        {
            Day(D) = GetMaxDay(Month(D) - 1, Year(D));
            Month(D) -= 1;
            sisa += 86400;
        }
        else
        {
            Year(D) -= 1;
            Month(D) = 12;
            Day(D) = 31;
            sisa += 86400;
        }
    }
    newtime = DetikToTIME(sisa);
    CreateDATETIME(&newdate, Day(D), Month(D), Year(D), Hour(newtime), Minute(newtime), Second(newtime));
    return (newdate);
}
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    long total = TIMEToDetik(Time(DAkh)) - TIMEToDetik(Time(DAw));
    Time(DAkh) = Time(DAw);
    while (!DEQ(DAw, DAkh))
    {
        DAw = DATETIMENextNDetik(DAw, 86400);
        total += 86400;
    }
    return total;
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */

#endif