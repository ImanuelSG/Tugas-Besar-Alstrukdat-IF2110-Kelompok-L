#include "MkarFile.h"
#include <stdio.h>

int main()
{
    startMKarFile("tes.config");
    int i = 0;
    while (!EOPFile)
    {
        if (currentCharFile == '\n')
        {
            printf("Ini NextLine");
        }
        else if (currentCharFile == '\r')
        {
            printf("Ini Carriage Return");
        }
        else
            printf("%c", currentCharFile);
        advMKarFile();
        i++;
    }
}