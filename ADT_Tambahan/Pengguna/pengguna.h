#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/charmachine/charmachine.h"
#include <stdio.h>

typedef struct
{
    Word nama ; 
    Word sandi ;
    Word bio ;
    Word nomor ;
    Word weton ;
    int tipe_akun ; // 0 itu public, 1 itu private
} Pengguna ;
   

void Daftar();

void Masuk();

void Keluar();

int getIdPengguna(Word nama) ;

#endif