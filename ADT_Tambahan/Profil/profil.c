#include "profil.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../pcolor.c"
#include "../utils/utils.h"
#include "../wordoperations.h"
#include "../Pengguna/liststatikpengguna.h"
#include "../Pengguna/pengguna.h"

ListStatikPengguna dataPengguna;

boolean cekWeton(Word weton, Word *kata)
{
    Word kembali;
    Word pahing, kliwon, wage, pon, legi ;
    pahing = stringToWord("pahing", 6) ;
    kliwon = stringToWord("kliwon", 6) ;
    wage = stringToWord("wage" , 4) ;
    pon = stringToWord("pon" , 3) ;
    legi = stringToWord("legi", 4) ;

    boolean valid;
    valid = true;
    int i;

    if (weton.Length == 6 && (weton.TabWord[0] == 'p' || weton.TabWord[0] == 'P'))
    {
        for (i = 0; i < weton.Length; i++)
        {
            if ((weton.TabWord[i] != pahing.TabWord[i]) && (weton.TabWord[i] != pahing.TabWord[i] - 32))
            {
                valid = false;
            }
        }
        kembali = pahing ;
    }
    else if (weton.Length == 6 && (weton.TabWord[0] == 'k' || weton.TabWord[0] == 'K'))
    {
        for (i = 0; i < weton.Length; i++)
        {
            if ((weton.TabWord[i] != kliwon.TabWord[i]) && (weton.TabWord[i] != kliwon.TabWord[i] - 32))
            {
                valid = false;
            }
        }
        kembali = kliwon ;
    }
    else if (weton.Length == 4 && (weton.TabWord[0] == 'w' || weton.TabWord[0] == 'W'))
    {
        for (i = 0; i < weton.Length; i++)
        {
            if ((weton.TabWord[i] != wage.TabWord[i]) && (weton.TabWord[i] != wage.TabWord[i] - 32))
            {
                valid = false;
            }
        }
        kembali = wage ;
    }
    else if (weton.Length == 4 && (weton.TabWord[0] == 'l' || weton.TabWord[0] == 'L'))
    {
        for (i = 0; i < weton.Length; i++)
        {
            if ((weton.TabWord[i] != legi.TabWord[i]) && (weton.TabWord[i] != legi.TabWord[i] - 32))
            {
                valid = false;
            }
        }
        kembali = legi ;
    }
    else if (weton.Length == 3)
    {
        for (i = 0; i < weton.Length; i++)
        {
            if ((weton.TabWord[i] != pon.TabWord[i]) && (weton.TabWord[i] != pon.TabWord[i] - 32))
            {
                valid = false;
            }
        }
        kembali = pon ;
    }
    else if (weton.Length == 0)
    {
        printf("Woohoo!\n");
        kembali = weton;
        valid = true;
    }
    else
        valid = false;

    if (valid)
    {
        *kata = kembali;
    }

    return valid;
}

void displayProfil(MatrixProfil profil)
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (profil.mem[i][j].TabWord[0] == 'R')
            {
                j += 1;
                print_red(profil.mem[i][j].TabWord[0]);
            }
            else if (profil.mem[i][j].TabWord[0] == 'G')
            {
                j += 1;
                print_green(profil.mem[i][j].TabWord[0]);
            }
            else
            {
                j += 1;
                print_blue(profil.mem[i][j].TabWord[0]);
            }
        }
        printf("\n");
    }
}

void Ganti_Profil()
{
    if (isLoggedIn) {

        currentWord.Length = 0;
        // display nama, bio, nomor, weton
        printf("| Nama: ");
        displayWord(currentPengguna.nama);
        printf("\n| Bio Akun: ");
        displayWord(currentPengguna.bio);
        printf("\n| No HP: ");
        displayWord(currentPengguna.nomor);
        printf("\n| Weton: ");
        displayWord(currentPengguna.weton);
        printf("\n");

        // input bio
        printf("Masukkan bio akun:\n");
        STARTKalimat();
        while (currentWord.Length > 135)
        {
            printf("Bio anda tidak valid! \n");
            printf("Masukkan bio akun:\n");
            STARTKalimat();
        }
        currentPengguna.bio = DuplicateWord(currentWord);

        // input no.hp
        printf("Masukkan No HP :\n"); // maksimum merupakan panjang dari adt word itu sendiri
        STARTKalimat();
        // validasi nomor telpon
        boolean valid;
        valid = true;
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            if (currentWord.TabWord[i] < 48 || currentWord.TabWord[i] > 57)
            {
                valid = false;
            }
        }

        if (currentWord.Length == 0) {
            valid = true;
        }
        while (!valid)
        {
            valid = true;
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
            printf("Masukkan No HP :\n");
            STARTKalimat();
            for (i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] < 48 || currentWord.TabWord[i] > 57)
                {
                    valid = false;
                }
            }
        }
        PointerDuplicateWord(currentWord, &currentPengguna.nomor);
        // input weton
        Word weton;
        printf("Masukkan weton : \n");
        STARTKalimat();
        while (!cekWeton(currentWord, &weton))
        {
            printf("Weton anda tidak valid!\n");
            printf("Masukkan weton : \n");
            STARTKalimat();
        }
        currentPengguna.weton = DuplicateWord(weton);
        printf("Profil anda sudah berhasil diperbaharui!\n");

        
    }
    else {
        printf("Maaf, anda belum login!\n") ;
    }
        printf("%d\n", currentWord.Length);
}

void Atur_Jenis_Akun()
{
    if (isLoggedIn) {
        char y[2];
        y[0] = 'Y';
        y[1] = 'A';
        char n[5];
        n[0] = 'T';
        n[1] = 'I';
        n[2] = 'D';
        n[3] = 'A';
        n[4] = 'K';

        Word ya, no;
        ya = stringToWord(y, 2);
        no = stringToWord(n, 5);

        boolean valid;
        if (currentPengguna.tipe_akun == 0)
        {
            printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
            STARTKalimat();
            if (isSameWord(currentWord, ya))
            {
                currentPengguna.tipe_akun = 1;
            }
            else if (isSameWord(currentWord, no))
            {
                // do nothing
            }
            else
            {
                valid = false;
                while (!valid)
                {
                    valid = true;
                    printf("(YA/TIDAK) huruf besar!\n");
                    STARTKalimat();
                    if (isSameWord(currentWord, ya))
                    {
                        currentPengguna.tipe_akun = 1;
                    }
                    else if (isSameWord(currentWord, no))
                    {
                        // do nothing
                    }
                    else
                        valid = false;
                }
            }
        }
        else
        {
            printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");
            STARTKalimat();
            if (isSameWord(currentWord, ya))
            {
                currentPengguna.tipe_akun = 0;
            }
            else if (isSameWord(currentWord, no))
            {
                // do nothing
            }
            else
            {
                valid = false;
                while (!valid)
                {
                    valid = true;
                    printf("(YA/TIDAK) huruf besar!\n");
                    STARTKalimat();
                    if (isSameWord(currentWord, ya))
                    {
                        currentPengguna.tipe_akun = 0;
                    }
                    else if (isSameWord(currentWord, no))
                    {
                        // do nothing
                    }
                    else
                        valid = false;
                }
            }
        }
    }
    else {
        printf("Maaf, anda belum login!\n") ;
    }
}

void Lihat_Profil(Word nama)
{
    if (isLoggedIn) {
        int id;
        id = getIdPengguna(nama);
        printf("%d", id);
        printf("%d", dataPengguna.contents[id].nama.Length);
        printf("%d", dataPengguna.contents[id].bio.Length);
        printf("%d", dataPengguna.contents[id].nomor.Length);
        printf("%d", dataPengguna.contents[id].weton.Length);

        if (id == -1)
        {
            printf("Pengguna tidak ditemukan!\n");
        }

        else if (dataPengguna.contents[id].tipe_akun == 0 || id == getIdPengguna(currentPengguna.nama))
        {
            // display nama, bio, nomor, weton
            printf("| Nama: ");
            displayWord(dataPengguna.contents[id].nama);
            printf("\n| Bio Akun: ");
            displayWord(dataPengguna.contents[id].bio);
            printf("\n| No HP: ");
            displayWord(dataPengguna.contents[id].nomor);
            printf("\n| Weton: ");
            displayWord(dataPengguna.contents[id].weton);
            printf("\n");

            // display foto
            printf("Foto profil akun ");
            displayWord(dataPengguna.contents[id].nama);
            printf("\n");
            displayProfil(dataPengguna.contents[id].profil);
        }
        else
        {
            printf("Wah, akunnya diprivat nih. Ikuti dulu untuk melihat profil!\n");
        }
    }
}

void Ubah_Foto_Profil()
{
    if (isLoggedIn) {
        // display profil
        int id;
        id = getIdPengguna(currentPengguna.nama);
        printf("Foto profil anda saat ini adalah \n");
        displayProfil(dataPengguna.contents[id].profil);
        printf("\n");

        // input profil baru
        printf("Masukkan foto profil yang baru\n");
        int i, j;
        STARTKalimat();
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0)
                {
                    dataPengguna.contents[id].profil.mem[i][j] = currentWord;
                }
                else
                {
                    ADVWORD();
                    dataPengguna.contents[id].profil.mem[i][j] = currentWord;
                }
            }
        }
        printf("Foto profil anda sudah berhasil diganti!\n");
    }
}

void createProfilDefault(MatrixProfil *profil)
{
    char warna[1], bintang[1];
    warna[0] = 'R';
    bintang[0] = '*';
    Word color, asterisk;
    color = stringToWord(warna, 1);
    asterisk = stringToWord(bintang, 1);

    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j % 2 == 0)
            {
                (*profil).mem[i][j] = color;
            }
            else
            {
                (*profil).mem[i][j] = asterisk;
            }
        }
    }
}
