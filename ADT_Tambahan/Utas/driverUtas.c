#include "Command_Utas.h"

//gcc -o utas driverUtas.c Command_Utas.c utas.c listdinutas.c ../wordoperations.c ../utils/utils.c ../Kicauan/listdinkicauan.c ../Pengguna/pengguna.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/wordmachine/wordmachine.c 
//gcc -o driver ../Kicauan/listdinkicauan.c ../wordoperations.c ../MesinBarisFile/MBarisFile.c ../MesinKarakterFile/MKarFile.c ../utils/utils.c ../../ADT_Bawaan/datetime/datetime.c ../../ADT_Bawaan/datetime/jam.c ../../ADT_Bawaan/matrix/matrix.c ../Kicauan/ADT_Kicauan.c ../../ADT_Bawaan/wordmachine/wordmachine.c ../Globals/globalvar.c ../../ADT_Bawaan/charmachine/charmachine.c ../Pengguna/pengguna.c ../Profil/profil.c ../DrafKicauan/DrafKicau.c ../DrafKicauan/StackDraf.c ../../ADT_Tambahan/teman/graf_teman.c ../Balasan/treebalasan.c ../Balasan/ADT_Balasan.c driverUtas.c Command_Utas.c utas.c listdinutas.c
//UTAS 1

int main(){
    printf("---------- Driver Utas ----------");
    printf("\n");
    printf("\n");

    //ListDinUtas & ListKicauanData terdefinisi secara global;
    CreateListDinUtas(&lDinUtas, 10);
    printf("");

    Pengguna currentPengguna;
    Kicauan K1, K2;
    Word tweet1, tweet2, newTweet, currentUser;
    Word penulis1, penulis2;
    DATETIME waktu1, waktu2;

    printf("--- Baca Kicauan ---\n");

    //Membuat ListKicauanData untuk testing
    CreateListDinKicauan(&ListKicauanData, 10);
    printf("tweet: "); STARTKalimat();
    tweet1 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis1 = currentWord;
    BacaDATETIME(&waktu1);
    CreateKicauan(&K1, penulis1, waktu1, tweet1, 0);
    insertLastKicau(&ListKicauanData, K1);

    printf("\n");

    printf("tweet: "); STARTKalimat();
    tweet2 = currentWord;
    printf("pengguna: "); STARTKalimat();
    penulis2 = currentWord;
    BacaDATETIME(&waktu2);
    CreateKicauan(&K2, penulis2, waktu2, tweet2, 0);
    insertLastKicau(&ListKicauanData, K2);

    printf("\n");
    currentPengguna.nama = penulis1;
    printf("Pengguna saat ini : "); PrintWord(currentPengguna.nama); printf("\n");

    //ListDinUtas & ListKicauanData terdefinisi secara global;
    printf("Validasi membuat utas baru dengan IDKicau ke-3\n");
    if (!IDKicauFound(3)){
        //Kicauan dengan ID IDKicau tidak ditemukan di listKicauan
        printf("Kicauan tidak ditemukan\n");
    }
    printf("Validasi membuat utas baru dengan IDKicau ke-2\n");
    if (!isIDKicauValid(2)){
        //Kicauan dengan ID IDKicau tak dibuat oleh currentPengguna 
        printf("Utas ini bukan milik currentPengguna!\n");
    }
    printf("Membuat utas baru dengan IDKicau ke-1\n");

    Utas newUtas;
    ListUtas lUtas;
    int index = 0; int IDUtas = 0;
    IDUtas ++;
    Kicauan kicauanUtama = ELMT_LIST_KICAUAN(ListKicauanData, 1);
    createKicauanUtas(&newUtas, IDUtas, 1, penulis1, WAKTU_KICAUAN(kicauanUtama), TWEET(kicauanUtama));
    printf("Utas dengan kicauan utama IDKicau ke-1 terbuat!\n"); printf("\n");
    CreateListUtas(&lUtas); //membuat lUtas kosong
    printf("List utas terbuat!\n"); printf("\n");
    insertFirstUtas(&lUtas, newUtas); //memasukkan newUtas ke lUtas
    printf("Utas dimasukkan ke list utas!\n"); printf("\n");
    insertLastListDinUtas(&lDinUtas, lUtas); //memasukkan lUtas baru ke lDinUtas
    printf("List utas dimasukkan ke list dinamis utas!\n"); printf("\n");

    Utas sambunganUtas, deletedUtas;
    printf("Utas dengan ID ke-1 disambung pada index 1\n"); printf("\n");
    sambungKicauanUtas(sambunganUtas, 1, 1, lUtas);

    printf("Cetak utas dengan ID ke-1\n"); printf("\n");
    displayListUtas(lUtas);

    printf("Utas dengan ID ke-1 dihapus pada index 1\n"); printf("\n");
    deleteAtUtas(&lUtas, 1, &deletedUtas);

    printf("Cetak utas dengan ID ke-1\n"); 
    displayListUtas(lUtas);

    printf("\n");
    printf("Informasi list dinamis utas: \n");
    printf("capacity: %d\n", CAPACITY(lDinUtas)); 
    printf("neff: %d\n", NEFF(lDinUtas));         
    printf("length: %d\n", listDinUtasLength(lDinUtas));      

    printf("Expand list\n");
    expandListDinUtas(&lDinUtas, 30);
    printf("capacity: %d\n", CAPACITY(lDinUtas)); 
    printf("neff: %d\n", NEFF(lDinUtas));         
    printf("length: %d\n", listDinUtasLength(lDinUtas));       

    printf("\nDealokasi list\n");
    dealocateListDinUtas(&lDinUtas);
    printf("capacity: %d\n", CAPACITY(lDinUtas)); 
    printf("neff: %d\n", NEFF(lDinUtas));         
    printf("length: %d\n", listDinUtasLength(lDinUtas));       

    printf("All tests passed.\n");
    printf("--------------------------");
    printf("\n");
}