#include "../MesinBarisFile/MBarisFile.h"
#include "../Kicauan/listdinkicauan.h"
#include "../wordoperations.h"
#include <stdio.h>

void ReadDraftConfig(char namafile[])
{
    int iteration, banyak;
    Word username, isi;
    DATETIME Date;

    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    ADVBaris();// baris == "username"
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
        ADVBaris();// baris == "isi"
        for (int j = 0; j < banyak; j++)
        {
            isi = currentBaris;
            ADVBaris();//baris == "tanggal"
            Date = wordToDatetime(currentBaris);
            ADVBaris();//baris == "isi"
            /*Create Draft Kicau*/
        }
    }
}