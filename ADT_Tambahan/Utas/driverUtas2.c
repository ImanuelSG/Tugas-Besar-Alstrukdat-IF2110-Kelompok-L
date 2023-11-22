#include "listdinutas.h"
#include "Command_Utas.h"


//gcc -o utas2 ../Kicauan/listdinkicauan.c ../wordoperations.c ../MesinBarisFile/MBarisFile.c ../MesinKarakterFile/MKarFile.c ../utils/utils.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/datetime/jam.c ../../ADT_Bawaan/matrix/matrix.c ../Kicauan/ADT_Kicauan.c ../../ADT_Bawaan/wordmachine/wordmachine.c ../Globals/globalvar.c ../../ADT_Bawaan/charmachine/charmachine.c ../Pengguna/pengguna.c ../Profil/profil.c ../DrafKicauan/DrafKicau.c ../DrafKicauan/StackDraf.c ../../ADT_Tambahan/teman/graf_teman.c ../Balasan/treebalasan.c ../Balasan/ADT_Balasan.c driverUtas2.c Command_Utas.c utas.c listdinutas.c

#define nl printf("\n")

int main(){
    //ListDinUtas lDinUtas;
    CreateListDinUtas(&lDinUtas, 100);
    //ListKicauan ListKicauanData;
    CreateListDinKicauan(&ListKicauanData, 10);

    Word currentUser;
    currentUser.TabWord[0] = 'K'; currentUser.TabWord[1] = 'a'; currentUser.TabWord[2] = 'y'; 
    currentUser.Length = 3;
    currentPengguna.nama = currentUser;

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

    Kicauan NewKicauan3;
    DATETIME WaktuKicauan3;
    BacaDATETIME(&WaktuKicauan3);
    Word NewTweet3;
    NewTweet3.TabWord[0] = 'P'; NewTweet2.TabWord[1] = 'P'; 
    NewTweet3.Length = 2;
    CreateKicauan(&NewKicauan3, currentUser, WaktuKicauan, NewTweet3, 0);
    insertLastKicau(&ListKicauanData, NewKicauan3);

    printList(ListKicauanData);
    nl;

    //UTAS(IDKicau);
    //Word perintah;

    //STARTWORD();
    //perintah = currentWord;
    
    UTAS(1);
    ListUtas lUtas = getUtas(lDinUtas,1);
    displayListUtas(lUtas);

    HAPUS_UTAS(3, 3);
}