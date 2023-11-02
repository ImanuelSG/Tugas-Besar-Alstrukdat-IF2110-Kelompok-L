/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
    BUFFER(*l) = (int *)malloc(capacity * sizeof(int));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
{
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
{
    return 0;
}

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l)
{
    return NEFF(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    return (i >= 0 && i <= CAPACITY(l) - 1);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i)
{
    return (i >= 0 && i <= NEFF(l) - 1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l)
{
    return (NEFF(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)

{
    int N, i, a;

    do
    {
        scanf("%d", &N);

    } while (N < 0 || N > CAPACITY(*l));

    if (N != 0)
    {
        for (i = 0; i <= N - 1; i++)
        {
            scanf("%d", &a);
            ELMT(*l, i) = a;
            NEFF(*l) += 1;
        }
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l)
{
    int i;
    printf("[");
    for (i = 0; i <= NEFF(l) - 1; i++)
    {
        if (i == 0)
        {
            printf("%d", ELMT(l, i));
        }
        else
        {
            printf(",%d", ELMT(l, i));
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    int i;
    ListDin L3;
    CreateListDin(&L3, CAPACITY(l1));
    for (i = 0; i <= NEFF(l1) - 1; i++)
    {
        if (plus)
        {
            ELMT(L3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else
        {
            ELMT(L3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
        NEFF(L3) += 1;
    }
    return L3;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    int i = 0;
    if (listLength(l1) != listLength(l2))
    {
        return false;
    }
    while (i <= listLength(l1) - 1)
    {
        if (ELMT(l1, i) != ELMT(l2, i))
        {
            return false;
        }
        i += 1;
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
    int i = 0;
    while (i < listLength(l))
    {
        if (ELMT(l, i) == val)
        {
            return i;
        }
        i += 1;
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
{
    int i;
    *max = *min = ELMT(l, 0);
    for (i = 0; i <= listLength(l) - 1; i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        else if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    int i;
    dealocateList(lOut);
    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i <= listLength(lIn) - 1; i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
        NEFF(*lOut) += 1;
    }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l)
{
    int i, count;
    count = 0;
    for (i = 0; i <= listLength(l) - 1; i++)
    {
        count += ELMT(l, i);
    }
    return count;
}

/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val)
{
    int i, count;
    count = 0;
    for (i = 0; i <= listLength(l) - 1; i++)
    {
        if (ELMT(l, i) == val)
        {
            count += 1;
        }
    }
    return count;
}

/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
{
    // 12345
    //
    int i, j, temp;
    for (i = 0; i < getLastIdx(*l); i++)
    {
        for (j = i + 1; j <= getLastIdx(*l); j++)
        {
            if (asc)
            {

                if (ELMT(*l, j) < ELMT(*l, i))
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
            else
            {
                if (ELMT(*l, j) > ELMT(*l, i))
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l) += 1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, listLength(*l) - 1);
    NEFF(*l) -= 1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
{
    ListDin temp;
    int i, nefftemp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    nefftemp = NEFF(*l);
    dealocateList(l);
    CreateListDin(l, CAPACITY(temp) + num);
    for (i = 0; i <= nefftemp - 1; i++)
    {
        ELMT(*l, i) = ELMT(temp, i);
        NEFF(*l) += 1;
    }
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num)
{

    ListDin temp;
    int i, nefftemp;
    CreateListDin(&temp, CAPACITY(*l));
    copyList(*l, &temp);
    nefftemp = NEFF(*l);
    if (!((CAPACITY(*l)) > num && NEFF(*l) < CAPACITY(*l) - num))
    {
        nefftemp = CAPACITY(*l) - num;
    }
    dealocateList(l);

    CreateListDin(l, CAPACITY(temp) - num);
    for (i = 0; i <= nefftemp - 1; i++)
    {
        ELMT(*l, i) = ELMT(temp, i);
        NEFF(*l) += 1;
    }
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l)
{
    ListDin L;
    int i, tempneff;
    tempneff = NEFF(*l);
    CreateListDin(&L, CAPACITY(*l));
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, tempneff);
    for (i = 0; i <= tempneff - 1; i++)
    {
        ELMT(*l, i) = ELMT(L, i);
        NEFF(*l) += 1;
    }
}
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif