#include <stdio.h>
#include <stdlib.h>
#include "treebalasan.h"

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE ADT TREE UNTUK BALASAN ********** */
Tree NewTree (ElType root, Tree left_child, Tree right_sibling) {
/* Menghasilkan sebuah pohon dari root, left_child, dan right_sibling 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
   Tree p = (Address) malloc(sizeof(TreeNode));
   if (p!=NULL) {
      INFO(p) = root;
      LEFT_CHILD(p) = left_child;
      RIGHT_SIBLING(p) = right_sibling;
   }
   return p;
}

void CreateTree (Tree *p, ElType root, Tree left_child, Tree right_sibling) {
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */ 
   *p = (Address) malloc(sizeof(TreeNode));
   if (p!=NULL) {
      INFO(*p) = root;
      LEFT_CHILD(*p) = left_child;
      RIGHT_SIBLING(*p) = right_sibling;
   }
}

Address newTreeNode(ElType val) {
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left_Child=NULL, p↑.right_Sibling=NULL 
   Jika alokasi gagal, mengirimkan NULL */
   Address p = (Address) malloc(sizeof(TreeNode));
   if (p!=NULL) {
      INFO(p) = val;
      LEFT_CHILD(p) = NULL;
      RIGHT_SIBLING(p) = NULL;
   }
   return p;
}

void deallocTreeNode (Address p) {
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
   free(p);
}

boolean isTreeEmpty (Tree p) {
/* Mengirimkan true jika p adalah pohon biner yang kosong */
   return (p == NULL);
}

boolean isOneElmt (Tree p) {
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
   return (!isTreeEmpty(p) && LEFT_CHILD(p) == NULL && RIGHT_SIBLING(p) == NULL);
}

boolean isUnerLeft (Tree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
   return (!isTreeEmpty(p) && LEFT_CHILD(p) != NULL && RIGHT_SIBLING(p) == NULL);
}

boolean isUnerRight (Tree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
   return (!isTreeEmpty(p) && LEFT_CHILD(p) == NULL && RIGHT_SIBLING(p) != NULL);
}

boolean isBinary (Tree p) {
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
   return (!isTreeEmpty(p) && LEFT_CHILD(p) != NULL && RIGHT_SIBLING(p) != NULL);
}

Address searchTree (Tree p, ID id) {
/* Mengirimkan address simpul dengan id=id jika ada pada pohon biner p 
   Mengirimkan NULL jika tidak ada */
   if (isTreeEmpty(p)) {
      return NULL;
   } else {
      if (ID_BALASAN(INFO(p)) == id) {
         return p;
      } else {
         Address temp = searchTree(LEFT_CHILD(p), id);
         if (temp == NULL) {
            temp = searchTree(RIGHT_SIBLING(p), id);
         }
         return temp;
      }
   }
}

void searchBeforeTree (Tree p, ID id, Address *before, Address *loc) {
/* I.S. p terdefinisi */
/* F.S. Jika ada simpul dengan IDBalasan = id, maka loc = address simpul tersebut */
/*      dan before = address simpul yang menunjuk simpul tersebut */
/*      Jika tidak, maka loc = NULL */
   if (isTreeEmpty(p)) {
      *loc = NULL;
      *before = NULL;
   } else {
      if (ID_BALASAN(INFO(p)) == id) { // menangani kasus hanya 1 elemen
         *loc = p;
         *before = NULL;
         return;
      } else {
         if (LEFT_CHILD(p) != NULL) {
            if (ID_BALASAN(INFO(LEFT_CHILD(p))) == id) {
               *loc = LEFT_CHILD(p);
               *before = p;
               return;
            } else {
               searchBeforeTree(LEFT_CHILD(p), id, before, loc);
               if (*loc != NULL) {
                  return;
               }
            }
         }
         if (RIGHT_SIBLING(p) != NULL) {
            if (ID_BALASAN(INFO(RIGHT_SIBLING(p))) == id) {
               *loc = RIGHT_SIBLING(p);
               *before = p;
               return;
            } else {
               searchBeforeTree(RIGHT_SIBLING(p), id, before, loc);
               if (*loc != NULL) {
                  return;
               }
            }
         }
      }
   }
}

/* ****** Display Tree ***** */
void printTree(Tree p, int h) {
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
   if (p!=NULL) {
      PrintBalasan(INFO(p), h);
      printTree(LEFT_CHILD(p), h+3);
      printTree(RIGHT_SIBLING(p), h);
   }
}

/* ****** Penambahan dan Penghapusan Elemen ****** */
void insertChild(Tree *p, ElType val) {
/* I.S. p boleh kosong */
/* F.S. Jika alokasi berhasil, maka p menjadi pohon dengan simpul left_child bernilai val */
/*      Jika alokasi gagal, maka p tetap */
   Address pNew = newTreeNode(val);
   if (pNew != NULL) {
      if (isTreeEmpty(*p)) {
         *p = pNew;
      } else {
         if (LEFT_CHILD(*p) == NULL) {
            LEFT_CHILD(*p) = pNew;
         } else {
            Tree temp = LEFT_CHILD(*p);
            while (RIGHT_SIBLING(temp) != NULL) {
               temp = RIGHT_SIBLING(temp);
            }
            RIGHT_SIBLING(temp) = pNew;
         }
      }
   }
}

void insertSiblingLast(Tree *p, ElType val) {
/* I.S. p boleh kosong */
/* F.S. Jika alokasi berhasil, maka p menjadi pohon dengan tambahan simpul right_sibling bernilai val */
/*      Jika alokasi gagal, maka p tetap */
   Address pNew = newTreeNode(val);
   if (pNew != NULL) {
      if (isTreeEmpty(*p)) {
         *p = pNew;
      } else {
         Tree temp = *p;
         while (RIGHT_SIBLING(temp) != NULL) {
            temp = RIGHT_SIBLING(temp);
         }
         RIGHT_SIBLING(temp) = pNew;
      }
   }
}

void deleteTree(Tree *p) {
/* I.S. p terdefinisi */
/* F.S. semua simpul p di-dealokasi secara kaskade */
/*      kaskade adalah proses dealokasi parent dan semua anak dan keturunannya */
/*      right_sibling tidak ikut di-dealokasi */
   Address before = NULL;
   Address loc = NULL;
   searchBeforeTree(*p, ID_BALASAN(INFO(*p)), &before, &loc);
   
   if (*p == LEFT_CHILD(before)) {
      LEFT_CHILD(before) = RIGHT_SIBLING(*p);
   } else {
      RIGHT_SIBLING(before) = RIGHT_SIBLING(*p);
   }
   deallocTreeNode(*p);
}
