#include <stdio.h>
#include <stdlib.h>
#include "listdinutas.h"

/* ********** KONSTRUKTOR ********** */
void CreateListDinUtas(ListDinUtas *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */{
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (ElType *) malloc (capacity * sizeof(ElType));
    NEFF(*l) = 0;
}

void dealocateListDinUtas(ListDinUtas *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */{
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinUtasLength(ListDinUtas l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */{
    return NEFF(l);
}

// /* *** Selektor INDEKS *** */
// IdxType getFirstIdxListDinUtas(ListDinUtas l)
// /* Prekondisi : List l tidak kosong */
// /* Mengirimkan indeks elemen l pertama */{

// }
// IdxType getLastIdxListDinUtas(ListDinUtas l);
// /* Prekondisi : List l tidak kosong */
// /* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxListDinUtasValid(ListDinUtas l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/{
    return ((i >= IDX_MIN) && (i < CAPACITY(l)));   
}
boolean isIdxListDinUtasEff(ListDinUtas l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */{
    return ((i >= IDX_MIN) && (i < NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinUtas(ListDinUtas l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */{
    return (NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isFullListDinUtas(ListDinUtas l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */{
    return (NEFF(l) == CAPACITY(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
// void readListDinUtas(ListDinUtas *l);
// /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
// /* F.S. List l terdefinisi */
// /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
// /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
// /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
// /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
// /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
//       0 satu per satu diakhiri enter */
// /*    Jika N = 0; hanya terbentuk l kosong */
void printListDinUtas(ListDinUtas l)
/* Proses : Menuliskan isi list dengan traversal*/
/* I.S. l boleh kosong */
/* F.S. Kumpulan utas */{
  int i;
  for (i = 0; i < NEFF(l); i++){
      displayListUtas(ELMTUTAS(l, i));
  }
}
void copyListDinUtas(ListDinUtas lIn, ListDinUtas *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ {
    int i;
    CreateListDinUtas(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (int i = 0; i < CAPACITY(lIn); i++) {
        ELMTUTAS(*lOut,i) = ELMTUTAS(lIn,i);
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfListDinUtas(ListDinUtas l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada ATAU LIST KOSONG, mengirimkan IDX_LISTDIN_UNDEF */{
    IdxType idx = IDX_LISTDIN_UNDEF;
    int i = 0;
    while (i < NEFF(l)) {
        if (ELMTUTAS(l, i) == val) {
            idx = i;
            break;
        }
        i++;
    }
    return idx;
}

ListUtas getUtas(ListDinUtas l, int IDUtas){
  return ELMTUTAS(l, IDUtas-1);
}

boolean isUtasAuthorValid(ListDinUtas l, int IDUtas, Pengguna currentPengguna){
    ListUtas lUtas = getUtas(l,IDUtas);
    Utas U = getKicauanUtas(lUtas, 0);
    return isSameWord(PENULISUTAS(U).nama, currentPengguna.nama);
}
boolean isBertemanUtasAuthor(ListDinUtas l, int IDUtas, Pengguna currentPengguna){
    ListUtas lUtas = getUtas(l,IDUtas);
    Utas U = getKicauanUtas(lUtas, 0);
    return isBerteman(currentPengguna.nama,PENULISUTAS(U).nama);
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinUtas(ListDinUtas *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */{
    ELMTUTAS(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}

// /* ********** MENGHAPUS ELEMEN ********** */
// void deleteLastListDinUtas(ListDinUtas *l, ElType *val);
// /* Proses : Menghapus elemen terakhir list */
// /* I.S. List tidak kosong */
// /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
// /*      Banyaknya elemen list berkurang satu */
// /*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinUtas(ListDinUtas *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */{
    ListDinUtas temp;
    int i, nefftemp;

    CreateListDinUtas(&temp, CAPACITY(*l));
    copyListDinUtas(*l, &temp);
    nefftemp = NEFF(*l);

    dealocateListDinUtas(l);
    CreateListDinUtas(l, CAPACITY(temp) + num);
    for (i = 0; i <= nefftemp - 1; i++) {
        ELMTUTAS(*l, i) = ELMTUTAS(temp, i);
        NEFF(*l) += 1;
    }
}

// void shrinkListDinUtas(ListDinUtas *l, int num);
// /* Proses : Mengurangi capacity sebanyak num */
// /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
// /* F.S. Ukuran list berkurang sebanyak num. */

// void compressListDinUtas(ListDinUtas *l);
// /* Proses : Mengubah capacity sehingga capacity = nEff */
// /* I.S. List tidak kosong */
// /* F.S. Ukuran capacity = nEff */