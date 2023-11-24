#ifndef COMMAND_UTAS_H
#define COMMAND_UTAS_H

#include "utas.h"
#include "listdinutas.h"
#include <stdio.h>



/****************** PRIMITIF ADT UTAS ******************/
void UTAS(ID IDKicau);
void SAMBUNG_UTAS(int IDUtas, int index);
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);

#endif