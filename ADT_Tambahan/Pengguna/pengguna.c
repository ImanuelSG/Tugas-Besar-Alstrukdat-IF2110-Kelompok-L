#include "../../ADT_Bawaan/wordmachine/wordmachine.c"
#include "../../ADT_Bawaan/charmachine/charmachine.c"
// #include "pengguna.c"
#include "../Globals/globalvar.c"
#include "../wordoperations.c"
#include <stdio.h>
#include <stdlib.h>
#include "../Profil/profil.c"


void Daftar() {
    if (isLoggedIn == true) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n") ;
    }
    else if (jumlahpengguna == 20) {
        printf("Maaf, Burbir hanya bisa mendaftarkan 20 pengguna!\n") ;
    }
    else {
        Pengguna daftarPengguna ;
        printf("Masukkan nama: ") ;
        STARTKalimat() ;
        printf("\n") ;
        daftarPengguna.nama = currentWord ;
        
        int idxPengguna = getIdPengguna(daftarPengguna.nama) ;

        if (idxPengguna != -1) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n") ;
        }
        else {
            printf("Masukkan kata sandi: ") ;
            STARTKalimat() ;
            printf("\n") ;
            daftarPengguna.sandi = currentWord ;
            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n") ;

            daftarPengguna.tipe_akun = 0 ;
            daftarPengguna.bio.Length = 0 ;
            daftarPengguna.nomor.Length = 0 ;
            daftarPengguna.weton.Length = 0 ;

            jumlahpengguna += 1 ;
            dataPengguna[jumlahpengguna-1] = daftarPengguna ;
            idxPengguna = jumlahpengguna - 1 ;

            // ISI PROFIL DEFAULT
            char warna[1], bintang[1] ;
            warna[0] = 'R' ;
            bintang[0] = '*' ;
            Word color, asterisk ;
            color = stringToWord(warna, 1) ;
            asterisk = stringToWord(bintang, 1) ;

            int i, j ;
            for (i = 0 ; i < 5 ; i++) {
                for (j = 0 ; j < 10 ; j++) {
                    if (j % 2 == 0) {
                        profil[idxPengguna][i][j] = color ;
                    }
                    else {
                        profil[idxPengguna][i][j] = asterisk ;
                    }
                }
            }
        }
    }
} 

void Masuk() {
    if (isLoggedIn == true) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n") ;
    }
    else {
        printf("Masukkan nama: ") ;
        STARTKalimat() ;
        printf("\n") ;
        boolean found = false ;
        int idxPengguna = getIdPengguna(currentWord) ;

        while (idxPengguna == -1) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n") ;
            printf("Masukkan nama: ") ;
            STARTKalimat() ;
            printf("\n") ;        
            idxPengguna = getIdPengguna(currentWord) ;    
        }

        printf("Masukkan kata sandi: ") ;
        STARTKalimat() ;
        printf("\n") ;
        while (!isSameWord(dataPengguna[idxPengguna].sandi, currentWord)) {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n") ;
            printf("Masukkan kata sandi: ") ;
            STARTKalimat() ;
            printf("\n") ;
        }
        printf("Anda telah berhasil masuk. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n") ;

        isLoggedIn = true ;
        currentPengguna = dataPengguna[idxPengguna] ;
    }
}

void Keluar() {
    if (isLoggedIn == false) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n") ;
    }
    else {
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n") ;
        isLoggedIn = false ;
    }
}

int getIdPengguna(Word nama) {
    int i = 0 ;
    boolean found = false ;
    while (!found && i < jumlahpengguna) {
        if (isSameWord(nama, dataPengguna[i].nama)) {
            found = true ;
        }
        else i++ ;
    }
    if (found) return i ;
    else return -1 ;
}

int main () {
    isLoggedIn = false;
    jumlahpengguna = 0 ;
    char vanson[1] ;
    vanson[0] = 'a' ;
    Word nama ;
    nama = stringToWord(vanson, 1) ;
    dataPengguna[0].nama = nama ;
    Daftar() ;
    displayWord(dataPengguna[0].nama) ;
    printf("\n") ;
    displayProfil(0) ;

    return 0 ;
}