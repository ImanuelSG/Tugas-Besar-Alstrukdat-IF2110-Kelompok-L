#include "Command_Draf.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"

int main()
{
    Pengguna A;
    Word nama = stringToWord("Joko", 4);
    Word sandi = stringToWord("Jokosandi", 9);
    Word bio = stringToWord("Jokobio", 7);
    Word nomor = stringToWord("Jokonomor", 9);
    Word weton = stringToWord("PAHING", 6);
    int tipe_akun = 1;
    MatrixProfil profil;
    StackDraf draf;
    createProfilDefault(&profil);
    CreateStackDraf(&draf);
    CreateListDinKicauan(&ListKicauanData, 100);
    CreatePengguna(&A, nama, sandi, bio, nomor, weton, tipe_akun, profil, draf);

    BUAT_DRAF(&A.draf, A.nama);
    BUAT_DRAF(&A.draf, A.nama);
    BUAT_DRAF(&A.draf, A.nama);

    
    StackDraf copy = CopyStackDraf(A.draf);
    
    printf("Original Stack:\n");
    DisplayStackDraf(A.draf);

    printf("\nCopied Stack:\n");
    DisplayStackDraf(copy);
    return 0;
}