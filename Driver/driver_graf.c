#include "graf_teman.h"
#include "../Pengguna/pengguna.h"
#include <stdio.h>
#include "../Globals/globalvar.h"
void displayGrafStuff() {

    printf("%d %d %d", dataTeman.NEffVertex, dataTeman.NEffEdges, dataTeman.NEffFriendRequests);
    if (dataTeman.NEffVertex != 0) {
        printf("\n");
        displayWord(dataTeman.ListVertex[0].nama);
        printf("\n");
    }

    displayWord(currentPengguna.nama);
    if (isLoggedIn) {
        printf("w");
        printf("Banyak teman dari "); displayWord(currentPengguna.nama); printf(": %d", BanyakTeman(&dataTeman, currentPengguna));
        if (isTeman(&dataTeman, dataTeman.ListVertex[0], dataTeman.ListVertex[0])) {
            // actually gk ngaruh;
        }
        else {
            printf("Bruh");
        }
        // int a = BanyakTeman(&dataTeman ,currentPengguna);
    }
}