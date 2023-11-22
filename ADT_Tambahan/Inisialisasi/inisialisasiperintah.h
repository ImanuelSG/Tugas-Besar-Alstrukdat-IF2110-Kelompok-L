/* File inisialisasi untuk fungsi/prosedur inisialisasi dan perintah main */

#ifndef _INIT_
#define _INIT_

#include <stdio.h>
#include "../wordoperations.h"
#define nl printf("\n")

extern Word KeyWords[100];
void initializeKeyWords();
// Array yang berisi semua keyword perintah dan prosedur untuk inisialisasinya

boolean isAKeyWord(Word w);
// Mengembalikan true jika w adalah keyword perintah

void displayLogoBurbir();
void displayBurbir();
// Prosedur menampilkan tampilan awal program

void inputConfigFile(FILE *file);
// Prosedur meminta string file input

boolean validatePath(Word foldername);
// Mengembalikan true jika ada foldernya dan berisi semua file config yang dibutuhkan

void bacaInput(Word *input);
// Membaca masukkan dari pengguna

void clearFirstCharacter(Word *word);

// Gabut hehehe
void checkSpellingError(Word perintah);

/*
stringToWord("MASUK")
stringToWord("DAFTAR")
stringToWord("TUTUP_PROGRAM")
stringToWord("MUAT")

stringToWord("KELUAR")
stringToWord("GANTI_PROFIL")
stringToWord("LIHAT_PROFIL")
stringToWord("ATUR_JENIS_AKUN")
stringToWord("UBAH_FOTO_PROFIL")
stringToWord("DAFTAR_TEMAN")
stringToWord("HAPUS_TEMAN")
stringToWord("TAMBAH_TEMAN")
stringToWord("BATAL_TAMBAH_TEMAN")
stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN")
stringToWord("SETUJUI_PERTEMANAN")

stringToWord("KICAU")
stringToWord("KICAUAN")
stringToWord("SUKA_KICAUAN")
stringToWord("UBAH_KICAUAN")

stringToWord("BALAS")
stringToWord("BALASAN")
stringToWord("HAPUS_BALASAN")

stringToWord("BUAT_DRAF")
stringToWord("lIHAT_DRAF")

stringToWord("UTAS")
stringToWord("SAMBUNG_UTAS")
stringToWord("HAPUS_UTAS")
stringToWord("CETAK_UTAS")

stringToWord("SIMPAN")
stringToWord("MUAT")/
*/
#endif