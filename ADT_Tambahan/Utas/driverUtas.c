#include "listdinutas.h"
#include "Command_Utas.h"

//gcc -o utas driverUtas.c Command_Utas.c utas.c listdinutas.c ../wordoperations.c ../utils/utils.c ../Kicauan/listdinkicauan.c ../Pengguna/pengguna.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/wordmachine/wordmachine.c 
//gcc -o utas ../Kicauan/listdinkicauan.c ../wordoperations.c ../MesinBarisFile/MBarisFile.c ../MesinKarakterFile/MKarFile.c ../utils/utils.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/datetime/jam.c ../../ADT_Bawaan/matrix/matrix.c ../Kicauan/ADT_Kicauan.c ../../ADT_Bawaan/wordmachine/wordmachine.c ../Globals/globalvar.c ../../ADT_Bawaan/charmachine/charmachine.c ../Pengguna/pengguna.c ../Profil/profil.c ../DrafKicauan/DrafKicau.c ../DrafKicauan/StackDraf.c ../../ADT_Tambahan/teman/graf_teman.c ../Balasan/treebalasan.c ../Balasan/ADT_Balasan.c driverUtas.c Command_Utas.c utas.c listdinutas.c
#define not(n) !n
#define nl printf("\n")
//UTAS 1
int main(){
    ListDinUtas lDinUtas;
    ListKicauan ListKicauanData;
    CreateListDinKicauan(&ListKicauanData, 10);

    Word currentUser;
    currentUser.TabWord[0] = 'K'; currentUser.TabWord[1] = 'a'; currentUser.TabWord[2] = 'y'; 
    currentUser.Length = 3;

    Kicauan NewKicauan;
    DATETIME WaktuKicauan;
    BacaDATETIME(&WaktuKicauan);

    Word NewTweet;
    NewTweet.TabWord[0] = 'h'; NewTweet.TabWord[1] = 'i'; 
    NewTweet.Length = 2;
    CreateKicauan(&NewKicauan, currentUser, WaktuKicauan, NewTweet, 0);
    insertLastKicau(&ListKicauanData, NewKicauan);

    Kicauan NewKicauan2;
    DATETIME WaktuKicauan2;
    BacaDATETIME(&WaktuKicauan2);
    Word NewTweet2;
    NewTweet2.TabWord[0] = 'q'; NewTweet2.TabWord[1] = 'i'; 
    NewTweet2.Length = 2;
    CreateKicauan(&NewKicauan2, currentUser, WaktuKicauan, NewTweet2, 0);
    insertLastKicau(&ListKicauanData, NewKicauan2);

    printList(ListKicauanData);
    nl;
    if (!isIdxEffKicau(ListKicauanData, 1)){
        //Kicauan dengan ID IDKicau tidak ditemukan di listKicauan
        printf("Kicauan tidak ditemukan\n");
    }

    CreateListDinUtas(&lDinUtas, 100);

    //UTAS(IDKicau);
    Word perintah;
    printf(">>> ");
    STARTWORD();
    perintah = currentWord;

    while (currentChar != ';')
    {
        if (isSameWord(perintah, stringToWord("UTAS", 4)))
        {
            ADVWORD();
            int id = wordToInteger(currentWord);

            printf("Panggil fungsi UTAS dengan parameter [IDKicauan]: %d", id);
            UTAS(id);
            nl;
        }

        else if (isSameWord(perintah, stringToWord("SAMBUNG_UTAS", 7)))
        {
            ADVWORD();
            int id = wordToInteger(currentWord);
            ADVWORD();
            int index = wordToInteger(currentWord);

            printf("Panggil fungsi SAMBUNG_UTAS dengan parameter [IDUtas] [index]: %d", id, index);
            SAMBUNG_UTAS(id, index);
            nl;
        }

        else if (isSameWord(perintah, stringToWord("HAPUS_UTAS", 12)))
        {
            ADVWORD();
            int id = wordToInteger(currentWord);
            ADVWORD();
            int index = wordToInteger(currentWord);

            printf("Panggil fungsi HAPUS_UTAS dengan parameter [IDUtas] [index]: %d", id, index);
            HAPUS_UTAS(id, index);
            nl;
        }

        else if (isSameWord(perintah, stringToWord("CETAK_UTAS", 12)))
        {
            ADVWORD();
            int id = wordToInteger(currentWord);

            printf("Panggil fungsi CETAK_UTAS dengan parameter [IDUtas]: %d", id);
            CETAK_UTAS(id);
        }
        
    }
    
}