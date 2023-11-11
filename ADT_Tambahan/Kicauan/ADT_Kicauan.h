/* Modul Kicauan */
/* Definisi ADT KICAUAN dengan memanfaatkan list dinamik untuk menyimpan list kicauan */

#ifndef __KICAUAN_H__
#define __KICAUAN_H__

#include "../../ADT_Bawaan/boolean.h"
#include "../../ADT_Bawaan/wordmachine/wordmachine.h"
#include "../datetime/datetime.h"

/* ********** DEFINISI TYPE KICAUAN ********** */
typedef int ID;

typedef struct {
    Word PenulisKicauan;    // Username pengguna pembuat kicauan
    DATETIME WaktuKicaun;   // Waktu kicauan dibuat (diambil dari waktu lokal)
    Word Tweet;             // Isi kicauan
    int LikeKicauan;        // Banyaknya like pada kicauan
    int CurrentIDBalasan;      // Banyaknya balasan utama pada kicauan
} Kicauan;

int JUMLAH_KICAUAN_DENGAN_BALASAN;   // Banyaknya kicauan yang memiliki balasan

/* ********** SELEKTOR KICAUAN ********** */
#define PENULIS_KICAUAN(K) (K).PenulisKicauan
#define WAKTU_KICAUAN(K) (K).WaktuKicaun
#define TWEET(K) (K).Tweet
#define LIKE(K) (K).LikeKicauan
#define CURRENT_ID_BALASAN(K) (K).CurrentIDBalasan

/* ********** PRIMITIF-PRIMITIF UNTUK TYPE KICAUAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT KICAUAN */
void CreateKicauan(Kicauan *K, Word Penulis, DATETIME WaktuKicauan, Word Tweet);
/* I.S. K sembarang */
/* F.S. Terbentuk struct Kicauan dengan K.PenulisKicauan = Penulis, K.WaktuKicaun = WaktuKicauan, K.Tweet = Tweet, K.LikeKicauan = 0, K.CurrentIDBalasan = 0 */

/* MENCETAK STRUCT KICAUAN */
void PrintKicauan(Kicauan K, ID id);
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
/* I.S. K terdefinisi */
/* F.S. Like pada K bertambah 1 */

/* MENGUBAH ISI TWEET */
void EditTweet(Kicauan *K, Word NewTweet);
/* I.S. K terdefinisi */
/* F.S. Tweet pada K diubah menjadi NewTweet */

// /* ********** PERINTAH-PERINTAH PADA FITUR KICAUAN ********** */
// /* ********** UNTUK MAIN PROGRAM ********** */
// /* KICAU */
// void KICAU(); 
// /* Membuat sebuah Kicauan */
// 
// /* KICAUAN */
// void KICAUAN();
// /* Menampilkan semua kicauan yang dibuat pengguna dan teman pengguna ke layar */
// /* Terurut berdasarkan kicauan terbaru (ID Kicauan terbesar) */
// 
// /* SUKA_KICAUAN */
// void SUKA_KICAUAN(ID IDKicauan);
// /* Menambahkan like pada kicauan yang dipilih pengguna */
// 
// /* UBAH_KICAUAN */
// void UBAH_KICAUAN(ID IDKicauan);
// /* Mengubah isi kicauan yang dipilih pengguna */

#endif