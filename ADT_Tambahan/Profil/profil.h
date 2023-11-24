
#ifndef PROFIL_H
#define PROFIL_H

#include <stdio.h>
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../Globals/globalvar.h"
typedef struct
{
   Word mem[5][10];
} MatrixProfil;

void Ganti_Profil();

void Lihat_Profil(Word nama);

void Atur_Jenis_Akun();

void Ubah_Foto_Profil();

boolean cekWeton(Word weton, Word *kata);

void displayProfil(MatrixProfil profil);

void createProfilDefault(MatrixProfil *profil);

#endif