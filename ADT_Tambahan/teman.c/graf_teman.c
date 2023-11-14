#include "graf_teman.h"

/* Konstruktor */
void CreateEdge(Edge* E, Pengguna v1, Pengguna v2) {
    E->vertex1 = v1;
    E->vertex2 = v2;
}
void CreateGrafTeman(GrafTeman* G) {
    int i, j;

    // Data pengguna
    // G->jumlah_pengguna = banyakPengguna;
    // for (j = 0; j < banyakPengguna; j++) {
    //     G->ListPengguna[j] = dataPengguna[j];
    // }

    // // Data Pertemanan pengguna
    // for (i = 0; i < ROW_EFF(matrixPertemanan); i++) {
    //     for (j = 0; j < COL_EFF(matrixPertemanan); j++) {
    //         if (ELMT(matrixPertemanan, i, j) == 1) {
    //             // TAMBAH PERTEMANAN dataPengguna[i]
    //             // NEffEdges++
    //         }
    //     }
    // }

    // Data Friend Req.
    // ini belom
}

/* Setters Getters */
void TambahPengguna(GrafTeman* G, Pengguna* V) {

}
void HilangkanPengguna(GrafTeman* G, Pengguna* V);
void TambahPertemanan(GrafTeman* G, Pengguna* v1, Pengguna* v2);        
void HapusPertemanan(GrafTeman* G, Pengguna* v1, Pengguna* v2);         

void SendFriendRequest(GrafTeman* G, Pengguna* v1, Pengguna* v2);        // Add Friend Request Edge
void AcceptFriendRequest(GrafTeman* G, Pengguna* v1, Pengguna* v2);      // Approve friend request
// this will add the requested friend request as an actual edge to the graph
int BanyakTeman(Pengguna* user);                                         // Amount of Edges
int jumlahTemanYangSama(Pengguna* user1, Pengguna* user2);

/* Boolean functions */
boolean isTeman(Pengguna* user1, Pengguna* user2); // sama dengan adjacent(G, x, y)

/* Procedures */
void DisplayTeman(Pengguna* user);
void DisplayFriendRequests(Pengguna* user);