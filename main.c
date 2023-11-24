/* Main */
#include "ADT_Tambahan/wordsimilarity.h"
#include "ADT_Tambahan/inisialisasi/inisialisasiperintah.h"
#include "ADT_Tambahan/Pengguna/pengguna.h"
#include "ADT_Tambahan/Kicauan/Command_Kicauan.h"
#include "ADT_Tambahan/Balasan/Command_Balasan.h"
#include "ADT_Tambahan/teman/graf_teman.h"
#include "ADT_Tambahan/Loader/load.h"
#include "ADT_Tambahan/DrafKicauan/Command_Draf.h"
#include "ADT_Tambahan/Utas/Command_Utas.h"

#define not(n) !n
/* Header Note */
// Yang bikin char machine skill isu gk ngerti ada karakter backslash n :(
// Nanti harusnya clearFirstCharacter gk butuh karena gua udh modif ignore blanks buat
// nge ignore '\n' juga, but just in case komentar ini gua gak hapus dulu

int main()
{

    nl;

    initializeKeyWords();
    displayLogoBurbir();
    displayBurbir();

    inputConfigFile();
    CreateGrafTeman(&dataTeman);
    // printf("%d %d", dataTeman.NEffVertex, dataTeman.NEffEdges);
    // for (int i = 0; i < dataTeman.NEffEdges; i++)
    // {
    //     displayWord(dataTeman.ListOfEdges[i].vertex1.nama);
    //     displayWord(dataTeman.ListOfEdges[i].vertex2.nama);
    // }
    initializeFriendRequests();
    printf("File berhasil dimuat!\n");

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
                STARTKalimat();
                Word nama = currentWord;
                if (isLoggedIn)
                {
                    Lihat_Profil(nama);
                    
                }
                else
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
            }

            else if (isSameWord(perintah, stringToWord("ATUR_JENIS_AKUN", 15)))
            {
                if (isLoggedIn)
                {
                    Atur_Jenis_Akun();
                }
                else
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
            }

            else if (isSameWord(perintah, stringToWord("UBAH_FOTO_PROFIL", 16)))
            {
                if (isLoggedIn)
                {
                    Ubah_Foto_Profil();
                }
                else
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
            }

            /*-------------------------------TEMAN-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("DAFTAR_TEMAN", 12)))
            {
                // displayGrafStuff();
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    DAFTAR_TEMAN();
                }
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_TEMAN", 11)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    HAPUS_TEMAN();
                }
            }

            else if (isSameWord(perintah, stringToWord("TAMBAH_TEMAN", 12)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    TAMBAH_TEMAN();
                }
            }

            else if (isSameWord(perintah, stringToWord("DAFTAR_PERMINTAAN_PERTEMANAN", 28)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    DAFTAR_PERMINTAAN_PERTEMANAN();
                }
            }

            else if (isSameWord(perintah, stringToWord("SETUJUI_PERTEMANAN", 18)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    SETUJUI_PERTEMANAN();
                }
            }

            /*-------------------------------KICAU-----------------------------------*/

            else if (isSameWord(perintah, stringToWord("KICAU", 5)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    KICAU();
                    nl;
                }
            }

            else if (isSameWord(perintah, stringToWord("KICAUAN", 7)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    KICAUAN();
                }
            }

            else if (isSameWord(perintah, stringToWord("SUKA_KICAUAN", 12)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    ADVWORD();
                    int id = wordToInteger(currentWord);
                    SUKA_KICAUAN(id);
                    nl;
                }
            }

            else if (isSameWord(perintah, stringToWord("UBAH_KICAUAN", 12)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    ADVWORD();
                    int id = wordToInteger(currentWord);

                    UBAH_KICAUAN(id);
                    nl;
                }
            }

            /*-------------------------------BALASAN----------------------------------*/

            else if (isSameWord(perintah, stringToWord("BALAS", 5)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    ADVWORD();
                    int id_kicau = wordToInteger(currentWord);
                    ADVWORD();
                    int id_balasan = wordToInteger(currentWord);

                    BALAS(id_kicau, id_balasan);
                }
            }

            else if (isSameWord(perintah, stringToWord("BALASAN", 7)))
            {
                if (not(isLoggedIn))
                {
                    printf("Anda belum masuk! Masuk untuk menikmati layanan Burbir.\n");
                }
                else
                {
                    ADVWORD();
                    int id_kicau = wordToInteger(currentWord);
                    BALASAN(id_kicau);
                }
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
                Word Penulis = currentPengguna.nama;
                int i = getIdPengguna(currentPengguna.nama);
                StackDraf *S = &dataPengguna.contents[i].draf;
                BUAT_DRAF(S, Penulis);
            }

            else if (isSameWord(perintah, stringToWord("LIHAT_DRAF", 10)))
            {
                Word Penulis = currentPengguna.nama;
                int i = getIdPengguna(currentPengguna.nama);
                StackDraf *S = &dataPengguna.contents[i].draf;
                LIHAT_DRAF(S, Penulis);
            }

            /*------------------------------ UTAS ----------------------------------*/

            else if (isSameWord(perintah, stringToWord("UTAS", 4)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                UTAS(id);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("SAMBUNG_UTAS", 12)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                SAMBUNG_UTAS(id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("HAPUS_UTAS", 10)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);
                ADVWORD();
                int index = wordToInteger(currentWord);

                HAPUS_UTAS(id, index);
                nl;
            }

            else if (isSameWord(perintah, stringToWord("CETAK_UTAS", 10)))
            {
                ADVWORD();
                int id = wordToInteger(currentWord);

                CETAK_UTAS(id);
            }

            /*------------------------- SIMPAN DAN MUAT -----------------------------*/

            else if (isSameWord(perintah, stringToWord("SIMPAN", 6)))
            {
                printf("Silahkan masukan folder untuk Menyimpan: ");
                START();
                ADVWORD();
                Word folderNameWord = currentWord;
                UpdateMatrixPertemanan(&dataTeman, &dataFriendRequest, &matrixPertemanan, &matrixPermintaan);
                SIMPAN(folderNameWord);
            }

            else if (isSameWord(perintah, stringToWord("MUAT", 4)))
            {
                if (isLoggedIn)
                {
                    printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.");
                }
                else
                {
                    inputConfigFile();
                }
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