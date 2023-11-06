/* File : word similarity.c */

#include "wordsimilarity.h"
#include "boolean.h"
#include <stdio.h>

int min3(int a, int b, int c) {
    if ((a <= b) && (a <=c)) {
        return a;
    }
    else if ((b <= a) && (b <= c)) {
        return b;
    }
    else {
        return c;
    }
}

Word tailOf(Word wIn) {
    Word wOut; 
    wOut.Length = wIn.Length - 1;

    if (wIn.Length != 1) {
        int i;
        for (i = 1; i < wIn.Length; i++) {
            wOut.TabWord[i-1] = wIn.TabWord[i];
        }
    }

    return wOut;
}


int CalculateLevenshteinDistance(Word w1, Word w2) {
    if (w1.Length == 0) {
        return w2.Length; // insert sisa dari w2
    }
    else if (w2.Length == 0) {
        return w1.Length; // insert sisa dari w1
    }
    else if (firstLetter(w1) == firstLetter(w2)) {
        return CalculateLevenshteinDistance(tailOf(w1), tailOf(w2));
    }

    else {
        return 1 + min3(
            CalculateLevenshteinDistance(tailOf(w1), w2), // delete head dari w1
            CalculateLevenshteinDistance(w1, tailOf(w2)), // delete head dari w2
            CalculateLevenshteinDistance(tailOf(w1), tailOf(w2)) // substitusi
        );
    }
} 

char firstLetter(Word w) {
    return w.TabWord[0];
}

void deleteChar(Word * w, char letter) {
    boolean flag = false;
    int idx;
    for (idx = 0; idx < (*w).Length; idx++) {
        if (((*w).TabWord[idx] == letter)) {
            flag = true;
        }
        if (flag) {
            (*w).TabWord[idx] = (*w).TabWord[idx+1];
        }
    }

    if (flag) {
        --(*w).Length;
    }
}
/* Deletes the input letter from w */
/* if letter doesn't exist, doesn't do anything */

boolean isAnagram(Word w1, Word w2) {
    if (w1.Length != w2.Length) {
        return false;
    }

    else if (w1.Length == 0) {
        return true;
    }

    else {
        char FL = firstLetter(w1);

        deleteChar(&w1, FL);
        deleteChar(&w2, FL);

        return isAnagram(w1, w2);
    }
}