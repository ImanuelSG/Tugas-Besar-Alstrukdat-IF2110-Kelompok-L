#include "liststatikpengguna.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatikPengguna *l) {
   (*l).Neff = 0 ;
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatikPengguna l) {
   return l.Neff == 0 ;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatikPengguna l) {
   return l.Neff == CAPACITUS ;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */

void insertLast(ListStatikPengguna *l, Pengguna val) {
   if (!isFull(*l)) {
      (*l).contents[(*l).Neff] = val ;
      (*l).Neff += 1 ;      
   }
} 
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */


