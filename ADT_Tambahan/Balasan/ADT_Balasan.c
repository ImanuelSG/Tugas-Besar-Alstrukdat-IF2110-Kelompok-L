#include <stdio.h>
#include <stdlib.h>
#include "ADT_Balasan.h"
#include "../utils/utils.h"

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE BALASAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT BALASAN */
void CreateBalasan(Balasan *B, Word Penulis, DATETIME Waktu, Word Isi, Kicauan *K) {
/* I.S. B sembarang */
/* F.S. B terdefinisi dengan IDBalasan = IDBalasan terakhir + 1, PenulisBalasan = Penulis, WaktuBalasan = Waktu, IsiBalasan = Isi */
   PENULIS_BALASAN(*B) = Penulis;
   WAKTU_BALASAN(*B) = Waktu;
   ISI_BALASAN(*B) = Isi;
   CURRENT_ID_BALASAN(*K) += 1;
   ID_BALASAN(*B) = CURRENT_ID_BALASAN(*K);
}

void PrintIndentasi(int indentasi) {
   int i;
   for (i = 0; i < indentasi; i++) {
      printf(" ");
   }
}

/* MENCETAK STRUCT BALASAN */
void PrintBalasan(Balasan B, int indentasi) {
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idbalasan>
    | <Nama Pengguna>
    | <Waktu post balasan>
    | <Isi balasan>
*/ 
   printf("\n");
   
   if (!isBerteman(currentPengguna.nama, PENULIS_BALASAN(B)) && getPengguna(PENULIS_BALASAN(B)).tipe_akun == 1) {
      PrintIndentasi(indentasi);    printf("| ID = %d\n", ID_BALASAN(B));
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
   } else {
      PrintIndentasi(indentasi);    printf("| ID = %d\n", ID_BALASAN(B));
      PrintIndentasi(indentasi);    printf("| "); printWord(PENULIS_BALASAN(B)); printf("\n");
      PrintIndentasi(indentasi);    printf("| "); TulisDATETIME(WAKTU_BALASAN(B)); printf("\n");
      PrintIndentasi(indentasi);    printf("| "); printWord(ISI_BALASAN(B)); printf("\n");
   }
}
