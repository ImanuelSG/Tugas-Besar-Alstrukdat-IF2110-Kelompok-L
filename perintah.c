#include <stdio.h>
#include "inisialisasiperintah.h"

void Begin() {
    displayBurbir();
    FILE* file;
    inputConfigFile(file);
    // load(file); // tunggu nuel

    boolean belom_selesai = true;

    do
    {
        inputLoop();
    } while (belom_selesai);
    
}