/*List Dinamis Penyimpan Utas*/
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINUTAS_H
#define LISTDINUTAS_H

#include "../../ADT_Bawaan/boolean.h"
#include "utas.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_LISTDIN_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef ListUtas ElType; /* type elemen listdin */
typedef int IdxType;
typedef struct listdinutas
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDinUtas;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDinUtas, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinUtas */
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
#define ELMTUTAS(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

//extern ListDinUtas lDinUtas;

/* ********** KONSTRUKTOR ********** */
void CreateListDinUtas(ListDinUtas *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinUtas(ListDinUtas *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinUtasLength(ListDinUtas l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

/* *** Selektor INDEKS *** */
// IdxType getFirstIdxListDinUtas(ListDinUtas l);
// /* Prekondisi : List l tidak kosong */
// /* Mengirimkan indeks elemen l pertama */
// IdxType getLastIdxListDinUtas(ListDinUtas l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxListDinUtasValid(ListDinUtas l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxListDinUtasEff(ListDinUtas l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinUtas(ListDinUtas l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDinUtas(ListDinUtas l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
// void readListDinUtas(ListDinUtas *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDinUtas(ListDinUtas l);
/* Proses : Menuliskan isi list dengan traversal*/
/* I.S. l boleh kosong */
/* F.S. Kumpulan utas */
void copyListDinUtas(ListDinUtas lIn, ListDinUtas *lOut);

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfListDinUtas(ListDinUtas l, ElType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada ATAU LIST KOSONG, mengirimkan IDX_LISTDIN_UNDEF */
ListUtas getUtas(ListDinUtas l, int IDUtas);
boolean isUtasAuthorValid(ListDinUtas l, int IDUtas, Pengguna currentPengguna);
boolean isBertemanUtasAuthor(ListDinUtas l, int IDUtas, Pengguna currentPengguna);
boolean isIDUtasValid(ListDinUtas lDinUtas, int IDUtas);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinUtas(ListDinUtas *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

// /* ********** MENGHAPUS ELEMEN ********** */
// void deleteLastListDinUtas(ListDinUtas *l, ElType *val);
// /* Proses : Menghapus elemen terakhir list */
// /* I.S. List tidak kosong */
// /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
// /*      Banyaknya elemen list berkurang satu */
// /*      List l mungkin menjadi kosong */

// /* ********* MENGUBAH UKURAN ARRAY ********* */
// void expandListDinUtas(ListDinUtas *l, int num);
// /* Proses : Menambahkan capacity l sebanyak num */
// /* I.S. List sudah terdefinisi */
// /* F.S. Ukuran list bertambah sebanyak num */

// void shrinkListDinUtas(ListDinUtas *l, int num);
// /* Proses : Mengurangi capacity sebanyak num */
// /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
// /* F.S. Ukuran list berkurang sebanyak num. */

// void compressListDinUtas(ListDinUtas *l);
// /* Proses : Mengubah capacity sehingga capacity = nEff */
// /* I.S. List tidak kosong */
// /* F.S. Ukuran capacity = nEff */

#endif