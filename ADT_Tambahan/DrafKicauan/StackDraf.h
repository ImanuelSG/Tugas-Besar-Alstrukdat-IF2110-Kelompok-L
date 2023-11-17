/* File: StackDraflinked.h */

#ifndef StackDrafDRAF_H
#define StackDrafDRAF_H

#include "../../ADT_Bawaan/boolean.h"
#include "../wordoperations.h"
#include "DrafKicau.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi INFODRAFtype */
typedef DrafKicau ElTypeDraf;
/* StackDraf dengan representasi berkait dengan pointer */
typedef struct node *AddressDraf;
typedef struct node
{
    ElTypeDraf INFODRAF;
    AddressDraf NEXTDRAF;
} Node;

/* Type StackDraf dengan ciri Top: */
typedef struct
{
    AddressDraf addrTop; /* alamat Top: elemen puncak */

} StackDraf;
extern int BanyakPenggunaDenganDraf;

/* Selektor */
#define NEXTDRAF(p) (p)->NEXTDRAF
#define INFODRAF(p) (p)->INFODRAF
#define ADDR_TOP(s) (s).addrTop
#define TOP(s) (s).addrTop->INFODRAF

/* Prototype manajemen memori */
AddressDraf newNode(ElTypeDraf x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan INFODRAF = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK StackDraf ***************/
boolean isEmptyStackDraf(StackDraf s);
/**
 * @brief Mencari Panjang StackDraf s
 *
 * @param s
 * @return int panjang Stack Draf
 */

int lengthStackDraf(StackDraf s);
/* Mengirimkan banyaknya elemen StackDraf. Mengirimkan 0 jika StackDraf s kosong */

/**
 * @brief Membuat StackDraf kosong dengan AddressDraf top = NULL
 *
 * @param s
 */
void CreateStackDraf(StackDraf *s);

/**
 * @brief Menampilkan StackDraf ke layar
 *
 * @param s
 */
void DisplayStackDraf(StackDraf s);
/**
 * @brief Menambahkan x sebagai elemen StackDraf s
 *
 * @param s Stack dari draf
 * @param x Draf yang ingin disimpan
 */
void SimpanDraf(StackDraf *s, ElTypeDraf x);

/**
 * @brief Menghapus elemen TOP dari StackDraf s
 *
 * @param s Stack dari draf
 * @param x Draf yang ingin dihapus

 */
void DeleteDraf(StackDraf *s, ElTypeDraf *x);

void ReverseStackDraf(StackDraf *s);

#endif