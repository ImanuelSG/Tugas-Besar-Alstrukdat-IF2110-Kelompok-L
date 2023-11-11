#include "../boolean.h"
#include "utils.h"

int getIdPengguna(Word nama) {
    int i = 0 ;
    boolean found = false ;
    while (!found && i < jumlahpengguna) {
        if (isSameWord(nama, dataPengguna[i].nama)) {
            found = true ;
        }
        else i++ ;
    }
    if (found) return i ;
    else return -1 ;
}
