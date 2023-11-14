#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../Pengguna/pengguna.h"
#include "../../ADT_Bawaan/boolean.h"
#include "../../ADT_Bawaan/matrix/matrix.h"
#include "../Balasan/treebalasan.h"

extern Pengguna currentPengguna; /*Berisi Data Current Pengguna*/

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/

extern ID CURRENT_ID_KICAUAN;/*Berisi Current Id Kicau*/

extern Matrix matrixPertemanan;/*Matrix Pertemanan*/

extern Matrix matrixPermintaan;/*Matrix Permintaan*/

extern ListBalasan ListBalasanData;/*List Dari Balasan yang ada*/

#endif