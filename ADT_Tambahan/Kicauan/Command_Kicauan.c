#include <stdio.h>
#include "listdinkicauan.h"
#include "../Utils/utils.h"
#include "../Globals/globalvar.h"
#include "../wordoperations.h"

/* ********** PERINTAH-PERINTAH PADA FITUR KICAUAN ********** */
/* ********** UNTUK MAIN PROGRAM ********** */
/* KICAU */
void KICAU()
{
    /* Membuat sebuah Kicauan */
    Word NewTweet;

    printf("\nMasukkan kicauan:\n");
    STARTKalimat();
    NewTweet = currentWord;

    if (IsAllBlank(NewTweet))
    {
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    }
    else
    { // tweet valid
        Kicauan NewKicauan;
        DATETIME WaktuKicauan;

        BacaDATETIME(&WaktuKicauan);
        
        CreateKicauan(&NewKicauan, currentPengguna.nama, WaktuKicauan, NewTweet, 0);
        insertLast(&ListKicauanData, NewKicauan);

        printf("\nSelamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:");
        PrintKicauan(NewKicauan, CURRENT_ID_KICAUAN);
        printf("\n");
    }
}

/* KICAUAN */
void KICAUAN()
{
    /* Menampilkan semua kicauan yang dibuat pengguna dan teman pengguna ke layar */
    /* Terurut berdasarkan kicauan terbaru (ID Kicauan terbesar) */
    printListKicauan(ListKicauanData, currentPengguna.nama);
}

/* SUKA_KICAUAN */
void SUKA_KICAUAN(ID IDKicauan)
{
    /* Menambahkan like pada kicauan yang dipilih pengguna */
    printf("\n");
    if (!isIdxEffKicau(ListKicauanData, IDKicauan))
    { // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d;\n", IDKicauan);
    }
    else
    {
        if (!isBerteman(currentPengguna.nama, ELMTKicau(ListKicauanData, IDKicauan).PenulisKicauan) && getPengguna(ELMTKicau(ListKicauanData, IDKicauan).PenulisKicauan).tipe_akun == 1)
        {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
        else
        { /* akun privat dan berteman, atau akun bersifat publik */
            AddLike(&ELMTKicau(ListKicauanData, IDKicauan));
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");
            PrintKicauan(ELMTKicau(ListKicauanData, IDKicauan), IDKicauan);
        }
    }
    printf("\n");
}

/* UBAH_KICAUAN */
void UBAH_KICAUAN(ID IDKicauan)
{
    /* Mengubah isi kicauan yang dipilih pengguna */
    printf("\n");

    if (isIdxEffKicau(ListKicauanData, IDKicauan))
    { // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d!;\n", IDKicauan);
    }
    // else if (!issame)
    // {
    //     printf("Kicauan dengan ID = %d bukan milikmu!\n", IDKicauan); // kicauan bukan milik pengguna
    // }
    else
    { // kicauan milik pengguna
        if (isSameWord(ELMTKicau(ListKicauanData, IDKicauan).PenulisKicauan, currentPengguna.nama))
        {
            Word NewTweet;
            printf("Masukkan kicauan baru:\n");
            STARTKalimat();
            NewTweet = currentWord;

            if (IsAllBlank(NewTweet))
            {
                printf("\nKicauan tidak boleh hanya berisi spasi!\n");
            }
            else
            { // tweet valid
                EditTweet(&ELMTKicau(ListKicauanData, IDKicauan), NewTweet);
                printf("\nSelamat! kicauan telah diterbitkan!\n");
                printf("Detil kicauan:");
                PrintKicauan(ELMTKicau(ListKicauanData, IDKicauan), IDKicauan);
            }
        }
        else
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", IDKicauan); // kicauan bukan milik pengguna
        }
    }

    printf("\n");
}