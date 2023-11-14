/* ADT Graf dengan Etype Pengguna */

#ifndef GRAF_TEMAN_H 
#define GRAF_TEMAN_H 

#include "../Pengguna/pengguna.h"
#include "../Globals/globalvar.h"
#define MAKS_JUMLAH_TEMAN 100

typedef Pengguna Vertex;
// IMPORTANT: VERTEX DI SINI ADALAH SAMA DENGAN PENGGUNA!!!
// (keduanya bisa dipertukarkan)

typedef struct {
    Vertex vertex1;
    Vertex vertex2;
} Edge;

typedef struct {

    int jumlah_pengguna;
    Vertex ListPengguna[MAKS_JUMLAH_TEMAN];

    int NEffEdges;
    Edge ListOfEdges[MAKS_JUMLAH_TEMAN * MAKS_JUMLAH_TEMAN];

    int NEffFriendRequests;
    Edge ListOfFriendRequests[MAKS_JUMLAH_TEMAN * MAKS_JUMLAH_TEMAN]; // Edges that have not yet been added; Awaiting accept friend.

} GrafTeman;

/* Konstruktor */
void CreateEdge(Edge* E, Pengguna v1, Pengguna v2);
void CreateGrafTeman(GrafTeman* G); // Graf yang dibuat sudah diisi data dari variabel global;

/* Setters Getters */
void TambahPengguna(GrafTeman* G, Pengguna* V);                         // Add vertex
void HilangkanPengguna(GrafTeman* G, Pengguna* V);                      // Remove vertex
void TambahPertemanan(GrafTeman* G, Pengguna* v1, Pengguna* v2);        // Add Edge
void HapusPertemanan(GrafTeman* G, Pengguna* v1, Pengguna* v2);         // Remove Edge

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

#endif