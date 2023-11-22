#include "load.h"

int main()
{
    Word path_config1, path_config2, path_config3, path_config4, path_config5;

    Word folderNameWord = stringToWord("Driver", 6);
    path_config1 = DuplicateWord(folderNameWord);
    path_config2 = DuplicateWord(folderNameWord);
    path_config3 = DuplicateWord(folderNameWord);
    path_config4 = DuplicateWord(folderNameWord);
    path_config5 = DuplicateWord(folderNameWord);

    appendWord(&path_config1, stringToWord("/pengguna.config", 16));
    appendWord(&path_config2, stringToWord("/kicauan.config", 15));
    appendWord(&path_config3, stringToWord("/balasan.config", 15));
    appendWord(&path_config4, stringToWord("/draf.config", 12));
    appendWord(&path_config5, stringToWord("/utas.config", 12));

    char *path_config1_str = wordToString(path_config1);
    char *path_config2_str = wordToString(path_config2);
    char *path_config3_str = wordToString(path_config3);
    char *path_config4_str = wordToString(path_config4);
    char *path_config5_str = wordToString(path_config5);

    ReadPenggunaConfig(path_config1_str);
    ReadKicauanConfig(path_config2_str);
    ReadDrafConfig(path_config4_str);
    ReadBalasanConfig(path_config3_str);

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

    printTree(ELMT_LIST_BALASAN(ListBalasanData, 5), 0);
}