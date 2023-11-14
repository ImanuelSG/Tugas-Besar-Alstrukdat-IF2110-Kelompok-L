#include "../MesinBarisFile/MBarisFile.h"
#include "../Kicauan/listdinkicauan.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Globals/globalvar.h"
#include <stdio.h>

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
        printf("%d\n", like);

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
    createMatrix(&matrixPertemanan, iteration, iteration);

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
        CreatePengguna(&pengguna, nama, password, bio, nomor, weton, tipeakun, profil);
        InsertPengguna(pengguna);
        ADVBaris();
    }
    for (int i = 0; i < iteration; i++)
    {
        for (int j = 0; j < iteration; j++)
        {
            ELMT(matrixPertemanan, i, j) = currentBaris.TabWord[j * 2];
        }
        ADVBaris();
    }
    jumlahpermintaan = wordToInteger(currentBaris);
    createMatrix(jumlahpermintaan, 3, &matrixPermintaan);
    for (int i = 0; i < jumlahpermintaan; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ELMT(matrixPermintaan, i, j) = currentBaris.TabWord[j * 2];
        }
        ADVBaris();
    }
}


