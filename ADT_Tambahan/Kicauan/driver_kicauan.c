#include <stdio.h>
#include <stdlib.h>
#include "listdinkicauan.h"

// gcc Driver_Kicauan.c listdinkicauan.c ../wordoperations.c ../MesinBarisFile/MBarisFile.c ../MesinKarakterFile/MKarFile.c ../utils/utils.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/datetime/jam.c ../../ADT_Bawaan/matrix/matrix.c ADT_Kicauan.c ../../ADT_Bawaan/wordmachine/wordmachine.c ../Globals/globalvar.c ../../ADT_Bawaan/charmachine/charmachine.c ../Pengguna/pengguna.c ../Profil/profil.c ../DrafKicauan/DrafKicau.c ../DrafKicauan/StackDraf.c ../../ADT_Tambahan/teman/graf_teman.c ../Balasan/treebalasan.c ../Balasan/ADT_Balasan.c
int main() {
// tes ADT Kicauan
    Kicauan K1, K2, K3;
    Word tweet1, tweet2, tweet3, newTweet, tweet4, tweet5, tweet6;
    Word penulis1, penulis2, penulis3;
    DATETIME waktu1, waktu2, waktu3;

    printf("tweet: "); STARTKalimat();
    tweet1 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis1 = currentWord;
    BacaDATETIME(&waktu1);
    CreateKicauan(&K1, penulis1, waktu1, tweet1, 0);

    printf("tweet: "); STARTKalimat();
    tweet2 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis2 = currentWord;
    BacaDATETIME(&waktu2);
    CreateKicauan(&K2, penulis2, waktu2, tweet2, 0);

    printf("tweet: "); STARTKalimat();
    tweet3 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis3 = currentWord;
    BacaDATETIME(&waktu3);
    CreateKicauan(&K3, penulis3, waktu3, tweet3, 0);

    ListKicauan ListK;
    CreateListDinKicauan(&ListK, 3);
    printf("\n");
    printf("Membuat list kosong berukuran 3 \n");
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK)); // 3
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));         // 0
    printf("length: %d\n", listLengthKicau(ListK));         // 0
    printf("firstIdx: %d\n", getFirstIdxKicau(ListK));      // IDX_UNDEF = 0
    printf("lastIdx: %d\n", getLastIdxKicau(ListK));        // IDX_UNDEF = 0
    printList(ListK);                                       // Tidak ada kicauan yang dapat ditampilkan!

    printf("\nDealokasi list\n");
    dealocateListDinKicauan(&ListK);
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK)); // 0
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));         // 0
    printf("length: %d\n", listLengthKicau(ListK));         // 0
    printList(ListK);                                       // Tidak ada kicauan yang dapat ditampilkan!

    CreateListDinKicauan(&ListK, 5);
    printf("\nMembuat list kosong berukuran 5\n");
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK)); // 5
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));         // 0
    printf("length: %d\n", listLengthKicau(ListK));         // 0
    printf("firstIdx: %d\n", getFirstIdxKicau(ListK));      // IDX_UNDEF = 0
    printf("lastIdx: %d\n", getLastIdxKicau(ListK));        // IDX_UNDEF = 0
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 1));  // true = 1
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 5));  // false = 0
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 3));      // false = 0
    printf("isfull: %d\n", isFullListKicau(ListK));         // false = 0
    printf("isempty: %d\n", isEmptyListKicau(ListK));       // true = 1
    
    printf("\nKicauan ditambahkan ke list\n");
    insertLastKicau(&ListK, K1);
    insertLastKicau(&ListK, K2);
    insertLastKicau(&ListK, K3);
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 3));      // true = 1
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 1));      // true = 1
    printf("isfull: %d\n", isFullListKicau(ListK));         // false = 0
    printf("isempty: %d\n", isEmptyListKicau(ListK));       // false = 0
    printList(ListK);

    AddLike(&ELMT_LIST_KICAUAN(ListK, 1));
    AddLike(&ELMT_LIST_KICAUAN(ListK, 1));
    AddLike(&ELMT_LIST_KICAUAN(ListK, 1));
    printf("\nLike pada Kicauan 3 bertambah 1\n");
    printf("Like Kicauan 1: %d\n", LIKE(ELMT_LIST_KICAUAN(ListK, 1))); // 1
    printf("Like Kicauan 2: %d\n", LIKE(ELMT_LIST_KICAUAN(ListK, 2))); // 0
    printf("Like Kicauan 3: %d\n", LIKE(ELMT_LIST_KICAUAN(ListK, 3))); // 0
    
    printf("\nMengubah Tweet Kicauan 1\n");
    printf("tweet: "); STARTKalimat();
    newTweet = currentWord;
    EditTweet(&ELMT_LIST_KICAUAN(ListK, 1), newTweet);
    printf("Tweet Kicauan 1: "); PrintWord(TWEET(ELMT_LIST_KICAUAN(ListK, 1))); printf("\n");
    printf("Tweet Kicauan 2: "); PrintWord(TWEET(ELMT_LIST_KICAUAN(ListK, 2))); printf("\n");
    printf("Tweet Kicauan 3: "); PrintWord(TWEET(ELMT_LIST_KICAUAN(ListK, 3))); printf("\n");

    expandListKicau(&ListK, 2);
    printf("\nMengubah kapasitas list menjadi 7\n");
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK)); // 7
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));         // 3
    printf("length: %d\n", listLengthKicau(ListK));         // 3
    printf("firstIdx: %d\n", getFirstIdxKicau(ListK));      // 1
    printf("lastIdx: %d\n", getLastIdxKicau(ListK));        // 3
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 6));  // true = 1
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 7));  // false = 0
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 3));      // true = 1
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 1));      // true = 1
    printf("isfull: %d\n", isFullListKicau(ListK));         // false = 0
    printf("isempty: %d\n", isEmptyListKicau(ListK));       // false = 0
}