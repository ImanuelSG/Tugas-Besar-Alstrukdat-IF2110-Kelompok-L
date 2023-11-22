#include "MkarFile.h"
#include <stdio.h>

int main()
{
    char namaFile[100];
    scanf("%s", &namaFile);
    startMKarFile(namaFile);
    int i = 0;
    while (!EOPFile)
    {
        if (currentCharFile == '\n')
        {
            printf("Ini NextLine");
        }
        printf("%c%d", currentCharFile, i);
        advMKarFile();
        i++;
    }
}