#include <stdio.h>
#include "listdinkicauan.h"
#include "../Globals/globalvar.h"

/* ********** PERINTAH-PERINTAH PADA FITUR KICAUAN ********** */
/* ********** UNTUK MAIN PROGRAM ********** */
/* KICAU */
void KICAU() {
/* Membuat sebuah Kicauan */
    Word NewTweet;

    printf("\nMasukkan kicauan:\n");
    STARTKalimat();
    NewTweet = currentWord;

    if (IsAllBlank(NewTweet)) {
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    } else {                        // tweet valid
        Kicauan NewKicauan;
        DATETIME WaktuKicauan;

        BacaDATETIME(&WaktuKicauan);
        CURRENT_ID_KICAUAN += 1;
        CreateKicauan(&NewKicauan, CURRENT_PENGGUNA, WaktuKicauan, NewTweet);
        insertLast(&LIST_KICAUAN_DATA, NewKicauan);

        printf("\nSelamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:");
        PrintKicauan(NewKicauan, CURRENT_ID_KICAUAN);
        printf("\n");
    }
}

/* KICAUAN */
void KICAUAN() {
/* Menampilkan semua kicauan yang dibuat pengguna dan teman pengguna ke layar */
/* Terurut berdasarkan kicauan terbaru (ID Kicauan terbesar) */
    printListKicauan(LIST_KICAUAN_DATA, CURRENT_PENGGUNA);
}

/* SUKA_KICAUAN */
void SUKA_KICAUAN(ID IDKicauan) {
/* Menambahkan like pada kicauan yang dipilih pengguna */
    printf("\n");
    if (!isIdxEff(LIST_KICAUAN_DATA, IDKicauan)) { // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d;\n", IDKicauan);
    } else {
        if (/* jika akun yang di like privat, dan tidak berteman */) {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        } else { /* akun privat dan berteman, atau akun bersifat publik */
            AddLike(&ELMT(LIST_KICAUAN_DATA, IDKicauan));
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");
            PrintKicauan(ELMT(LIST_KICAUAN_DATA, IDKicauan), IDKicauan);
        }
    }
    printf("\n");
}

/* UBAH_KICAUAN */
void UBAH_KICAUAN(ID IDKicauan) {
/* Mengubah isi kicauan yang dipilih pengguna */
    printf("\n");
    if (/* bukan kicauan milik pengguna */) {
        printf("Kicauan dengan ID = %d bukan milikmu!\n", IDKicauan);
    } else if (isIdxEff(LIST_KICAUAN_DATA, IDKicauan)) {                        // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d!;\n", IDKicauan);
    } else {                                                                    // kicauan milik pengguna
        Word NewTweet;
        printf("Masukkan kicauan baru:\n");
        STARTKalimat();
        NewTweet = currentWord;
        
        if (IsAllBlank(NewTweet)) {
            printf("\nKicauan tidak boleh hanya berisi spasi!\n");
        } else {                    //tweet valid
            EditTweet(&ELMT(LIST_KICAUAN_DATA, IDKicauan), NewTweet);
            printf("\nSelamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:");
            PrintKicauan(ELMT(LIST_KICAUAN_DATA, IDKicauan), IDKicauan);
        }
    }
    printf("\n");
}