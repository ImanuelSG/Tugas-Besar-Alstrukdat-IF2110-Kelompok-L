#include <stdio.h>
#include "ADT_Kicauan.h"

int JUMLAH_KICAUAN_DENGAN_BALASAN;
/* ********** PRIMITIF-PRIMITIF UNTUK TYPE KICAUAN ********** */
/* *** KONSTRUKTOR *** */
/* MEMBUAT STRUCT KICAUAN */
void CreateKicauan(Kicauan *K, Word Penulis, DATETIME WaktuKicauan, Word Tweet, int Like) {
/* I.S. K sembarang */
/* F.S. Terbentuk struct Kicauan dengan PenulisKicauan = Penulis, WaktuKicaun = Waktu, Tweet = Tweet, LikeKicauan = 0, JumlahBalasan = 0 */
    PENULIS_KICAUAN(*K) = Penulis;
    WAKTU_KICAUAN(*K) = WaktuKicauan;
    TWEET(*K) = Tweet;
    LIKE(*K) = Like;
    CURRENT_ID_BALASAN(*K) = 0;
}

/* MENCETAK STRUCT KICAUAN */
void PrintKicauan(Kicauan K, ID id) {
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
    printf("| "); PrintWord(PENULIS_KICAUAN(K)); printf("\n");
    printf("| "); TulisDATETIME(WAKTU_KICAUAN(K)); printf("\n");
    printf("| "); PrintWord(TWEET(K)); printf("\n");
    printf("| Disukai: %d\n", LIKE(K));
}

/* MENAMBAH LIKE */
void AddLike(Kicauan *K) {
/* I.S. K terdefinisi */
/* F.S. Like pada K bertambah 1 */
    LIKE(*K) += 1;
}

/* MENGUBAH ISI TWEET */
void EditTweet(Kicauan *K, Word Tweet) {
/* I.S. K terdefinisi */
/* F.S. Tweet pada K diubah menjadi NewTweet */
    TWEET(*K) = Tweet;
}