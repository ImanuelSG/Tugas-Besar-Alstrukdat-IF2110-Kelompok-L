/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef mBarisFile
#define mBarisFile

#include "../../ADT_Bawaan/boolean.h"
#include "../MesinKarakterFile/MKarFile.h"
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"


/* State Mesin Baris */
extern boolean EndBaris;
extern Word currentBaris;

/**
 * @brief Memulai mesin baris
 * 
 * @param namefile file untuk dibaca
 */
void STARTBaris(char namefile[]);

/**
 * @brief Melakukan Pembacaan ke Baris selanjutnya
 *
 */

void ADVBaris();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

/**
 * @brief Akan melakukan Akuisisi baris dan menyimpannya di currentbaris
 *
 */
void CopyBaris();
/* Mengakuisisi baris menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintBaris(Word B);
/* I.S. : Baris sembarang
   F.S. : Baris tercetak di layar */

#endif