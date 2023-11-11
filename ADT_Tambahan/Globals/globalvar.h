#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../Pengguna/pengguna.h"
#include "../Kicauan/listdinkicauan.h"
#include "boolean.h"
#include "matrix.h"
#include "../Balasan/treebalasan.h"

extern Pengguna currentPengguna; /*Berisi Data Current Pengguna*/

extern int banyakPengguna; /*Berisi jumlah pengguna saat ini*/

extern Pengguna dataPengguna[20];

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/

extern ListKicauan ListKicauanData; /*Berisi List Kicauan saat ini*/

extern ID CURRENT_ID_KICAUAN;

extern Matrix matrixPertemanan;

extern ListBalasan ListBalasanData;

#endif