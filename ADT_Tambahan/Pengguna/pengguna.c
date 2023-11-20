#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/charmachine/charmachine.h"
#include "pengguna.h"
#include "../Globals/globalvar.h"
#include "../wordoperations.h"
#include "../utils/utils.h"
#include "../DrafKicauan/StackDraf.h"
#include <stdio.h>
#include <stdlib.h>

// isloggedin untuk semua fungsi

ListStatikPengguna dataPengguna; /*List Pengguna*/
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
    dataPengguna.contents[banyakPengguna] = akun;
    banyakPengguna += 1;
}

void Daftar()
{
    if (isLoggedIn == true)
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
    if (isLoggedIn == true)
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

            Word ya, no;
            boolean valid ;
            ya = stringToWord("YA", 2);
            no = stringToWord("TIDAK", 5); 

            printf("Ingin melanjutkan? (YA/TIDAK)\n");
            STARTKalimat();
                if (isSameWord(currentWord, ya))
                {}
                else if (isSameWord(currentWord, no))
                {
                    idxPengguna = -999 ;
                    break ;
                }
                else
                {
                    valid = false;
                    while (!valid)
                    {
                        valid = true;
                        printf("(YA/TIDAK) huruf besar!\n");
                        STARTKalimat();
                        if (isSameWord(currentWord, ya)){

                        }
                        else if (isSameWord(currentWord, no))
                        {
                            idxPengguna = -999 ;
                            break ;
                        }
                        else
                            valid = false;
                    }
                }
            printf("Masukkan nama: ");
            STARTKalimat();
            printf("\n");
            idxPengguna = getIdPengguna(currentWord);
        }
        if (idxPengguna != -999) {
            printf("Masukkan kata sandi: ");
            STARTKalimat();
            printf("\n");
            while (!isSameWord(dataPengguna.contents[idxPengguna].sandi, currentWord))
            {
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
                printf("Masukkan kata sandi: ");
                STARTKalimat();
                printf("\n");
            }
            printf("Anda telah berhasil masuk. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");

            isLoggedIn = true;
            currentPengguna = dataPengguna.contents[idxPengguna];
        }
    }
}

void Keluar()
{
    if (isLoggedIn == false)
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