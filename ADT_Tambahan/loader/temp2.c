#include "../MesinBarisFile/MBarisFile.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Profil/profil.h"
#include "../Globals/globalvar.h"
#include "../Kicauan/listdinkicauan.h"
#include "../DrafKicauan/StackDraf.h"
#include "../utils/utils.h"

#include <stdio.h>

/**
 * @brief Prosedur membaca config pengguna
 *
 * @param namafile file yang ingin dibaca relatif terhadap tempat pemanggilan prosedur
 */
void ReadPenggunaConfig(char namafile[])
{

    int iteration, tipeakun, jumlahpermintaan;
    Pengguna pengguna;
    Word nama, password, bio, nomor, weton, temp;
    MatrixProfil profil;

    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    ADVBaris();
    createMatrix(iteration, iteration, &matrixPertemanan);

    for (int i = 0; i < iteration; i++)
    {
        /*Bagian Ngisi Pengguna*/
        nama = currentBaris;
        ADVBaris();
        password = currentBaris;
        ADVBaris();
        bio = currentBaris;
        ADVBaris();
        nomor = currentBaris;
        ADVBaris();
        weton = currentBaris;
        ADVBaris();
        temp = currentBaris;
        /*tipe akun*/
        if (isSameWord(temp, stringToWord("Publik", 6)))
        {
            tipeakun = 0;
        }
        else
        {
            tipeakun = 1;
        }
        for (int j = 0; j < 5; j++)
        {
            ADVBaris();
            int n = 0;
            for (int k = 0; k < 10; k++)
            {
                profil.mem[j][k].TabWord[0] = currentBaris.TabWord[k * 2];
                // To Place the index in the right position
            }
        }
        StackDraf S;
        CreateStackDraf(&S);
        CreatePengguna(&pengguna, nama, password, bio, nomor, weton, tipeakun, profil, S);
        InsertPengguna(pengguna);

        ADVBaris();
    }

    for (int i = 0; i < iteration; i++)
    {
        for (int j = 0; j < iteration; j++)
        {
            ELMT(matrixPertemanan, i, j) = charToDigit(currentBaris.TabWord[j * 2]);
        }
        ADVBaris();
    }

    jumlahpermintaan = wordToInteger(currentBaris);
    createMatrix(jumlahpermintaan, 3, &matrixPermintaan);
    for (int i = 0; i < jumlahpermintaan; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ELMT(matrixPermintaan, i, j) = charToDigit(currentBaris.TabWord[j * 2]);
        }
        ADVBaris();
    }
}
/**
 * @brief Prosedur Membaca Konfig Kicau
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void ReadKicauanConfig(char namafile[])
{
    CreateListDinKicauan(&ListKicauanData, 100);
    int iteration, like;
    Kicauan kicau;
    Word Penulis, WaktuKicauan, Tweet;
    DATETIME Waktu;

    STARTBaris(namafile);

    iteration = wordToInteger(currentBaris);

    ADVBaris();

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris();
        Tweet = currentBaris;

        ADVBaris();

        like = wordToInteger(currentBaris);

        ADVBaris();
        Penulis = currentBaris;
        ADVBaris();
        Waktu = wordToDatetime(currentBaris);
        ADVBaris();

        CreateKicauan(&kicau, Penulis, Waktu, Tweet, like);
        insertLastKicau(&ListKicauanData, kicau);
    }
}
/**
 * @brief Prosedur Membaca Konfig Draf
 *
 * @param namafile
 */
void ReadDrafConfig(char namafile[])
{
    int iteration, banyak;
    Word username, isi;
    DATETIME Date;
    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    ADVBaris(); // baris == "username"
    for (int i = 0; i < iteration; i++)
    {
        banyak = 0;
        i = currentBaris.Length - 1;
        int pengkali = 1;
        while (currentBaris.TabWord[i] != ' ')
        {
            banyak += charToDigit(currentBaris.TabWord[i]) * pengkali;
            pengkali *= 10;
            i--;
            currentBaris.Length--;
        }
        currentBaris.Length--;
        username = currentBaris;
        Pengguna *curr = getPengguna(username);
        ADVBaris(); // baris == "isi"
        for (int j = 0; j < banyak; j++)
        {
            DrafKicau currdraf;
            isi = currentBaris;
            ADVBaris(); // baris == "tanggal"
            Date = wordToDatetime(currentBaris);
            ADVBaris(); // baris == "isi"
            CreateDraf(&currdraf, isi, Date);
            SimpanDraf(&curr->draf, currdraf);
        }
        ReverseStackDraf(&curr->draf);
    }
}
/**
 * @brief Prosedur Membaca Konfig Utas
 *
 * @param namafile
 */
void ReadUtasConfig(char namafile[])
{
    int iteration, like;

    Word Penulis, WaktuKicauan, Tweet;
    DATETIME Waktu;

    STARTBaris(namafile); // curr baris == iteration

    iteration = wordToInteger(currentBaris);

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris(); // curr baris == "ID"
        ID IDKicauUtama = wordToInteger(currentBaris);
        ADVBaris(); // curr baris == jumlahUtas
        int jumlahUtas = wordToInteger(currentBaris);
        for (int i = 0; i < jumlahUtas; i++)
        {
            ADVBaris();
            Word Text = currentBaris;
            ADVBaris();
            Word Author = currentBaris;
            ADVBaris();
            DATETIME Waktu = wordToDatetime(currentBaris);
            /*Create Utas and insert it to the list*/
        }
    }
}
/**
 * @brief  Prosedur Membaca Konfig Balasan
 *
 * @param namafile
 */

void parseId(Word w, int *idparent, int *idbalasan)
{
    int i = 0;
    int id = 0;
    int isneg = 1;
    while (w.TabWord[i] != ' ')
    {
        if (w.TabWord[i] == '-')
        {
            isneg = -1;
            i++;
        }
        else
        {
            id *= 10;
            id += charToDigit(w.TabWord[i]);
            i++;
        }
    }
    *idparent = id * isneg;
    int last = w.Length - 1;
    int num = 0;
    int pengkali = 1;
    while (w.TabWord[last] != ' ')
    {
        num += charToDigit(w.TabWord[last]) * pengkali;
        pengkali *= 10;
        last--;
    }
    *idbalasan = num;
}

void ReadBalasanConfig(char namafile[])
{
    int iteration;
    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);

    ADVBaris();
    ID IDKicauUtama = wordToInteger(currentBaris);
    for (int i = 0; i < iteration; i++)
    {
        ADVBaris();
        int jumlahbalasan = wordToInteger(currentBaris);
        for (int j = 0; j < jumlahbalasan; j++)
        {
            ADVBaris();
            int idparent, idbalasan;
            parseId(currentBaris, &idparent, &idbalasan);
            ADVBaris();
            Word te
            ADVBaris();
            Word Author = currentBaris;
            ADVBaris();
            DATETIME Waktu = wordToDatetime(currentBaris);
            /*Create Balasan and insert it to the list*/
        }
    }
}
// void Load(char *namafolder)
// {

//     Word path_config1, path_config2, path_config3, path_config4, path_config5;

//     path_config1 = DuplicateWord(folderNameWord);
//     path_config2 = DuplicateWord(folderNameWord);
//     path_config3 = DuplicateWord(folderNameWord);
//     path_config4 = DuplicateWord(folderNameWord);
//     path_config5 = DuplicateWord(folderNameWord);

//     appendWord(&path_config1, stringToWord("/pengguna.config", 16));
//     appendWord(&path_config2, stringToWord("/kicauan.config", 15));
//     appendWord(&path_config3, stringToWord("/balasan.config", 15));
//     appendWord(&path_config4, stringToWord("/draf.config", 12));
//     appendWord(&path_config5, stringToWord("/utas.config", 12));

//     char *path_config1_str = wordToString(path_config1);
//     char *path_config2_str = wordToString(path_config2);
//     char *path_config3_str = wordToString(path_config3);
//     char *path_config4_str = wordToString(path_config4);
//     char *path_config5_str = wordToString(path_config5);

//     ReadPenggunaConfig(path_config1_str);
//     ReadKicauanConfig(path_config2_str);
//     ReadDrafConfig(path_config4_str);

//      for (int i = 0; i < banyakPengguna; i++)
//     {
//         printf("Nama : ");
//         displayWord(dataPengguna[i].nama);
//         printf("\n");
//         printf("Sandi : ");
//         displayWord(dataPengguna[i].sandi);
//         printf("\n");
//         printf("Bio : ");
//         displayWord(dataPengguna[i].bio);
//         printf("\n");
//         printf("Nomor : ");
//         displayWord(dataPengguna[i].nomor);
//         printf("\n");
//         printf("Weton : ");
//         displayWord(dataPengguna[i].weton);
//         printf("\n");
//         printf("Tipe Akun : %d\n", dataPengguna[i].tipe_akun);
//         printf("Profil : \n");
//         displayProfil(dataPengguna[i].profil);
//         printf("Draf Kicau: \n");
//         DisplayStackDraf(dataPengguna[i].draf);

//         printf("\n");
//     }
//     displayMatrix(matrixPertemanan);
//     displayMatrix(matrixPermintaan);
//     printList(ListKicauanData);
// }