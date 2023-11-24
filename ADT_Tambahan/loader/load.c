#include "load.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

void ReadPenggunaConfig(char namafile[])
{

    int iteration, tipeakun, jumlahpermintaan;
    Pengguna pengguna;
    Word nama, password, bio, nomor, weton, temp;
    MatrixProfil profil;
    banyakPengguna = 0;

    CreateListStatik(&dataPengguna);

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
        advMKarFile();
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

            for (int k = 0; k < 10; k++)
            {
                profil.mem[j][k].TabWord[0] = currentBaris.TabWord[k * 2];
                
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
    Word Penulis, Tweet;
    DATETIME Waktu;
    ID CURRENT_ID_KICAUAN = 0;
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
    BanyakPenggunaDenganDraf = 0;
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
    int iteration;

    CreateListDinUtas(&lDinUtas, 100);
    STARTBaris(namafile); // curr baris == iteration

    iteration = wordToInteger(currentBaris);
    IDUtas = 0;
    for (int i = 0; i < iteration; i++)
    {
        ADVBaris(); // curr baris == "ID"

        Utas newUtas;
        ListUtas lUtas;

        int index = 0;
        IDUtas++;

        ID IDKicauUtama = wordToInteger(currentBaris);
        Kicauan kicauanUtama = ELMT_LIST_KICAUAN(ListKicauanData, IDKicauUtama);
        createKicauanUtas(&newUtas, IDUtas, IDKicauUtama, PENULIS_KICAUAN(kicauanUtama), WAKTU_KICAUAN(kicauanUtama), TWEET(kicauanUtama));
        CreateListUtas(&lUtas);           // membuat lUtas kosong
        insertFirstUtas(&lUtas, newUtas); // memasukkan newUtas ke lUtas

        // memasukkan newUtas ke lUtas
        insertLastListDinUtas(&lDinUtas, lUtas); // memasukkan lUtas baru ke lDinUtas
        ADVBaris();                              // curr baris == jumlahUtas
        int jumlahUtas = wordToInteger(currentBaris);
        for (int i = 0; i < jumlahUtas; i++)
        {
            index++;
            ADVBaris();
            Word Text = currentBaris;
            ADVBaris();
            Word Author = currentBaris;
            ADVBaris();
            DATETIME Waktu = wordToDatetime(currentBaris);
            Utas nextUtas;
            createKicauanUtas(&nextUtas, IDUtas, -1, Author, Waktu, Text);
            // Print nextUtas
            insertAtUtas(&lUtas, nextUtas, index); // Insert nextUtas into lUtas
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
            Kicauan *K = &ELMT_LIST_KICAUAN(ListKicauanData, IDKicauUtama);
            //*ini untuk memastikan ID gasalah*//
            CURRENT_ID_BALASAN(*K) = idbalasan - 1;

            CreateBalasan(&B, Author, Waktu, text, K, idparent);

            if (idparent == -1)
            {
                insertSiblingLast(&ELMT_LIST_BALASAN(ListBalasanData, IDKicauUtama), B);
            }
            else
            {
                Address P = searchTree(ELMT_LIST_BALASAN(ListBalasanData, IDKicauUtama), idparent);
                insertChild(&P, B);
            }
        }
    }
}

int isDirectoryExists(char *path)
{
    struct stat info;

    if (stat(path, &info) != 0)
    {
        /*Akses Error*/
        return 0;
    }
    else if (S_ISDIR(info.st_mode))
    {
        /*Directory ada*/
        return 1;
    }
    else
    {
        /* Engga ada */
        return 0;
    }
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
        printf("Gagal Membuat File :(\n");
        return;
    }

    fprintf(file, "%d\n", banyakPengguna);

    // Loop through the list and write each Pengguna's information
    for (int i = 0; i < banyakPengguna; i++)
    {
        fprintf(file, "%s\n", wordToString(ELMTListStatik(dataPengguna, i).nama));
        fprintf(file, "%s\n", wordToString(ELMTListStatik(dataPengguna, i).sandi));
        fprintf(file, "%s\n", wordToString(ELMTListStatik(dataPengguna, i).bio));
        fprintf(file, "%s\n", wordToString(ELMTListStatik(dataPengguna, i).nomor));
        fprintf(file, "%s\n", wordToString(ELMTListStatik(dataPengguna, i).weton));

        // Determine the account type
        if (ELMTListStatik(dataPengguna, i).tipe_akun == 0)
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
                    fprintf(file, "%c ", ELMTListStatik(dataPengguna, i).profil.mem[j][k].TabWord[0]);
                else

                    fprintf(file, "%c", ELMTListStatik(dataPengguna, i).profil.mem[j][k].TabWord[0]);
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
        printf("Gagal Membuat File :(\n");
        return;
    }

    fprintf(file, "%d\n", BanyakPenggunaDenganDraf); // Write the number of Pengguna

    int i = 0;
    int j = 0;
    int temp = BanyakPenggunaDenganDraf;

    while (i < banyakPengguna && j < temp)
    {
        Pengguna Curr = ELMTListStatik(dataPengguna, i);

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

    fclose(file);
}

void WriteBalasanToFile(Tree p, FILE *file)
{
    if (p != NULL)
    {

        fprintf(file, "%d %d\n", ID_PARENT(INFO_TREE(p)), ID_BALASAN(INFO_TREE(p)));
        fprintf(file, "%s\n", wordToString(ISI_BALASAN(INFO_TREE(p))));
        fprintf(file, "%s\n", wordToString(PENULIS_BALASAN(INFO_TREE(p))));
        fprintf(file, "%s\n", wordToString(datetimeToWord(WAKTU_BALASAN(INFO_TREE(p)))));
        if (RIGHT_SIBLING(p) != NULL)
        {
            WriteBalasanToFile(RIGHT_SIBLING(p), file);
        }
        if (LEFT_CHILD(p) != NULL)
        {
            WriteBalasanToFile(LEFT_CHILD(p), file);
        }
    }
}

void WriteBalasanConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w"); // Open the file for writing
    int j = 1;
    if (file == NULL)
    {
        printf("Gagal Membuat File :(\n");
        return;
    }
    int count = JUMLAH_KICAUAN_DENGAN_BALASAN;

    fprintf(file, "%d\n", count); //
    j = 1;
    while (count > 0)
    {
        while (j < CAPACITY_LIST_BALASAN(ListBalasanData))
        {
            if (ELMT_LIST_BALASAN(ListBalasanData, j) != NULL)
            {
                fprintf(file, "%d\n", j);
                break;
            }
            else
            {
                j++;
            }
        }
        Tree P = ELMT_LIST_BALASAN(ListBalasanData, j);
        fprintf(file, "%d\n", countNodes(P));
        if (P != NULL)
        {
            WriteBalasanToFile(P, file);
        }
        count--;
        j++;
    }
    fclose(file);
}

void WriteUtasConfig(char namafile[])
{
    FILE *file = fopen(namafile, "w");

    if (file == NULL)
    {
        printf("Gagal Membuat File :(\n");
        return;
    }

    // Jumlah Utas
    fprintf(file, "%d\n", NEFF(lDinUtas));

    // Loop Sejumlah Utas
    for (int i = 0; i < NEFF(lDinUtas); i++)
    {

        ListUtas currentlist = ELMTUTAS(lDinUtas, i);
        fprintf(file, "%d\n", currentlist->info.IDKicau);
        fprintf(file, "%d\n", lengthListUtas(currentlist) - 1);
        for (int j = 1; j < lengthListUtas(currentlist); j++)
        {
            Utas currentelmtutas = getKicauanUtas(currentlist, j);
            fprintf(file, "%s\n", wordToString(TWEETUTAS(currentelmtutas)));
            fprintf(file, "%s\n", wordToString(PENULISUTAS(currentelmtutas)));
            fprintf(file, "%s\n", wordToString(datetimeToWord(WAKTUUTAS(currentelmtutas))));
        }
    }

    // Close the file
    fclose(file);
}

void SIMPAN(Word foldername)
{
    Word path_config1, path_config2, path_config3, path_config4, path_config5;

    path_config1 = DuplicateWord(foldername);
    path_config2 = DuplicateWord(foldername);
    path_config3 = DuplicateWord(foldername);
    path_config4 = DuplicateWord(foldername);
    path_config5 = DuplicateWord(foldername);

    appendWord(&path_config1, stringToWord("/pengguna.config", 16));
    appendWord(&path_config2, stringToWord("/kicauan.config", 15));
    appendWord(&path_config3, stringToWord("/balasan.config", 15));
    appendWord(&path_config4, stringToWord("/draf.config", 12));
    appendWord(&path_config5, stringToWord("/utas.config", 12));

    char *path_config1_str = wordToString(path_config1);
    char *path_config2_str = wordToString(path_config2);
    char *path_config3_str = wordToString(path_config3);
    char *path_config4_str = wordToString(path_config4);
    char *path_config5_str = wordToString(path_config5);
    char *stringfolder = wordToString(foldername);

    if (isDirectoryExists(stringfolder) == 0)
    {
        printf("Belum terdapat folder%s. Akan dilakukan pembuatan folder %s terlebih dahulu.\n", stringfolder, stringfolder);
        printf("Mohon tunggu...\n");
        for (int i = 1; i <= 3; i++)
        {

            printf("%d...\n", i);
        }
        createDirectory(stringfolder);
        printf("Folder %s sudah berhasil dibuat.\n", stringfolder);
    }

    printf("Anda akan melakukan penyimpanan di %s.\n", stringfolder);
    printf("Mohon tunggu...\n");

    // Simulating save process with a delay
    for (int i = 1; i <= 3; i++)
    {

        printf("%d...\n", i);
    }
    WritePenggunaConfig(path_config1_str);
    WriteKicauanConfig(path_config2_str);
    WriteBalasanConfig(path_config3_str);
    WriteDrafConfig(path_config4_str);
    WriteUtasConfig(path_config5_str);

    printf("Penyimpanan telah berhasil dilakukan!\n");
}

void createDirectory(const char *path)
{
#ifdef _WIN32
    if (_mkdir(path) == -1)
    {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }
#else
    if (mkdir(path, 0777) == -1)
    {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }
#endif
}

void MUAT(Word foldername)
{
    Word path_config1, path_config2, path_config3, path_config4, path_config5;

    path_config1 = DuplicateWord(foldername);
    path_config2 = DuplicateWord(foldername);
    path_config3 = DuplicateWord(foldername);
    path_config4 = DuplicateWord(foldername);
    path_config5 = DuplicateWord(foldername);

    appendWord(&path_config1, stringToWord("/pengguna.config", 16));
    appendWord(&path_config2, stringToWord("/kicauan.config", 15));
    appendWord(&path_config3, stringToWord("/balasan.config", 15));
    appendWord(&path_config4, stringToWord("/draf.config", 12));
    appendWord(&path_config5, stringToWord("/utas.config", 12));

    char *path_config1_str = wordToString(path_config1);
    char *path_config2_str = wordToString(path_config2);
    char *path_config3_str = wordToString(path_config3);
    char *path_config4_str = wordToString(path_config4);
    char *path_config5_str = wordToString(path_config5);

    printf("Anda akan melakukan pemuatan dari %s.\n", wordToString(foldername));
    printf("Mohon tunggu...\n");

    for (int i = 1; i <= 3; i++)
    {
        printf("%d...\n", i);
    }
    ReadPenggunaConfig(path_config1_str);
    ReadKicauanConfig(path_config2_str);
    ReadBalasanConfig(path_config3_str);
    ReadDrafConfig(path_config4_str);
    ReadUtasConfig(path_config5_str);
}
