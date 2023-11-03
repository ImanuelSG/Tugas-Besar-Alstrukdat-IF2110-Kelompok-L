#include "../ADT_Bawaan/wordmachine.h"
#include "../ADT_Bawaan/charmachine.h"
#include "pengguna.h"
#include "./Globals/globalvar.h"
#include "wordoperations.h"
#include <stdio.h>
#include <stdlib.h>


void Daftar() {
    if (login == true) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n") ;
    }
    else if (banyakPengguna == 20) {
         printf("Maaf, Burbir hanya bisa mendaftarkan 20 pengguna!\n") ;
    }
    else {
        Pengguna daftarPengguna ;
        printf("Masukkan nama: ") ;
        BacaKalimat() ;
        printf("\n") ;
        daftarPengguna.nama = currentWord ;
        
        int idxPengguna = getIdPengguna(daftarPengguna.nama) ;

        if (idxPengguna != -1) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n") ;
        }
        else {
            printf("Masukkan kata sandi: ") ;
            BacaKalimat() ;
            printf("\n") ;
            daftarPengguna.sandi = currentWord ;
            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n") ;

            banyakPengguna += 1 ;
            daftarPengguna.tipe_akun = 0 ;
            dataPengguna[banyakPengguna-1] = daftarPengguna ;
        }
    }
}

void Masuk() {
    if (login == true) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n") ;
    }
    else {
        printf("Masukkan nama: ") ;
        BacaKalimat() ;
        printf("\n") ;
        boolean found = false ;
        int idxPengguna = getIdPengguna(currentWord) ;

        while (idxPengguna == -1) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n") ;
            printf("Masukkan nama: ") ;
            BacaKalimat() ;
            printf("\n") ;        
            idxPengguna = getIdPengguna(currentWord) ;    
        }

        printf("Masukkan kata sandi: ") ;
        BacaKalimat() ;
        printf("\n") ;
        while (!isSameWord(dataPengguna[idxPengguna].sandi, currentWord)) {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n") ;
            printf("Masukkan kata sandi: ") ;
            BacaKalimat() ;
            printf("\n") ;
        }
        printf("Anda telah berhasil masuk. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n") ;

        login = true ;
        currentPengguna = dataPengguna[idxPengguna] ;
    }
}

void Keluar() {
    if (login == false) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n") ;
    }
    else {
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n") ;
        login = false ;
    }
}

int getIdPengguna(Word nama) {
    int i = 0 ;
    boolean found = false ;
    while (!found && i < banyakPengguna) {
        if (isSameWord(nama, dataPengguna[i].nama)) {
            found = true ;
        }
        else i++ ;
    }
    if (found) return i ;
    else return -1 ;
}