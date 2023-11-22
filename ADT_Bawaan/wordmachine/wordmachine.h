/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean.h"
#include "../charmachine/charmachine.h"

#define NMax 280
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreBackslashN();

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTKalimat();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentword adalah kalimat yang sudah diakuisisi,
          currentChar = MARK */

void BacaKalimat();
/* Mengakuisisi kalimat, menyimpan dalam currentword
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentword berisi kalimat yang sudah diakuisisi
          currentChar = MARK */

void PrintWord(Word W);
/* I.S. : W sembarang
   F.S. : W tercetak di layar */

boolean IsAllBlank(Word W);
/* Mengembalikan true jika semua karakter W adalah BLANK */

#endif