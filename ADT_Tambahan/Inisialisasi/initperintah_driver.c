#include "inisialisasiperintah.h"
#include <stdio.h>

int main() {

    // print keywords
    initializeKeyWords();
    int i;
    for (i = 0; i < 100; i++) {
        displayWord(KeyWords[i]);
        nl;
    }

    // keyword check
    STARTWORD();
    Word w1 = currentWord;
    if (isAKeyWord((currentWord))) {
        printf("Yay\n");
    }
    else {
        printf("UwU\n");
    }

    // lvd
    checkSpellingError(w1);

}