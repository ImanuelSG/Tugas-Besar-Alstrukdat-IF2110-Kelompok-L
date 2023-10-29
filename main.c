#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "kicau.h"
#include "boolean.h"


// ini buat contoh aja untuk skema nya,
// nantinya load bakal beda file
void load() {
    jmlKicauan = 727;
}
// nanti hapus aja y



int main() {
    load();
    tambahKicau();
    displayJmlKicau();
}