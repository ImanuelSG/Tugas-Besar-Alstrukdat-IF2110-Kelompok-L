/* MODUL LIST DINAMIK UNTUK KICAUAN */
/* Berisi definisi dan semua primitif pemrosesan list kicauan */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef __LISTDINKICAUAN_H__
#define __LISTDINKICAUAN_H__

#include "../../ADT_Bawaan/boolean.h"
#include "ADT_Kicauan.h"

/* ********** DEFINISI TYPE LIST DINAMIK UNTUK KICAUAN ********** */
#define IDX_MIN_LIST_KICAUAN 1 /* Indeks minimum list */
#define IDX_UNDEF 0            /* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
   Kicauan *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;       /* >= 0, banyaknya elemen efektif */
   int capacity;   /* ukuran list */
} ListKicauan;
/* Indeks yang digunakan [1..capacity-1] */
/* Jika l adalah : ListKicauan, cara deklarasi dan akses: */
/* Deklarasi : l : ListKicauan */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
   list kosong: l.nEff = 0
   Definisi elemen pertama : l.buffer[i] dengan i = 1
   Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i = l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF_LIST_KICAUAN(l) (l).nEff
#define BUFFER_LIST_KICAUAN(l) (l).buffer
#define ELMT_LIST_KICAUAN(l, i) (l).buffer[i]
#define CAPACITY_LIST_KICAUAN(l) (l).capacity

extern ListKicauan ListKicauanData; /*Berisi List Kicauan saat ini*/

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE LISTKICAUAN ********** */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinKicauan(ListKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthKicau(ListKicauan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

/* *** Selektor INDEKS *** */
ID getFirstIdxKicau(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
ID getLastIdxKicau(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidKicau(ListKicauan l, ID i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffKicau(ListKicauan l, ID i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListKicau(ListKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListKicau(ListKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** TULIS LIST ********** */
void printListKicauan(ListKicauan l, Word NamaPengguna);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

void printList(ListKicauan l);
/* Proses : Menuliskan isi list dengan traversal,
   list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: tercetak daftar seluruh kicauan */
/*      Penulisan dari kicauan terbaru ke yang terlama */

/* ********** OPERASI LAIN ********** */
void copyListKicau(ListKicauan lIn, ListKicauan *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastKicau(ListKicauan *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicau(ListKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

#endif