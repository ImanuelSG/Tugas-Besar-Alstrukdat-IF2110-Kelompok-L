#include "datetime.h"
#include "stdio.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
{
    if (M == 1||M==3|M==5||M==7||M==8||M==10||M==12){
        return 31;
    }
    else if (M == 2){
        if (M % 400 == 0){
            return 29;
        }
        else{
            if (M % 100 == 0){return 28;}
            else if (M % 4 == 0) {return 29;}
            else{return 28;}
        }
    }
    else{
        return 30;
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
{
    return((1<=D && D<=31)&&(1<=M && M<=12)&&(Y>0) && IsTIMEValid(h, m, s));
}
/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
{
    if (IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)){
        TIME T;
        CreateTime(&T, hh, mm, ss);
        Day(*D) = DD;
        Month(*D) = MM;
        Year(*D) = YYYY;
        Time(*D) = T;
    }
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
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
{
    int DD, MM, YYYY, hh, mm, ss;
    do
    {
        scanf("%d", &DD);
        scanf("%d", &MM);
        scanf("%d", &YYYY);
        scanf("%d", &hh);
        scanf("%d", &mm);
        scanf("%d", &ss);
        if (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)){
            printf("DATETIME tidak valid\n");
        }
    } while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss));
    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
    
}

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
{
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1=D2, false jika tidak */
{
    return (TEQ(Time(D1), Time(D2)) && (Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)));
}
boolean DNEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1 tidak sama dengan D2 */{
    return !DEQ(D1, D2);
}
boolean DLT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1<D2, false jika tidak */{
    if (Year(D1) < Year(D2)){
        return true;
    }
    else if (Year(D1) == Year(D2)){
        if (Month(D1) < Month(D2)){
            return true;
        }
        else if (Month(D1) == Month(D2)){
            if (Day(D1) < Day(D2)){
                return true;
            }
            else if (Day(D1) == Day(D2)){
                if ((Hour(Time(D1)) < Hour(Time(D2))) || (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(Time(D1)) < Minute(Time(D2))) || (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(Time(D1)) == Minute(Time(D2))) && (Second(Time(D1)) < Second(Time(D2)))){return true;}
                else{return false;}
            }
            else{return false;}
        }
        else{
            return false;}
    }
    else{
        return false;}
}
boolean DGT(DATETIME D1, DATETIME D2){
    return !DLT(D1, D2);
}
/* Mengirimkan true jika D1>D2, false jika tidak */
DATETIME DATETIMENextNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik ditambah N */{
    DATETIME newD;
    TIME newT = NextNDetik(Time(D), N);
    CreateDATETIME(&newD, Day(D), Month(D), Year(D), Hour(newT), Minute(newT), Second(newT));
    return (newD);
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik dikurang N */{
    DATETIME newD;
    TIME newT = PrevNDetik(Time(D), N);
    CreateDATETIME(&newD, Day(D), Month(D), Year(D), Hour(newT), Minute(newT), Second(newT));
    return (newD);
}
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */{
    long DayAkh = Year(DAkh) * + Month(DAkh) * + GetMaxDay(Month(DAw),Year(DAkh));
    long NAw =  TIMEToDetik(Time(DAw));
    long NAkh = TIMEToDetik(Time(DAkh));
    long selisih = NAkh - NAw;
    if (DLT(DAw, DAkh) && selisih !=0){
        selisih += 86400;
    }
    return selisih;
}
