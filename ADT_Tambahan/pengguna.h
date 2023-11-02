#include "../ADT_Bawaan/wordmachine.h"
#include "../ADT_Bawaan/charmachine.h"
#include <stdio.h>

typedef struct
{
    Word nama ; 
    Word sandi ;
    Word bio ;
    Word nomor ;
    Word weton ;
    int tipe_akun ;
} Pengguna ;

void Daftar() ;

void Masuk() ;

void Keluar() ;