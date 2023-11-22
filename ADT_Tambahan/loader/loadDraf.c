#include "../MesinBarisFile/MBarisFile.h"
#include "../Kicauan/listdinkicauan.h"
#include "../DrafKicauan/StackDraf.h"
#include "../utils/utils.h"
#include <stdio.h>

void ReadDrafConfig(char namafile[])
{
    int iteration, banyak;
    Word username, isi;
    DATETIME Date;

    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);

    ADVBaris(); // baris == "username"
    for (int i = 0; i < iteration; i++)
    {
        banyak = 0;
        i = currentBaris.Length - 1;
        int pengkali = 1;
        while (currentBaris.TabWord[i] != ' ')
        {
            banyak += charToDigit(currentBaris.TabWord[i] * pengkali);
            pengkali *= 10;
            i--;
            currentBaris.Length--;
        }
        currentBaris.Length--;
        username = currentBaris;
        Pengguna *curr = getPengguna(username);
        ADVBaris(); // baris == "isi"
        for (int j = 0; j < banyak; j++)
        {
            DrafKicau currdraf;
            isi = currentBaris;
            ADVBaris(); // baris == "tanggal"
            Date = wordToDatetime(currentBaris);
            ADVBaris(); // baris == "isi"
            CreateDraf(&currdraf, isi, Date);
            SimpanDraf(&curr->draf, currdraf);
        }
        ReverseStackDraf(&curr->draf);
    }
}