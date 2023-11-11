/* File: utils.h */
/* Tambahan operasi dan primitif word */

#ifndef UTILS_H
#define UTILS_H

#include "boolean.h"
#include "wordmachine.h"
#include "pengguna.h"
#include <stdio.h>

/**
 * @brief fungsi untuk menentukan apakah Pengguna A berteman dengan Pengguna B
 *
 * @param namaA nama Pengguna 1
 * @param namaB nama Pengguna 2
 * @return boolean True jika iya, False jika tidak
 */
boolean isBerteman(Word namaA, Word namaB);

/**
 * @brief fungsi untuk mendapatkan id dari suatu pengguna
 *
 * @param  nama pengguna
 * @return int id pengguna
 */
int getIdPengguna(Word nama);

/**
 * @brief fungsi untuk mendapatkan data pengguna
 *
 * @param  nama pengguna
 * @return Pengguna data pengguna
 */

Pengguna getPengguna(Word nama);

#endif
