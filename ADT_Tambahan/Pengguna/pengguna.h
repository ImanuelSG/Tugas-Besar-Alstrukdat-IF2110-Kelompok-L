#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/charmachine/charmachine.h"
#include "liststatikpengguna.h"
#include "../Profil/profil.h"
#include "../DrafKicauan/StackDraf.h"
#include <stdio.h>

typedef struct
{
    Word nama;
    Word sandi;
    Word bio;
    Word nomor;
    Word weton;
    int tipe_akun;
    MatrixProfil profil;
    StackDraf draf;
} Pengguna;

extern int banyakPengguna;
extern ListStatikPengguna dataPengguna; /*List Pengguna*/
extern Pengguna currentPengguna;  /*Berisi Data Current Pengguna*/

void CreatePengguna(Pengguna *akun, Word nama, Word sandi, Word bio, Word nomor, Word weton, int tipe_akun, MatrixProfil profil, StackDraf draf);

void InsertPengguna(Pengguna akun); // masukin pengguna ke data pengguan

void Daftar();

void Masuk();

void Keluar();

#endif