#include "../../ADT_Bawaan/matrix/matrix.h"
#include "../Globals/globalvar.h"
#include "../wordoperations.h"
#include "utils.h"


int getIdPengguna(Word nama)
{
    int i = 0;
    boolean found = false;
    while (!found && i < banyakPengguna)
    {
        if (isSameWord(nama, dataPengguna[i].nama))
        {
            found = true;
        }
        else
            i++;
    }
    if (found)
        return i;
    else
        return -1;
}
boolean isBerteman(Word namaA, Word namaB)
{
    int idA = getIdPengguna(namaA);
    int idB = getIdPengguna(namaB);

    return (ELMT(matrixPertemanan, idA, idB) == 1);
}
Pengguna getPengguna(Word nama)
{
    int i = 0;
    boolean found = false;
    while (!found && i < banyakPengguna)
    {
        if (isSameWord(nama, dataPengguna[i].nama))
        {
            found = true;
        }
        else
            i++;
    }
    if (found)
        return dataPengguna[i];
    else
        return dataPengguna[0];
}