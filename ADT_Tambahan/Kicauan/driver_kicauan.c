#include <stdio.h>
#include <stdlib.h>
#include "listdinkicauan.h"

int main() {
// tes ADT Kicauan
    Kicauan K1, K2, K3;
    Word tweet1, tweet2, tweet3;
    Word penulis1, penulis2, penulis3;
    DATETIME waktu1, waktu2, waktu3;
    Word tes_nama_pengguna;

    tes_nama_pengguna.TabWord[0] = 'a';
    tes_nama_pengguna.TabWord[1] = 'g';
    tes_nama_pengguna.TabWord[2] = 'i';
    tes_nama_pengguna.TabWord[3] = 'l';
    tes_nama_pengguna.Length = 4;

    printf("tweet: ");
    STARTKalimat();
    tweet1 = currentWord;
    printf("pengguna: ");
    STARTKalimat();
    penulis1 = currentWord;
    BacaDATETIME(&waktu1);
    CreateKicauan(&K1, penulis1, waktu1, tweet1, 0);

    printf("tweet: ");
    STARTKalimat();
    tweet2 = currentWord;
    printf("pengguna: ");
    STARTKalimat();
    penulis2 = currentWord;
    BacaDATETIME(&waktu2);
    CreateKicauan(&K2, penulis2, waktu2, tweet2, 0);

    printf("tweet: ");
    STARTKalimat();
    tweet3 = currentWord;
    printf("pengguna: ");
    STARTKalimat();
    penulis3 = currentWord;
    BacaDATETIME(&waktu3);
    CreateKicauan(&K3, penulis3, waktu3, tweet3, 0);

    ListKicauan ListK;
    CreateListDinKicauan(&ListK, 3);
    printf("\n");
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK));
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));
    printf("length: %d\n", listLengthKicau(ListK));
    printf("firstIdx: %d\n", getFirstIdxKicau(ListK));
    printf("lastIdx: %d\n", getLastIdxKicau(ListK));
    printList(ListK);
    dealocateListDinKicauan(&ListK);
    printf("\n");
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK));
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));
    printf("length: %d\n", listLengthKicau(ListK));
    printList(ListK);
    CreateListDinKicauan(&ListK, 5);
    printf("capacity: %d\n", CAPACITY_LIST_KICAUAN(ListK));
    printf("neff: %d\n", NEFF_LIST_KICAUAN(ListK));
    printf("length: %d\n", listLengthKicau(ListK));
    printf("firstIdx: %d\n", getFirstIdxKicau(ListK));
    printf("lastIdx: %d\n", getLastIdxKicau(ListK));
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 1));
    printf("isIdxValid: %d\n", isIdxValidKicau(ListK, 5));
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 3));
    printf("isfull: %d\n", isFullListKicau(ListK));
    printf("isempty: %d\n", isEmptyListKicau(ListK));
    insertLastKicau(&ListK, K1);
    insertLastKicau(&ListK, K2);
    insertLastKicau(&ListK, K3);
    printf("isIdxEff: %d\n", isIdxEffKicau(ListK, 1));
    printf("isfull: %d\n", isFullListKicau(ListK));
    printf("isempty: %d\n", isEmptyListKicau(ListK));
    printList(ListK);


}