/* File inisialisasi untuk fungsi/prosedur inisialisasi dan perintah main */

#include <stdio.h>
#include "wordoperations.h"
#include "ADT_Bawaan/boolean.h"

#define enter printf("\n")

Word KeyWords[100];
void initializeKeyWords();
// Array yang berisi semua keyword perintah dan prosedur untuk inisialisasinya

boolean isAKeyWord(Word w);
// Mengembalikan true jika w adalah keyword perintah

void displayBurbir();
// Prosedur menampilkan tampilan awal program

void inputConfigFile(FILE* file);
// Prosedur meminta string file input

boolean fileExists(char* filename);
// Mengembalikan true jika nama file ditemukan, false jika tidak

boolean isLoggedIn();
// Mengembalikan true jika user sudah login

/*
MASUK
DAFTAR
TUTUP_PROGRAM
MUAT

KELUAR
GANTI_PROFIL
LIHAT_PROFIL
ATUR_JENIS_AKUN
UBAH_FOTO_PROFIL
DAFTAR_TEMAN
HAPUS_TEMAN
TAMBAH_TEMAN
BATAL_TAMBAH_TEMAN
DAFTAR_PERMINTAAN_PERTEMANAN
SETUJUI_PERTEMANAN

KICAU
KICAUAN
SUKA_KICAUAN
UBAH_KICAUAN

BALAS
BALASAN
HAPUS_BALASAN

BUAT_DRAF
lIHAT_DRAF

UTAS
SAMBUNG_UTAS
HAPUS_UTAS
CETAK_UTAS

SIMPAN
MUAT
*/