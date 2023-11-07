/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include <stdio.h>
/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */

/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    int i, j;
    for (i = 0; i < nRows; i++)
    {
        for (j = 0; j < nCols; j++)
        {
            ELMT(*m, i, j) = 0;
        }
    }
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    return ((i >= 0 && i <= 99) && (j >= 0 && j <= 99));
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    return ((ROW_EFF(m) - 1));
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m)
{
    return (COL_EFF(m) - 1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    return (i >= 0 && i <= getLastIdxRow(m) && j <= getLastIdxCol(m) && j >= 0);
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);
    int i, j;
    for (i = 0; i <= ROW_EFF(mIn) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(mIn) - 1; j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i <= nRow - 1; i++)
    {
        for (j = 0; j <= nCol - 1; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayMatrix(Matrix m)
{
    int i, j;
    for (i = 0; i <= ROW_EFF(m) - 1; i++)
    {
        for (j = 0; j <= ROW_EFF(m) - 1; j++)
        {
            if (j == COL_EFF(m) - 1)

            {
                printf("%d\n", ELMT(m, i, j));
            }
            else
            {
                printf("%d ", ELMT(m, i, j));
            }
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    int i, j;
    Matrix M3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &M3);
    for (i = 0; i <= ROW_EFF(m1) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(m1) - 1; j++)
        {
            ELMT(M3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return (M3);
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    int i, j;
    Matrix M3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &M3);
    for (i = 0; i <= ROW_EFF(m1) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(m1) - 1; j++)
        {
            ELMT(M3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return (M3);
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    int i, j, k;
    Matrix M3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &M3);
    for (i = 0; i <= ROW_EFF(m1) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(m2) - 1; j++)
        {
            for (k = 0; k <= COL_EFF(m1) - 1; k++)
            {

                ELMT(M3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return (M3);
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod)
{
    int i, j, k;
    Matrix M3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &M3);
    for (i = 0; i <= ROW_EFF(m1) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(m2) - 1; j++)
        {
            for (k = 0; k <= COL_EFF(m1) - 1; k++)
            {

                ELMT(M3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(M3, i, j) %= mod;
        }
    }
    return (M3);
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x)
{
    int i, j;
    Matrix M3;
    createMatrix(ROW_EFF(m), COL_EFF(m), &M3);
    for (i = 0; i <= ROW_EFF(m) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(m) - 1; j++)
        {
            ELMT(M3, i, j) = x * ELMT(m, i, j);
        }
    }
    return (M3);
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k)
{
    int i, j;
    for (i = 0; i <= ROW_EFF(*m) - 1; i++)
    {
        for (j = 0; j <= COL_EFF(*m) - 1; j++)
        {
            ELMT(*m, i, j) = k * ELMT(*m, i, j);
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    int i, j;
    i = 0;
    if (!(ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2)))
    {
        return false;
    }
    else
    {
        while (i <= ROW_EFF(m1) - 1)
        {
            j = 0;
            while (j <= COL_EFF(m1) - 1)
            {
                if (ELMT(m1, i, j) != ELMT(m2, i, j))
                {
                    return false;
                }
                j += 1;
            }
            i += 1;
        }
    }
    return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return (!isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    return ROW_EFF(m) * COL_EFF(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return (ROW_EFF(m) == COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m)
{
    int i = 0, j;
    if (!(isSquare(m)))
    {
        return false;
    }
    else
        while (i <= getLastIdxCol(m))
        {
            j = 0;
            while (j <= getLastIdxCol(m))
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    return false;
                }
                j += 1;
            }

            i += 1;
        }
    return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m)
{
    int i = 0, j;
    if (!(isSquare(m)))
    {
        return false;
    }
    else
        while (i <= getLastIdxCol(m))
        {
            j = 0;
            while (j <= getLastIdxCol(m))
            {
                if (i == j)
                {
                    if (ELMT(m, i, j) != 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (ELMT(m, i, j) != 0)
                    {
                        return false;
                    }
                }
                j += 1;
            }

            i += 1;
        }
    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m)
{
    int count = 0;
    int i, j;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return count <= (ROW_EFF(m) * COL_EFF(m) * 5 / 100);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m)
{
    return (multiplyByConst(m, -1));
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m)
{
    copyMatrix(negation(*m), m);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
Matrix submatrix(Matrix m, int idxbaris, int idxkolom, int size)

{
    Matrix m1;
    int i, j, tempi, tempj;
    createMatrix(size, size, &m1);
    tempi = 0;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        tempj = 0;
        for (j = 0; j <= getLastIdxCol(m); j++)
        {

            if (i != idxbaris && j != idxkolom)
            {

                ELMT(m1, tempi, tempj) = ELMT(m, i, j);
                tempj += 1;
            }
        }
        if (i != idxbaris)
        {
            tempi += 1;
        }
    }
    return m1;
}
float determinant(Matrix m)
{
    int i, j;
    float det;
    det = 0;
    if (ROW_EFF(m) == 2)
    {
        return (ELMT(m, 0, 0) * ELMT(m, 1, 1) - (ELMT(m, 0, 1) * ELMT(m, 1, 0)));
    }
    else
    {
        for (i = 0; i <= getLastIdxRow(m); i++)
        {
            if (i % 2 == 0)
            {
                det += ELMT(m, i, 0) * determinant(submatrix(m, i, 0, getLastIdxRow(m)));
            }
            else
            {
                det -= ELMT(m, i, 0) * determinant(submatrix(m, i, 0, getLastIdxRow(m)));
            }
        }
    }
    return det;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m)
{
    Matrix m3;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
    int i, j;
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m); j++)
        {
            ELMT(m3, i, j) = ELMT(m, j, i);
        }
    }
    return m3;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m)
{
    copyMatrix(transpose(*m), m);
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

boolean isSegitigaBawah (Matrix m){
    int i = 0;
    int j = i+1;
    boolean reset = false;
    boolean notsegbawh= false;
    while (!(i == getLastIdxRow (m) && j >getLastIdxCol(m))  && notsegbawh==false){
        if (ELMT(m,i,j) != 0){
            notsegbawh = true;
        }
        if (j == getLastIdxCol(m) & i!= getLastIdxRow (m)){
            i ++ ;
            j = i+1;
        }
        else{
            j++;
        }

    }
    return (!notsegbawh);
}

#endif