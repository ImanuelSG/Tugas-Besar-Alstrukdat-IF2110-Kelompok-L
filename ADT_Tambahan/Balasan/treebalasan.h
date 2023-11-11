/* MODUL TREE UNTUK BALASAN */
/* Berisi definisi dan semua primitif pemrosesan tre balasan */
/* Tree dengan representasi left-child right-sibling */

#ifndef __TREEBALASAN_H__
#define __TREEBALASAN_H__

#include "../boolean.h"
#include "ADT_Balasan.h"

/* ********** DEFINISI TYPE ADT TREE UNTUK BALASAN ********** */
/* ADT TREE DENGAN REPRESENTASI LEFT-CHILD RIGHT-SIBLING */
typedef Balasan ElType;
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElType info;
     Address left_Child;
     Address right_Sibling;
} TreeNode;

typedef Address Tree;

/* ********** SELEKTOR TREE ********** */
#define INFO(P) (P)->info
#define LEFT_CHILD(P) (P)->left_Child
#define RIGHT_SIBLING(P) (P)->right_Sibling

/* ********** DEFINISI TYPE LIST BALASAN ********** */
typedef struct {
    Address *buffer;     /* memori tempat penyimpan elemen (container) */
    int capacity;        /* ukuran list */
} ListBalasan;

/* ********** SELEKTOR LIST BALASAN ********** */
#define BUFFER_LIST_BALASAN(l) (l).buffer
#define ELMT_LIST_BALASAN(l, i) (l).buffer[i]
#define CAPACITY_LIST_BALASAN(l) (l).capacity


/* ********** PRIMITIF-PRIMITIF UNTUK TYPE ADT TREE UNTUK BALASAN ********** */
Tree NewTree (ElType root, Tree left_child, Tree right_sibling); 
/* Menghasilkan sebuah pohon dari root, left_child, dan right_sibling 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (Tree *p, ElType root, Tree left_child, Tree right_sibling);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left_Child=NULL, p↑.right_Sibling=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (Tree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (Tree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (Tree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (Tree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (Tree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

Address searchTree (Tree p, ID id);
/* Mengirimkan address simpul dengan id=id jika ada pada pohon biner p 
   Mengirimkan NULL jika tidak ada */

void searchBeforeTree (Tree p, ID id, Address *before, Address *loc);
/* I.S. p terdefinisi */
/* F.S. Jika ada simpul dengan IDBalasan = id, maka loc = address simpul tersebut */
/*      dan before = address simpul yang menunjuk simpul tersebut */
/*      Jika tidak, maka loc = NULL */

/* ****** Display Tree ***** */
void printTree(Tree p, int h);
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
   1
     2
       3
     4
       5
         6
   Penulisan setiap node juga diakhiri newline */

/* ****** Penambahan dan Penghapusan Elemen ****** */
void insertChild(Tree *p, ElType val);
/* I.S. p boleh kosong, i adalah posisi anak (1..n) */
/* F.S. Jika alokasi berhasil, maka p menjadi pohon dengan tambahan simpul anak bernilai val pada posisi i */
/*      Jika alokasi gagal, maka p tetap */

void insertSiblingLast(Tree *p, ElType val);
/* I.S. p boleh kosong, i adalah posisi saudara (1..n) */
/* F.S. Jika alokasi berhasil, maka p menjadi pohon dengan tambahan simpul saudara bernilai val pada posisi i */
/*      Jika alokasi gagal, maka p tetap */

//void deleteChild(Tree *p);
///* I.S. p tidak kosong, i adalah posisi anak (1..n) */
///* F.S. Jika ada anak ke-i, maka anak ke-i tersebut dihapus dan didealokasi */
///*      Jika tidak ada anak ke-i, maka p tetap */
//
//void deleteSibling(Tree *p, ID idBalasan);
///* I.S. p tidak kosong, i adalah posisi saudara (1..n) */
///* F.S. Jika ada saudara ke-i, maka saudara ke-i tersebut dihapus dan didealokasi */
///*      Jika tidak ada saudara ke-i, maka p tetap */

void deleteTree(Tree *p);
/* I.S. p terdefinisi */
/* F.S. semua simpul p di-dealokasi secara kaskade */
/*      kaskade adalah proses dealokasi parent dan semua anak dan keturunannya */

#endif