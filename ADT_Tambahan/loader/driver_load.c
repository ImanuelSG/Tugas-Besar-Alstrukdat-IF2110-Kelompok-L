#include "load.h"

int main()
{
    ReadPenggunaConfig("pengguna.config");
    ReadKicauanConfig("kicauan.config");
    ReadDrafConfig("draf.config");
    for (int i = 0; i < banyakPengguna; i++)
    {
        printf("Nama : ");
        displayWord(dataPengguna[i].nama);
        printf("\n");
        printf("Sandi : ");
        displayWord(dataPengguna[i].sandi);
        printf("\n");
        printf("Bio : ");
        displayWord(dataPengguna[i].bio);
        printf("\n");
        printf("Nomor : ");
        displayWord(dataPengguna[i].nomor);
        printf("\n");
        printf("Weton : ");
        displayWord(dataPengguna[i].weton);
        printf("\n");
        printf("Tipe Akun : %d\n", dataPengguna[i].tipe_akun);
        printf("Profil : \n");
        displayProfil(dataPengguna[i].profil);
        printf("Draf Kicau: \n");
        DisplayStackDraf(dataPengguna[i].draf);

        printf("\n");
    }
    
    WriteKicauanConfig("kicauantes2.config");
    WritePenggunaConfig("penggunates2.config");
    WriteDrafConfig("draftes2.config");
    displayMatrix(matrixPertemanan);
    displayMatrix(matrixPermintaan);
   
}