#include "../Kicauan/Kicau.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int banyakKicauan;
    Kicauan kicauan[MAX_KICAUAN];

    // Membaca konfigurasi kicauan dari file
    FILE *file = fopen("kicauan.config", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fscanf(file, "%d", &banyakKicauan);
    for (int i = 0; i < banyakKicauan; i++) {
        fscanf(file, "%d", &kicauan[i].id);
        fgetc(file);  // Membaca karakter newline
        fgets(kicauan[i].text, sizeof(kicauan[i].text), file);
        fscanf(file, "%d", &kicauan[i].like);
        fgetc(file);  // Membaca karakter newline
        fgets(kicauan[i].author, sizeof(kicauan[i].author), file);
        fgets(kicauan[i].datetime, sizeof(kicauan[i].datetime), file);
    }

    fclose(file);

    // Menampilkan kicauan yang telah dibaca
    for (int i = 0; i < banyakKicauan; i++) {
        printf("ID: %d\n", kicauan[i].id);
        printf("Text: %s", kicauan[i].text);
        printf("Like: %d\n", kicauan[i].like);
        printf("Author: %s", kicauan[i].author);
        printf("Datetime: %s", kicauan[i].datetime);
    }

    // Menambahkan atau mengubah kicauan jika diperlukan

    // Menyimpan konfigurasi kicauan ke file
    file = fopen("kicauan.config", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "%d\n", banyakKicauan);
    for (int i = 0; i < banyakKicauan; i++) {
        fprintf(file, "%d\n", kicauan[i].id);
        fprintf(file, "%s", kicauan[i].text);
        fprintf(file, "%d\n", kicauan[i].like);
        fprintf(file, "%s", kicauan[i].author);
        fprintf(file, "%s", kicauan[i].datetime);
    }

    fclose(file);

    return 0;
}
