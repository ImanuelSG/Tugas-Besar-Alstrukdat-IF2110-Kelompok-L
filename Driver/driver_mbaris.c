#include "MBarisFile.h"
#include "../wordoperations.h"
#include <stdio.h>
#include "../../ADT_Bawaan/datetime/datetime.h"

int main()
{
    
    STARTBaris("tes.config");
    int i = 1;
    while (!EndBaris)
    {
        printf("Baris %d : ", i);
        displayWord(currentBaris);
        printf("\n");
        ADVBaris();
        i++;
    }
    printf("Pembacaan Selesai");
}