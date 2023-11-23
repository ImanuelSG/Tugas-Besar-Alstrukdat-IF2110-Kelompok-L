#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val) {
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    Address new = (Address) malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
} 

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p = FIRST(l);
    int i = 0;
    while (i < idx) {
        i++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx) {
        i++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    int idx = 0;
    boolean found = false;
    Address p = FIRST(l);
    
    while (p != NULL && !found) {
        if (INFO(p) == val) {
            found = true;
        } else {
            p = NEXT(p);
            idx++;
        }
    }

    if (!found) {
        idx = IDX_UNDEF;
    }

    return idx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address new = newNode(val);
    if (new != NULL) {
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
}

void insertLast(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address new = newNode(val);
        if (new != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = new;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address new = newNode(val);
        if (new != NULL) {
            Address p = FIRST(*l);
            for (int i = 0; i < idx-1; i++) {
                p = NEXT(p);
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address temp = FIRST(*l);
    *val = INFO(temp);
    FIRST(*l) = NEXT(temp);
    free(temp);
}

void deleteLast(List *l, ElType *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address last = FIRST(*l);
    Address prevlast = NULL;
    
    while (NEXT(last) != NULL) {
        prevlast = last;
        last = NEXT(last);
    }

    if (prevlast == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(prevlast) = NULL;
    }
    *val = INFO(last);
    free(last);
}

void deleteAt(List *l, int idx, ElType *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address p = FIRST(*l);
        for (int i = 0; i < idx-1; i++) {
            p = NEXT(p);
        }
        Address temp = NEXT(p);
        *val = INFO(temp);
        NEXT(p) = NEXT(temp);
        free(temp);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");

    Address p = FIRST(l);
    while (p != NULL) {
        printf("%d", INFO(p));
        if (NEXT(p) != NULL) {
            printf(",");
        }
        p = NEXT(p);
    }

    printf("]");
}

int length(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    Address p = FIRST(l);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateList(&l3);

    Address p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    Address p = FIRST(L);
    boolean found = false;
    while (p != NULL && !found) {
        if (p == P) {
            found = true;
        } else {
            p = NEXT(p);
        }
    }
    return found;
}

Address searchPrec(List L, ElType X) {
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    Address p = FIRST(L);
    Address prev = NULL;
    boolean found = false;
    while (p != NULL && !found) {
        if (INFO(p) == X) {
            found = true;
        } else {
            prev = p;
            p = NEXT(p);
        }
    }
    
    if (!found) {
        prev = NULL;
    }
    return prev;
}

/*** Prekondisi untuk Max/Min/Rata-rata : List tidak kosong ***/
ElType maxValue(List l) {
/* Mengirimkan nilai info(P) yang maksimum */
    ElType max = INFO(FIRST(l));
    Address p = NEXT(FIRST(l));
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l) {
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    ElType max = INFO(FIRST(l));
    Address maxP = FIRST(l);
    Address p = NEXT(FIRST(l));
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
            maxP = p;
        }
        p = NEXT(p);
    }
    return maxP;
}

ElType minValue(List l) {
/* Mengirimkan nilai info(P) yang minimum */
    ElType min = INFO(FIRST(l));
    Address p = NEXT(FIRST(l));
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    ElType min = INFO(FIRST(l));
    Address minP = FIRST(l);
    Address p = NEXT(FIRST(l));
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
            minP = p;
        }
        p = NEXT(p);
    }
    return minP;
}

float average(List L) {
/* Mengirimkan nilai rata-rata info(P) */
    ElType sum = 0;
    int count = 0;
    Address p = FIRST(L);
    while (p != NULL) {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    return (float) sum / (float) count;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    Address p = FIRST(*l);
    while (p != NULL) {
        Address temp = p;
        p = NEXT(p);
        free(temp);
    }
    FIRST(*l) = NULL;
}

void copyList(List *l1, List *l2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    FIRST(*l2) = FIRST(*l1);
}

void inverseList(List *l) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    Address prev = NULL;
    Address curr = FIRST(*l);
    Address next = NULL;
    while (curr != NULL) {
        next = NEXT(curr);
        NEXT(curr) = prev;
        prev = curr;
        curr = next;
    }
    FIRST(*l) = prev;
}