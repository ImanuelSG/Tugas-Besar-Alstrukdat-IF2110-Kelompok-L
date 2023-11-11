#include <stdio.h>
#include "ADT_Kicauan.h"

int main() {
    Word namapengguna;
    Word kicauan;
    DATETIME waktu;
    Kicauan K;
    ID id = 1;

    BacaKalimat();
    namapengguna = currentWord;
    BacaKalimat();
    kicauan = currentWord;
    BacaDATETIME(&waktu);
    CreateKicauan(&K, namapengguna, waktu, kicauan);
    PrintKicauan(K, id);
}