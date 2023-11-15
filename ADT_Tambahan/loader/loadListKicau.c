#include "../MesinBarisFile/MBarisFile.h"
#include "../Kicauan/listdinkicauan.h"
#include "../wordoperations.h"
#include <stdio.h>
// Word BaristoWord(Baris B)
// {
//     Word w;
//     int i;
//     for (i = 0; i < B.Length; i++)
//     {
//         w.TabWord[i] = B.TabWord[i];
//     }
//     w.Length = B.Length;
//     return w;
// }

void ReadKicauanConfig(char namafile[])
{
    CreateListDinKicauan(&ListKicauanData, 100);
    int iteration, like;
    Kicauan kicau;
    Word Penulis, WaktuKicauan, Tweet;
    DATETIME Waktu;

    STARTBaris(namafile);

    iteration = wordToInteger(currentBaris);

    ADVBaris();

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris();
        Tweet = currentBaris;

        ADVBaris();

        like = wordToInteger(currentBaris);

        ADVBaris();
        Penulis = currentBaris;
        ADVBaris();
        Waktu = wordToDatetime(currentBaris);
        ADVBaris();

        CreateKicauan(&kicau, Penulis, Waktu, Tweet, like);
        insertLastKicau(&ListKicauanData, kicau);
    }
}

void WriteKicauanConfig(char namafile[])
{
    FILE *filesave;

    // Check if the file already exists
    filesave = fopen("pengguna.config", "w");
}

int main()
{
    ReadKicauanConfig("kicauan.config");
    printList(ListKicauanData);
    
}