#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (ElType*)malloc(capacity * sizeof(ElType));
    if (BUFFER(*l) != NULL)
    {
        CAPACITY(*l) = capacity;
        NEFF(*l) = 0;
    }
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
{
    return NEFF(l);
}
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IDX_MIN && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return ((i >= IDX_MIN) && (i <= getLastIdx(l))); //i <=NEFF(l)
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int n;
    do
    {
        scanf("%d", &n);
    } while (!(n >= IDX_MIN && n <= CAPACITY(*l)));
    
    if (n!=0)
    {
        int i, value;
        for (i = IDX_MIN; i < n; i++)
        {
            scanf("%d", &value);
            ELMT(*l, i) = value;
        }
        NEFF(*l) = n;
    }
}
void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        int i;
        printf("[");
        for (i = IDX_MIN; i < listLength(l); i++)
        {
            printf("%d", ELMT(l, i));
            if (i != listLength(l) - 1)
            {
                printf(",");
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    int i;
    ListDin l3;
    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);
    for (i = IDX_MIN; i < listLength(l1); i++)
    {
        if (plus)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if (NEFF(l1) == NEFF(l2))
    {
        int i;
        for (i = IDX_MIN; i < listLength(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    int idx = IDX_UNDEF;
    if (!(isEmpty(l)))
    {
        int i;
        for (i = IDX_MIN; i < listLength(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                idx = i;
                break;
            }
        }
    }
    return idx;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    int i;
    for (i = IDX_MIN+1; i < listLength(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    int i;
    for (i = IDX_MIN; i < listLength(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int sum = 0;
    int i;
    if (!isEmpty(l))
    {
        for (i = IDX_MIN; i < listLength(l); i++)
        {
            sum += ELMT(l, i);
        }
    }
    return sum;
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int count = 0;
    int i;
    if (!isEmpty(l))
    {
        for (i = IDX_MIN; i < listLength(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                count ++;
            }
        }
    }
    return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    if (!isEmpty(*l))
    {
        int temp, i, j;
        for (i = IDX_MIN; i < listLength(*l); i++)
        {
            for (j = i + 1; j < listLength(*l); j++)
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
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    if (!isFull(*l))
    {
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l) ++;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) --;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /*
    ListDin *temp;
    int prevNeff = NEFF(*l);
    int prevCapacity = CAPACITY(*l);
    copyList(*l, temp);

    dealocateList(l);
    CreateListDin(l, prevCapacity + num);
    NEFF(*l) = NEFF(*temp);

    int i;
    for (i = IDX_MIN; i < listLength(*temp); i++)
    {
        ELMT(*l, i) = ELMT(*temp, i);
    }
    */
   CAPACITY(*l) += num;
   BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l) * sizeof(ElType)));
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /*
    ListDin *temp;
    int prevNeff = NEFF(*l);
    int prevCapacity = CAPACITY(*l);
    copyList(*l, temp);

    dealocateList(l);
    CreateListDin(l, prevCapacity - num);
    NEFF(*l) = prevNeff;

    int i;
    for (i = IDX_MIN; i < prevNeff; i++)
    {
        ELMT(*l, i) = ELMT(*temp, i);
    }
    */
   CAPACITY(*l) -= num;
   BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l) * sizeof(ElType)));
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
{
/*
    ListDin *temp;
    copyList(*l, temp);
    int prevNEFF = NEFF(*l);

    dealocateList(l);
    CreateListDin(l, prevNEFF);
    NEFF(*l) = prevNEFF;

    int i;
    for (i = IDX_MIN; i < getLastIdx(*l); i++)
    {
        ELMT(*l, i) = ELMT(*temp, i);
    }
*/
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), NEFF(*l) * sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}