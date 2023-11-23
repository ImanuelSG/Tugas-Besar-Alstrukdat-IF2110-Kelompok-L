#include "MBarisFile.h"
#include "stdio.h"

boolean EndBaris;
Word currentBaris;

void STARTBaris(char namafile[])
{
    startMKarFile(namafile);
    if (EOPFile)
    {
        EndBaris = true;
    }
    else
    {
        EndBaris = false;
        CopyBaris();
        if (currentCharFile == '\n')
        {
            advMKarFile();
        }
        else if (currentCharFile == '\r')
        {
            advMKarFile();
            advMKarFile();
        }
    }
}

void ADVBaris()
{
    if (EOPFile)
    {
        EndBaris = true;
    }
    else
    {
        CopyBaris();
        if (currentCharFile == '\n')
        {
            advMKarFile();
        }
        else if (currentCharFile == '\r')
        {
            advMKarFile();
            advMKarFile();
        }
    }
}

void CopyBaris()
{
    int i = 0;
    while ((currentCharFile != '\n') && !EOPFile && (currentCharFile != '\r'))
    {
        currentBaris.TabWord[i] = currentCharFile;
        advMKarFile();
        i++;
    }
    currentBaris.Length = i;
}

void PrintBaris(Word B)
{
    for (int i = 0; i < B.Length; i++)
    {
        if (B.TabWord[i] != '\n')
            printf("%c", B.TabWord[i]);
        else
        {
            printf("ini slashn\n");
        }
    }
}
