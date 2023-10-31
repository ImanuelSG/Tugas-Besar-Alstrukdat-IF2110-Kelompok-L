/* File: wordoperations.c*/
/* Tambahan operasi dan primitif word */

#include <stdio.h>
#include "wordoperations.h"
#include "../ADT_Bawaan/boolean.h"

boolean isSameWord (Word w1, Word w2) {
    if (w1.Length == w2.Length) {
        int i;
        boolean same = true;

        while ((same) && i < w1.Length) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                same = false;
            }
            else {
                i++;
            }
        }

        return same;
    }

    else {
        return false;
    }
    
}
/* Mengembalikan true jika kata w1 = w2 */
/* dan tentunya false jika tidak */

Word stringToWord(char letters[], int length) {
    Word w;
    int i;
    for (i = 0; i < length; i++) {
        w.TabWord[i] = letters[i];
    }
    w.Length = length;

    return w;
}
/* Mengubah string literal dengan panjang length menjadi word */
/* Contoh: stringToWord("KICAU") akan mengembalikan Word dengan length 5
dan elemen TabWord berisi 'K', 'I', 'C', 'A', dan 'U'. */


void displayWord(Word w) {
    int i;
    for (i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
}
/* Menampilkan kata w tanpa newline */

void reverseWord (Word * w) {
    int i;
    char tmp;
    for (i = 0; i < (*w).Length; i++) {
        tmp = (*w).TabWord[i];
        (*w).TabWord[i] = (*w).TabWord[(*w).Length - 1 - i];
        (*w).TabWord[(*w).Length - 1 - i] = tmp;
    }
}
/* Membalikkan kata w */


int charToDigit(char c) {
    return c - '0';
}
/* Mengubah tipe data karakter ke int
NOTE: Masukan hanya berupa karakter '0' - '9' */

char digitToChar(int num) {
    return num + '0';
}
/* Mengubah tipe data int ke karakter
NOTE: Masukan hanya berupa integer[0..9] */

int wordToInteger(Word w) {
    int res = 0;
    int i;
    for (i = 0; i < w.Length; i++) {
        res *= 10;
        res += charToDigit(w.TabWord[i]);
    }

    return res;
}
/* Mengubah kata menjadi integer 
NOTE: Masukan hanya berupa kata yang karakternya adalah digit semua */


Word integerToWord(int num) {
    Word w; 
    int i = 0;
    char c;

    while (num != 0) {
        c = digitToChar(num % 10);
        w.TabWord[i] = c;

        num /= 10;
        i++;
    }
    w.Length = i;

    return w;
}
/* Mengubah integer ke dalam tipe bentukan kata */