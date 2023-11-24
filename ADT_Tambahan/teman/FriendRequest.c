#include <stdio.h>
#include "FriendRequest.h"
#include "../Globals/globalvar.h"

#include "../Pengguna/liststatikpengguna.h"


Matrix matrixPermintaan;
Matrix matrixPertemanan;
/* *** Kreator *** */
void newRequest(Request *req, Pengguna sender, int BanyakTeman)
{
    req->BanyakTeman = BanyakTeman;
    req->sender = sender;
}

void MakeEmptyFriendReq(PriorityQueueFriendRequest *pq)
{
    pq->idxHead = IDX_TIDAK_TERDEFIINISI;
    pq->idxTail = IDX_TIDAK_TERDEFIINISI;
}

boolean isEmptyFriendReq(PriorityQueueFriendRequest *pq)
{
    return pq->idxTail == IDX_TIDAK_TERDEFIINISI;
}

boolean isFullFriendReq(PriorityQueueFriendRequest *pq)
{
    return ((pq->idxTail + 1) % 20) == pq->idxHead;
}

int lengthFriendReq(PriorityQueueFriendRequest *pq)
{
    if (isEmptyFriendReq(pq))
    {
        return 0;
    }
    else
    {
        return ((pq->idxTail - pq->idxHead + (2 * MAX_PEOPLE)) % MAX_PEOPLE) + 1;
    }
}

void enqueueFriendReq(PriorityQueueFriendRequest *pq, Request req)
{
    if (isFullFriendReq(pq))
    {
        printf("Loh loh loh kok pq nya full ya...? Coba configsnya dicek lagi :)\n");
    }
    else if (isEmptyFriendReq(pq))
    {
        pq->buffer[0] = req;
        pq->idxHead = 0;
        pq->idxTail = 0;
    }
    else
    {
        int i = pq->idxTail;
        boolean bigger = pq->buffer[i].BanyakTeman < req.BanyakTeman;
        while (i != pq->idxHead && bigger)
        {
            if (pq->buffer[i].BanyakTeman > req.BanyakTeman)
            {
                bigger = false;
            }
            else
            {
                pq->buffer[(i + 1) % MAX_PEOPLE] = pq->buffer[i];
                --i;
                i = (i + MAX_PEOPLE) % MAX_PEOPLE;
            }
        }

        bigger = pq->buffer[i].BanyakTeman < req.BanyakTeman;
        if (bigger)
        {
            pq->buffer[(i + 1) % MAX_PEOPLE] = pq->buffer[i];
            pq->buffer[i] = req;
        }
        else
        {
            pq->buffer[(i + 1) % MAX_PEOPLE] = req;
        }

        pq->idxTail = (pq->idxTail + 1) % MAX_PEOPLE;
    }
}

void dequeueFriendReq(PriorityQueueFriendRequest *pq, Request *req)
{
    *req = pq->buffer[(pq->idxHead)];
    if (pq->idxHead == pq->idxTail)
    {
        MakeEmptyFriendReq(pq);
    }
    else
    {
        pq->idxHead = (pq->idxHead + 1) % MAX_PEOPLE;
    }
}

void initializeFriendRequests()
{
    int i;
    dataFriendRequest.NEff = banyakPengguna;

    for (i = 0; i < MAX_PEOPLE; i++)
    {
        MakeEmptyFriendReq(&dataFriendRequest.buffer[i]);
    }

    for (i = 0; i < ROW_EFF(matrixPermintaan); i++)
    {
        int id_pengguna = ELMT(matrixPermintaan, i, 0);
        int id_pengirim = ELMT(matrixPermintaan, i, 1);

        Request req;
        newRequest(&req, dataPengguna.contents[id_pengirim], ELMT(matrixPermintaan, i, 2));
        enqueueFriendReq(&dataFriendRequest.buffer[id_pengguna], req);
    }
}