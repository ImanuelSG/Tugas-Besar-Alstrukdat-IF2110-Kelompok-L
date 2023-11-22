/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "MKarFile.h"
#include <stdio.h>

char currentCharFile;
boolean EOPFile;
static FILE *pita;
static int retval;

void startMKarFile(char namaFile[])
{
    pita = fopen(namaFile, "r");
    advMKarFile();
}

void advMKarFile()
{
    retval = fscanf(pita, "%c", &currentCharFile);
    EOPFile = (retval != 1);
    if (EOPFile)
    {
        fclose(pita);
    }
}