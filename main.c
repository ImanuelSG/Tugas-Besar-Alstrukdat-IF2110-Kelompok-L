/* Main */
#include "ADT_Tambahan\\inisialisasi\\inisialisasiperintah.h"
#include "ADT_Tambahan\\wordsimilarity.h"
#include "ADT_Tambahan\\Pengguna\pengguna.h"

#define not(n) !n

int main() {
    
    nl;
    initializeKeyWords();
    displayBurbir();
    FILE *f;

    inputConfigFile(f);
    // load (f);
    printf("File berhasil dimuat!\n");

    // boolean firstInput = true;
    boolean stopped = false;

    while (not(stopped)) {
        Word perintah;
        bacaInput(&perintah);
        clearFirstCharacter(&perintah);

        if (isAKeyWord(perintah)) {

         /*---------------------------PENGGUNA--------------------------------------*/

            if (isSameWord(perintah, stringToWord("DAFTAR", 6))) {
                printf("Panggil fungsi DAFTAR");
            }

            else if (isSameWord(perintah, stringToWord("MASUK", 5))) {
                printf("Panggil fungsi MASUK");
            }

            else if (isSameWord(perintah, stringToWord("KELUAR", 5))) {
                printf("Panggil fungsi KELUAR");
            }

            else if (isSameWord(perintah, stringToWord("TUTUP_PROGRAM", 5))) {
                stopped = true; // TUTUP_PROGRAM()
            }



        /*-------------------------------PROFIL-----------------------------------*/


            else if (isSameWord(perintah, stringToWord("GANTI_PROFIL", 12))) {
                printf("Panggil fungsi GANTI_PROFIL");
            }

            else if (isSameWord(perintah, stringToWord("LIHAT_PROFIL", 12))) {
                ADVWORD(); 
                Word nama = currentWord;

                printf("Panggil fungsi LIHAT_PROFIL dengan parameter [NAMA]: ");
                displayWord(nama);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("ATUR_JENIS_AKUN", 15))) {
                printf("Panggil fungsi ATUR_JENIS_AKUN");
            }

            else if (isSameWord(perintah, stringToWord("UBAH_FOTO_PROFIL", 16))) {
                printf("Panggil fungsi UBAH_FOTO_PROFIL");
            }



        /*-------------------------------TEMAN-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("DAFTAR_TEMAN", 12))) {
                printf("Panggil fungsi DAFTAR_TEMAN");
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_TEMAN", 11))) {
                printf("Panggil fungsi HAPUS_TEMAN");
            }

            else if (isSameWord(perintah, stringToWord("TAMBAH_TEMAN", 12))) {
                printf("Panggil fungsi TAMBAH_TEMAN");
            }

            else if (isSameWord(perintah, stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN", 28))) {
                printf("Panggil fungsi DAFTAR_PERMINTAAN_PERTEMANAN");
            }

            else if (isSameWord(perintah, stringToWord("SETUJUI_PERTEMANAN", 18))) {
                printf("Panggil fungsi SETUJUI_PERTEMANAN");
            }


        /*-------------------------------KICAU-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("KICAU", 5))) {
                printf("Panggil fungsi KICAU");
            }

            else if (isSameWord(perintah, stringToWord("KICAUAN", 7))) {
                printf("Panggil fungsi KICAUAN");
            }

            else if (isSameWord(perintah, stringToWord("SUKA_KICAUAN", 12))) {
                ADVWORD(); 
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi SUKA_KICAUAN dengan parameter [IDKicauan]: %d", id);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("UBAH_KICAUAN", 12))) {
                ADVWORD(); 
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi UBAH_KICAUAN dengan parameter [IDKicauan]: %d", id);
                nl;
            }


        /*-------------------------------BALASAN----------------------------------*/

            else if (isSameWord(perintah, stringToWord("BALAS", 5))) {
                printf("Panggil fungsi BALAS");
            }

            else if (isSameWord(perintah, stringToWord("BALASAN", 7))) {
                printf("Panggil fungsi BALASAN");
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_BALASAN", 13))) {
                printf("Panggil fungsi HAPUS_BALASAN");
            }

        // BALAS [IDKicau] [IDBalasan], BALASAN [IDKicau], HAPUS_BALASAN [IDKicau] [IDBalasan]


        /*------------------------------ DRAF ---------------------------------*/

            else if (isSameWord(perintah, stringToWord("BUAT_DRAF", 9))) {
                printf("Panggil fungsi BUAT_DRAF");
            }

            else if (isSameWord(perintah, stringToWord("LIHAT_DRAF", 10))) {
                printf("Panggil fungsi LIHAT_DRAF");
            }


        /*------------------------------ UTAS ----------------------------------*/


            else if (isSameWord(perintah, stringToWord("UTAS", 5))) {
                ADVWORD(); 
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi UTAS dengan parameter [IDKicauan]: %d", id);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("SAMBUNG_UTAS", 7))) {
                ADVWORD(); 
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                printf("Panggil fungsi SAMBUNG_UTAS dengan parameter [IDUtas] [index]: %d", id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_UTAS", 12))) {
                ADVWORD(); 
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                printf("Panggil fungsi HAPUS_UTAS dengan parameter [IDUtas] [index]: %d", id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("CETAK_UTAS", 12))) {
                ADVWORD();
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi CETAK_UTAS dengan parameter [IDUtas]: %d", id);
            }


        /*------------------------- SIMPAN DAN MUAT -----------------------------*/

            else if (isSameWord(perintah, stringToWord("SIMPAN", 6))) {
                printf("Panggil fungsi SIMPAN");
            }

            else if (isSameWord(perintah, stringToWord("MUAT", 4))) {
                printf("Panggil fungsi MUAT");
            }
            
        }

        else {
            checkSpellingError(perintah);
        }
        
        nl;
    }


}