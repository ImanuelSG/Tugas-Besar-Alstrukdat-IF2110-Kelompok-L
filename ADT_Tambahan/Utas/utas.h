#ifndef UTAS_H
#define UTAS_H

#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/datetime/datetime.h"
#include "../../ADT_Bawaan/boolean.h"
#include "../Pengguna/pengguna.h"
#include "../Kicauan/listdinkicauan.h"
#include "../Globals/globalvar.h"
#include "../utils/utils.h"
#include "../wordoperations.h"
#include <stdio.h>

Pengguna currentPengguna;
/* Definisi Tipe Data Utas*/
typedef struct utas
{
    int IDUtas; // autoincrement, index dari listdinutas + 1
    ID IDKicau; //jika bukan kicauan utama idKicau = IDX_UNDEF
    //int index; //index utas
    //Kicauan kicauanUtama;  //kicauan utama dari utas
    Word utasAuthor;
    DATETIME WaktuKicauan;
    Word Tweet; // Isi kicauan
} Utas;

#define IDUTAS(U) (U).IDUtas
#define IDKICAU(U) (U).IDKicau
//#define KICAUANUTAMA(U) (U).kicauanUtama
//#define INDEX(U) (U).index
#define PENULISUTAS(U) (U).utasAuthor
#define WAKTUUTAS(U) (U).WaktuKicauan
#define TWEETUTAS(U)  (U).Tweet

/* ****************** KONSTRUKTOR ADT UTAS *******************/
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, Word utasAuthor, DATETIME WaktuKicauan, Word Tweet);
/*Menyusun utas dari komponennya*/

/* ****************** Definisi Node Utas *******************/
typedef Utas InfoType;
typedef struct nodeutas* Address_Utas;
typedef struct nodeutas {
    InfoType info;
    Address_Utas next;
} NodeUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address_Utas newNodeKicauanUtas(InfoType val);
/*Node berisi kicauan utas*/

/* ****************** Definisi Linked List Utas  *******************/
typedef Address_Utas ListUtas; //pointer to NodeUtas
#define IDX_UNDEF_ListUtas (-1)
#define FIRST(l) (l)

//extern ListUtas LIST_UTAS;

/* PROTOTYPE BERKAITAN LINKED LIST UTAS*/
void CreateListUtas(ListUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk linked list kosong */

boolean isEmptyUtas(ListUtas l);
/* Mengirim true jika list kosong */

InfoType getKicauanUtas(ListUtas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan kicauan utas pada indeks linked list ke-idx */

// int indexOfUtas(ListUtas l, InfoType val);
// /* I.S. l, val terdefinisi */
// /* F.S. Mencari apakah ada elemen list l yang bernilai val */
// /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
// /* Mengembalikan IDX_UNDEF jika tidak ditemukan */

void insertFirstUtas(ListUtas *l, InfoType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama linked list dengan nilai val jika alokasi berhasil.*/
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastUtas(ListUtas *l, InfoType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtUtas(ListUtas *l, InfoType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah NodeUtas dan */
/* menyisipkan elemen dalam listUtas pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

// void deleteFirstUtas(ListUtas *l, InfoType *val);
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
boolean isIndexUtasValid(ListUtas lUtas, int index);
/*Mengirimkan true jika utas dengan index index ditemukan di ListUtas*/
void printKicauanUtas(Utas U, int index);
void sambungKicauanUtas(Utas sambunganUtas, ID IDUtas, int index, ListUtas lUtas);

#endif