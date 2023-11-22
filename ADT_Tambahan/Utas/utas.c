#include "utas.h"
#include "listdinutas.h"
#include <stdlib.h>
#include <stdio.h>


/* ****************** KONSTRUKTOR ADT UTAS *******************/
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, Word utasAuthor, DATETIME WaktuKicauan, Word Tweet){
    //Membuat utas secara individual dari komponennya
    IDUTAS(*U) = IDUtas;
    IDKICAU(*U) = IDKicau;
    //KICAUANUTAMA(*U) = kicauanUtama; 
    //INDEX(*U) = index;
    PENULISUTAS(*U) = utasAuthor;
    WAKTUUTAS(*U) = WaktuKicauan;
    TWEETUTAS(*U) = Tweet;
}

/* ****************** Definisi Node Utas *******************/
Address_Utas newNodeKicauanUtas(InfoType val){
    Address_Utas new = (Address_Utas) malloc(sizeof(Utas));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

//ListUtas LIST_UTAS;/////////
/* PROTOTYPE BERKAITAN LINKED LIST UTAS*/
void CreateListUtas(ListUtas *l)
/* I.S. sembarang             */
/* F.S. Terbentuk linked list utas kosong */{
    FIRST(*l) = NULL;
}
boolean isEmptyUtas(ListUtas l){
/* Mengirim true jika linked list kosong */
    return (FIRST(l)  == NULL);
}
InfoType getKicauanUtas(ListUtas l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan kicauan utas pada indeks linked list ke-idx */
    Address_Utas p = FIRST(l);
    int i = 0;
    while (i < idx)
    {
        i++;
        p = NEXT(p);
    }
    return INFO(p);
}
void insertFirstUtas(ListUtas *l, InfoType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama linked list dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */{
    Address_Utas new = newNodeKicauanUtas(val);
    if (new != NULL) {
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
}

void insertLastUtas(ListUtas *l, InfoType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */{
    if (isEmptyUtas(*l)) {
        insertFirstUtas(l, val);
    } else {
        Address_Utas new = newNodeKicauanUtas(val);
        if (new != NULL) {
            Address_Utas last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = new;
        }
    }
}

void insertAtUtas(ListUtas *l, InfoType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah NodeUtas dan */
/* menyisipkan elemen dalam listUtas pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */{
    if (idx == 0) {
        insertFirstUtas(l, val);
    } else {
        Address_Utas new = newNodeKicauanUtas(val);
        if (new != NULL) {
            Address_Utas p = FIRST(*l);
            for (int i = 0; i < idx-1; i++) {
                p = NEXT(p);
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}

// void deleteFirstUtas(ListUtas *l, InfoType *val)
// /* I.S. List l tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
// /*      dan alamat elemen pertama di-dealokasi */{
//     Address_Utas temp = FIRST(*l);
//     *val = INFO(temp);
//     FIRST(*l) = NEXT(temp);
//     free(temp);
// }

void deleteAtUtas(ListUtas *l, int idx, InfoType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */{
    Address_Utas p = FIRST(*l);
    for (int i = 0; i < idx-1; i++) {
        p = NEXT(p);
    }
    Address_Utas temp = NEXT(p);
    *val = INFO(temp);
    NEXT(p) = NEXT(temp);
    free(temp);
}

void displayListUtas(ListUtas l)
/* I.S. List berisi utas */
/* F.S. Serangkaian utas tercetak ke layar*/{
    Address_Utas p = FIRST(l);
    int index = 0;
    while (p != NULL) {
        printKicauanUtas(INFO(p), index);
        p = NEXT(p);
        index ++;
    }
}

int lengthListUtas(ListUtas l)
/* Mengirimkan banyaknya utas; mengirimkan 0 jika linked list kosong */
{
    int count = 0;
    Address_Utas p = FIRST(l);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

/***************** FUNGSI TAMBAHAN UNTUK ADT UTAS *****************/
boolean IDKicauFound(ID IDKicau){
/*Mengirimkan true jika kicauan dengan IDKicau tidak ditemukan di listKicauan*/
    return isIdxEffKicau(ListKicauanData, IDKicau);
}
boolean isIDKicauValid(ID IDKicau){
/*Mengirimkan true jika kicauan dengan IDKicau dibuat oleh currentPengguna */
    return isSameWord(PENULIS_KICAUAN(ELMT_LIST_KICAUAN(ListKicauanData, IDKicau)), currentPengguna.nama);
}

boolean isIndexUtasValid(ListUtas lUtas, int index){
    int len = lengthListUtas(lUtas);
    return (index > 0 && index < len);
}

void printKicauanUtas(Utas U, int index){
/* I.S. U terdefinisi */
/* F.S. Kicauan yang merupakan bagian dari utas tercetak di layar*/  
    printf("\n"); 
    if (index == 0){
        printf("| ID = %d\n", IDKICAU(U));
        printf("| "); PrintWord(PENULISUTAS(U)); printf("\n");
        printf("| "); TulisDATETIME(WAKTUUTAS(U)); printf("\n");
        printf("| "); PrintWord(TWEETUTAS(U)); printf("\n");
    }
    else{
        printf("   "); printf("| INDEX = %d\n", index);
        printf("   "); printf("| "); PrintWord(PENULISUTAS(U)); printf("\n");
        printf("   "); printf("| "); TulisDATETIME(WAKTUUTAS(U)); printf("\n");
        printf("   "); printf("| "); PrintWord(TWEETUTAS(U)); printf("\n");
    }
}

void sambungKicauanUtas(Utas sambunganUtas, ID IDUtas, int index, ListUtas lUtas){
    DATETIME WaktuSambunganUtas;
    BacaDATETIME(&WaktuSambunganUtas);

    Word tweetSambunganUtas;
    printf("\nMasukkan kicauan: \n");
    STARTKalimat();
    tweetSambunganUtas = currentWord;

    createKicauanUtas(&sambunganUtas, IDUtas, -1, currentPengguna.nama, WaktuSambunganUtas, tweetSambunganUtas);
    insertAtUtas(&lUtas, sambunganUtas, index);
}