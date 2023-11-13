/* File : word similarity.h */
/* Semua hal yg berkaitan tentang kemiripan dua kata */

#ifndef WORDSIMILARITY_H
#define WORDSIMILARITY_H

#include "wordoperations.h"

Word tailOf(Word w);
/* Returns tail of w */

char firstLetter(Word w);
/* Returns head (first letter) of w */
/* Prakondisi w tidak kosong */

int CalculateLevenshteinDistance(Word w1, Word w2, int steps);
/* Calculates the Levenshtein distance between w1 and w2; */
/* The Levenshtein distance is the minimum operations required
to transform w1 to w2 (or the other way around). Operations include
substitution, deletion, and insertion */

boolean isAnagram(Word w1, Word w2);
/* Returns true if w1 is an anagram of w2 and vice versa, and false if not */

#endif 