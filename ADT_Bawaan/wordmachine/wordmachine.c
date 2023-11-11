/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */
#include <stdio.h>
#include "../boolean.h"
#include "../charmachine/charmachine.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK && currentChar != MARK) {
        ADV();
    }
}

void STARTWORD() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

void STARTKalimat() {
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentword adalah kalimat yang sudah diakuisisi,
          currentChar = MARK */
   START();
   if (currentChar == MARK) {
      EndWord = true;
   } else {
      EndWord = false;
      BacaKalimat();
   }
}

void BacaKalimat() {
/* Mengakuisisi kalimat, menyimpan dalam currentword
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentword berisi kalimat yang sudah diakuisisi
          currentChar = MARK */
   int i = 0;
   while ((currentChar != MARK) && (i < NMax)) {
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }
   currentWord.Length = i ;
}

void PrintWord(Word W) {
/* I.S. : W sembarang
   F.S. : W tercetak di layar */
   for (int i = 0; i < W.Length; i++) {
      printf("%c", W.TabWord[i]);
   }
}

boolean IsAllBlank(Word W) {
/* Mengembalikan true jika semua karakter W adalah BLANK */
   boolean AllBlank = true;
   int i = 0;
   while ((i < W.Length) && (AllBlank)) {
      if (W.TabWord[i] != BLANK) {
         AllBlank = false;
      }
      i++;
   }
   return AllBlank;
}