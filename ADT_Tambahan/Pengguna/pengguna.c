#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/charmachine/charmachine.h"
#include "pengguna.h"
#include "../Globals/globalvar.h"
#include "../wordoperations.h"
#include "../utils/utils.h"
#include "../DrafKicauan/StackDraf.h"
#include "../teman/graf_teman.h"
#include <stdio.h>
#include <stdlib.h>

Pengguna dataPengguna[20]; /*List Pengguna*/
int banyakPengguna = 0;
Pengguna currentPengguna;

void CreatePengguna(Pengguna *akun, Word NAMA, Word SANDI, Word BIO, Word NOMOR, Word WETON, int TIPE_AKUN, MatrixProfil PROFIL, StackDraf DRAF)
{
    (*akun).nama = NAMA;
    (*akun).sandi = SANDI;
    (*akun).bio = BIO;
    (*akun).nomor = NOMOR;
    (*akun).weton = WETON;
    (*akun).tipe_akun = TIPE_AKUN;
    (*akun).profil = PROFIL;
    (*akun).draf = DRAF;
}

void InsertPengguna(Pengguna akun)
{

    dataPengguna[banyakPengguna] = akun;
    banyakPengguna += 1;
        // graf
    TambahPenggunaGraf(&dataTeman, akun);
}

void Daftar()
{
    if (isLoggedIn)
    {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
    else if (banyakPengguna == 20)
    {
        printf("Maaf, Burbir hanya bisa mendaftarkan 20 pengguna!\n");
    }
    else
    {
        Pengguna daftarPengguna;
        printf("Masukkan nama: ");
        STARTKalimat();
        printf("\n");
        daftarPengguna.nama = currentWord;

        int idxPengguna = getIdPengguna(daftarPengguna.nama);

        if (idxPengguna != -1)
        {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
        }
        else
        {
            printf("Masukkan kata sandi: ");
            STARTKalimat();
            printf("\n");
            daftarPengguna.sandi = currentWord;
            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");

            daftarPengguna.tipe_akun = 0;
            daftarPengguna.bio.Length = 0;
            daftarPengguna.nomor.Length = 0;
            daftarPengguna.weton.Length = 0;
            MatrixProfil profil;
            createProfilDefault(&profil);
            daftarPengguna.profil = profil;
            StackDraf draf;
            CreateStackDraf(&draf);
            daftarPengguna.draf = draf;
            InsertPengguna(daftarPengguna);

        }
    }
}

void Masuk()
{
    if (isLoggedIn)
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    }
    else
    {
        printf("Masukkan nama: ");
        STARTKalimat();
        printf("\n");
        boolean found = false;
        int idxPengguna = getIdPengguna(currentWord);

        while (idxPengguna == -1)
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            printf("Masukkan nama: ");
            STARTKalimat();
            printf("\n");
            idxPengguna = getIdPengguna(currentWord);
        }

        printf("Masukkan kata sandi: ");
        STARTKalimat();
        printf("\n");
        while (!isSameWord(dataPengguna[idxPengguna].sandi, currentWord))
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("Masukkan kata sandi: ");
            STARTKalimat();
            printf("\n");
        }
        printf("Anda telah berhasil masuk. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");

        isLoggedIn = true;
        currentPengguna = dataPengguna[idxPengguna];
    }
}

void Keluar()
{
    if (!isLoggedIn)
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
    else
    {
        printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
        isLoggedIn = false;
    }
}
/*
int main()
{
    isLoggedIn = false;
    banyakPengguna = 0;
    char vanson[1];
    vanson[0] = 'a';
    Word nama;
    nama = stringToWord(vanson, 1);
    dataPengguna[0].nama = nama;
    Daftar();
    displayWord(dataPengguna[0].nama);
    printf("\n");
    displayProfil(dataPengguna[0].profil);

    return 0;
}*/