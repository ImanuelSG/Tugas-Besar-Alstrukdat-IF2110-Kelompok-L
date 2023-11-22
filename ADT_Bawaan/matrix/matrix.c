#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return ((i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}

ElTypeMatrix getElmtDiagonal(Matrix m, IdxType i) {
/* Mengirimkan elemen m(i,i) */
    return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
/* Melakukan assignment mOut <- mIn */
    int i, j;

    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    
    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    int i, j;

    createMatrix(nRow, nCol, m);

    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix mhasil;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mhasil);

    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(mhasil, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return mhasil;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix mhasil;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mhasil);

    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(mhasil, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return mhasil;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix mhasil;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mhasil);

    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            
            ElTypeMatrix hasilkali = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                hasilkali += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            
            ELMT(mhasil, i, j) = hasilkali;
        }
    }

    return mhasil;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
    Matrix mhasil;
    int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mhasil);
    mhasil = multiplyMatrix(m1, m2);

    for (i = 0; i < ROW_EFF(mhasil); i++) {
        for (j = 0; j < COL_EFF(mhasil); j++) {
            ELMT(mhasil, i, j) %= mod;
        }
    }

    return mhasil;
}

Matrix multiplyByConst(Matrix m, ElTypeMatrix x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    int i, j;
    Matrix mhasil;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);

    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(mhasil, i, j) = ELMT(m, i, j) * x;
        }
    }
    return mhasil;
}

void pMultiplyByConst(Matrix *m, ElTypeMatrix k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    int i, j;
    boolean equal = true;

    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))) {
        equal = false;
    } else {
        for (i = 0; i < ROW_EFF(m1); i++) {
            for (j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                    equal = false;
                    break;
                }
            }
        }
    }
    return equal;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    int i, j;
    boolean symmetric = true;

    if (!isSquare(m)) {
        symmetric = false;
    } else {
        for (i = 0; i < ROW_EFF(m); i++) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (ELMT(m, i, j) != ELMT(m, j, i)) {
                    symmetric = false;
                    break;
                }
            }
        }
    }
    return symmetric;
}

boolean isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    int i, j;
    boolean identity = true;

    if (!isSquare(m)) {
        identity = false;
    } else {
        for (i = 0; i < ROW_EFF(m); i++) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (i == j) {
                    if (ELMT(m, i, j) != 1) {
                        identity = false;
                        break;
                    }
                } else {
                    if (ELMT(m, i, j) != 0) {
                        identity = false;
                        break;
                    }
                }
            }
        }
    }
    return identity;
}

boolean isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    float not0 = 0;
    float persen;
    int i, j;

    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                not0++;
            }
        }
    }
    persen = (not0/countElmt(m)) * 100;

    if (persen > 5) {
        return false;
    } else {
        return true;
    }
}

Matrix negation(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    return (multiplyByConst(m, -1));
}

void pNegation(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    pMultiplyByConst(m, -1);
}

Matrix minor(Matrix m, int i, int j) {
/* Prekondisi: isSquare(m) */
/* Menghasilkan minor m(i,j) */
    Matrix temp;
    int k, l;
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &temp);

    // Sebelum baris yang akan dihapus
    for (k = 0; k < i; k++) {
        // sebelum kolom yang akan di hapus
        for (l = 0; l < j; l++) {
            ELMT(temp, k, l) = ELMT(m, k, l);
        }
        // Setelah kolom yang akan dihapus 
        for (l = j + 1; l < COL_EFF(m); l++) {
            ELMT(temp, k, l - 1) = ELMT(m, k, l);
        }
    }
    // Setelah baris yang akan dihapus
    for (k = i + 1; k < ROW_EFF(m); k++) {
        // sebelum kolom yang akan di hapus
        for (l = 0; l < j; l++) {
            ELMT(temp, k - 1, l) = ELMT(m, k, l);
        }
        // Setelah kolom yang akan dihapus
        for (l = j + 1; l < COL_EFF(m); l++) {
            ELMT(temp, k - 1, l - 1) = ELMT(m, k, l);
        }
    }

    return temp;
}


Matrix transpose(Matrix m) {
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix mhasil;
    int i, j;

    createMatrix(COL_EFF(m), ROW_EFF(m), &mhasil);
    for (i = 0; i < COL_EFF(m); i++) {
        for (j = 0; j < ROW_EFF(m); j++) {
            ELMT(mhasil, i, j) = ELMT(m, j, i);
        }
    }
    return mhasil;
}

void pTranspose(Matrix *m) {
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    copyMatrix(transpose(*m), m);
}

boolean isSegitigaBawah (Matrix m) {
/* Mengirimkan true jika m adalah matriks segitiga bawah */
    int i = 0;
    int j = i+1;
    boolean reset = false;
    boolean notsegbawah= false;

    while (!(i == getLastIdxRow (m) && j >getLastIdxCol(m))  && notsegbawah==false) {
        if (ELMT(m,i,j) != 0){
            notsegbawah = true;
        }
        
        if (j == getLastIdxCol(m) & i!= getLastIdxRow (m)){
            i ++ ;
            j = i+1;
        } else{
            j++;
        }

    }

    return (!notsegbawah);
}