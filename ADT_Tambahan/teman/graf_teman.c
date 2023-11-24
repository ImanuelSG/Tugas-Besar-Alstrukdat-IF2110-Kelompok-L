#include "graf_teman.h"
#include "../utils/utils.h"
#include "../Globals/globalvar.h"
#include "../Pengguna/liststatikpengguna.h"
#include "../../ADT_Bawaan/matrix/matrix.h"

#include <stdio.h>
#define newline printf("\n")
// aku benci syntax printf scanf

Matrix matrixPermintaan;
Matrix matrixPertemanan;
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
}
Request CreateRequest(Pengguna v1, Pengguna v2, int BanyakTeman)
{
    Request R;
    R.pengirim = v1;
    R.penerima = v2;
    R.BanyaknyaTeman = BanyakTeman;

    return R;
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
    G->NEffFriendRequests = 0;

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

    for (i = 0; i < ROW_EFF(matrixPermintaan); i++)
    {

        Pengguna v1 = dataPengguna.contents[ELMT(matrixPermintaan, i, 0)];
        Pengguna v2 = dataPengguna.contents[ELMT(matrixPermintaan, i, 1)];
        int BanyakTeman = ELMT(matrixPertemanan, i, 2);

        Request R = CreateRequest(v1, v2, BanyakTeman);

        SendFriendRequest(G, R);
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

void SendFriendRequest(GrafTeman *G, Request R)
{
    G->ListOfFriendRequests[G->NEffFriendRequests] = R;
    ++G->NEffFriendRequests;
}

void AcceptFriendRequest(GrafTeman *G, Request R)
{

    boolean found = false;
    int i = 0;

    while ((!found) && (i < G->NEffFriendRequests))
    {

        Word nama_pengirim = (R.pengirim.nama);
        Word nama_penerima = (R.penerima.nama);

        Word search_pengirim = (G->ListOfFriendRequests[i].pengirim.nama);
        Word search_penerima = (G->ListOfFriendRequests[i].penerima.nama);

        if (isSameWord(nama_pengirim, search_pengirim) && isSameWord(nama_penerima, search_penerima))
        {
            found = true;
        }
        else
        {
            ++i;
        }
    }

    if (!found)
    {
        printf("Something went wronG->.. there isn't a friend request with those details!\n");
    }

    TambahPertemanan(G, R.pengirim, R.penerima);

    while (i < G->NEffFriendRequests)
    {
        G->ListOfFriendRequests[i] = G->ListOfFriendRequests[i + 1];
        ++i;
    }

    --G->NEffFriendRequests;

} // Approve friend request

int BanyakTeman(GrafTeman *G, Pengguna user)
{
    int count = 0;
    int i;

    for (i = 0; i < G->NEffVertex; i++)
    {
        if (isTeman(G, G->ListVertex[i], user))
        {
            ++count;
        }
    }

    return count;

    return 0;
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
        // printf("id1 = %d\n", id1);
        // printf("id2 = %d\n", id2);

        int id_search1 = getIdPengguna(G->ListOfEdges[i].vertex1.nama);
        int id_search2 = getIdPengguna(G->ListOfEdges[i].vertex2.nama);
        // printf("id_search1 = %d\n", id_search1);
        // printf("id_search2 = %d\n", id_search2);
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
Request *SortedListOfFriendRequests(GrafTeman *G, Pengguna user)
{

    Request *requests;
    requests = (Request *)malloc(20 * (sizeof(Request)));
    int NEffRequests = 0;

    int i;
    for (i = 0; i < G->NEffFriendRequests; i++)
    {

        Word search = G->ListOfFriendRequests[i].penerima.nama;

        if (isSameWord(search, user.nama))
        {
            requests[NEffRequests] = G->ListOfFriendRequests[i];
            NEffRequests++;
        }
    }

    int j;

    for (i = 0; i < NEffRequests; i++)
    {
        for (j = i + 1; j < NEffRequests; j++)
        {
            if (requests[i].BanyaknyaTeman < requests[j].BanyaknyaTeman)
            {
                Request tmp = requests[j];
                requests[j] = requests[i];
                requests[i] = tmp;
            }
        }
    }

    return requests;
}

int amountOfFriendRquests(GrafTeman *G, Pengguna user)
{

    int amount = 0;
    int i;
    for (i = 0; i < G->NEffFriendRequests; i++)
    {

        int id = getIdPengguna(user.nama);
        int search_id = getIdPengguna(G->ListOfFriendRequests[i].penerima.nama);

        if (id == search_id)
        {

            amount++;
        }
    }

    return amount;
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
        if ((isTeman(G, G->ListVertex[i], user)))
        {
            printf("| ");
            displayWord(G->ListVertex[i].nama);
            newline;
        }
    }
}
void DisplayFriendRequests(GrafTeman *G, Pengguna user)
{

    int i;
    Request *requests = SortedListOfFriendRequests(G, user);
    int NEffRequests = amountOfFriendRquests(G, user);

    if (0 == NEffRequests)
    {
        printf("Tidak ada yang mau berteman dengan Anda! :(\n");
    }
    else
    {

        printf("Terdapat %d permintaan pertemanan untuk Anda.", NEffRequests);
        newline;

        for (i = 0; i < NEffRequests; i++)
        {

            printf("| ");
            displayWord(requests[i].pengirim.nama);
            newline;
            printf("| Jumlah teman: %d", requests[i].BanyaknyaTeman);
            newline;
        }
    }
}

void UpdateMatrixPertemanan(GrafTeman *G, Matrix pertemanan, Matrix friendReq)
{

    createMatrix(G->NEffVertex, G->NEffVertex, &matrixPertemanan);
    for (int i = 0; i < (G->NEffEdges); i++)
    {
        int idx1 = getIdPengguna(G->ListOfEdges[i].vertex1.nama);
        int idx2 = getIdPengguna(G->ListOfEdges[i].vertex2.nama);
        ELMT(matrixPertemanan, idx1, idx2) = 1;
        ELMT(matrixPertemanan, idx2, idx1) = 1;
    }

    int k;
    createMatrix(G->NEffFriendRequests, 3, &matrixPermintaan);
    for (k = 0; k < G->NEffFriendRequests; k++)
    {
        ELMT(matrixPermintaan, k, 0) = getIdPengguna(G->ListOfFriendRequests[k].penerima.nama);
        ELMT(matrixPermintaan, k, 1) = getIdPengguna(G->ListOfFriendRequests[k].penerima.nama);
        ELMT(matrixPermintaan, k, 2) = G->ListOfFriendRequests[k].BanyaknyaTeman;
    }
}

/*
 * COMMANDS
 */

void DAFTAR_TEMAN()
{
    if (isLoggedIn)
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
        }
    }
    else
    {
        printf("Anda belum melakukan login!");
        newline;
    }
}

void HAPUS_TEMAN()
{
    if (isLoggedIn)
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

            if (getIdPengguna(query_user) == -1)
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
                        printf("Input tidak dikenali.");
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
    else
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.");
        newline;
    }
}

void TAMBAH_TEMAN()
{

    int kasus;
    if (amountOfFriendRquests(&dataTeman, currentPengguna) != 0)
    {
        kasus = 1;
    }

    else
    {

        printf("Masukkan nama pengguna: ");
        STARTWORD();
        Word query_user = currentWord;

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

            Request R = CreateRequest(currentPengguna, *getPengguna(query_user), BanyakTeman(&dataTeman, currentPengguna));

            boolean udah_ngirim = false;
            int i = 0;

            while ((!udah_ngirim) && (i < dataTeman.NEffFriendRequests))
            {

                int id_pengirim = getIdPengguna(R.pengirim.nama);
                int id_penerima = getIdPengguna(R.penerima.nama);

                int search_id_pengirim = getIdPengguna(dataTeman.ListOfFriendRequests[i].pengirim.nama);
                int search_id_penerima = getIdPengguna(dataTeman.ListOfFriendRequests[i].penerima.nama);

                if ((id_pengirim == search_id_pengirim) && (id_penerima == search_id_penerima))
                {
                    udah_ngirim = true;
                }
                else
                {
                    ++i;
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
        printf("Anda sudah mengirimkan permintaan pertemanan kepada .");
        displayWord(currentWord);
        printf("Silakan tunggu hingga permintaan Anda disetujui.");
        newline;
    }
    else if (kasus == 5)
    {
        SendFriendRequest(&dataTeman, CreateRequest(currentPengguna, *getPengguna(currentWord), BanyakTeman(&dataTeman, currentPengguna)));
        printf("Permintaan pertemanan kepada ");
        displayWord(currentWord);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
    }
    else if (kasus == 6)
    {
        printf("Anda tidak bisa berteman dengan diri sendiri. Silakan cari teman yang merupakan pengguna lain.\n.");
    }
}

void DAFTAR_PERMINTAAN_PERTEMANAN()
{
    DisplayFriendRequests(&dataTeman, currentPengguna);
}

void SETUJUI_PERTEMANAN()
{

    Request *requests = SortedListOfFriendRequests(&dataTeman, currentPengguna);
    int NEffRequests = amountOfFriendRquests(&dataTeman, currentPengguna);

    if (NEffRequests == 0)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.");
    }

    else
    {

        printf("Permintaan pertemanan teratas dari ");
        displayWord(requests[0].pengirim.nama);
        newline;

        printf("| ");
        displayWord(requests[0].pengirim.nama);
        newline;

        printf("| Jumlah teman: %d", requests[0].BanyaknyaTeman);
        newline;

        boolean correct_input = false;
        do
        {
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
            STARTWORD();

            if (isSameWord(currentWord, stringToWord("YA", 2)))
            {
                correct_input = true;
                AcceptFriendRequest(&dataTeman, requests[0]);

                printf("Permintaan pertemanan dari ");
                displayWord(requests[0].pengirim.nama);
                printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
                displayWord(requests[0].pengirim.nama);
            }

            else if (isSameWord(currentWord, stringToWord("TIDAK", 5)))
            {
                correct_input = true;
                AcceptFriendRequest(&dataTeman, requests[0]);

                HapusPertemanan(&dataTeman, currentPengguna, requests[0].pengirim);
                printf("Permintaan pertemanan dari ");
                displayWord(requests[0].pengirim.nama);
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
