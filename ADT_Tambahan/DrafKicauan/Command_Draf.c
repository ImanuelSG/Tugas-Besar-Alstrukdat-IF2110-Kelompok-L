#include <stdio.h>
#include "Command_Draf.h"

void BUAT_DRAF(StackDraf *s, Word Penulis)
{
    printf("Masukkan draf:\n");
    STARTKalimat();
    Word Draf = currentWord;
    if (IsAllBlank(Draf))
    {
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    }
    else
    {
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        STARTWORD();
        printf("\n");
        Word HAPUS = stringToWord("HAPUS", 5);
        Word SIMPAN = stringToWord("SIMPAN", 6);
        Word TERBIT = stringToWord("TERBIT", 6);
        if (isSameWord(currentWord, HAPUS))
        {
            printf("Draf telah berhasil dihapus!\n");
        }
        else if (isSameWord(currentWord, SIMPAN))
        {
            DrafKicau D;
            DATETIME WaktuDraf;
            BacaDATETIME(&WaktuDraf);
            CreateDraf(&D, Draf, WaktuDraf);
            SimpanDraf(s, D);
            printf("Draf telah berhasil disimpan!\n");
        }
        else if (isSameWord(currentWord, TERBIT))
        {
            Kicauan K;
            DATETIME WaktuKicauan;
            BacaDATETIME(&WaktuKicauan);
            CreateKicauan(&K, Penulis, WaktuKicauan, Draf, 0);
            insertLastKicau(&ListKicauanData, K);
            printf("Selamat! Draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            PrintKicauan(K, CURRENT_ID_KICAUAN);
            printf("\n");
        }
        else
        {
            printf("Input tidak dikenali!\n");
        }
    }
}

void LIHAT_DRAF(StackDraf *s, Word Penulis)
{
    if (isEmptyStackDraf(*s))
    {
        printf("\n");
        printf("Yah, and belum memiliki draf apapun! Buat dulu ya:D\n");
    }
    else
    {
        Word HAPUS = stringToWord("HAPUS", 5);
        Word UBAH = stringToWord("UBAH", 4);
        Word TERBIT = stringToWord("TERBIT", 6);
        Word KEMBALI = stringToWord("KEMBALI", 7);
        printf("\n");
        printf("Ini draf terakhir anda:");
        PrintDraf(TOP(*s));
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        STARTKalimat();
        Word C = currentWord;
        if (isSameWord(C, HAPUS))
        {
            DrafKicau val;
            DeleteDraf(s, &val);
            printf("Draf telah berhasil dihapus!\n");
        }
        else if (isSameWord(C, UBAH))
        {
            BUAT_DRAF(s, Penulis);
        }
        else if (isSameWord(C, TERBIT))
        {
            Kicauan K;
            DATETIME WaktuKicauan;
            BacaDATETIME(&WaktuKicauan);
            DrafKicau D;
            DeleteDraf(s, &D);
            CreateKicauan(&K, Penulis, WaktuKicauan, ISI_DRAF(D), 0);
            insertLastKicau(&ListKicauanData, K);
            printf("Selamat! Draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            PrintKicauan(K, CURRENT_ID_KICAUAN);
        }
        else if (isSameWord(C, KEMBALI))
        {
            printf("Kembali ke menu utama...\n");
        }
        else
        {
            printf("Input tidak dikenali!\n");
        }
    }
}