/* File: wordoperations.h */
/* Tambahan operasi dan primitif word */

#ifndef UTILS_H
#define UTILS_H

#include "../boolean.h"
#include <stdio.h>
#include "../Globals/globalvar.c"

/**
 * @brief fungsi untuk menentukan apakah Pengguna A berteman dengan Pengguna B
 * 
 * @param A Pengguna 1
 * @param B Pengguna 2
 * @return boolean True jika iya, False jika tidak
 */
boolean isBerteman (Pengguna A, Pengguna B) ;

int getIdPengguna(Word nama) ;



#endif
