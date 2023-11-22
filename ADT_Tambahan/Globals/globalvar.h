#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../../ADT_Bawaan/boolean.h"
#include "../../ADT_Bawaan/matrix/matrix.h"
#include "../Balasan/treebalasan.h"
#include "../Utas/listdinutas.h"

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/


extern Matrix matrixPertemanan;/*Matrix Pertemanan*/

extern Matrix matrixPermintaan;/*Matrix Permintaan*/

extern ListBalasan ListBalasanData;/*List Dari Balasan yang ada*/

extern ListDinUtas lDinUtas;

#endif