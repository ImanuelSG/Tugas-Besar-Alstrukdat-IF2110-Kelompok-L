#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../Pengguna/pengguna.h"
#include "../Kicauan/Kicau.h"
#include "../boolean.h"

extern Pengguna currentPengguna; /*Berisi Data Current Pengguna*/
extern Pengguna dataPengguna[20] ;

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/

extern int jumlahpengguna; /*Berisi jumlah pengguna saat ini*/

extern ListKicauan ListKicauanData; /*Berisi List Kicauan saat ini*/

extern IDkicau currentIDKicau;

extern Word profil [20][5][10] ;

#endif