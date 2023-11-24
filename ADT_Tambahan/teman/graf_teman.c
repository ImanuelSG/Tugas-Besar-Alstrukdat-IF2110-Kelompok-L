#include "graf_teman.h"
#include "../utils/utils.h"
#include "../Globals/globalvar.h"
#include "../Pengguna/liststatikpengguna.h"
#include "../../ADT_Bawaan/matrix/matrix.h"

#include <stdio.h>
#define newline printf("\n")
// aku benci syntax printf scanf

ListOfPriorityQueueFriendRequests dataFriendRequest;
GrafTeman dataTeman;

/* Konstruktor */
void CreateEdge(Edge *E, Pengguna v1, Pengguna v2)
{
    E->vertex1 = v1;
    E->vertex2 = v2;
}
void TambahPenggunaGraf(GrafTeman *G, Pengguna V)
{
    G->ListVertex[G->NEffVertex] = V;
    ++G->NEffVertex;
    TambahPertemanan(G, V, V);
}

void TambahPertemanan(GrafTeman *G, Pengguna v1, Pengguna v2)
{

    Edge E;
    CreateEdge(&E, v1, v2);

    G->ListOfEdges[G->NEffEdges] = E;
    ++G->NEffEdges;
}
void CreateGrafTeman(GrafTeman *G)
{
    G->NEffVertex = 0;
    G->NEffEdges = 0;

    int i;
    for (i = 0; i < banyakPengguna; i++)
    {
        TambahPenggunaGraf(G, dataPengguna.contents[i]);
    }

    int j;
    for (i = 0; i < banyakPengguna; i++)
    {
        for (j = 0; j < banyakPengguna; j++)
        {
            if (ELMT(matrixPertemanan, i, j))
            {
                if (!isTeman(G, dataPengguna.contents[i], dataPengguna.contents[j]))
                {
                    TambahPertemanan(G, dataPengguna.contents[i], dataPengguna.contents[j]);
                }
            }
        }
    }
}

/* Setters Getters */
void HapusPertemanan(GrafTeman *G, Pengguna v1, Pengguna v2)
{

    boolean found = false;
    int i = 0;

    while ((!found) && (i < G->NEffEdges))
    {

        Word search1 = (G->ListOfEdges[i].vertex1.nama);
        Word search2 = (G->ListOfEdges[i].vertex2.nama);

        Word name1 = (v1.nama);
        Word name2 = (v2.nama);

        if ((isSameWord(name1, search1) && isSameWord(name2, search2)) || (isSameWord(name2, search1) && isSameWord(search2, name1)))
        {
            found = true;
        }
        else
        {
            ++i;
        }
    }

    do
    {
        G->ListOfEdges[i] = G->ListOfEdges[i + 1];
        i++;
    } while (i < G->NEffEdges);

    --G->NEffEdges;
}

void SendFriendRequest(ListOfPriorityQueueFriendRequests *listpq, int id_penerima, Request req)
{
    enqueueFriendReq(&listpq->buffer[id_penerima], req);
}

void AcceptFriendRequest(ListOfPriorityQueueFriendRequests *listpq, int id_penerima, GrafTeman *G)
{

    Request req;
    dequeueFriendReq(&listpq->buffer[id_penerima], &req);

    Pengguna user1 = dataPengguna.contents[id_penerima];
    Pengguna user2 = (req.sender);

    TambahPertemanan(G, user1, user2);

} // Approve friend request

int BanyakTeman(GrafTeman *G, Pengguna user)
{
    int count = 0;
    int i;

    for (i = 0; i < G->NEffVertex; i++)
    {
        if (isTeman(G, G->ListVertex[i], user) && !isSameWord(user.nama, G->ListVertex[i].nama))
        {
            ++count;
        }
    }

    return count;
}

/* Boolean functions */
boolean isTeman(GrafTeman *G, Pengguna user1, Pengguna user2)
{

    // printf("pls ini apansi??");

    int i = 0;
    boolean found = false;
    while (!found && (i < G->NEffEdges))
    {

        int id1 = getIdPengguna(user1.nama);
        int id2 = getIdPengguna(user2.nama);

        int id_search1 = getIdPengguna(G->ListOfEdges[i].vertex1.nama);
        int id_search2 = getIdPengguna(G->ListOfEdges[i].vertex2.nama);

        if ((id1 == id_search1 && id2 == id_search2) || (id1 == id_search2 && id2 == id_search1))
        {
            found = true;
        }
        else
        {
            ++i;
        }
    }

    return found;
}

int amountOfFriendRquests(ListOfPriorityQueueFriendRequests *listpq, Pengguna user)
{
    int id_pengguna = getIdPengguna(user.nama);
    return lengthFriendReq(&listpq->buffer[id_pengguna]);
}

/* Procedures */
void DisplayTeman(GrafTeman *G, Pengguna user)
{

    int i;
    int banyak_teman_orang_ini = BanyakTeman(G, user);

    displayWord(user.nama);
    printf(" memiliki %d teman.", banyak_teman_orang_ini);
    newline;
    printf("Daftar teman ");
    displayWord(user.nama);
    newline;

    for (i = 0; i < G->NEffVertex; i++)
    {

        if ((isTeman(G, G->ListVertex[i], user)) && !isSameWord(G->ListVertex[i].nama, currentPengguna.nama))
        {
            
            printf("| ");
            displayWord(G->ListVertex[i].nama);
            newline;
        }
    }
}

void UpdateMatrixPertemanan(GrafTeman *G, ListOfPriorityQueueFriendRequests *listpq, Matrix *pertemanan, Matrix *friendReq)
{
    int i;
    createMatrix(G->NEffVertex, G->NEffVertex, pertemanan);
    for (i = 0; i < (G->NEffEdges); i++)
    {
        int idx1 = getIdPengguna(G->ListOfEdges[i].vertex1.nama);
        int idx2 = getIdPengguna(G->ListOfEdges[i].vertex2.nama);
        ELMT(*pertemanan, idx1, idx2) = 1;
        ELMT(*pertemanan, idx2, idx1) = 1;
    }

    Request req;
    int row = 0;
    for (i = 0; i < 20; i++)
    {
        while (!isEmptyFriendReq(&listpq->buffer[i]))
        {
            dequeueFriendReq(&listpq->buffer[i], &req);
            ELMT(*friendReq, row, 0) = i;
            ELMT(*friendReq, row, 1) = getIdPengguna(req.sender.nama);
            ELMT(*friendReq, row, 2) = req.BanyakTeman;
        }
    }
}

/*
 * COMMANDS
 */

void DAFTAR_TEMAN()
{
    if (BanyakTeman(&dataTeman, currentPengguna) == 0)
    {
        displayWord(currentPengguna.nama);
        printf(" belum mempunyai teman.");
        newline;
    }
    else
    {
        DisplayTeman(&dataTeman, currentPengguna);
        newline;
    }
}

void HAPUS_TEMAN()
{

    if (BanyakTeman(&dataTeman, currentPengguna) == 0)
    {
        printf("Anda belum berteman!\n");
    }

    else
    {

        printf("Masukkan nama pengguna: ");
        STARTWORD();
        Word query_user = currentWord;
        if (isSameWord(query_user, currentPengguna.nama))
        {
            printf("Anda tidak bisa menghapus diri sendiri... Silakan masukkan pengguna lain.");
            newline;
        }
        else if (getIdPengguna(query_user) == -1)
        {
            printf("Tidak ditemukan pengguna dengan nama ");
            displayWord(query_user);
        }

        else if (isTeman(&dataTeman, *getPengguna(query_user), currentPengguna))
        {

            boolean correct_input = false;
            do
            {
                printf("Apakah anda yakin ingin menghapus ");
                displayWord(query_user);
                printf(" dari daftar teman anda?(YA/TIDAK): ");
                STARTWORD();

                if (isSameWord(currentWord, stringToWord("YA", 2)))
                {
                    correct_input = true;
                    HapusPertemanan(&dataTeman, *getPengguna(query_user), currentPengguna);
                    displayWord(query_user);
                    printf(" telah berhasil dihapus dari daftar pertemanan Anda.\n");
                }

                else if (isSameWord(currentWord, stringToWord("TIDAK", 5)))
                {
                    correct_input = true;
                    printf("Penghapusan teman dibatalkan.\n");
                }

                else
                {
                    printf("Input tidak dikenali. Perhatikan lagi instruksi input yang diberikan");
                    newline;
                    newline;
                }

            } while (!correct_input);
        }

        else
        {
            displayWord(query_user);
            printf(" bukan teman Anda");
            newline;
        }
    }
}

void TAMBAH_TEMAN()
{

    Word query_user;
    Request R;
    int id_pengirim = getIdPengguna(currentPengguna.nama);

    int kasus;
    if (amountOfFriendRquests(&dataFriendRequest, currentPengguna) != 0)
    {
        kasus = 1;
    }

    else
    {

        printf("Masukkan nama pengguna: ");
        STARTWORD();
        query_user = currentWord;
        newRequest(&R, currentPengguna, BanyakTeman(&dataTeman, currentPengguna));

        if (getIdPengguna(query_user) == -1)
        {
            kasus = 2;
        }

        else if (isSameWord(query_user, currentPengguna.nama))
        {
            kasus = 6;
        }

        else if (isTeman(&dataTeman, *getPengguna(query_user), currentPengguna))
        {
            kasus = 3;
        }

        else
        {

            boolean udah_ngirim = false;
            int id_penerima = getIdPengguna(query_user);
            int i = dataFriendRequest.buffer[id_penerima].idxHead;

            if (i == IDX_TIDAK_TERDEFIINISI)
            {
                printf("Yay!\n");
            }
            else
            {
                printf("id = %d\n", id_penerima);
                printf("i = %d\n", i);
            }

            while ((!udah_ngirim) && (i != dataFriendRequest.buffer[id_penerima].idxTail))
            {

                int search_id_pengirim = getIdPengguna(dataFriendRequest.buffer[id_penerima].buffer[i].sender.nama);

                if ((id_pengirim == search_id_pengirim))
                {
                    udah_ngirim = true;
                }
                else
                {
                    ++i;
                    i = i % MAX_PEOPLE;
                    printf("%d", i);
                }
            }

            if (udah_ngirim)
            {
                kasus = 4;
            }
            else
            {
                kasus = 5;
            }
        }
    }

    if (kasus == 1)
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
    }
    else if (kasus == 2)
    {
        printf("Pengguna bernama ");
        displayWord(currentWord);
        printf(" tidak ditemukan.");
    }
    else if (kasus == 3)
    {
        printf("Anda sudah berteman dengan ");
        displayWord(currentWord);
    }
    else if (kasus == 4)
    {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayWord(query_user);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.");
        newline;
    }
    else if (kasus == 5)
    {
        printf("Woi ah apesi!\n");
        printf("%d", R.BanyakTeman);
        newline;
        displayWord(R.sender.nama);
        newline;
        printf("%d", getIdPengguna(query_user));
        newline;
        SendFriendRequest(&dataFriendRequest, getIdPengguna(query_user), R);
        printf("Permintaan pertemanan kepada ");
        displayWord(query_user);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
    }
    else if (kasus == 6)
    {
        printf("Anda tidak bisa berteman dengan diri sendiri... Silakan cari teman yang merupakan pengguna lain.\n.");
    }
}

void DAFTAR_PERMINTAAN_PERTEMANAN()
{
    int id = getIdPengguna(currentPengguna.nama);
    int i;

    if (isEmptyFriendReq(&dataFriendRequest.buffer[id]))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }

    else
    {
        int banyak_teman_ini_orang = lengthFriendReq(&dataFriendRequest.buffer[id]);
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", banyak_teman_ini_orang);
        for (i = 0; i < banyak_teman_ini_orang; i++)
        {
            Request req = dataFriendRequest.buffer[id].buffer[(dataFriendRequest.buffer[id].idxHead + i) % MAX_PEOPLE];
            printf("| ");
            displayWord(req.sender.nama);
            newline;
            printf("| Jumlah teman: %d", req.BanyakTeman);
            newline;
        }
    }
}

void SETUJUI_PERTEMANAN()
{

    int id = getIdPengguna(currentPengguna.nama);
    printf("%d", lengthFriendReq(&dataFriendRequest.buffer[id]));

    if (lengthFriendReq(&dataFriendRequest.buffer[id]) == 0)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.");
    }

    else
    {

        Request req = dataFriendRequest.buffer[id].buffer[dataFriendRequest.buffer[id].idxHead];

        printf("Permintaan pertemanan teratas dari ");
        displayWord(req.sender.nama);
        newline;

        printf("| ");
        displayWord(req.sender.nama);
        newline;

        printf("| Jumlah teman: %d", req.BanyakTeman);
        newline;

        boolean correct_input = false;
        do
        {
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
            STARTWORD();

            if (isSameWord(currentWord, stringToWord("YA", 2)))
            {
                correct_input = true;
                AcceptFriendRequest(&dataFriendRequest, getIdPengguna(currentPengguna.nama), &dataTeman);

                printf("Permintaan pertemanan dari ");
                displayWord(req.sender.nama);
                printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
                displayWord(req.sender.nama);
            }

            else if (isSameWord(currentWord, stringToWord("TIDAK", 5)))
            {
                correct_input = true;
                AcceptFriendRequest(&dataFriendRequest, getIdPengguna(currentPengguna.nama), &dataTeman);
                HapusPertemanan(&dataTeman, currentPengguna, req.sender);

                printf("Permintaan pertemanan dari ");
                displayWord(req.sender.nama);
                printf(" telah ditolak.");
            }

            else
            {
                printf("Input tidak dikenali.");
                newline;
                newline;
            }

        } while (!correct_input);
    }
}
