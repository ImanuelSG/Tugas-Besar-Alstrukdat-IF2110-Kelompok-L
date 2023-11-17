/* Modul Kicauan */
/* Definisi ADT KICAUAN dengan memanfaatkan list dinamik untuk menyimpan list kicauan */

#ifndef _DRAFKICAU_H__
#define _DRAFKICAU_H__

#include "../../ADT_Bawaan/boolean.h"
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/datetime/datetime.h"

/* ********** DEFINISI TYPE Draf Kicauan********** */
typedef struct
{
    DATETIME WaktuDraf; // Waktu draf dibuat (diambil dari waktu lokal)
    Word IsiDraf;       // Isi draft kicauan
} DrafKicau;

/* ********** SELEKTOR KICAUAN ********** */
#define WAKTU_DRAF(K) (K).WaktuDraf
#define ISI_DRAF(K) (K).IsiDraf

/**
 * @brief Membuat Draft
 *
 * @param D Terdefinisi
 * @param Isidraft Adalah isi dari draft
 * @param WaktuDraf Adalah waktu draft dibuat (Dari lokal time)
 */

void CreateDraf(DrafKicau *D, Word Isidraf, DATETIME WaktuDraf);

/**
 * @brief Draft terprint ke layar
 *
 * @param D
 */
void PrintDraf(DrafKicau D);
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idkicauan>
    | <Nama Pengguna>
    | <Waktu post kicauan>
    | <Isi kicauan>
    | Disukai: <like>
*/

#endif