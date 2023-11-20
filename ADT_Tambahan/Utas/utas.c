#include "utas.h"
#include <stdlib.h>
#include <stdio.h>

ListUtas LIST_UTAS;
/* PROTOTYPE BERKAITAN LINKED LIST UTAS*/
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(ListUtas *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list utas kosong */ {
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(ListUtas l)
{
    /* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElTypeUtas getKicauanUtas(ListUtas l, int idx)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan utas pada indeks idx */
    Address p = FIRST(l);
    int i = 0;
    while (i < idx)
    {
        i++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setELMTKicau(ListUtas *l, int idx, ElTypeUtas val)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx)
    {
        i++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

boolean IDKicauFound(ID IDKicau)
{
    return isIdxEffKicau(ListKicauanData, IDKicau);
}
boolean isIDKicauValid(ID IDKicau)
{
    return wordCompare(PENULIS_KICAUAN(ELMTKicau(ListKicauanData, IDKicau)), currentPengguna.nama);
}
void createKicauanUtas(Utas *U, int IDUtas, ID IDKicau, int index, Pengguna utasAuthor, DATETIME WaktuKicauan, Word Tweet)
{
    // Membuat node untuk utas secara individual
    IDUTAS(*U) = IDUtas;
    IDKICAU(*U) = IDKicau;
    KICAUANUTAMA(*U) = ELMTKicau(ListKicauanData, IDKicau);
    INDEX(*U) = index;
    PENULISUTAS(*U) = currentPengguna;
    WAKTUKICAUAN(*U) = WaktuKicauan;
    TWEET(*U) = Tweet;
}
void printKicauanUtas(Utas U, int index)
{
    /* I.S. U terdefinisi */
    /* F.S. Kicauan yang merupakan bagian dari utas tercetak di layar*/
    printf("\n");
    if (index == 0)
    {
        printf("| ID = %d\n", IDUTAS(U));
        printf("| ");
        printWord(PENULISUTAS(U));
        printf("\n");
        printf("| ");
        TulisDATETIME(WAKTU_KICAUAN(KICAUANUTAMA(U)));
        printf("\n");
        printf("| ");
        printWord(TWEET(KICAUANUTAMA(U)));
        printf("\n");
    }
    else
    {
        printf("\t");
        printf("| INDEX = %d\n", index);
        printf("\t");
        printf("| ");
        printWord(PENULISUTAS(U));
        printf("\n");
        printf("\t");
        printf("| ");
        TulisDATETIME(WAKTUKICAUAN(U));
        printf("\n");
        printf("\t");
        printf("| ");
        printWord(TWEET(U));
        printf("\n");
    }
}

void UTAS(ID IDKicau)
{
    // Mencari apakah id kicauan utama valid, lalu membuat utas
    // dengan index ke-0 nya kicauan utama (buat node baru)
    // setelah linked list terbuat, insert ke listdin listUtas
    if (!IDKicauFound(IDKicau))
    {
        printf("Kicauan tidak ditemukan\n");
    }
    else if (!isIDKicauValid(IDKicau))
    {
        printf("Utas ini bukan milik Anda!\n");
    }
    else
    {

        // insert ke listdin
    }
}