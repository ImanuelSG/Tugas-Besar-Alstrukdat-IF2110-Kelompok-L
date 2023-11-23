#include <stdio.h>
#include <stdlib.h>
#include "ADT_Balasan.h"
#include "../utils/utils.h"
#include "../Globals/globalvar.h"

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE BALASAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT BALASAN */
void CreateBalasan(Balasan *B, Word Penulis, DATETIME Waktu, Word Isi, Kicauan *K, ID IDParent)
{
   /* I.S. B sembarang */
   /* F.S. B terdefinisi dengan IDBalasan = IDBalasan terakhir + 1, PenulisBalasan = Penulis, WaktuBalasan = Waktu, IsiBalasan = Isi */
   PENULIS_BALASAN(*B) = Penulis;
   WAKTU_BALASAN(*B) = Waktu;
   ISI_BALASAN(*B) = Isi;
   CURRENT_ID_BALASAN(*K) += 1;
   ID_BALASAN(*B) = CURRENT_ID_BALASAN(*K);
   ID_PARENT(*B) = IDParent;
}

void PrintIndentasi(int indentasi) {
/* I.S. indentasi terdefinisi */
/* F.S. mencetak spasi sebanyak indentasi */
   int i;
   for (i = 0; i < indentasi; i++)
   {
      printf(" ");
   }
}

/* MENCETAK STRUCT BALASAN */
void PrintBalasan(Balasan B, int indentasi)
{
   /* I.S. K terdefinisi */
   /* F.S. Struct Kicauan tercetak di layar dengan format:
       | ID = <idbalasan>
       | <Nama Pengguna>
       | <Waktu post balasan>
       | <Isi balasan>
   */
void PrintBalasan(Balasan B, int indentasi) {
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idbalasan>
    | <Nama Pengguna>
    | <Waktu post balasan>
    | <Isi balasan>
*/
   printf("\n");

   if (!isBerteman(currentPengguna.nama, PENULIS_BALASAN(B)) && getPengguna(PENULIS_BALASAN(B))->tipe_akun == 1) {
      PrintIndentasi(indentasi);    printf("| ID = %d\n", ID_BALASAN(B));
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
      PrintIndentasi(indentasi);    printf("| PRIVAT\n");
   }
   else {
      PrintIndentasi(indentasi);    printf("| ID = %d\n", ID_BALASAN(B));
      PrintIndentasi(indentasi);    printf("| ");  PrintWord(PENULIS_BALASAN(B));   printf("\n");
      PrintIndentasi(indentasi);    printf("| ");  TulisDATETIME(WAKTU_BALASAN(B)); printf("\n");
      PrintIndentasi(indentasi);    printf("| ");  PrintWord(ISI_BALASAN(B));       printf("\n");
   }
}

void PrintBalasanOnly(Balasan B, int indentasi) {
/* I.S. memprint semua balasan (hanya untuk tes) */
   printf("\n");
   PrintIndentasi(indentasi);    printf("| ID = %d\n", ID_BALASAN(B));
   PrintIndentasi(indentasi);    printf("| ");  PrintWord(PENULIS_BALASAN(B));   printf("\n");
   PrintIndentasi(indentasi);    printf("| ");  TulisDATETIME(WAKTU_BALASAN(B)); printf("\n");
   PrintIndentasi(indentasi);    printf("| ");  PrintWord(ISI_BALASAN(B));       printf("\n");
}