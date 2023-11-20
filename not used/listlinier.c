#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

// typedef int ElType;
// typedef struct node* Address;
// typedef struct node {
//     ElType info;
//     Address next;
// } Node;

// #define INFO(p) (p)->info
// #define NEXT(p) (p)->next

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

//typedef Address List;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l) //pointer to first node

Address newNode(ElType val){
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */{
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */{
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */{
    Address p = FIRST(l);
    int idcount = 0;
    while (idcount < idx){
        p = NEXT(p);
        idcount ++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */ 
    Address p = FIRST(*l);
    int idcount = 0;
    while (idcount < idx){ //idcount < idx
        p = NEXT(p);
        idcount ++;
    }
    INFO(p) = val;
}


int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */{
    Address p = FIRST(l);
    int idcount = 0;
    int foundIdx = IDX_UNDEF;
    while (foundIdx == IDX_UNDEF && p != NULL){
        if (INFO(p) == val){
            foundIdx = idcount;
        }
        else{
            p = NEXT(p);
            idcount ++;
        }
    }
    return foundIdx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address newP = newNode(val);
    if (newP != NULL){
        NEXT(newP) = FIRST(*l); //kalo isEmpty emang bakal NULL
        FIRST(*l) = newP;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address newP = newNode(val);
        if (newP != NULL){
            Address p = FIRST(*l);
            while (NEXT(p) != NULL){
                p = NEXT(p);
            }
            //NEXT(p) == NULL, karena mau berhenti sebelum p jadi NULL (berhenti di last node)
            NEXT(p) = newP;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */{
    if (idx == 0){
        insertFirst(l, val);
    }
    else{
        Address newP = newNode(val);
        if (newP != NULL){
            int idcount = 0;
            Address loc = FIRST(*l);
            while (idcount < idx - 1){
                idcount ++;
                loc = NEXT(loc);
            } //berhenti saat idcount = idx - 1; sebelum idx yang ingin dicari
            NEXT(newP) = NEXT(loc);
            NEXT(loc) = newP;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */{
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */{
    Address p,loc;
    p = FIRST(*l);
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc != NULL){
        NEXT(loc) = NULL;
    }
    else{
        FIRST(*l) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */{
    if (idx == 0){
        deleteFirst(l, val);
    }
    else{
        Address loc, p;
        loc = FIRST(*l);
        int idcount = 0;
        while (idcount < idx - 1){
            idcount ++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }  
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */{
    printf("[");
    if (!isEmpty(l)){
        Address p = FIRST(l);
        while (p != NULL){
            printf("%d", INFO(p));
            if (NEXT(p) != NULL){
                printf(",");
            }
            p = NEXT(p);
        }
    }
    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */{
    int count = 0;
    Address p = FIRST(l);
    while (p != NULL){
        p = NEXT(p);
        count ++;
    }
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) 
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */{
    List l3;
    Address p;
    CreateList(&l3);

    p = FIRST(l1);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */{
    Address loc = FIRST(L);
    boolean found = false;
    while (!found && loc != NULL){
        if (loc == P){
            found = true;
        }
        else{
            loc = NEXT(loc);
        }
    }
    return found; //kalo isEmpty(L) bakal return false
}
Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari traversal ulang jika setelah Search akan dilakukan operasi lain */{
    boolean found = false;
    Address P = FIRST(L);
    Address Prec = NULL;
    while (!found && P != NULL){
        if (INFO(P) == X){
            found = true;
        }
        else{
            Prec = P;
            P = NEXT(P);
        }
    }
    if (found){
        return Prec;
    }
    else{
        return NULL;
    }
}

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
ElType max(List l)
/* Mengirimkan nilai info(P) yang maksimum */{
    return INFO(adrMax(l));
}
Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */{
    Address maxAdr = FIRST(l);
    Address p = NEXT(FIRST(l));
    while (p != NULL){
        if (INFO(maxAdr) < INFO(p)){
            maxAdr = p;
        }
        p = NEXT(p);
    }
    return maxAdr;
}
ElType min(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    return INFO(adrMin(l));
}
Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */{
    Address minAdr = FIRST(l);
    Address p = NEXT(FIRST(l));
    while (p != NULL){
        if (INFO(minAdr) > INFO(p)){
            minAdr = p;
        }
        p = NEXT(p);
    }
    return minAdr;
}
float average(List l) //rayhankinan
/* Mengirimkan nilai rata-rata info(P) */{
    Address p = FIRST(l);
    int sum = 0;
    int count = 0;
    while (p != NULL){
        sum += INFO(p);
        count ++;
        p = NEXT(p);
    }
    float avg = (float) (sum/count);
    return avg;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */{
    ElType val;
    while (!isEmpty(*l)){
        deleteFirst(l, &val);
    }
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */{
    CreateList(l2);
    FIRST(*l2) = FIRST(*l1);
}

void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    Address last = FIRST(*l);
    Address loc = NULL;
    Address temp = NULL;
    while (last != NULL){
        temp = last;
        last = NEXT(last);
        NEXT(temp) = loc;
        loc = temp;
    }
    FIRST(*l) = loc;
}
void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */{
    CreateList(l1);
    CreateList(l2);
    if (!isEmpty(l)){
        int len = length(l);
        int idx = 0;
        ElType val;
        Address p = FIRST(l);
        while (p != NULL){
            val = INFO(p);

            if (idx < (len/2)){
                insertLast(l1, val);
            }
            else{
                insertLast(l2, val);
            }
            
            p = NEXT(p);
            idx ++;
        }
     }
}

List fInverseList(List l)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */{
    List newl;
    CreateList(&newl);
    ElType val;
    Address p = FIRST(l);
    while (p != NULL){
        val = INFO(p);
        insertFirst(&newl, val);
        p = NEXT(p);
    }
    return newl;

    // List newl = fCopyList(l);
    // inverseList(&newl);
    // return newl;
}

List fCopyList(List l)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */{
    List newl;
    Address p, newP, prev;
    CreateList(&newl);
    boolean success = true;
    p = FIRST(l);
    prev = NULL;
    while (p != NULL && success){
        //insertLast(&newl, INFO(p));
        newP = newNode(INFO(p));
        if (newP != NULL){
            if (isEmpty(newl)){//prev == NULL
                FIRST(newl) = newP;
            }
            else{ //insert last
                NEXT(prev) = newP;
            }
            prev = newP;
            p = NEXT(p);
        }
        else{
            free(newP);
            deleteAll(&newl);
            success = false;
        }
    }
    return newl;
}

void cpAllocList(List lIn, List *lOut)
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */{
    CreateList(lOut);
    (*lOut) = fCopyList(lIn);
}
