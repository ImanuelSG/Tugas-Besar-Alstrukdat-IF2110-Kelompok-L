/* File: wordoperations.h */
/* Tambahan operasi dan primitif word */

#ifndef WORDOPERATIONS_H
#define WORDOPERATIONS_H

#include "../ADT_Bawaan/boolean.h"
#include "../ADT_Bawaan/wordmachine.h"
#include <stdio.h>

boolean isSameWord(Word w1, Word w2);
/* Mengembalikan true jika kata w1 = w2 */
/* dan tentunya false jika tidak */

Word stringToWord(char letters[], int length);
/* Mengubah string literal dengan panjang length menjadi word */
/* Contoh: stringToWord("KICAU") akan mengembalikan Word dengan length 5
dan elemen TabWord berisi 'K', 'I', 'C', 'A', dan 'U'. */

void displayWord(Word w);
/* Menampilkan kata w tanpa newline */

void reverseWord (Word * w);
/* Membalikkan kata w */

int charToDigit(char c);
/* Mengubah tipe data karakter ke int
NOTE: Masukan hanya berupa karakter '0' - '9' */

char digitToChar(int num);
/* Mengubah tipe data int ke karakter
NOTE: Masukan hanya berupa integer[0..9] */

int wordToInteger(Word w);
/* Mengubah kata menjadi integer 
NOTE: Masukan hanya berupa kata yang karakternya adalah digit semua */

Word integerToWord(int num);
/* Mengubah integer ke dalam tipe bentukan kata */

#endif