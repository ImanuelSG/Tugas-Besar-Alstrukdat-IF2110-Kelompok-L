#include "../ADT_Tambahan/Pengguna/pengguna.h"
#include "../ADT_Tambahan/Pengguna/liststatikpengguna.h"

int main()
{
    ListStatikPengguna dataPengguna;
    int banyakPengguna = 0;
    Pengguna akun;
    Word Nama, Sandi, Bio, Nomor, Weton;
    int TipeAkun;
    MatrixProfil profil;
    StackDraf Draf;

    Nama = stringToWord("Aldy", 4);
    Sandi = stringToWord("abcd", 4);
    Bio = stringToWord(" ", 0);
    Nomor = stringToWord("08123456789", 10);
    Weton = stringToWord("Pahing", 6);
    TipeAkun = 1;
    createProfilDefault(&profil);
    CreateStackDraf(&Draf);

    CreatePengguna(&akun, Nama, Sandi, Bio, Nomor, Weton, TipeAkun, profil, Draf);
    InsertPengguna(akun);

    printf("| Nama: ");
    displayWord(dataPengguna.contents[0].nama);
    printf("\n| Sandi: ");
    displayWord(dataPengguna.contents[0].sandi);
    printf("\n| Bio Akun: ");
    displayWord(dataPengguna.contents[0].bio);
    printf("\n| No HP: ");
    displayWord(dataPengguna.contents[0].nomor);
    printf("\n| Weton: ");
    displayWord(dataPengguna.contents[0].weton);
    printf("\n| Tipe Akun: ");
    printf(dataPengguna.contents[0].tipe_akun);
    printf("\n");

    return 0;
}