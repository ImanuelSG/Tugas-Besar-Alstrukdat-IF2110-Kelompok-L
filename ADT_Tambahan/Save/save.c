#include "../MesinBarisFile/MBarisFile.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Profil/profil.h"
#include "../Globals/globalvar.h"
#include "../Kicauan/listdinkicauan.h"
#include "../DrafKicauan/StackDraf.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <sys/stat.h>

void printword(FILE *file, Word w)
{
    for (int i = 0; i < w.Length; i++)
    {
        fprintf(file, "%c", w.TabWord[i]);
        fprintf(file, "\n");
    }
}

int isDirectoryExists(const char *path)
{
    struct stat info;
    if (stat(path, &info) != 0)
    {

        return 0;
    }

    return S_ISDIR(info.st_mode);
}

void SavePenggunaConfig(char namafile[])
{
    FILE *filesave;
    filesave = fopen(namafile, "w");
    fprintf(filesave, "Hello");

    // Close the file after writing
    fclose(filesave);
}

void WriteKicauanConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w"); // Open the file for writing

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", NEFF_LIST_KICAUAN(ListKicauanData)); // Write the number of iterations

    // Loop through the list and write each Kicauan's information
    for (int i = 1; i <= NEFF_LIST_KICAUAN(ListKicauanData); i++)
    {
        Kicauan curr = ELMT_LIST_KICAUAN(ListKicauanData, i);

        fprintf(file, "%s\n", wordToString(TWEET(curr)));
        fprintf(file, "%d\n", LIKE(curr));
        fprintf(file, "%s\n", PENULIS_KICAUAN(curr));
        fprintf(file, "%s\n", wordToString(datetimeToWord(WAKTU_KICAUAN(curr))));
    }

    fclose(file); // Close the file
}

int main()
{
    FILE *filesave;
    const char *directoryPath = "tes";

    if (isDirectoryExists(directoryPath))
    {
        printf("Directory exists.\n");
        filesave = fopen("tes/pengguna.config", "w");
        fprintf(filesave, "Hmm?");

        // Close the file after writing
        fclose(filesave);
    }
    else
    {
        printf("Directory does not exist.\n");
        filesave = fopen("tes/pengguna.config", "w");
        fprintf(filesave, "Hello");

        // Close the file after writing
        fclose(filesave);
    }

    return 0;
}