#include "stdio.h"
#include "ADT_Tambahan/Kicauan/ADT_Kicauan.h"

int main() {
    DATETIME T1, T2;
    Kicauan K1, K2;
    Word Pengguna1, Pengguna2, Tweet1, Tweet2;
    
    printf("Masukkan nama pengguna 1: ");
    STARTKalimat();
    Pengguna1 = currentWord;
    printf("Masukkan tweet 1: ");
    BacaDATETIME(&T1);
    STARTKalimat();
    Tweet1 = currentWord;
    printf("Masukkan nama pengguna 2: ");
    STARTKalimat();
    Pengguna2 = currentWord;
    printf("Masukkan tweet 2: ");
    BacaDATETIME(&T2);
    STARTKalimat();
    Tweet2 = currentWord;

    CreateKicauan(&K1, Pengguna1, T1, Tweet1, 0);
    CreateKicauan(&K2, Pengguna2, T2, Tweet2, 0);

    PrintKicauan(K1, 1);
    PrintKicauan(K2, 2);

    AddLike(&K1);
    AddLike(&K2);
    AddLike(&K1);

    printf("Masukkan tweet baru: ");
    STARTKalimat();
    Tweet1 = currentWord;
    EditTweet(&K1, Tweet1);
    PrintKicauan(K1, 1);

    return 0;   
}
// gcc driver_kicauan.c ADT_Bawaan\\datetime\\jam.c ADT_Bawaan\\charmachine\\charmachine.c ADT_Bawaan\\wordmachine\\wordmachine.c ADT_Bawaan\\datetime\\datetime.c ADT_Tambahan\\Kicauan\\ADT_Kicauan.c -o b.exe