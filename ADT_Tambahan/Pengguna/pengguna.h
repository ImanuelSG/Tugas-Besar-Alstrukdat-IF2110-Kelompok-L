#ifndef PENGGUNA_H
#define PENGGUNA_H

#include <stdio.h>
#include "../Globals/globalvar.c"

// #include "../Profil/profil.c"


   
void CreatePengguna (Pengguna *akun, Word nama, Word sandi, Word bio, Word nomor, Word weton, int tipe_akun, MatrixProfil profil) ;

void InsertPengguna (Pengguna akun) ; // masukin pengguna ke data pengguan 

void Daftar();

void Masuk();

void Keluar();


#endif