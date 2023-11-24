#include "MkarFile.h"
#include <stdio.h>

int main()
{
    startMKarFile("TesMKarFile.config");
    int i = 0;
    while (!EOPFile)
    {
        if (currentCharFile == '\n')
        {
            printf("Ini NextLine\n");
        }
        else if (currentCharFile == '\r')
        {
            printf("Ini Carriage Return\n");
        }
        else
            printf("%c", currentCharFile);
        advMKarFile();
        i++;
    }
}