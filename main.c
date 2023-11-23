/* Main */
#include "ADT_Tambahan/wordsimilarity.h"
#include "ADT_Tambahan/inisialisasi/inisialisasiperintah.h"
#include "ADT_Tambahan/Pengguna/pengguna.h"
#include "ADT_Tambahan/Kicauan/Command_Kicauan.h"
#include "ADT_Tambahan/Balasan/Command_Balasan.h"
#include "ADT_Tambahan/teman/graf_teman.h"
#include "ADT_Tambahan/teman/driverGraf.h"

#define not(n) !n
/* Header Note */
// Yang bikin char machine skill isu gk ngerti ada karakter backslash n :(
// Nanti harusnya clearFirstCharacter gk butuh karena gua udh modif ignore blanks buat
// nge ignore '\n' juga, but just in case komentar ini gua gak hapus dulu

int main()
{

    nl;
    CreateGrafTeman(&dataTeman);

    initializeKeyWords();
    displayLogoBurbir();
    displayBurbir();
    FILE *f;

    inputConfigFile(f);
    // load (f);
    printf("File berhasil dimuat!\n");

    // boolean firstInput = true;
    boolean stopped = false;

    while (not(stopped))
    {

        Word perintah;
        bacaInput(&perintah);

        if (isAKeyWord(perintah))
        {

            /*---------------------------PENGGUNA--------------------------------------*/

            if (isSameWord(perintah, stringToWord("DAFTAR", 6)))
            {
                Daftar();
            }

            else if (isSameWord(perintah, stringToWord("MASUK", 5)))
            {
                Masuk();
                // displayGrafStuff();
            }

            else if (isSameWord(perintah, stringToWord("KELUAR", 6)))
            {
                Keluar();
            }

            else if (isSameWord(perintah, stringToWord("TUTUP_PROGRAM", 13)))
            {
                stopped = true; // TUTUP_PROGRAM()
            }

            /*-------------------------------PROFIL-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("GANTI_PROFIL", 12)))
            {
                Ganti_Profil();
            }

            else if (isSameWord(perintah, stringToWord("LIHAT_PROFIL", 12)))
            {
                ADVWORD();
                Word nama = currentWord;

                Lihat_Profil(nama);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("ATUR_JENIS_AKUN", 15)))
            {
                Atur_Jenis_Akun();
            }

            else if (isSameWord(perintah, stringToWord("UBAH_FOTO_PROFIL", 16)))
            {
                Ubah_Foto_Profil();
            }

            /*-------------------------------TEMAN-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("DAFTAR_TEMAN", 12)))
            {
                // displayGrafStuff();
                DAFTAR_TEMAN();
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_TEMAN", 11)))
            {
                HAPUS_TEMAN();
            }

            else if (isSameWord(perintah, stringToWord("TAMBAH_TEMAN", 12)))
            {
                TAMBAH_TEMAN();
            }

            else if (isSameWord(perintah, stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN", 28)))
            {
               DAFTAR_PERMINTAAN_PERTEMANAN();
            }

            else if (isSameWord(perintah, stringToWord("SETUJUI_PERTEMANAN", 18)))
            {
                SETUJUI_PERTEMANAN();
            }

            /*-------------------------------KICAU-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("KICAU", 5))) {
                KICAU();
            }

            else if (isSameWord(perintah, stringToWord("KICAUAN", 7))) {
                KICAUAN();
            }

            else if (isSameWord(perintah, stringToWord("SUKA_KICAUAN", 12)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                SUKA_KICAUAN(id);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("UBAH_KICAUAN", 12)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                UBAH_KICAUAN(id);
                nl;
            }

            /*-------------------------------BALASAN----------------------------------*/

            else if (isSameWord(perintah, stringToWord("BALAS", 5)))
            {
                ADVWORD();
                int id_kicau = wordToInteger(currentWord);
                ADVWORD();
                int id_balasan = wordToInteger(currentWord);
                
                BALAS(id_kicau, id_balasan);
            }

            else if (isSameWord(perintah, stringToWord("BALASAN", 7)))
            {
                ADVWORD();
                int id_kicau = wordToInteger(currentWord);
                BALASAN(id_kicau);
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_BALASAN", 13)))
            {
                ADVWORD();
                int id_kicau = wordToInteger(currentWord);
                ADVWORD();
                int id_balasan = wordToInteger(currentWord);

                HAPUS_BALASAN(id_kicau, id_balasan);
            }

            /*------------------------------ DRAF ---------------------------------*/

            else if (isSameWord(perintah, stringToWord("BUAT_DRAF", 9)))
            {
                printf("Panggil fungsi BUAT_DRAF");
            }

            else if (isSameWord(perintah, stringToWord("LIHAT_DRAF", 10)))
            {
                printf("Panggil fungsi LIHAT_DRAF");
            }

            /*------------------------------ UTAS ----------------------------------*/

            else if (isSameWord(perintah, stringToWord("UTAS", 4)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi UTAS dengan parameter [IDKicauan]: %d", id);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("SAMBUNG_UTAS", 7)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                printf("Panggil fungsi SAMBUNG_UTAS dengan parameter [IDUtas] [index]: %d %d", id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_UTAS", 12)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                printf("Panggil fungsi HAPUS_UTAS dengan parameter [IDUtas] [index]: %d %d", id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("CETAK_UTAS", 10)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                printf("Panggil fungsi CETAK_UTAS dengan parameter [IDUtas]: %d", id);
            }

            /*------------------------- SIMPAN DAN MUAT -----------------------------*/

            else if (isSameWord(perintah, stringToWord("SIMPAN", 6)))
            {
                printf("Panggil fungsi SIMPAN");
            }

            else if (isSameWord(perintah, stringToWord("MUAT", 4)))
            {
                printf("Panggil fungsi MUAT");
            }
        }

        else
        {
            checkSpellingError(perintah);
        }

        nl;
    }

    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.");
    nl;
}