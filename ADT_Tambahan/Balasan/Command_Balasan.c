#include <stdio.h>
#include "treebalasan.h"
#include "../Globals/globalvar.h"

/* ********** PERINTAH-PERINTAH PADA FITUR BALASAN ********** */
/* ********** UNTUK MAIN PROGRAM ********** */
/* BALAS */
void BALAS(ID id_Kicau, ID id_Balasan) {
/* Membuat sebuah Balasan pada balasan dengan id_Balasan pada kicauan dengan id_Kicau */
/* jika id_Balasan = -1, balasan akan dibuat pada kicauan dengan id_Kicau */
    if (id_Balasan == -1) {
        if (/*kicauan ada*/) {
            if (/*pengguna berteman or penulis kicauan publik*/) {

            } else { // penulis kicauan privat dan tidak berteman

            }
        } else { // kicauan tidak ada
        
        }
    } else { // id_Balasan != -1
        if (/*balasan ada*/) {
            if (/*pengguna berteman or penulis kicauan publik*/) {

            } else { // penulis kicauan privat dan tidak berteman

            }
        } else { // balasan tidak ada

        }
    }
}

/* BALASAN */
void BALASAN(ID id_Kicau) {
/* Menampilkan semua balasan pada kicauan dengan id_Kicau ke layar */
/* Terurut berdasarkan struktur tree */
    if (/* kicuan ada*/) {
        if (/*balasan ada*/) {
            if (/*pengguna berteman or penulis kicauan publik*/) {
                if 
            } else { //penulis kicuan privat dan tidak berteman

            }
        } else { // balasan tidak ada

        }
    } else { // kicauan tidak ada
    
    }
}

/* HAPUS_BALASAN */
void HAPUS_BALASAN(ID id_Kicau, ID id_Balasan) {
/* Menghapus balasan dengan id_Balasan pada kicauan dengan id_Kicau */
    if (/*kicauan ada*/) {
        if (/*balasan ada*/) {
            if (/*milik pengguna*/) {

            } else { // bukan milik pengguna

            }
        } else { // balasan tidak ada

        }
    } else { // kicauan tidak ada
    
    }
}