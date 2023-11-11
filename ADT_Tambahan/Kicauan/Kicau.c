#include <stdio.h>
#include <stdlib.h>
#include "Kicau.h"
#include "globalvar.h"
#include "wordoperations.h"
#include "utils.h"
/* ********** PRIMITIF-PRIMITIF UNTUK TYPE KICAUAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT KICAUAN */
Pengguna currentPengguna;
ListKicauan ListKicauanData;

void CreateKicauan(Kicauan *K, Word Penulis, DATETIME WaktuKicauan, Word Tweet)
{
    /* I.S. K sembarang */
    /* F.S. Terbentuk struct Kicauan dengan PenulisKicauan = Penulis, WaktuKicaun = Waktu, Tweet = Tweet, LikeKicauan = 0, JumlahBalasan = 0 */
    PENULIS_KICAUAN(*K) = Penulis;
    WAKTU_KICAUAN(*K) = WaktuKicauan;
    TWEET(*K) = Tweet;
    LIKE(*K) = 0;
    JUMLAH_BALASAN(*K) = 0;
}

/* MENCETAK STRUCT KICAUAN */
void PrintKicauan(Kicauan K, ID id)
{
    /* I.S. K terdefinisi */
    /* F.S. Struct Kicauan tercetak di layar dengan format:
        | ID = <idkicauan>
        | <Nama Pengguna>
        | <Waktu post kicauan>
        | <Isi kicauan>
        | Disukai: <like>
    */
    printf("\n");
    printf("| ID = %d\n", id);
    printf("| ");
    printWord(PENULIS_KICAUAN(K));
    printf("\n");
    printf("| ");
    TulisDATETIME(WAKTU_KICAUAN(K));
    printf("\n");
    printf("| ");
    printWord(TWEET(K));
    printf("\n");
    printf("| Disukai: %d\n", LIKE(K));
}

/* MENAMBAH LIKE */
void AddLike(Kicauan *K)
{
    /* I.S. K terdefinisi */
    /* F.S. Like pada K bertambah 1 */
    LIKE(*K) += 1;
}

/* MENGUBAH ISI TWEET */
void EditTweet(Kicauan *K, Word Tweet)
{
    /* I.S. K terdefinisi */
    /* F.S. Tweet pada K diubah menjadi NewTweet */
    TWEET(*K) = Tweet;
}

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE LISTKICAUAN ********** */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListKicauan *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (Kicauan *)malloc(capacity * sizeof(Kicauan));
    NEFF(*l) = 0;
    BANYAK_BALASAN(*l) = 0;
}

void dealocateListDinKicauan(ListKicauan *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0; BANYAK_BALASAN(l)=0 */
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    BANYAK_BALASAN(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListKicauan l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
ID getFirstIdx(ListKicauan l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN_LIST_KICAUAN;
}

ID getLastIdx(ListKicauan l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* indeks dimulai dari 1 */
    return NEFF(l);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListKicauan l, ID i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IDX_MIN_LIST_KICAUAN) && (i < CAPACITY(l)));
}

boolean isIdxEff(ListKicauan l, ID i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 1..NEFF(l) */
    return ((i >= IDX_MIN_LIST_KICAUAN) && (i <= NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListKicauan l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* *** Test list penuh *** */
    return (NEFF(l) == 0);
}

boolean isFull(ListKicauan l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (NEFF(l) == CAPACITY(l) - 1);
    // dikurang 1 karena indeks dimulai dari 1
}

/* ********** TULIS LIST ********** */
void printListKicauan(ListKicauan l, Word NamaPengguna)
{
    /* Proses : Menuliskan isi list dengan traversal,
       list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: tercetak daftar kicauan pengguna dan temannya */
    /*      Penulisan dari kicauan terbaru ke yang terlama */
    ID i;

    for (i = getLastIdx(l); i >= getFirstIdx(l); i--)
    {
        if (IsBerteman(NamaPengguna, PENULIS_KICAUAN(ELMT(l, i))))
        {
            PrintKicauan(ELMT(l, i), i);
        }
    }
}

void printList(ListKicauan l)
{
    /* Proses : Menuliskan isi list dengan traversal,
       list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: tercetak daftar seluruh kicauan */
    /*      Penulisan dari kicauan terbaru ke yang terlama */
    ID i;

    for (i = getLastIdx(l); i >= getFirstIdx(l); i--)
    {
        PrintKicauan(ELMT(l, i), i);
        printf("\n");
    }
}

/* ********** OPERASI LAIN ********** */
void copyList(ListKicauan lIn, ListKicauan *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    int i;
    CreateListDinKicauan(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    BANYAK_BALASAN(*lOut) = BANYAK_BALASAN(lIn);
    for (i = getFirstIdx(lIn); i <= getLastIdx(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListKicauan *l, Kicauan val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, mungkin penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    if (isFull(*l))
    {
        expandList(l, 50);
    }
    NEFF(*l) += 1;
    ELMT(*l, getLastIdx(*l)) = val;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListKicauan *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    CAPACITY(*l) += num;
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}

void shrinkList(ListKicauan *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    CAPACITY(*l) -= num;
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}

void compressList(ListKicauan *l)
{
    /* Proses : Mengubah capacity sehingga capacity = nEff + 1, karena indeks dimulai dari 1, bukan 0 */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */
    CAPACITY(*l) = NEFF(*l) + 1;
    BUFFER(*l) = (Kicauan *)realloc(BUFFER(*l), CAPACITY(*l) * sizeof(Kicauan));
}

/* ********** PERINTAH-PERINTAH PADA FITUR KICAUAN ********** */
/* ********** UNTUK MAIN PROGRAM ********** */
/* KICAU */
void KICAU()
{
    /* Membuat sebuah Kicauan */
    Word NewTweet;

    printf("\nMasukkan kicauan:\n");
    BacaKalimat();
    NewTweet = currentWord;

    if (IsAllBlank(NewTweet))
    {
        printf("\nKicauan tidak boleh hanya berisi spasi!\n");
    }
    else
    { // tweet valid
        Kicauan NewKicauan;
        DATETIME WaktuKicauan;

        BacaDATETIME(&WaktuKicauan);
        CURRENT_ID_KICAUAN += 1;
        CreateKicauan(&NewKicauan, currentPengguna.nama, WaktuKicauan, NewTweet);
        insertLast(&ListKicauanData, NewKicauan);

        printf("\nSelamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:");
        PrintKicauan(NewKicauan, CURRENT_ID_KICAUAN);
        printf("\n");
    }
}

/* KICAUAN */
void KICAUAN()
{
    /* Menampilkan semua kicauan yang dibuat pengguna dan teman pengguna ke layar */
    /* Terurut berdasarkan kicauan terbaru (ID Kicauan terbesar) */
    printListKicauan(ListKicauanData, currentPengguna.nama);
}

/* SUKA_KICAUAN */
void SUKA_KICAUAN(ID IDKicauan)
{
    /* Menambahkan like pada kicauan yang dipilih pengguna */
    printf("\n");
    if (!isIdxEff(&ListKicauanData, IDKicauan))
    { // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d;\n", IDKicauan);
    }
    else
    {
        if (!isBerteman(currentPengguna.nama, PENULIS_KICAUAN(ELMT(ListKicauanData, IDKicauan))) && getPengguna(PENULIS_KICAUAN(ELMT(ListKicauanData, IDKicauan))).tipe_akun == 1)
        {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
        else
        { /* akun privat dan berteman, atau akun bersifat publik */
            AddLike(&ELMT(ListKicauanData, IDKicauan));
            printf("Selamat! kicauan telah disukai!\n");
            printf("Detil kicauan:");
            PrintKicauan(ELMT(ListKicauanData, IDKicauan), IDKicauan);
        }
    }
    printf("\n");
}

/* UBAH_KICAUAN */
void UBAH_KICAUAN(ID IDKicauan)
{
    /* Mengubah isi kicauan yang dipilih pengguna */
    printf("\n");
    if (!isSameWord(currentPengguna.nama, getKicauanAuthor(IDKicauan)))
    {
        printf("Kicauan dengan ID = %d bukan milikmu!\n", IDKicauan);
    }
    else if (isIdxEff(ListKicauanData, IDKicauan))
    { // IDKicauan tidak valid
        printf("Tidak ditemukan kicauan dengan ID = %d!;\n", IDKicauan);
    }
    else
    { // kicauan milik pengguna
        Word NewTweet;
        printf("Masukkan kicauan baru:\n");
        BacaKalimat();
        NewTweet = currentWord;

        if (IsAllBlank(NewTweet))
        {
            printf("\nKicauan tidak boleh hanya berisi spasi!\n");
        }
        else
        { // tweet valid
            EditTweet(&ELMT(ListKicauanData, IDKicauan), NewTweet);
            printf("\nSelamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:");
            PrintKicauan(ELMT(ListKicauanData, IDKicauan), IDKicauan);
        }
    }
    printf("\n");
}

Word getKicauanAuthor(ID IDKicauan)
{
    /* Mengembalikan nama pengguna yang membuat kicauan */
    return PENULIS_KICAUAN(ELMT(ListKicauanData, IDKicauan));
}