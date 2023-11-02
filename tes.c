#include <stdio.h>
#include "Kicau.h"

int main() {
    Kicauan K;
    Word Penulis, Tweet;
    DATETIME Waktu;
    int like, balasan;

    BacaDATETIME(&Waktu);
    
    printf("Masukkan nama pengguna: ");
    STARTWORD();
    Penulis = currentWord;
    printf("\n");
    printf("Masukkan isi kicauan: ");
    STARTWORD();
    Tweet = currentWord;
    printf("\n");

    CreateKicauan(&K, Penulis, Waktu, Tweet);
    LIKE(K) = 0;
    JUMLAH_BALASAN(K) = 0;
    PrintKicauan(K, 1);

    return 0;
}