#include "Command_Utas.h"

//BERHUBUNGAN GLOBAL

void UTAS(ID IDKicau){
    //Membuat utas dengan index ke-0 nya kicauan utama (buat node baru)
    //setelah linked list listUtas terbuat, insert ke listdin listDinUtas
    if (!isIdxEffKicau(ListKicauanData, IDKicau)){
        //Kicauan dengan ID IDKicau tidak ditemukan di listKicauan
        printf("Kicauan tidak ditemukan\n");
    }
    else if (!isIDKicauValid(IDKicau)){
        //Kicauan dengan ID IDKicau tak dibuat oleh currentPengguna 
        printf("Utas ini bukan milik Anda!\n");
    }
    else if (isKicauanUtamaUtas(lDinUtas, IDKicau)){
        printf("Kicauan ini sudah pernah menjadi utas!\n");
    }
    else{
        Utas newUtas;
        ListUtas lUtas;
        int index = 0;
        IDUtas ++;
        Kicauan kicauanUtama = ELMT_LIST_KICAUAN(ListKicauanData, IDKicau);

        printf("Utas berhasil dibuat!\n"); printf("\n");
        createKicauanUtas(&newUtas, IDUtas, IDKicau, currentPengguna.nama, WAKTU_KICAUAN(kicauanUtama), TWEET(kicauanUtama));
        CreateListUtas(&lUtas); //membuat lUtas kosong
        insertFirstUtas(&lUtas, newUtas); //memasukkan newUtas ke lUtas
        insertLastListDinUtas(&lDinUtas, lUtas); //memasukkan lUtas baru ke lDinUtas

        Utas sambunganUtas;
        index++;
        sambungKicauanUtas(sambunganUtas, IDUtas, index, lUtas);

        Word Ya;
        Ya.TabWord[0] = 'Y'; Ya.TabWord[1] = 'A';
        Ya.Length = 2;
        Word confirmSambung;
        do
        {
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) \n");
            STARTKalimat();
            confirmSambung = currentWord;
            if (isSameWord(confirmSambung,Ya)){
                Utas nextUtas;
                index++;
                sambungKicauanUtas(nextUtas, IDUtas, index, lUtas);
            }
        } while (isSameWord(confirmSambung,Ya));
    }
}

void SAMBUNG_UTAS(int IDUtas, int index){
    if (!isIDUtasValid(lDinUtas, IDUtas)){
        //Utas dengan IDUtas tidak ditemukan di LDinUtas
        printf("Utas tidak ditemukan!\n");
    }
    else if (!isUtasAuthorValid(lDinUtas, IDUtas, currentPengguna)){
        //Utas tidak dibuat oleh currentPengguna
        printf("Anda tidak bisa menyambung utas ini!\n");
    }
    else{
        ListUtas lUtas = getUtas(lDinUtas,IDUtas);
        if (index == 0){
            printf("Anda tidak bisa menyambung pada kicauan utama!\n");
        }
        else if (!isIndexUtasValid(lUtas, index)) { 
            //Utas dengan index tidak ditemukan di lUtas
            printf("Index terlalu tinggi!");
        }
        else{
            Utas sambunganUtas;
            sambungKicauanUtas(sambunganUtas, IDUtas, index, lUtas);
        }
    }
}

void HAPUS_UTAS(int IDUtas, int index){
    if (!isIDUtasValid(lDinUtas, IDUtas)){
        //Utas dengan IDUtas tidak ditemukan di LDinUtas
        printf("Utas tidak ditemukan!\n");
    }
    else if (!isUtasAuthorValid(lDinUtas, IDUtas, currentPengguna)){
        //Utas tidak dibuat oleh currentPengguna
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
    }
    else{
        ListUtas lUtas = getUtas(lDinUtas,IDUtas);
        if (index == 0){
            printf("Anda tidak bisa menghapus kicauan utama!\n");
        }
        else if (!isIndexUtasValid(lUtas, index)){
            printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        }
        else{
            Utas deleted;
            deleteAtUtas(&lUtas, index, &deleted);
            printf("Kicauan sambungan berhasil dihapus!\n");
        }
    }
}

void CETAK_UTAS(int IDUtas){
    if (!isIDUtasValid(lDinUtas, IDUtas)){
        //Utas dengan IDUtas tidak ditemukan di LDinUtas
        printf("Utas tidak ditemukan!\n");
    }
    else if (!isBertemanUtasAuthor(lDinUtas, IDUtas, currentPengguna)){
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
    }
    else{
        ListUtas lUtas = getUtas(lDinUtas,IDUtas);
        displayListUtas(lUtas);
    }
}