#include <stdlib.h>
#include "StackDraf.h"
#include <stdio.h>
/* Prototype manajemen memori */

int BanyakPenggunaDenganDraf = 0;

AddressDraf newNode(ElTypeDraf x)
{
    AddressDraf P = (AddressDraf)malloc(sizeof(Node));
    if (P != NULL)
    {
        INFODRAF(P) = x;
        NEXTDRAF(P) = NULL;
    }
    return P;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan INFODRAF = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK StackDraf ***************/
boolean isEmptyStackDraf(StackDraf s)
{
    return ADDR_TOP(s) == NULL;
}
/* Mengirim true jika StackDraf kosong: TOP(s) = NIL */

int lengthStackDraf(StackDraf s)
{
    int count = 0;
    AddressDraf P = ADDR_TOP(s);
    while (P != NULL)
    {
        count += 1;
        P = NEXTDRAF(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen StackDraf. Mengirimkan 0 jika StackDraf s kosong */

void CreateStackDraf(StackDraf *s)
{
    ADDR_TOP(*s) = NULL;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah StackDraf s yang kosong */

void DisplayStackDraf(StackDraf s)
{
    AddressDraf P = ADDR_TOP(s);
    while (P != NULL)
    {
        PrintDraf(INFODRAF(P));
        printf("\n");
        P = NEXTDRAF(P);
    }
}
/* Proses : Menuliskan isi StackDraf, ditulis di antara kurung siku; antara dua elemen
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika StackDraf kosong : menulis [] */

void SimpanDraf(StackDraf *s, ElTypeDraf x)
{

    AddressDraf Num = newNode(x);
    if (Num != NULL)
    {
        if (isEmptyStackDraf(*s))
        {
            BanyakPenggunaDenganDraf += 1;
        }

        NEXTDRAF(Num) = ADDR_TOP(*s);
        ADDR_TOP(*s) = Num;
    }
}
/* Menambahkan x sebagai elemen StackDraf s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void DeleteDraf(StackDraf *s, ElTypeDraf *x)
{
    *x = TOP(*s);
    AddressDraf p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXTDRAF(ADDR_TOP(*s));
    if (isEmptyStackDraf(*s))
    {
        BanyakPenggunaDenganDraf -= 1;
    }
    free(p);
}
/* Menghapus Top dari StackDraf s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
void ReverseStackDraf(StackDraf *s)
{
    StackDraf temp;
    CreateStackDraf(&temp);
    ElTypeDraf x;
    while (!isEmptyStackDraf(*s))
    {
        DeleteDraf(s, &x);
        SimpanDraf(&temp, x);
    }
    *s = temp;
}
