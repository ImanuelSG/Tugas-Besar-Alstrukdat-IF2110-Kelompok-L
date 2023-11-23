#ifndef LOADANDSAVE_H
#define LOADANDSAVE_H

#include "../MesinBarisFile/MBarisFile.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Profil/profil.h"
#include "../Globals/globalvar.h"
#include "../Kicauan/listdinkicauan.h"
#include "../DrafKicauan/StackDraf.h"
#include "../utils/utils.h"
#include "../Balasan/treebalasan.h"
#include "../teman/graf_teman.h"
#include "../Pengguna/liststatikpengguna.h"
#include "../Utas/listdinutas.h"
#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief Prosedur membaca config pengguna
 *
 * @param namafile file yang ingin dibaca relatif terhadap tempat pemanggilan prosedur
 */
void ReadPenggunaConfig(char namafile[]);
/**
 * @brief Prosedur Membaca Config Kicau
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void ReadKicauanConfig(char namafile[]);
/**
 * @brief Prosedur Membaca Config Draf
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void ReadDrafConfig(char namafile[]);
/**
 * @brief Prosedur Membaca Config Balasan
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void ReadBalasanConfig(char namafile[]);
/**
 * @brief Prosedur Membaca Config Utas
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void ReadUtasConfig(char namafile[]);
/**
 * @brief Untuk MencariTahu Apakah Directory Ada
 *
 * @param path
 * @return int
 */

int isDirectoryExists(char *path);
/**
 * @brief  Prosedur Menulis Config Pengguna
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */

void WritePenggunaConfig(char namafile[]);

/**
 * @brief Prosedur Menulis Config Kicauan
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void WriteKicauanConfig(char namafile[]);
/**
 * @brief Prosedur Menulis Config Draf
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void WriteDrafConfig(char namafile[]);
/**
 * @brief Prosedur Menulis Config Balasan
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void WriteBalasanConfig(char namafile[]);
/**
 * @brief Prosedur Menulis Config Utas
 *
 * @param namafile relatif terhadap posisi pemanggilan prosedur
 */
void WriteUtasConfig(char namafile[]);
/**
 * @brief Prosedur Membaca Konfigurasi
 *
 * @param namafolder relatif terhadap posisi pemanggilan prosedur
 */
void SIMPAN(Word namafolder);
/**
 * @brief Prosedur Membuat Directory
 *
 */
void createDirectory(const char *path);
/**
 * @brief Prosedur Menulis Konfigurasi
 *
 * @param namafolder relatif terhadap posisi pemanggilan prosedur
 */
void MUAT(Word namafolder);

#endif
