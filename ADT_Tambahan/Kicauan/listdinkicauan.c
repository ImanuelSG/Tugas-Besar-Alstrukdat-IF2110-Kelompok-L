#include <stdio.h>
#include <stdlib.h>
#include "listdinkicauan.h"
#include "../utils/utils.h"
#include "../Balasan/treebalasan.h"

ListKicauan ListKicauanData;
/* ********** PRIMITIF-PRIMITIF UNTUK TYPE LISTKICAUAN ********** */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListKicauan *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY_LIST_KICAUAN(*l) = capacity;
    BUFFER_LIST_KICAUAN(*l) = (Kicauan *) malloc (capacity * sizeof(Kicauan));
    NEFF_LIST_KICAUAN(*l) = 0;
}

void dealocateListDinKicauan(ListKicauan *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF_LIST_KICAUAN(l)=0; BANYAK_BALASAN(l)=0 */
    CAPACITY_LIST_KICAUAN(*l) = 0;
    NEFF_LIST_KICAUAN(*l) = 0;
    free(BUFFER_LIST_KICAUAN(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthKicau(ListKicauan l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF_LIST_KICAUAN(l);
}

/* *** Selektor INDEKS *** */
ID getFirstIdxKicau(ListKicauan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    if (NEFF_LIST_KICAUAN(l) == 0) {
        return IDX_UNDEF;
    } else {
        return IDX_MIN_LIST_KICAUAN;
    }
}

ID getLastIdxKicau(ListKicauan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
/* indeks dimulai dari 1 */
    if (NEFF_LIST_KICAUAN(l) == 0) {
        return IDX_UNDEF;
    } else {
        return NEFF_LIST_KICAUAN(l);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidKicau(ListKicauan l, ID i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN_LIST_KICAUAN) && (i < CAPACITY_LIST_KICAUAN(l)));
}

boolean isIdxEffKicau(ListKicauan l, ID i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 1..NEFF_LIST_KICAUAN(l) */
    return ((i >= IDX_MIN_LIST_KICAUAN) && (i <= NEFF_LIST_KICAUAN(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListKicau(ListKicauan l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return (NEFF_LIST_KICAUAN(l) == 0);
}

boolean isFullListKicau(ListKicauan l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF_LIST_KICAUAN(l) == CAPACITY_LIST_KICAUAN(l)-1);
    // dikurang 1 karena indeks dimulai dari 1
}

/* ********** TULIS LIST ********** */
void printListKicauan(ListKicauan l, Word NamaPengguna) {
/* Proses : Menuliskan isi list dengan traversal,
   list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: tercetak daftar kicauan pengguna dan temannya */
/*      Penulisan dari kicauan terbaru ke yang terlama */
    if (!isEmptyListKicau(l)) {
        ID i;
        for (i = getLastIdxKicau(l); i >= getFirstIdxKicau(l); i--) {
            if (isBerteman(NamaPengguna, PENULIS_KICAUAN(ELMT_LIST_KICAUAN(l, i)))) {
                PrintKicauan(ELMT_LIST_KICAUAN(l, i), i);
                printf("\n");
            }
        }
    }
    else {
        printf("Tidak ada kicauan yang dapat ditampilkan!\n");
    }
}

void printList(ListKicauan l) {
    /* Proses : Menuliskan isi list dengan traversal,
       list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: tercetak daftar seluruh kicauan */
    /*      Penulisan dari kicauan terbaru ke yang terlama */
    if (!isEmptyListKicau(l)) {
        ID i;
        for (i = getLastIdxKicau(l); i >= getFirstIdxKicau(l); i--) {
            PrintKicauan(ELMT_LIST_KICAUAN(l, i), i);
            printf("\n");
        }
    }
    else {
        printf("Tidak ada kicauan yang dapat ditampilkan!\n");
    }
}

/* ********** OPERASI LAIN ********** */
void copyListKicau(ListKicauan lIn, ListKicauan *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, NEFF_LIST_KICAUAN dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int i;
    CreateListDinKicauan(lOut, CAPACITY_LIST_KICAUAN(lIn));
    NEFF_LIST_KICAUAN(*lOut) = NEFF_LIST_KICAUAN(lIn);
    for (i = getFirstIdxKicau(lIn); i <= getLastIdxKicau(lIn); i++) {
        ELMT_LIST_KICAUAN(*lOut, i) = ELMT_LIST_KICAUAN(lIn, i);
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastKicau(ListKicauan *l, Kicauan val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, mungkin penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (isFullListKicau(*l)) {
        expandListKicau(l, 50);
        expandListBalas(&ListBalasanData, 50);
    }
    NEFF_LIST_KICAUAN(*l) += 1;
    ELMT_LIST_KICAUAN(*l, getLastIdxKicau(*l)) = val;
    CURRENT_ID_KICAUAN += 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicau(ListKicauan *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY_LIST_KICAUAN(*l) += num;
    BUFFER_LIST_KICAUAN(*l) = (Kicauan *) realloc (BUFFER_LIST_KICAUAN(*l), CAPACITY_LIST_KICAUAN(*l) * sizeof(Kicauan));
}