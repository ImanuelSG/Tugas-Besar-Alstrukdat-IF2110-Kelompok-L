#ifndef FRIENDREQ_H
#define FRIENDREQ_H

#include "../Pengguna/pengguna.h"
#include "../Utils/utils.h"

#define MAX_PEOPLE 20
#define IDX_TIDAK_TERDEFIINISI -1

typedef struct
{
    Pengguna sender;
    int BanyakTeman;
} Request;

typedef struct
{
    Request buffer[MAX_PEOPLE];
    int idxHead;
    int idxTail;
} PriorityQueueFriendRequest;

typedef struct
{
    PriorityQueueFriendRequest buffer[MAX_PEOPLE];
    int NEff;
} ListOfPriorityQueueFriendRequests;

extern ListOfPriorityQueueFriendRequests dataFriendRequest;
extern Matrix matrixPermintaan;
extern Matrix matrixPertemanan;

void newRequest(Request *req, Pengguna sender, int BanyakTeman);
/* *** Kreator *** */
void MakeEmptyFriendReq(PriorityQueueFriendRequest *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmptyFriendReq(PriorityQueueFriendRequest *pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFullFriendReq(PriorityQueueFriendRequest *pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthFriendReq(PriorityQueueFriendRequest *pq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueueFriendReq(PriorityQueueFriendRequest *pq, Request req);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeueFriendReq(PriorityQueueFriendRequest *pq, Request *req);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur";
        pq mungkin kosong */

void initializeFriendRequests();
/* Inisialisasi list of prio queue data pertemanan */

#endif