#include <stdio.h>
#include "wordoperations.h"
#include "inisialisasiperintah.h"

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

void initializeKeyWords() {
    Word w = stringToWord("NULL", 4);
    int i;
    for (i = 0; i < 100; i++) {
        KeyWords[i] = w;
    }
}

boolean isAKeyWord(Word w) {
    int i;
    boolean found = false;

    while ((!found) &&  (i < 100)) {
        if (isSameWord(KeyWords[i], w)) {
            found = true;
        }
    }

    return found;
}

void inputConfigFile(FILE* file) {
    char* fileNameStr;
    Word fileNameWord;

    do
    {
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        STARTWORD();
        fileNameWord = currentWord;
        fileNameStr = (char*) malloc(fileNameWord.Length);
        int i;
        for (i = 0; i < fileNameWord.Length; i++) {
            fileNameStr[i] = fileNameWord.TabWord[i];
        }

        if (!fileExists(fileNameStr)) {
            printf("Tidak ada folder yang dimaksud!\n");
            printf("\n");
        }

    } while (!fileExists(fileNameStr));
}

boolean fileExists(char* filename) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    else {
        fclose(file);
        return true;
    }


}
// Mengembalikan true jika nama file ditemukan, false jika tidak

boolean isLoggedIn();
// Mengembalikan true jika user sudah login