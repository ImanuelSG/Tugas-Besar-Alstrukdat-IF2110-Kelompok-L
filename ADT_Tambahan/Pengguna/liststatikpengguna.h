/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef ListStatikPengguna_H
#define ListStatikPengguna_H

#include "../../ADT_Bawaan/boolean.h"
#include "pengguna.h"

/*  Kamus Umum */
#define CAPACITUS 20
/* Kapasitas penyimpanan */
#define IDX_MINUS 0
/* Indeks minimum list */
#define IDX_UNDEFUS -1
/* Indeks tak terdefinisi*/
#define MARKUS -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
   Pengguna contents[CAPACITUS]; /* memori tempat penyimpan elemen (container) */
   int Neff ;
} ListStatikPengguna;
extern ListStatikPengguna dataPengguna;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTListStatik(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatikPengguna *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatikPengguna l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatikPengguna l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

void insertLast(ListStatikPengguna *l, Pengguna val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */


#endif