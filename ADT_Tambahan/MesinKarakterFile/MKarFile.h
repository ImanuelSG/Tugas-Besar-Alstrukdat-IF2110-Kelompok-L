/* File: MKarFile.h */
/* Definisi Mesin Karakter File*/

#ifndef mKarFile
#define mKarfile

#include "../../ADT_Bawaan/boolean.h"

/**
 * @brief Penanda bahwa input untuk MesinKarakterFile selesai (EOF Terdefisini by C)
 *
 */
#define MARKF EOF

/**
 * @brief Karakter yang sedang dibaca oleh Mesin Karakter File
 *
 */
extern char currentCharFile;

/**
 * @brief State penyimpan apakah sudah EOP Sehingga bisa berhenti
 * 
 */
extern boolean EOPFile;

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca karakter ada pada karakter pertama setelah fungsi dijalankan.
 * @param namaFile file yang akan dibaca. Gunakan directory file relatif pada directory program, bukan nama file saja.
 *
 */
void startMKarFile(char namaFile[]);

/**
 * @brief Memajukan pita satu karakter. Menyalakan EOP jika karakter selanjutnya adalah MARK.
 *
 */
void advMKarFile();

#endif