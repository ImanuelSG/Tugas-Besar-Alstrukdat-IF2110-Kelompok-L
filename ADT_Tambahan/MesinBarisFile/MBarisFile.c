#include "MBarisFile.h"
#include "stdio.h"

boolean EndBaris;
Word currentBaris;

void STARTBaris (char namafile[]){
    startMKarFile(namafile);
    if (EOPFile){
        EndBaris = true;
    }
    else{
        EndBaris = false;
        CopyBaris();
        advMKarFile();  
    }
}

void ADVBaris (){
    if (EOPFile){
        EndBaris = true;
    }
    else{
        CopyBaris();
        advMKarFile();   
    }

}

void CopyBaris (){
    int i = 0;
    while ((currentCharFile != '\n') && !EOPFile){
        currentBaris.TabWord[i] = currentCharFile;
        advMKarFile();
        i++;
    }

    currentBaris.Length = i;
}

void PrintBaris(Word B){
    for (int i = 0 ; i<B.Length; i++){
        printf("%c", B.TabWord[i]);
    }
}


