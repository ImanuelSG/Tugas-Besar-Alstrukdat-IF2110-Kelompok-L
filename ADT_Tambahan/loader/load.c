#include "load.h"

#include <stdio.h>

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
        StackDraf S;
        CreateStackDraf(&S);
        CreatePengguna(&pengguna, nama, password, bio, nomor, weton, tipeakun, profil, S);
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
    ADVBaris();
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

void ReadKicauanConfig(char namafile[])
{
    CreateListDinKicauan(&ListKicauanData, 100);
    int iteration, like;
    Kicauan kicau;
    Word Penulis, WaktuKicauan, Tweet;
    DATETIME Waktu;

    STARTBaris(namafile);

    iteration = wordToInteger(currentBaris);

    ADVBaris();

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris();
        Tweet = currentBaris;

        ADVBaris();

        like = wordToInteger(currentBaris);

        ADVBaris();
        Penulis = currentBaris;
        ADVBaris();
        Waktu = wordToDatetime(currentBaris);
        ADVBaris();

        CreateKicauan(&kicau, Penulis, Waktu, Tweet, like);
        insertLastKicau(&ListKicauanData, kicau);
    }
}

void ReadDrafConfig(char namafile[])
{
    int iteration, banyak;
    Word username, isi;
    DATETIME Date;
    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    ADVBaris(); // baris == "username"
    for (int i = 0; i < iteration; i++)
    {
        banyak = 0;
        int j = currentBaris.Length - 1;
        int pengkali = 1;
        while (currentBaris.TabWord[j] != ' ')
        {
            banyak += charToDigit(currentBaris.TabWord[j]) * pengkali;
            pengkali *= 10;
            j--;
            currentBaris.Length--;
        }
        currentBaris.Length--;
        username = currentBaris;
        Pengguna *curr = getPengguna(username);
        ADVBaris(); // baris == "isi"
        for (int k = 0; k < banyak; k++)
        {
            DrafKicau currdraf;
            isi = currentBaris;
            ADVBaris(); // baris == "tanggal"
            Date = wordToDatetime(currentBaris);
            ADVBaris(); // baris == "isi"
            CreateDraf(&currdraf, isi, Date);
            SimpanDraf(&curr->draf, currdraf);
        }
        ReverseStackDraf(&curr->draf);
    }
}

void ReadUtasConfig(char namafile[])
{
    int iteration, like;

    Word Penulis, WaktuKicauan, Tweet;
    DATETIME Waktu;

    STARTBaris(namafile); // curr baris == iteration

    iteration = wordToInteger(currentBaris);

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris(); // curr baris == "ID"
        ID IDKicauUtama = wordToInteger(currentBaris);
        ADVBaris(); // curr baris == jumlahUtas
        int jumlahUtas = wordToInteger(currentBaris);
        for (int i = 0; i < jumlahUtas; i++)
        {
            ADVBaris();
            Word Text = currentBaris;
            ADVBaris();
            Word Author = currentBaris;
            ADVBaris();
            DATETIME Waktu = wordToDatetime(currentBaris);
            /*Create Utas and insert it to the list*/
        }
    }
}

void parseId(Word w, int *idparent, int *idbalasan)
{
    int i = 0;
    int id = 0;
    int isneg = 1;
    while (w.TabWord[i] != ' ')
    {
        if (w.TabWord[i] == '-')
        {
            isneg = -1;
            i++;
        }
        else
        {
            id *= 10;
            id += charToDigit(w.TabWord[i]);
            i++;
        }
    }
    *idparent = id * isneg;
    int last = w.Length - 1;
    int num = 0;
    int pengkali = 1;
    while (w.TabWord[last] != ' ')
    {
        num += charToDigit(w.TabWord[last]) * pengkali;
        pengkali *= 10;
        last--;
    }
    *idbalasan = num;
}

void ReadBalasanConfig(char namafile[])
{
    int iteration;
    STARTBaris(namafile);
    iteration = wordToInteger(currentBaris);
    CreateListBalasan(&ListBalasanData, 100);
    JUMLAH_KICAUAN_DENGAN_BALASAN = iteration;

    for (int i = 0; i < iteration; i++)
    {
        ADVBaris(); // curr baris == "ID Kicau Utama"
        ID IDKicauUtama = wordToInteger(currentBaris);
        ADVBaris(); // curr baris == "jumlah balasan"
        int jumlahbalasan = wordToInteger(currentBaris);
        for (int j = 0; j < jumlahbalasan; j++)
        {
            ADVBaris();
            int idparent, idbalasan;
            parseId(currentBaris, &idparent, &idbalasan);

            ADVBaris();
            Word text = currentBaris;
            ADVBaris();
            Word Author = currentBaris;
            ADVBaris();
            DATETIME Waktu = wordToDatetime(currentBaris);
            Balasan B;
            Kicauan * K= &ELMT_LIST_KICAUAN(ListKicauanData, IDKicauUtama);
            
            CreateBalasan(&B, Author, Waktu, text, K);
            currentPengguna.nama = Author;
            
            
            
            if (idbalasan == -1)
            {
                insertChild(&ELMT_LIST_BALASAN(ListBalasanData, IDKicauUtama), B);
                PrintBalasan(ELMT_LIST_BALASAN(ListBalasanData, IDKicauUtama)->info_tree, 0);
            }
            else
            {
                Address P = searchTree(ELMT_LIST_BALASAN(ListBalasanData, IDKicauUtama), idparent);
                insertChild(&P, B);
            }
        }
    }
}

int isDirectoryExists(const char *path)
{
    struct stat info;
    if (stat(path, &info) != 0)
    {

        return 0;
    }

    return S_ISDIR(info.st_mode);
}

void WriteKicauanConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w"); // buka file

    if (file == NULL)
    {
        printf("Gagal Membuat File :(\n");
        return;
    }

    fprintf(file, "%d\n", NEFF_LIST_KICAUAN(ListKicauanData)); // ini buat iterasi
    // ini buat nulis data kicauan
    for (int i = 1; i <= NEFF_LIST_KICAUAN(ListKicauanData); i++)
    {
        Kicauan curr = ELMT_LIST_KICAUAN(ListKicauanData, i);
        fprintf(file, "%d\n", i);
        fprintf(file, "%s\n", wordToString(TWEET(curr)));
        fprintf(file, "%d\n", LIKE(curr));

        fprintf(file, "%s\n", wordToString(PENULIS_KICAUAN(curr)));
        fprintf(file, "%s\n", wordToString(datetimeToWord(WAKTU_KICAUAN(curr))));
    }

    fclose(file); // Close the file
}

void WritePenggunaConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", banyakPengguna);

    // Loop through the list and write each Pengguna's information
    for (int i = 0; i < banyakPengguna; i++)
    {
        fprintf(file, "%s\n", wordToString(dataPengguna[i].nama));
        fprintf(file, "%s\n", wordToString(dataPengguna[i].sandi));
        fprintf(file, "%s\n", wordToString(dataPengguna[i].bio));
        fprintf(file, "%s\n", wordToString(dataPengguna[i].nomor));
        fprintf(file, "%s\n", wordToString(dataPengguna[i].weton));

        // Determine the account type
        if (dataPengguna[i].tipe_akun == 0)
        {
            fprintf(file, "Publik\n");
        }
        else
        {
            fprintf(file, "Privat\n");
        }

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (k != 9)
                    fprintf(file, "%c ", dataPengguna[i].profil.mem[j][k].TabWord[0]);
                else

                    fprintf(file, "%c", dataPengguna[i].profil.mem[j][k].TabWord[0]);
            }
            fprintf(file, "\n");
        }
    }

    for (int i = 0; i < ROW_EFF(matrixPertemanan); i++)
    {
        for (int j = 0; j < COL_EFF(matrixPertemanan); j++)
        {
            if (j != COL_EFF(matrixPertemanan) - 1)
                fprintf(file, "%d ", ELMT(matrixPertemanan, i, j));
            else
                fprintf(file, "%d", ELMT(matrixPertemanan, i, j));
        }
        fprintf(file, "\n");
    }

    fprintf(file, "%d\n", ROW_EFF(matrixPermintaan)); // Write the number of permintaan

    // write matrixPermintaan
    for (int i = 0; i < ROW_EFF(matrixPermintaan); i++)
    {
        for (int j = 0; j < COL_EFF(matrixPermintaan); j++)
        {
            if (j != COL_EFF(matrixPermintaan) - 1)
                fprintf(file, "%d ", ELMT(matrixPermintaan, i, j));
            else
                fprintf(file, "%d", ELMT(matrixPermintaan, i, j));
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void WriteDrafConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w"); // Open the file for writing

    if (file == NULL)
    {
        printf("Gagal Membuat File.\n");
        return;
    }

    fprintf(file, "%d\n", BanyakPenggunaDenganDraf); // Write the number of Pengguna

    int i = 0;
    int j = 0;
    int temp = BanyakPenggunaDenganDraf;

    while (i < banyakPengguna && j < temp)
    {
        Pengguna Curr = dataPengguna[i];
        if (!isEmptyStackDraf(Curr.draf))
        {
            fprintf(file, "%s %d\n", wordToString(Curr.nama), lengthStackDraf(Curr.draf));
            j++;
            StackDraf Copy = CopyStackDraf(Curr.draf);
            while (!isEmptyStackDraf(Copy))
            {
                DrafKicau val;
                DeleteDraf(&Copy, &val);
                // isi draf
                fprintf(file, "%s\n", wordToString(ISI_DRAF(val)));

                // Write the timestamp of the DrafKicau
                fprintf(file, "%s\n", wordToString(datetimeToWord(WAKTU_DRAF(val))));
            }
        }
        i++;
    }
    BanyakPenggunaDenganDraf = temp;
    fclose(file); // Close the file
}