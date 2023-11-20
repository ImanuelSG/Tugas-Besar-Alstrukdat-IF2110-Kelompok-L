#ifndef UTAS_H
#define UTAS_H

#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/datetime/datetime.h"
#include "../../ADT_Bawaan/boolean.h"
#include "../Kicauan/ADT_Kicauan.h"
#include "../Globals/globalvar.h"
#include "../wordoperations.h"
#include <stdio.h>

/* Definisi Tipe Data Utas*/
typedef struct utas
{
    int IDUtas; // autoincrement, index dari listdinutas + 1
    ID IDKicau; //jika bukan kicauan utama idKicau = IDX_UNDEF
    Kicauan kicauanUtama; //kicauan utama dari utas
    int index; //index utas
    Pengguna utasAuthor;
    DATETIME WaktuKicauan;
    Word Tweet;           // Isi kicauan
} Utas;

#define IDUTAS(U) (U).IDUtas
#define IDKICAU(U) (U).IDKicau
#define KICAUANUTAMA(U) (U).kicauanUtama
#define INDEX(U) (U).index
#define PENULISUTAS(U) (U).utasAuthor
#define WAKTUKICAUAN(U) (U).WaktuKicauan
#define TWEET(U)  (U).Tweet

/* ****************** KONSTRUKTOR ADT UTAS *******************/
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, int index, Pengguna utasAuthor, DATETIME WaktuKicauan, Word Tweet);
/*Menyusun utas dari komponennya*/

/* ****************** Definisi Node Utas *******************/
typedef Utas InfoType;
typedef struct nodeutas* Address;
typedef struct nodeutas {
    InfoType info;
    Address next;
} NodeUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNodeKicauanUtas(InfoType val);
/*Node berisi kicauan pada utas*/

/* ****************** Definisi Linked List Utas  *******************/
typedef Address ListUtas; //pointer to NodeUtas
#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE BERKAITAN LINKED LIST UTAS*/
void CreateListUtas(ListUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk linked list kosong */

boolean isEmptyUtas(ListUtas l);
/* Mengirim true jika list kosong */

InfoType getKicauanUtas(ListUtas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

// int indexOfUtas(ListUtas l, InfoType val);
// /* I.S. l, val terdefinisi */
// /* F.S. Mencari apakah ada elemen list l yang bernilai val */
// /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
// /* Mengembalikan IDX_UNDEF jika tidak ditemukan */

void insertFirstUtas(ListUtas *l, InfoType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastUtas(ListUtas *l, InfoType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtUtas(ListUtas *l, InfoType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void deleteFirstUtas(ListUtas *l, InfoType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void deleteAtUtas(ListUtas *l, int idx, InfoType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

void displayListUtas(ListUtas l);
/* I.S. List berisi kicauan utama */
/* F.S. Serangkaian utas tercetak ke layar*/

int lengthListUtas(ListUtas l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

// /****************** FUNGSI TAMBAHAN UNTUK ADT UTAS ******************/
boolean IDKicauFound(ID IDKicau);
/*Mengirimkan true jika kicauan dengan IDKicau tidak ditemukan di listKicauan*/
boolean isIDKicauValid(ID IDKicau);
/*Mengirimkan true jika kicauan dengan IDKicau dibuat oleh currentPengguna */
void printKicauanUtas(Utas U, int index);

// void UTAS(ID IDKicau);
// void SAMBUNG_UTAS(int IDUtas, int index);
// /*Validasi IDUtas*/
// /*Search at index in listUtas*/
// void HAPUS_UTAS(int IDUtas, int index);
// void CETAK_UTAS(int IDUtas);

#endif