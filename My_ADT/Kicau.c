#include <stdio.h>
#include <stdlib.h>
#include "Kicau.h"

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE KICAUAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT KICAUAN */
void CreateKicauan(Kicauan *K, Word Penulis, DATETIME Waktu, Word Tweet) {
/* I.S. K sembarang */
/* F.S. Terbentuk struct Kicauan dengan PenulisKicauan = Penulis, WaktuKicaun = Waktu, Tweet = Tweet, LikeKicauan = 0, JumlahBalasan = 0 */
    PENULIS_KICAUAN(*K) = Penulis;
    WAKTU_KICAUAN(*K) = Waktu;
    TWEET(*K) = Tweet;
    LIKE(*K) = 0;
    JUMLAH_BALASAN(*K) = 0;
}

/* MENCETAK STRUCT KICAUAN */
void PrintKicauan(Kicauan K, ID id) {
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idkicauan>
    | <Nama Pengguna>
    | <Waktu post kicauan>
    | <Isi kicauan>
    | Disukai: <like>
*/
    printf("| ID = %d\n", id);
    printf("| "); printWord(PENULIS_KICAUAN(K)); printf("\n");
    printf("| "); TulisDATETIME(WAKTU_KICAUAN(K)); printf("\n");
    printf("| "); printWord(TWEET(K)); printf("\n");
    printf("| Disukai: %d\n", LIKE(K));
}

/* MENAMBAH LIKE */
void AddLike(Kicauan *K) {
/* I.S. L terdefinisi, id terdefinisi */
/* F.S. Jika id terdapat pada list, LIKE(K) bertambah 1 */
    LIKE(*K) += 1;
}

/* MENGUBAH ISI TWEET */
void EditTweet(Kicauan *K, Word Tweet) {
/* I.S. L terdefinisi, id terdefinisi, Tweet terdefinisi */
/* F.S. Jika id terdapat pada list, TWEET(K) berubah menjadi Tweet */
    TWEET(*K) = Tweet;
}


/* ********** PRIMITIF-PRIMITIF UNTUK TYPE LISTKICAUAN ********** */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListKicauan *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (Kicauan *) malloc (capacity * sizeof(Kicauan));
    NEFF(*l) = 0;
    BANYAK_BALASAN(*l) = 0;
}

void dealocateList(ListKicauan *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0; BANYAK_BALASAN(l)=0 */
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    BANYAK_BALASAN(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListKicauan l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
ID getFirstIdx(ListKicauan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

ID getLastIdx(ListKicauan l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
/* indeks dimulai dari 1 */
    return NEFF(l);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListKicauan l, ID i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN) && (i < CAPACITY(l)));
}

boolean isIdxEff(ListKicauan l, ID i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 1..NEFF(l) */
    return ((i >= IDX_MIN) && (i <= NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListKicauan l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return (NEFF(l) == 0);
}

boolean isFull(ListKicauan l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF(l) == CAPACITY(l)-1);
    // dikurang 1 karena indeks dimulai dari 1
}

/* ********** TULIS LIST ********** */
void printListKicauan(ListKicauan l, Word NamaPengguna) {
/* Proses : Menuliskan isi list dengan traversal, 
   list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: tercetak daftar kicauan pengguna dan temannya */
/*      Penulisan dari kicauan terbaru ke yang terlama */
//    ID i;
//
//    for (i = getLastIdx(l); i >= getFirstIdx(l); i--) {
//        if (IsBerteman(NamaPengguna, PENULIS_KICAUAN(ELMT(l, i)))) {
//            PrintKicauan(ELMT(l, i), i);
//            printf("\n");
//        }
//    }
}

void printList(ListKicauan l) {
/* Proses : Menuliskan isi list dengan traversal, 
   list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: tercetak daftar seluruh kicauan */
/*      Penulisan dari kicauan terbaru ke yang terlama */
    ID i;

    for (i = getLastIdx(l); i >= getFirstIdx(l); i--) {
        PrintKicauan(ELMT(l, i), i);
        printf("\n");
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListKicauan lIn, ListKicauan *lOut) {
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int i;
    CreateListDinKicauan(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    BANYAK_BALASAN(*lOut) = BANYAK_BALASAN(lIn);
    for (i = getFirstIdx(lIn); i <= getLastIdx(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListKicauan *l, Kicauan val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, mungkin penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (isFull(*l)) {
        expandList(l, 50);
    }
    NEFF(*l) += 1;
    ELMT(*l, getLastIdx(*l)) = val;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListKicauan *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY(*l) += num;
    BUFFER(*l) = (Kicauan *) realloc (BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}

void shrinkList(ListKicauan *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY(*l) -= num;
    BUFFER(*l) = (Kicauan *) realloc (BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}

void compressList(ListKicauan *l) {
/* Proses : Mengubah capacity sehingga capacity = nEff + 1, karena indeks dimulai dari 1, bukan 0 */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
    CAPACITY(*l) = NEFF(*l) + 1;
    BUFFER(*l) = (Kicauan *) realloc (BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}