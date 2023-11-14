#include "../MesinBarisFile/MBarisFile.h"
#include "../Pengguna/pengguna.h"
#include "../wordoperations.h"
#include "../Profil/profil.h"
#include "../Globals/globalvar.h"

void ReadPenggunaConfig(char namafile[])
{

    int iteration, tipeakun, jumlahpermintaan;
    Pengguna pengguna;
    Word nama, password, bio, nomor, weton, temp;
    MatrixProfil profil;

    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    ADVBaris();
    createMatrix(iteration, iteration, &matrixPertemanan);

    for (int i = 0; i < iteration; i++)
    {
        /*Bagian Ngisi Pengguna*/
        nama = currentBaris;
        ADVBaris();
        password = currentBaris;
        ADVBaris();
        bio = currentBaris;
        ADVBaris();
        nomor = currentBaris;
        ADVBaris();
        weton = currentBaris;
        ADVBaris();
        temp = currentBaris;
        /*tipe akun*/
        if (isSameWord(temp, stringToWord("Publik", 6)))
        {
            tipeakun = 0;
        }
        else
        {
            tipeakun = 1;
        }
        for (int j = 0; j < 5; j++)
        {
            ADVBaris();
            int n = 0;
            for (int k = 0; k < 10; k++)
            {
                profil.mem[j][k].TabWord[0] = currentBaris.TabWord[k * 2];
                // To Place the index in the right position
            }
        }
        CreatePengguna(&pengguna, nama, password, bio, nomor, weton, tipeakun, profil);
        InsertPengguna(pengguna);
        ADVBaris();
    }
    for (int i = 0; i < iteration; i++)
    {
        for (int j = 0; j < iteration; j++)
        {
            ELMT(matrixPertemanan, i, j) = charToDigit(currentBaris.TabWord[j * 2]);
        }
        ADVBaris();
    }
    jumlahpermintaan = wordToInteger(currentBaris);
    createMatrix(jumlahpermintaan, 3, &matrixPermintaan);
    for (int i = 0; i < jumlahpermintaan; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ELMT(matrixPermintaan, i, j) = charToDigit(currentBaris.TabWord[j * 2]);
        }
        ADVBaris();
    }
}

int main()
{
    ReadPenggunaConfig("pengguna.config");
    for(int i = 0 ; i < banyakPengguna ; i++){
        printf("Nama : ");
        displayWord(dataPengguna[i].nama);
        printf("\n");
        printf("Sandi : ");
        displayWord(dataPengguna[i].sandi);
        printf("\n");
        printf("Bio : ");
        displayWord(dataPengguna[i].bio);
        printf("\n");
        printf("Nomor : ");
        displayWord(dataPengguna[i].nomor);
        printf("\n");
        printf("Weton : ");
        displayWord(dataPengguna[i].weton);
        printf("\n");
        printf("Tipe Akun : %d\n", dataPengguna[i].tipe_akun);
        printf("Profil : \n");
        displayProfil(dataPengguna[i].profil);
        printf("\n");
    }
    displayMatrix(matrixPertemanan);
    displayMatrix(matrixPermintaan);
    
}