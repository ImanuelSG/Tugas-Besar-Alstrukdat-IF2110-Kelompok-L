#include "DrafKicau.h"
#include <stdio.h>
#include "../../ADT_Bawaan/datetime/datetime.h"
void CreateDraf(DrafKicau *D, Word Isidraf, DATETIME WaktuDraf)
{

    ISI_DRAF(*D) = Isidraf;
    WAKTU_DRAF(*D) = WaktuDraf;
}

/**
 * @brief Melakukan printdraf teratas
 *
 * @param D Draf terdefinisi
 */
void PrintDraf(DrafKicau D)
{
    printf("\n");
    printf("| ");
    TulisDATETIME(WAKTU_DRAF(D));
    printf("\n");
    printf("| ");
    PrintWord(ISI_DRAF(D));
    printf("\n");
}
