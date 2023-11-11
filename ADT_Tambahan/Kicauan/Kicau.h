/* Modul Kicauan */
#ifndef __KICAUAN_H__
#define __KICAUAN_H__

#include "../boolean.h"
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../../ADT_Bawaan/datetime/datetime.h"

/* ********** DEFINISI TYPE KICAUAN ********** */
typedef int IDkicau;

typedef struct {
    Word PenulisKicauan;
    DATETIME WaktuKicaun;
    Word Tweet;
    int LikeKicauan;
    int JumlahBalasan;
} Kicauan;

IDkicau CURRENTIDkicau;

#define PENULIS_KICAUAN(K) (K).PenulisKicauan
#define WAKTU_KICAUAN(K) (K).WaktuKicaun
#define TWEET(K) (K).Tweet
#define LIKE(K) (K).LikeKicauan
#define JUMLAH_BALASAN(K) (K).JumlahBalasan

/* ********** DEFINISI TYPE LIST DINAMIK UNTUK KICAUAN ********** */
#define IDX_MIN 1       /* Indeks minimum list */
#define IDX_UNDEF 0     /* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
    Kicauan *buffer;    /* memori tempat penyimpan elemen (container) */
    int nEff;           /* >=0, banyaknya elemen efektif */
    int capacity;       /* ukuran elemen */
    int BanyakBalasan;  /* Banyaknya ID yang punya balasan */
} ListKicauan;
/* Indeks yang digunakan [1..capacity-1] */
/* Jika l adalah : ListKicauan, cara deklarasi dan akses: */
/* Deklarasi : l : ListKicauan */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity
#define BANYAK_BALASAN(l) (l).BanyakBalasan

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE KICAUAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT KICAUAN */
void CreateKicauan(Kicauan *K, Word Penulis, DATETIME Waktu, Word Tweet);
/* I.S. K sembarang */
/* F.S. Terbentuk struct Kicauan dengan PenulisKicauan = Penulis, WaktuKicaun = Waktu, Tweet = Tweet, LikeKicauan = 0, JumlahBalasan = 0 */

/* MENCETAK STRUCT KICAUAN */
void PrintKicauan(Kicauan K, IDkicau id);
/* I.S. K terdefinisi */
/* F.S. Struct Kicauan tercetak di layar dengan format:
    | ID = <idkicauan>
    | <Nama Pengguna>
    | <Waktu post kicauan>
    | <Isi kicauan>
    | Disukai: <like>
*/

/* MENAMBAH LIKE */
void AddLike(Kicauan *K);
/* I.S. L terdefinisi, id terdefinisi */
/* F.S. Jika id terdapat pada list, LIKE(K) bertambah 1 */

/* MENGUBAH ISI TWEET */
void EditTweet(Kicauan *K, Word Tweet);
/* I.S. L terdefinisi, id terdefinisi, Tweet terdefinisi */
/* F.S. Jika id terdapat pada list, TWEET(K) berubah menjadi Tweet */


/* ********** PRIMITIF-PRIMITIF UNTUK TYPE LISTKICAUAN ********** */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicauan(ListKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListKicauan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IDkicau getFirstIdx(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IDkicau getLastIdx(ListKicauan l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListKicauan l, IDkicau i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListKicauan l, IDkicau i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListKicauan l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListKicauan l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** TULIS LIST ********** */
void printListKicauan(ListKicauan l, Word NamaPengguna);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

void printList(ListKicauan l);
/* Proses : Menuliskan isi list dengan traversal, 
   list yang ditulis hanya Kicauan milik pengguna beserta teman-temannya
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: tercetak daftar seluruh kicauan */
/*      Penulisan dari kicauan terbaru ke yang terlama */

/* ********** OPERASI LAIN ********** */
void copyList(ListKicauan lIn, ListKicauan *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListKicauan *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListKicauan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListKicauan *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListKicauan *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

/* PERINTAH-PERINTAH PADA FITUR KICAUAN */
/* UNTUK MAIN PROGRAM */
/* KICAU */
void KICAU();

/* KICAUAN */
void KICAUAN();

/* SUKA_KICAUAN */
void SUKA_KICAUAN();

/* UBAH_KICAUAN */
void UBAH_KICAUAN();

#endif