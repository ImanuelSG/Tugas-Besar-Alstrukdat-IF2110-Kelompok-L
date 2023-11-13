#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\\wordoperations.h"
#include "inisialisasiperintah.h"
#include "..\\wordsimilarity.h"

void displayBurbir() {
    printf(".______    __    __  .______      .______    __  .______"); enter;  
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\    ");  enter;
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    "); enter;
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     "); enter;
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----. "); enter;
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____| "); enter;

    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode");
    printf(" pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
}

boolean isAKeyWord(Word w) {
    int i=0;
    boolean found = false;

    while ((!found) && (i < 100)) {
        if (isSameWord(KeyWords[i], w)) {
            found = true;
        }
        else {
            i++;
        }
    }

    return found;
}

void inputConfigFile(FILE* file) {
    Word fileNameWord;
    char * fileNameStr;
    int i;

    boolean firstInput = true;

    do
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        START();
        ADVWORD();
        if (!firstInput) {
            clearFirstCharacter(&currentWord);
        }
        fileNameWord = currentWord;
        fileNameStr = (char*) malloc (currentWord.Length);
        for (i = 0; i < fileNameWord.Length; i++) {
            fileNameStr[i] = fileNameWord.TabWord[i];
        }

        if (!fileExists(fileNameStr, fileNameWord.Length)) {
            printf("Tidak ada folder yang dimaksud!\n");
            printf("\n");
        }
        firstInput = false;

        // displayWord(stringToWord(fileNameStr, fileNameWord.Length + 2));
        // printf("\n");

    } while (!fileExists(fileNameStr, fileNameWord.Length));
}

boolean fileExists(char *filename, int filename_length) {

    char* path = (char*) malloc (filename_length + 1);
    int i;

    for (i = 0; i < filename_length; i++) {
        path[i] = filename[i];
    }
    path [filename_length] = NULL;
    // printf("%s", path);

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        free(path);
        return false;
    }
    else {
        free(path);
        fclose(file);
        return true;
    }

}
// Mengembalikan true jika nama file ditemukan, false jika tidak

void bacaInput(Word* input) {
    printf(">>> ");
    START();
    ADVWORD();
    *input = currentWord;
}

void clearFirstCharacter(Word* word) {

    int i;
    for (i = 0; i < word->Length; i++) {
        word->TabWord[i] = word->TabWord[i+1];
    }

    --word->Length;
}


void initializeKeyWords() {
    Word w = stringToWord("NULL", 4);
    int i;
    for (i = 0; i < 100; i++) {
        KeyWords[i] = w;
    }

    i = 0;

    KeyWords[i] = stringToWord("MASUK", 5); i++;
    KeyWords[i] = stringToWord("DAFTAR", 6); i++;
    KeyWords[i] = stringToWord("TUTUP_PROGRAM", 13); i++;
    KeyWords[i] = stringToWord("MUAT", 4); i++;

    KeyWords[i] = stringToWord("KELUAR", 6); i++;
    KeyWords[i] = stringToWord("GANTI_PROFIL", 12); i++;
    KeyWords[i] = stringToWord("LIHAT_PROFIL", 12); i++;
    KeyWords[i] = stringToWord("ATUR_JENIS_AKUN", 15); i++;
    KeyWords[i] = stringToWord("UBAH_FOTO_PROFIL", 16); i++;
    KeyWords[i] = stringToWord("DAFTAR_TEMAN", 12); i++;
    KeyWords[i] = stringToWord("HAPUS_TEMAN", 11); i++;
    KeyWords[i] = stringToWord("TAMBAH_TEMAN", 12); i++;
    KeyWords[i] = stringToWord("BATAL_TAMBAH_TEMAN", 18); i++;
    KeyWords[i] = stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN", 28); i++;
    KeyWords[i] = stringToWord("SETUJUI_PERTEMANAN", 18); i++;

    KeyWords[i] = stringToWord("KICAU", 5); i++;
    KeyWords[i] = stringToWord("KICAUAN", 7); i++;
    KeyWords[i] = stringToWord("SUKA_KICAUAN", 12); i++;
    KeyWords[i] = stringToWord("UBAH_KICAUAN", 12); i++;

    KeyWords[i] = stringToWord("BALAS", 5); i++;
    KeyWords[i] = stringToWord("BALASAN", 7); i++;
    KeyWords[i] = stringToWord("HAPUS_BALASAN", 13); i++;

    KeyWords[i] = stringToWord("BUAT_DRAF", 9); i++;
    KeyWords[i] = stringToWord("LIHAT_DRAF", 10); i++;

    KeyWords[i] = stringToWord("UTAS", 4); i++;
    KeyWords[i] = stringToWord("SAMBUNG_UTAS", 12); i++;
    KeyWords[i] = stringToWord("HAPUS_UTAS", 10); i++;
    KeyWords[i] = stringToWord("CETAK_UTAS", 10); i++;

    KeyWords[i] = stringToWord("SIMPAN", 6); i++;
}