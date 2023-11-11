#include "time.h"
#include <stdio.h>
#include "boolean.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
boolean IsTIMEValid (int H, int M, int S)
{
    return ((H<=23) && (H>=0) && (M>=0) && (M<=60) && (S<=60) && (S>=0));
}

/*KONSTRUKTOR, membentuk Time dari komponennya*/
void CreateTime(TIME *T, int HH, int MM, int SS)
{
   Hour(*T) = HH;
   Minute(*T) = MM;
   Second(*T) = SS;
}

/* KELOMPOK BACA/TULIS                                               */
void BacaTIME (TIME * T)
{
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    while (!IsTIMEValid(h, m, s))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &h, &m, &s);
    }

    CreateTime(T, h, m, s);
}
void TulisTIME (TIME T)
{
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

/* KELOMPOK KONVERSI TERHADAP TYPE*/
long TIMEToDetik (TIME T)
{
    return (3600 * Hour(T) + 60 * Minute(T) + Second(T));
}

TIME DetikToTIME (long N)
{
    TIME T;
    int h, m, s;
    N = N % 86400;
    h = N/3600;
    N = N % 3600;
    m = N/60;
    N = N % 60;
    s = N;
    CreateTime(&T, h, m, s);
    return T;
}

/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
{
    return ((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && Second(T1) == Second(T2));
}
boolean TNEQ (TIME T1, TIME T2)
{
    return (!TEQ(T1, T2));
}
boolean TLT (TIME T1, TIME T2)
{
    long N1 = TIMEToDetik (T1);
    long N2 = TIMEToDetik (T2);
    N1 %= 86400;
    N2 %= 86400;
    return (N1 < N2);
}
boolean TGT (TIME T1, TIME T2)
{
    return (!TLT(T1, T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
{
    int h = Hour(T);
    int m = Minute(T);
    int s = Second(T);
    s += 1;
    if (s == 60){
        s = 0;
        m += 1;
        if (m == 60){
            m = 0;
            h += 1;
            if (h == 24){
                h = 0;
            }
        }
    }
    CreateTime(&T, h, m, s);
    return T;
}

TIME NextNDetik (TIME T, int N)
{
    long sec = TIMEToDetik(T);
    sec += N;
    return DetikToTIME(sec);
}

TIME PrevDetik (TIME T)
{
    long sec = TIMEToDetik(T);
    sec -= 1;
    return DetikToTIME(sec);
}
TIME PrevNDetik (TIME T, int N)
{
    long sec = TIMEToDetik(T);
    sec -= N;
    return DetikToTIME(sec);
}
long Durasi (TIME TAw, TIME TAkh)
{
    long NAw = TIMEToDetik(TAw);
    long NAkh = TIMEToDetik(TAkh);
    long selisih = NAkh - NAw;
    if (TGT(TAw, TAkh) && selisih !=0){
        selisih += 86400;
    }
    return selisih;
}