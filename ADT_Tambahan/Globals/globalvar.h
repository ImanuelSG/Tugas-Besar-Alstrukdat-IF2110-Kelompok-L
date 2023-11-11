#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "../boolean.h"
#include "../../ADT_Bawaan/datetime/datetime.h"
#include "../wordoperations.c"
#include "../../ADT_Bawaan/wordmachine/wordmachine.c"
#include "../../ADT_Bawaan/charmachine/charmachine.h"


typedef struct
{
   Word mem[5][10];
} MatrixProfil;

typedef struct
{
    Word nama ; 
    Word sandi ;
    Word bio ;
    Word nomor ;
    Word weton ;
    int tipe_akun ; // 0 itu public, 1 itu private
    MatrixProfil profil ;
} Pengguna ;

typedef int ID;

typedef struct {
    Word PenulisKicauan;    // Username pengguna pembuat kicauan
    DATETIME WaktuKicaun;   // Waktu kicauan dibuat (diambil dari waktu lokal)
    Word Tweet;             // Isi kicauan
    int LikeKicauan;        // Banyaknya like pada kicauan
    int JumlahBalasan;      // Banyaknya balasan utama pada kicauan
} Kicauan;
ID CURRENT_ID_KICAUAN;               // ID kicauan terakhir yang dibuat

typedef struct {
    Kicauan *buffer;    /* memori tempat penyimpan elemen (container) */
    int nEff;           /* >= 0, banyaknya elemen efektif */
    int capacity;       /* ukuran list */
    int BanyakBalasan;  /* Banyaknya ID yang punya balasan */
} ListKicauan;

extern Pengguna currentPengguna; /*Berisi Data Current Pengguna*/
extern Pengguna dataPengguna[20] ;

extern boolean isLoggedIn; /*True jika ada pengguna sedang login, false sebaliknya.*/

extern int jumlahpengguna; /*Berisi jumlah pengguna saat ini*/

extern ListKicauan LIST_KICAUAN_DATA; /*Berisi List Kicauan saat ini*/

extern ID CURRENT_ID_KICAUAN;


#endif