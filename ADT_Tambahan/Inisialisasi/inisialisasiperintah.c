#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\\wordoperations.h"
#include "inisialisasiperintah.h"
#include "..\\wordsimilarity.h"

Word KeyWords[100];
void displayBurbir()
{
    printf(".______    __    __  .______      .______    __  .______");
    nl;
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\    ");
    nl;
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    ");
    nl;
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     ");
    nl;
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----. ");
    nl;
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____| ");
    nl;

    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode");
    printf(" pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
}

boolean isAKeyWord(Word w)
{
    int i = 0;
    boolean found = false;

    while ((!found) && (i < 100))
    {
        if (isSameWord(KeyWords[i], w))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return found;
}

void inputConfigFile(FILE *file)
{
    Word folderNameWord;
    int i;

    boolean firstInput = true;

    do
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        START();
        ADVWORD();
        folderNameWord = currentWord;

        if (!validatePath(folderNameWord))
        {
            printf("Tidak ada folder yang dimaksud!\n");
            printf("\n");
        }

    } while (!validatePath(folderNameWord));
}

boolean validatePath(Word folderNameWord)
{

    Word path_config1, path_config2, path_config3, path_config4, path_config5;

    path_config1 = DuplicateWord(folderNameWord);
    path_config2 = DuplicateWord(folderNameWord);
    path_config3 = DuplicateWord(folderNameWord);
    path_config4 = DuplicateWord(folderNameWord);
    path_config5 = DuplicateWord(folderNameWord);

    appendWord(&path_config1, stringToWord("/pengguna.config", 16));
    appendWord(&path_config2, stringToWord("/kicauan.config", 15));
    appendWord(&path_config3, stringToWord("/balasan.config", 15));
    appendWord(&path_config4, stringToWord("/draf.config", 12));
    appendWord(&path_config5, stringToWord("/utas.config", 12));

    char *path_config1_str = wordToString(path_config1);
    char *path_config2_str = wordToString(path_config2);
    char *path_config3_str = wordToString(path_config3);
    char *path_config4_str = wordToString(path_config4);
    char *path_config5_str = wordToString(path_config5);

    FILE *file1 = fopen(path_config1_str, "r");
    FILE *file2 = fopen(path_config2_str, "r");
    FILE *file3 = fopen(path_config3_str, "r");
    FILE *file4 = fopen(path_config4_str, "r");
    FILE *file5 = fopen(path_config5_str, "r");

    if (file1 == NULL || file2 == NULL || file3 == NULL || file4 == NULL || file5 == NULL)
    {
        fclose(file1);
        fclose(file2);
        fclose(file3);
        fclose(file4);
        fclose(file5);
        return false;
    }
    else
    {
        fclose(file1);
        fclose(file2);
        fclose(file3);
        fclose(file4);
        fclose(file5);
        return true;
    }
}
// Mengembalikan true jika nama file ditemukan, false jika tidak

void bacaInput(Word *input)
{
    printf(">>> ");
    STARTWORD();
    *input = currentWord;
}

void clearFirstCharacter(Word *word)
{

    int i;
    for (i = 0; i < word->Length; i++)
    {
        word->TabWord[i] = word->TabWord[i + 1];
    }

    --word->Length;
}

void checkSpellingError(Word perintah)
{
    Word saltik;
    int i = 0;
    boolean found = false;
    while (!found && (i < 100))
    {
        int ld = CalculateLevenshteinDistance(perintah, KeyWords[i], 0);
        if (ld < 3)
        {
            found = true;
            saltik = KeyWords[i];
        }
        else
        {
            ++i;
        }
    }

    if (!found)
    {
        printf("Input tidak dikenali!");
        nl;
    }
    else
    {
        printf("Input tidak dikenali!");
        nl;
        printf("Apakah Anda bermaksud untuk mengetik '");
        displayWord(saltik);
        printf("'..?");
        nl;
    }
}

void initializeKeyWords()
{
    Word w = stringToWord("NULL", 4);
    int i;
    for (i = 0; i < 100; i++)
    {
        KeyWords[i] = w;
    }

    i = 0;

    KeyWords[i] = stringToWord("MASUK", 5);
    i++;
    KeyWords[i] = stringToWord("DAFTAR", 6);
    i++;
    KeyWords[i] = stringToWord("TUTUP_PROGRAM", 13);
    i++;
    KeyWords[i] = stringToWord("MUAT", 4);
    i++;

    KeyWords[i] = stringToWord("KELUAR", 6);
    i++;
    KeyWords[i] = stringToWord("GANTI_PROFIL", 12);
    i++;
    KeyWords[i] = stringToWord("LIHAT_PROFIL", 12);
    i++;
    KeyWords[i] = stringToWord("ATUR_JENIS_AKUN", 15);
    i++;
    KeyWords[i] = stringToWord("UBAH_FOTO_PROFIL", 16);
    i++;
    KeyWords[i] = stringToWord("DAFTAR_TEMAN", 12);
    i++;
    KeyWords[i] = stringToWord("HAPUS_TEMAN", 11);
    i++;
    KeyWords[i] = stringToWord("TAMBAH_TEMAN", 12);
    i++;
    KeyWords[i] = stringToWord("BATAL_TAMBAH_TEMAN", 18);
    i++;
    KeyWords[i] = stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN", 28);
    i++;
    KeyWords[i] = stringToWord("SETUJUI_PERTEMANAN", 18);
    i++;

    KeyWords[i] = stringToWord("KICAU", 5);
    i++;
    KeyWords[i] = stringToWord("KICAUAN", 7);
    i++;
    KeyWords[i] = stringToWord("SUKA_KICAUAN", 12);
    i++;
    KeyWords[i] = stringToWord("UBAH_KICAUAN", 12);
    i++;

    KeyWords[i] = stringToWord("BALAS", 5);
    i++;
    KeyWords[i] = stringToWord("BALASAN", 7);
    i++;
    KeyWords[i] = stringToWord("HAPUS_BALASAN", 13);
    i++;

    KeyWords[i] = stringToWord("BUAT_DRAF", 9);
    i++;
    KeyWords[i] = stringToWord("LIHAT_DRAF", 10);
    i++;

    KeyWords[i] = stringToWord("UTAS", 4);
    i++;
    KeyWords[i] = stringToWord("SAMBUNG_UTAS", 12);
    i++;
    KeyWords[i] = stringToWord("HAPUS_UTAS", 10);
    i++;
    KeyWords[i] = stringToWord("CETAK_UTAS", 10);
    i++;

    KeyWords[i] = stringToWord("SIMPAN", 6);
    i++;
}