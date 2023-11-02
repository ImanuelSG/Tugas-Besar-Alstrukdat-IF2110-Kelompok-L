#include "../ADT_Bawaan/wordmachine.h"
#include "../ADT_Bawaan/charmachine.h"
#include "pengguna.h"
#include "./Globals/globalvar.h"
#include <stdio.h>
#include <stdlib.h>


void Daftar() {
    if (currentPengguna.login == false) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.") ;
    }
    else {
    printf("Masukkan nama: ") ;
    BacaKalimat() ;

    }
}

void Masuk() {

}

void Keluar() {

}