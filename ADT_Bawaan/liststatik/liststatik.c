/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "boolean.h"
#include <stdio.h>
/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen List */
typedef int IdxType;
typedef struct
{
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */ {
   IdxType i;
   for (i = IDX_MIN; i < CAPACITY; i++)
   {
      ELMT(*l, i) = MARK;
   }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */ {
   IdxType i, count;
   i = count = 0;
   while (i <= CAPACITY - 1 && ELMT(l, i) != MARK)
   {
      count += 1;
      i += 1;
   }
   return (count);
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) { return (IDX_MIN); }

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l)

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   return (listLength(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/ {
   return (i >= IDX_MIN && i < CAPACITY);
}
boolean isIdxEff(ListStatik l, IdxType i)
{
   return (i >= IDX_MIN && i <= listLength(l) - 1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
{
   return (listLength(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l)
{
   return (listLength(l) == CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
{
   int n;
   IdxType i;
   CreateListStatik(l);
   do
   {
      scanf("%d", &n);
   } while (!(n >= 0 && n <= CAPACITY));
   if (n == 0)
   {
      CreateListStatik(l);
   }
   else
   {
      for (i = 0; i < n; i++)
      {
         scanf("%d", &ELMT(*l, i));
      }
   }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l)
{
   int i;
   if (listLength(l) == 0)
   {
      printf("[]");
   }
   else
   {
      for (i = 0; i < listLength(l); i++)
      {
         if (i == 0)
         {
            printf("[%d", ELMT(l, i));
         }
         else
         {
            printf(",%d", ELMT(l, i));
         }
      }
      printf("]");
   }
}

/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
   ListStatik L3;
   int i;
   CreateListStatik(&L3);
   for (i = 0; i < listLength(l1); i++)
   {
      if (plus)
      {
         ELMT(L3, i) = ELMT(l1, i) + ELMT(l2, i);
      }
      else
      {
         ELMT(L3, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }
   return (L3);
}

/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
{
   int i = 0;
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

/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val)
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
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
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
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
{
   int i;
   for (i = listLength(*l); i > 0; i--)
   {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, 0) = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx)
{
   int i;
   for (i = listLength(*l); i > idx; i--)
   {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, idx) = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val)
{
   ELMT(*l, listLength(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
{
   int i;
   *val = ELMT(*l, 0);
   for (i = 0; i < listLength(*l); i++)
   {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
   int i;
   *val = ELMT(*l, idx);
   for (i = idx; i <= listLength(*l) - 1; i++)
   {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
{
   *val = ELMT(*l, listLength(*l) - 1);
   ELMT(*l, listLength(*l) - 1) = MARK;
}

/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */

void sortList(ListStatik *l, boolean asc)
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

#endif