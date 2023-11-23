#include "listdinNomor.h"
#include "../../ADT_Bawaan/boolean.h"
#include <stdlib.h>

void printListNomor(ListDinNomor l) {
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    int i;

    printf("[");
    for (i = 0; i < NEFF(l); i++) {
        printf("%d", ELMT(l, i));
        if (i != getLastIdx(l)) {
            printf(",");
        }
    }
    printf("]");
}


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinNomor(ListDinNomor *l) {
    CAPACITY(*l) = 5;
    BUFFER(*l) = (char *) malloc (CAPACITY(*l));
    NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */


boolean isFullNomor(ListDinNomor l) {
    return (NEFF(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */



/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastNomor(ListDinNomor *l, char val) {
    if (isFull(*l)) {
        expandList(l, 5) ;
    }
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */


/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListNomor(ListDinNomor *l, int num) {
    printf("FULL\n") ;
    CAPACITY(*l) += num ;
    BUFFER(*l) = (char *) realloc (BUFFER(*l), CAPACITY(*l)) ;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
