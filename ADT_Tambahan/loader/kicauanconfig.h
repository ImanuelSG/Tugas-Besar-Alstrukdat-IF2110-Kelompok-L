typedef struct {
    Word PenulisKicauan;
    DATETIME WaktuKicaun;
    Word Tweet;
    int LikeKicauan;
    int JumlahBalasan;
} Kicauan;

#define PENULIS_KICAUAN(K) (K).PenulisKicauan
#define WAKTU_KICAUAN(K) (K).WaktuKicaun
#define TWEET(K) (K).Tweet
#define LIKE(K) (K).LikeKicauan
#define JUMLAH_BALASAN(K) (K).JumlahBalasan

typedef struct {
    Kicauan buffer;    / memori tempat penyimpan elemen (container) */
    int nEff;           /* >=0, banyaknya elemen efektif */
    int capacity;       /* ukuran elemen */
    int BanyakBalasan;  /* Banyaknya ID yang punya balasan */
} ListKicauan;

#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity
#define BANYAK_BALASAN(l) (l).BanyakBalasan