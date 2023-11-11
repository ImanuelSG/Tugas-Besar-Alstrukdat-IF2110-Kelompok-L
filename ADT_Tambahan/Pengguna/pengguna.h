#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../ADT_Bawaan/charmachine/charmachine.h"
#include <stdio.h>

typedef struct
{
    Word nama;
    Word sandi;
    Word bio;
    Word nomor;
    Word weton;
    int tipe_akun;
} Pengguna;

void Daftar();

void Masuk();

void Keluar();

#endif