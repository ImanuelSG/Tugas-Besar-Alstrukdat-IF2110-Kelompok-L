#include "utas.h"
#include "listdinutas.h"
#include <stdlib.h>
#include <stdio.h>

/* ****************** KONSTRUKTOR ADT UTAS *******************/
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, int index, Pengguna utasAuthor, DATETIME WaktuKicauan, Word Tweet){
    //Membuat utas secara individual dari komponennya
    IDUTAS(*U) = IDUtas;
    IDKICAU(*U) = IDKicau;
    KICAUANUTAMA(*U) = ELMT(LIST_KICAUAN_DATA, IDKicau);
    INDEX(*U) = index;
    PENULISUTAS(*U) = currentPengguna;
    WAKTUKICAUAN(*U) = WaktuKicauan;
    TWEET(*U) = Tweet;
}

Address newNodeKicauanUtas(InfoType val){
    Address new = (Address) malloc(sizeof(Utas));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

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
/* F.S. Mengembalikan utas pada indeks linked list ke-idx */
    Address p = FIRST(l);
    int i = 0;
    while (i < idx) {
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
    Address new = newNodeKicauanUtas(val);
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
        Address new = newNodeKicauanUtas(val);
        if (new != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = new;
        }
    }
}

void insertAtUtas(ListUtas *l, InfoType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */{
    if (idx == 0) {
        insertFirstUtas(l, val);
    } else {
        Address new = newNodeKicauanUtas(val);
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

void deleteFirstUtas(ListUtas *l, InfoType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */{
    Address temp = FIRST(*l);
    *val = INFO(temp);
    FIRST(*l) = NEXT(temp);
    free(temp);
}

void deleteAtUtas(ListUtas *l, int idx, InfoType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */{
    if (idx == 0) {
        deleteFirstUtas(l, val);
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

void displayListUtas(ListUtas l)
/* I.S. List berisi kicauan utama */
/* F.S. Serangkaian utas tercetak ke layar*/{
    Address p = FIRST(l);
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
    Address p = FIRST(l);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

/***************** FUNGSI TAMBAHAN UNTUK ADT UTAS *****************/
boolean IDKicauFound(ID IDKicau){
/*Mengirimkan true jika kicauan dengan IDKicau tidak ditemukan di listKicauan*/
    return isIdxEff(LIST_KICAUAN_DATA, IDKicau);
}
boolean isIDKicauValid(ID IDKicau){
/*Mengirimkan true jika kicauan dengan IDKicau dibuat oleh currentPengguna */
    return wordCompare(PENULIS_KICAUAN(ELMT(LIST_KICAUAN_DATA, IDKicau)), currentPengguna.nama);
}

void printKicauanUtas(Utas U, int index){
/* I.S. U terdefinisi */
/* F.S. Kicauan yang merupakan bagian dari utas tercetak di layar*/  
    printf("\n"); 
    if (index == 0){
        printf("| ID = %d\n", IDUTAS(U));
        printf("| "); printWord(PENULISUTAS(U)); printf("\n");
        printf("| "); TulisDATETIME(WAKTU_KICAUAN(KICAUANUTAMA(U))); printf("\n");
        printf("| "); printWord(TWEET(KICAUANUTAMA(U))); printf("\n");
    }
    else{
        printf("\t"); printf("| INDEX = %d\n", index);
        printf("\t"); printf("| "); printWord(PENULISUTAS(U)); printf("\n");
        printf("\t"); printf("| "); TulisDATETIME(WAKTUKICAUAN(U)); printf("\n");
        printf("\t"); printf("| "); printWord(TWEET(U)); printf("\n");
    }
}

void UTAS(ID IDKicau){
    //Membuat utas dengan index ke-0 nya kicauan utama (buat node baru)
    //setelah linked list listUtas terbuat, insert ke listdin listDinUtas
    if (!IDKicauFound(IDKicau)){
        printf("Kicauan tidak ditemukan\n");
    }
    else if (!isIDKicauValid(IDKicau)){
        printf("Utas ini bukan milik Anda!\n");
    }
    else{
        printf("Utas berhasil dibuat!\n"); printf("\n");
        //insertfirst kicauan utama to linked list, insert to listdin
        // listlinier listkicau;
        // kicaux = createUtas();
        // p = newnode(kicaux)
        // createLinkedList(&listkicau)
        
        printf("Masukkan kicauan: \n");
        Word newTweet;
        STARTKalimat();
        newTweet = currentWord;
        /*sambungKicauanUtas()*/

        Word Ya;
        Ya.TabWord[0] = 'Y'; Ya.TabWord[1] = 'A';
        Ya.Length = 2;
        Word confirmSambung;
        do
        {
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) \n");
            STARTKalimat();
            confirmSambung = currentWord;
            if (isSameWord(confirmSambung,Ya)){
                /*sambungKicauanUtas()*/
            }
        } while (isSameWord(confirmSambung,Ya));
        
        // insertLast(&listkicau)
        // insertLast();
        //insert ke listdin
    }
}