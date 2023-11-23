#include "load.h"

int main()
{
    Word folderNameWord;


    do
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        START();
        ADVWORD();
        folderNameWord = currentWord;
        if (!isDirectoryExists(wordToString(folderNameWord)))
        {
            printf("Tidak ada folder yang dimaksud!\n");
            printf("\n");
        }
        else
        {
            MUAT(folderNameWord);
        }

    } while (!isDirectoryExists(wordToString(folderNameWord)));

    for (int i = 0; i < banyakPengguna; i++)
    {
        printf("***************PENGGUNA KE - %d***************\n", i + 1);
        printf("Nama : ");
        displayWord(ELMTListStatik(dataPengguna, i).nama);
        printf("\n");
        printf("Sandi : ");
        displayWord(ELMTListStatik(dataPengguna, i).sandi);
        printf("\n");
        printf("Bio : ");
        displayWord(ELMTListStatik(dataPengguna, i).bio);
        printf("\n");
        printf("Nomor : ");
        displayWord(ELMTListStatik(dataPengguna, i).nomor);
        printf("\n");
        printf("Weton : ");
        displayWord(ELMTListStatik(dataPengguna, i).weton);
        printf("\n");
        printf("Tipe Akun : %d\n", ELMTListStatik(dataPengguna, i).tipe_akun);
        printf("Profil : \n");
        displayProfil(ELMTListStatik(dataPengguna, i).profil);
        printf("Draf Kicau Pengguna ke -%d : \n", i + 1);
        DisplayStackDraf(ELMTListStatik(dataPengguna, i).draf);
        printf("\n");
    }
    printf("***************DATA UTAS***************\n");
    ListUtas Listutasdata = getUtas(lDinUtas, 1);
    displayListUtas(Listutasdata);

    ListUtas Listutasdata2 = getUtas(lDinUtas, 2);
    displayListUtas(Listutasdata2);

    printf("***************MATRIX PERTEMANAN***************\n");
    displayMatrix(matrixPertemanan);
    printf("***************MATRIX PERMINTAAN***************\n");
    displayMatrix(matrixPermintaan);
    printf("***************DATA BALASAN***************\n");
    printTree(ELMT_LIST_BALASAN(ListBalasanData, 5), 0);

    printf("Silahkan masukan folder untuk Menyimpan: ");
    START();
    ADVWORD();
    folderNameWord = currentWord;

    SIMPAN(folderNameWord);
}