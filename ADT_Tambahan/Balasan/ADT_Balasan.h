/* Modul Balasan */
#ifndef __BALASAN_H__
#define __BALASAN_H__

#include "../../ADT_Bawaan/boolean.h"
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/datetime/datetime.h"
#include "../Globals/globalvar.h"
#include "../Kicauan/ADT_Kicauan.h"

/* ********** DEFINISI TYPE BALASAN ********** */
typedef struct {
    ID IDBalasan;            // ID balasan
    Word PenulisBalasan;     // Username pengguna pembuat balasan
    DATETIME WaktuBalasan;   // Waktu balasan dibuat (diambil dari waktu lokal)
    Word IsiBalasan;         // Isi balasan
} Balasan;

/* ********** SELEKTOR BALASAN ********** */
#define ID_BALASAN(B) (B).IDBalasan
#define PENULIS_BALASAN(B) (B).PenulisBalasan
#define WAKTU_BALASAN(B) (B).WaktuBalasan
#define ISI_BALASAN(B) (B).IsiBalasan

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE BALASAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT BALASAN */
void CreateBalasan(Balasan *B, Word Penulis, DATETIME Waktu, Word Isi, Kicauan K);
/* I.S. B sembarang */
/* F.S. B terdefinisi dengan IDBalasan = IDBalasan terakhir + 1, PenulisBalasan = Penulis, WaktuBalasan = Waktu, IsiBalasan = Isi */

/* MENCETAK STRUCT BALASAN */
void PrintBalasan(Balasan B, int indentasi);
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idbalasan>
    | <Nama Pengguna>
    | <Waktu post balasan>
    | <Isi balasan>
*/

#endif