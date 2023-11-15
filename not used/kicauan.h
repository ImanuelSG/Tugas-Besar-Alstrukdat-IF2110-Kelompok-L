#ifndef KICAUAN_H
#define KICAUAN_H

#include "ADT/boolean.h"
#include "ADT/wordmachine.h"
#include "ADT/datetime.h"

typedef struct kicauan
{
    int id;
    Word text;
    int like;
    Word author;
    DATETIME datetime;
} Kicauan;

Kicauan findKicau(int id);

#endif