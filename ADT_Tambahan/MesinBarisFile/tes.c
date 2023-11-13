#include "MBarisFile.h"
#include "../wordoperations.h"
#include <stdio.h>
#include "../../ADT_Bawaan/datetime/datetime.h"

int main (){
    DATETIME D;
    STARTBaris("tes.config");
    int i = 1;
    while (!EndBaris){
        D = wordToDatetime(currentBaris);
        TulisDATETIME(D);
        printf("\n");
        ADVBaris();
    }
    

    printf("Pembacaan Selesai");
}