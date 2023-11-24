#include <stdio.h>
#include <stdlib.h>
#include "listdinutas.h"

ListDinUtas lDinUtas;

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

void printListDinUtas(ListDinUtas l)
/* Proses : Menuliskan kumpulan utas dengan traversal*/
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
    /*Menghasilkan ListUtas dengan IDUtas*/
  return ELMTUTAS(l, IDUtas-1);
}

boolean isUtasAuthorValid(ListDinUtas l, int IDUtas, Pengguna currentPengguna){
    /*Menghasilkan true jika ListUtas dengan IDUtas dibuat oleh currentPengguna*/
    ListUtas lUtas = getUtas(l,IDUtas);
    Utas U = getKicauanUtas(lUtas, 0);
    return isSameWord(PENULISUTAS(U), currentPengguna.nama);
}
boolean isBertemanUtasAuthor(ListDinUtas l, int IDUtas, Pengguna currentPengguna){
    /*Menghasilkan true jika author ListUtas dengan IDUtas berteman dengan currentPengguna*/
    ListUtas lUtas = getUtas(l,IDUtas);
    Utas U = getKicauanUtas(lUtas, 0);
    return isBerteman(currentPengguna.nama,PENULISUTAS(U));
}
boolean isIDUtasValid(ListDinUtas lDinUtas, int IDUtas){
/*IDUtas valid untuk kapasitas ListDinUtas*/
    return (IDUtas >= 1 && IDUtas <= NEFF(lDinUtas));
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinUtas(ListDinUtas *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */{
    if (isFullListDinUtas(*l)) {
        expandListDinUtas(l, 50);
    }
    ELMTUTAS(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}

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

boolean isKicauanUtamaUtas(ListDinUtas l, ID IDKICAU){
/*Menghasilkan true jika kicauan dengan IDKicau telah dijadikan sebuah kicauan utama*/
    boolean isKicauanUtama = false;
    int i = 0;
    while (i < NEFF(l) && !isKicauanUtama){
        ListUtas lUtas =  ELMTUTAS(l, i);
        if (getKicauanUtas(lUtas, 0).IDKicau == IDKICAU){
            isKicauanUtama = true;
        }
        else{
            i++;
        }
    }
    return isKicauanUtama;
}
