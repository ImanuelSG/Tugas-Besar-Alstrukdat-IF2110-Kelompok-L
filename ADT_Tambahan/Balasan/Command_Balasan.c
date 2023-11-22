#include "Command_Balasan.h"
#include "../Kicauan/listdinkicauan.h"

/* ********** PERINTAH-PERINTAH PADA FITUR BALASAN ********** */
/* ********** UNTUK MAIN PROGRAM ********** */
/* BALAS */
void BALAS(ID id_Kicau, ID id_Balasan)
{
    /* Membuat sebuah Balasan pada balasan dengan id_Balasan pada kicauan dengan id_Kicau */
    /* jika id_Balasan = -1, balasan akan dibuat pada kicauan dengan id_Kicau */
    if (id_Balasan == -1)
    {
        if (isIdxEffKicau(ListKicauanData, id_Kicau))
        { // ID_Kicau valid
            Pengguna *Penulis_Kicau = getPengguna(PENULIS_KICAUAN(ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau)));

            if (!isBerteman(currentPengguna.nama, PENULIS_KICAUAN(ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau))) && (*Penulis_Kicau).tipe_akun == 1)
            { // penulis kicauan privat dan tidak berteman
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
            }
            else
            { /*pengguna berteman or penulis kicauan publik*/
                Word NewBalasan;

                printf("\nMasukkan balasan:\n");
                STARTKalimat();
                NewBalasan = currentWord;

                if (IsAllBlank(NewBalasan))
                {
                    printf("\nBalasan tidak boleh hanya berisi spasi!\n");
                }
                else
                {
                    Balasan Struct_Balasan;
                    DATETIME WaktuBalasan;

                    BacaDATETIME(&WaktuBalasan);
                    CreateBalasan(&Struct_Balasan, currentPengguna.nama, WaktuBalasan, NewBalasan, &ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau), id_Balasan);
                    if (&ELMT_LIST_BALASAN(ListBalasanData, id_Kicau) == NULL)
                    {
                        JUMLAH_KICAUAN_DENGAN_BALASAN += 1;
                    }
                    insertChild(&ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), Struct_Balasan);

                    printf("\nSelamat! balasan telah diterbitkan!\n");
                    printf("Detil balasan:");
                    PrintBalasan(Struct_Balasan, 0);
                    printf("\n");
                }
            }
        }
        else
        { // kicauan tidak ada
            printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        }
    }

    else
    { // id_Balasan != -1
        if (isIdxEffKicau(ListKicauanData, id_Kicau))
        { // kicauan ada
            if (searchTree(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), id_Balasan) != NULL)
            { // balasan ada
                Address balas = searchTree(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), id_Balasan);
                Pengguna *Penulis_Balasan = getPengguna(PENULIS_BALASAN(INFO_TREE(balas)));

                if (!isBerteman(currentPengguna.nama, PENULIS_BALASAN(INFO_TREE(balas))) && (*Penulis_Balasan).tipe_akun == 1)
                { // penulis balasan privat dan tidak berteman
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n");
                }
                else
                { /*pengguna berteman or penulis kicauan publik*/
                    Word NewBalasan;

                    printf("\nMasukkan balasan:\n");
                    STARTKalimat();
                    NewBalasan = currentWord;

                    if (IsAllBlank(NewBalasan))
                    {
                        printf("\nBalasan tidak boleh hanya berisi spasi!\n");
                    }
                    else
                    {
                        Balasan Struct_Balasan;
                        DATETIME WaktuBalasan;

                        BacaDATETIME(&WaktuBalasan);
                        CreateBalasan(&Struct_Balasan, currentPengguna.nama, WaktuBalasan, NewBalasan, &ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau), id_Balasan);
                        insertChild(&balas, Struct_Balasan);

                        printf("\nSelamat! balasan telah diterbitkan!\n");
                        printf("Detil balasan:");
                        PrintBalasan(Struct_Balasan, 0);
                        printf("\n");
                    }
                }
            }
            else
            { // balasan tidak ada
                printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            }
        }
        else
        { // kicauan tidak ada
            printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        }
    }
}

/* BALASAN */
void BALASAN(ID id_Kicau)
{
    /* Menampilkan semua balasan pada kicauan dengan id_Kicau ke layar */
    /* Terurut berdasarkan struktur tree */
    if (isIdxEffKicau(ListKicauanData, id_Kicau))
    { // ID_Kicau valid
        Pengguna *Penulis_Kicau = getPengguna(PENULIS_KICAUAN(ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau)));

        if (!isBerteman(currentPengguna.nama, PENULIS_KICAUAN(ELMT_LIST_KICAUAN(ListKicauanData, id_Kicau))) && (*Penulis_Kicau).tipe_akun == 1)
        { // penulis kicuan privat dan tidak berteman
            printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        }

        else
        { // pengguna berteman or penulis kicauan publik

            if (LEFT_CHILD(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau)) != NULL)
            { // balasan ada
                printTree(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), 0);
            }
            else
            { // balasan tidak ada
                printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
            }
        }
    }

    else
    { // kicauan tidak ada
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    }
}

/* HAPUS_BALASAN */
void HAPUS_BALASAN(ID id_Kicau, ID id_Balasan)
{
    /* Menghapus balasan dengan id_Balasan pada kicauan dengan id_Kicau */
    if (isIdxEffKicau(ListKicauanData, id_Kicau))
    { /*kicauan ada*/

        if (searchTree(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), id_Balasan) != NULL)
        { /*balasan ada*/
            Address balas = searchTree(ELMT_LIST_BALASAN(ListBalasanData, id_Kicau), id_Balasan);

            if (isSameWord(PENULIS_BALASAN(INFO_TREE(balas)), currentPengguna.nama))
            { /*milik pengguna*/
                deleteTree(&balas);
                if (ELMT_LIST_BALASAN(ListBalasanData, id_Kicau) == NULL)
                {
                    JUMLAH_KICAUAN_DENGAN_BALASAN -= 1;
                }
                printf("Balasan berhasil dihapus.\n");
            }
            else
            { // bukan milik pengguna
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            }
        }

        else
        { // balasan tidak ada
            printf("Balasan tidak ditemukan.\n");
        }
    }

    else
    { // kicauan tidak ada
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    }
}