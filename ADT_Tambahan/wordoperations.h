/* File: wordoperations.h */
/* Tambahan operasi dan primitif word */

#ifndef WORDOPERATIONS_H
#define WORDOPERATIONS_H

#include "../ADT_Bawaan/boolean.h"
#include "../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../ADT_Bawaan/datetime/datetime.h"
#include <stdio.h>

boolean isSameWord(Word w1, Word w2);
/* Mengembalikan true jika kata w1 = w2 */
/* dan tentunya false jika tidak */

Word stringToWord(char letters[], int length);
/* Mengubah string literal dengan panjang length menjadi word */
/* Contoh: stringToWord("KICAU", 5) akan mengembalikan Word dengan length 5
dan elemen TabWord berisi 'K', 'I', 'C', 'A', dan 'U'. */

void displayWord(Word w);
/* Menampilkan kata w tanpa newline */

void reverseWord(Word *w);
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

/**
 * @brief Menambahkan W2 ke W1
 *
 * @param w1 Kata di depan
 * @param w2 Kata di belakang
 */
void appendWord(Word *w1, Word w2);

/**
 * @brief Membuat Puluhan dari suatu Kata
 *
 * @param w1 Kata input
 * @param index1 index puluhan
 * @param index2 index satuan
 * @return int
 */
int makePuluhanfromWord(Word w, int index1, int index2);
/**
 * @brief Mengubah kata menjadi datetime, FORMAT INPUT HARUS SESUAI
 *
 * @param w kata yang ingin diubah
 * @return DATETIME
 */

DATETIME wordToDatetime(Word w);


char* wordToString(Word w);
/* Mengembalikan string literal (array of char) dari word */
/* IMPORTANT: ADA PENAMBAHAN 'NULL' CHARACTER (\0) DI AKHIR*/

Word DuplicateWord(Word W);
/* Returns a copy of W */

#endif
