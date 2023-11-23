#include <stdio.h>
#include <stdlib.h>
#include "treebalasan.h"
#include "../Kicauan/listdinkicauan.h"

// gcc Driver_Balasan.c ../Kicauan/listdinkicauan.c ../wordoperations.c ../MesinBarisFile/MBarisFile.c ../MesinKarakterFile/MKarFile.c ../utils/utils.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/datetime/jam.c ../../ADT_Bawaan/matrix/matrix.c ../Kicauan/ADT_Kicauan.c ../../ADT_Bawaan/wordmachine/wordmachine.c ../Globals/globalvar.c ../../ADT_Bawaan/charmachine/charmachine.c ../Pengguna/pengguna.c ../Profil/profil.c ../DrafKicauan/DrafKicau.c ../DrafKicauan/StackDraf.c ../../ADT_Tambahan/teman/graf_teman.c treebalasan.c ADT_Balasan.c
int main() {
// tes ADT Balasan
//  menyiapkan kicauan
    Kicauan K1;
    Word tweet1;
    Word penulis1;
    DATETIME waktu1;

    printf("tweet: "); STARTKalimat();
    tweet1 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis1 = currentWord;
    BacaDATETIME(&waktu1);
    CreateKicauan(&K1, penulis1, waktu1, tweet1, 0);
    
    ListKicauan ListK;
    CreateListDinKicauan(&ListK, 2);
    insertLastKicau(&ListK, K1);

//  menyiapkan balasan
/*
    K1
    | ID = 1
        | ID = 3
        | ID = 4
            | ID = 5
                | ID = 7
    | ID = 2
        | ID = 6
*/
    Balasan B1, B2, B3, B4, B5, B6, B7;
    Word balasan1, balasan2, balasan3, balasan4, balasan5, balasan6, balasan7;
    Word author1, author2, author3, author4, author5, author6, author7;
    DATETIME time1, time2, time3, time4, time5, time6, time7;

    printf("balasan: "); STARTKalimat();
    balasan1 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author1 = currentWord;
    BacaDATETIME(&time1);
    CreateBalasan(&B1, author1, time1, balasan1, &K1, -1);

    printf("balasan: "); STARTKalimat();
    balasan2 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author2 = currentWord;
    BacaDATETIME(&time2);
    CreateBalasan(&B2, author2, time2, balasan2, &K1, -1);

    printf("balasan: "); STARTKalimat();
    balasan3 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author3 = currentWord;
    BacaDATETIME(&time3);
    CreateBalasan(&B3, author3, time3, balasan3, &K1, 1);

    printf("balasan: "); STARTKalimat();
    balasan4 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author4 = currentWord;
    BacaDATETIME(&time4);
    CreateBalasan(&B4, author4, time4, balasan4, &K1, 1);

    printf("balasan: "); STARTKalimat();
    balasan5 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author5 = currentWord;
    BacaDATETIME(&time5);
    CreateBalasan(&B5, author5, time5, balasan5, &K1, 4);

    printf("balasan: "); STARTKalimat();
    balasan6 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author6 = currentWord;
    BacaDATETIME(&time6);
    CreateBalasan(&B6, author6, time6, balasan6, &K1, 2);

    printf("balasan: "); STARTKalimat();
    balasan7 = currentWord;
    printf("pengguna: "); STARTKalimat();
    author7 = currentWord;
    BacaDATETIME(&time7);
    CreateBalasan(&B7, author7, time7, balasan7, &K1, 5);

    ListBalasan ListB;
    CreateListBalasan(&ListB, 5);    
    insertSiblingLast(&ELMT_LIST_BALASAN(ListB, 1), B1);
    insertSiblingLast(&ELMT_LIST_BALASAN(ListB, 1), B2);

    Address balas1 = searchTree(ELMT_LIST_BALASAN(ListB, 1), 1);
    insertChild(&balas1, B3);
    insertChild(&balas1, B4);

    Address balas4 = searchTree(ELMT_LIST_BALASAN(ListB, 1), 4);
    insertChild(&balas4, B5);

    Address balas2 = searchTree(ELMT_LIST_BALASAN(ListB, 1), 2);
    insertChild(&balas2, B6);

    Address balas5 = searchTree(ELMT_LIST_BALASAN(ListB, 1), 5);
    insertChild(&balas5, B7);

    printf("List Balasan:\n");
    printTree(ELMT_LIST_BALASAN(ListB, 1), 0);

    printf("\n");
    Address loc, before;
    searchBeforeTree(ELMT_LIST_BALASAN(ListB, 1), 5, &before, &loc);
    printf("before: %d\n", ID_BALASAN(INFO_TREE(before)));
    printf("loc: %d\n", ID_BALASAN(INFO_TREE(loc)));

    printf("**************************************************************\n");
    deleteTree(&ELMT_LIST_BALASAN(ListB, 1), 1);
    printTree(ELMT_LIST_BALASAN(ListB, 1), 0);

    printf("**************************************************************\n");
    deleteTree(&ELMT_LIST_BALASAN(ListB, 1), 2);
    printTree(ELMT_LIST_BALASAN(ListB, 1), 0);
}