/* Main */
#include "inisialisasiperintah.h"
#include "ADT_Tambahan\\wordsimilarity.h"

#define not(n) !n
#define nl printf("\n");


int main() {
    
    initializeKeyWords();
    displayBurbir();
    FILE *f;

    if(isSameWord(stringToWord("MUAT", 4),stringToWord("MUAL", 4))) {
        printf("What..?"); nl;
    }

    inputConfigFile(f);
    // load (f);
    printf("File berhasil dimuat!\n");

    // boolean firstInput = true;
    boolean stopped = false;

    while (not(stopped)) {
        Word perintah;
        bacaInput(&perintah);
        clearFirstCharacter(&perintah);

        if (isAKeyWord(perintah)) {
        
            // YANG GAK ADA PARAMETER NYA LANGSUNG DIPANGGIL AJA
            printf("Lakukan ");
            displayWord(perintah);

            // YANG ADA PARAMETERNYA:
            // SUKA_KICAUAN [IDKicau], UBAH_KICAUAN [IDKicau]
            
            // BALAS [IDKicau] [IDBalasan], BALASAN [IDKicau], HAPUS_BALASAN [IDKicau] [IDBalasan]
            
            // UTAS [IDKicau], SAMBUNG_UTAS [IDUtas] [index],  HAPUS_UTAS [IDUtas] [index]
            // CETAK_UTAS [IDUtas]
            ////// nanti handle semuanya, yg di bawah ini proof of concept!
            if (isSameWord(perintah, stringToWord("HAPUS_UTAS", 10))) {
                ADVWORD(); 
                int param1 = wordToInteger(currentWord);
                ADVWORD();
                int param2 = wordToInteger(currentWord);

                printf(" dengan parameter %d, %d", param1, param2);
            }

            nl;
        }

        else {

            Word saltik;
            int i = 0;
            boolean found = false;
            while(!found && (i < 100)) {
                int ld = CalculateLevenshteinDistance(perintah, KeyWords[i], 0);
                if (ld < 3) {
                    found = true;
                    saltik = KeyWords[i];
                }
                else {
                    ++i;
                }
            }

            if (!found) {
                printf("Input tidak dikenali!"); nl;
            }
            else {
                printf("Input tidak dikenali!"); nl;
                printf("Apakah Anda bermaksud untuk mengetik '");
                displayWord(saltik); printf("'..?"); nl;
            }
        }
        
        nl;
    }


}