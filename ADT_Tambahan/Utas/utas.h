#ifndef UTAS_H
#define UTAS_H

#include "../ADT_Bawaan/wordmachine/wordmachine.h"
//#include "../ADT_Bawaan/listdin/listdin.h"
#include "../ADT_Bawaan/datetime/datetime.h"
#include "../boolean.h"
#include "../Kicauan/Kicau.h"
#include "../Globals/globalvar.h"
#include <stdio.h>

/* Definisi Utas : */
typedef struct utas
{
    int IDUtas; // autoincrement
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

/* Definisi Node Utas : */
typedef Utas ElType;
typedef struct nodeutas* Address;
typedef struct nodeutas {
    ElType info;
    Address next;
} NodeUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);

typedef Address ListUtas; //pointer to NodeUtas
#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE BERKAITAN LINKED LIST UTAS*/
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(ListUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(ListUtas l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getKicauanUtas(ListUtas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(ListUtas *l, int idx, ElType val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfUtas(ListUtas l, ElType val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstUtas(ListUtas *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastUtas(ListUtas *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtUtas(ListUtas *l, ElType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstUtas(ListUtas *l, ElType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastUtas(ListUtas *l, ElType *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtUtas(ListUtas *l, int idx, ElType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListUtas(ListUtas l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthListUtas(ListUtas l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PRIMITIF ADT UTAS ******************/
boolean IDKicauFound(ID IDKicau);
/*Mengirimkan true jika kicauan dengan IDKicau tidak ditemukan di listKicauan*/
boolean isIDKicauValid(ID IDKicau);
/*Mengirimkan true jika kicauan dengan IDKicau dibuat oleh currentPengguna */
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, int index, Pengguna utasAuthor, DATETIME WaktuKicauan, Word Tweet);
void printKicauanUtas(Utas U, int index);
void UTAS(ID IDKicau);
void SAMBUNG_UTAS(int IDUtas, int index);
/*Validasi IDUtas*/
/*Search at index in listUtas*/
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);

#endif