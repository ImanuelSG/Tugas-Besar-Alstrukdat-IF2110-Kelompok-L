#include "utils.h"
#include "../teman/graf_teman.h"

GrafTeman dataTeman;

int getIdPengguna(Word nama)
{
    int i = 0;
    boolean found = false;

    while (!found && i < banyakPengguna)
    {
        // printf("%d <--nama    datapenggunai--> %d", nama.Length, dataPengguna[i].nama.Length);

        if (isSameWord(nama, dataPengguna[i].nama))
        {
            found = true;
        }
        else
        {
            // displayProfil(dataPengguna[i].profil);
            i++;
        }
    }
    if (found)
        return i;
    else
        return -1;
}
boolean isBerteman(Word namaA, Word namaB)
{
    return isTeman(&dataTeman, *getPengguna(namaA), *getPengguna(namaB));
}
Pengguna *getPengguna(Word nama)
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
        return &dataPengguna[i];
    else
        return NULL;
}