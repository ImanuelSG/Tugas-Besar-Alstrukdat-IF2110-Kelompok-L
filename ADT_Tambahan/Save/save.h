#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Profil/profil.h"
#include "../Globals/globalvar.h"
#include "../Kicauan/listdinkicauan.h"
#include "../DrafKicauan/StackDraf.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <sys/stat.h>


int isDirectoryExists(const char *path);


void SavePenggunaConfig(char namafile[]);

void SaveKicauanConfig(char namafile[]);
