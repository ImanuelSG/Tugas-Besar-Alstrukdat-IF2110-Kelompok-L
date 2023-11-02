#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../pengguna.h"
#include "../Kicauan/Kicau.h"
#include "boolean.h"

extern Pengguna currentPengguna; /*Berisi Data Current Pengguna*/

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/

extern int jumlahpengguna; /*Berisi jumlah pengguna saat ini*/

extern ListKicauan ListKicauanData; /*Berisi List Kicauan saat ini*/

extern IDkicau currentIDKicau;

#endif