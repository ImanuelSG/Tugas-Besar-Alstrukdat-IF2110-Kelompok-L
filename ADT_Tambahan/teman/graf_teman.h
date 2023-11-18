/* ADT Graf dengan Etype Pengguna */
/* Implementasi matriks pertemanan dengan graf */

#ifndef GRAF_TEMAN_H 
#define GRAF_TEMAN_H 

#include "../Pengguna/pengguna.h"
#include "../Globals/globalvar.h"

#define MAKS_PENGGUNA 20

typedef Pengguna Vertex;
// IMPORTANT: VERTEX DI SINI ADALAH SAMA DENGAN PENGGUNA!!!
// (keduanya bisa dipertukarkan)

typedef struct {
    Vertex vertex1;
    Vertex vertex2;
} Edge;

typedef struct {
    Pengguna penerima;
    Pengguna pengirim;
    int BanyaknyaTeman;
} Request;

typedef struct {

    int NEffVertex;
    Vertex ListVertex[MAKS_PENGGUNA];

    int NEffEdges;
    Edge ListOfEdges[MAKS_PENGGUNA * MAKS_PENGGUNA];

    int NEffFriendRequests;
    Request ListOfFriendRequests[MAKS_PENGGUNA * MAKS_PENGGUNA]; // Edges that have not yet been added; Awaiting accept friend.

} GrafTeman;



extern GrafTeman dataTeman;

// tes
void displayGraf();

/* Konstruktor */
void CreateEdge(Edge* E, Pengguna v1, Pengguna v2);
void CreateGrafTeman(GrafTeman* G); // Graf yang dibuat sudah diisi data dari variabel global;

/* Setters Getters */
Request CreateRequest(Pengguna v1, Pengguna v2, int BanyakTeman);
void TambahPenggunaGraf(GrafTeman* G, Pengguna V);                         // Add vertex
void TambahPertemanan(GrafTeman* G, Pengguna v1, Pengguna v2);        // Add Edge
void HapusPertemanan(GrafTeman* G, Pengguna v1, Pengguna v2);         // Remove Edge

/* Boolean function */
boolean isTeman(GrafTeman* G, Pengguna user1, Pengguna user2); // sama dengan adjacent(G, x, y)

void SendFriendRequest(GrafTeman* G, Request R);        // Add Friend Request Edge
void AcceptFriendRequest(GrafTeman* G, Request R);      // Approve friend request
// this will add the requested friend request as an actual edge to the graph

int BanyakTeman(GrafTeman* G, Pengguna user);                                         // Amount of Edges
Request* ListOfFriendRequests(GrafTeman* G, Pengguna user);


/* Procedures */
void DisplayTeman(GrafTeman* G, Pengguna user);
void DisplayFriendRequests(GrafTeman* G, Pengguna user);


/* main.c Commands*/
void DAFTAR_TEMAN();
void HAPUS_TEMAN();
void TAMBAH_TEMAN();
void DAFTAR_PERMINTAAN_PERTEMANAN();
void SETUJUI_PERTEMANAN();

#endif