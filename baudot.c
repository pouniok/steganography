#include <stdio.h>
#include <stdlib.h>

// Les tables de correspondance pour le code Baudot uniquement avec les lettres
char* lettres[] = {
    "", "E", "\n", "A", " ", "S", "I", "U",
    "\r", "D", "R", "J", "N", "F", "C", "K",
    "T", "Z", "L", "W", "H", "Y", "P", "Q", 
    "O", "B", "G", "", "M", "X", "V", ""
};

char* lettres_ita1[] = {
    "", "A", "E", "\r", "Y", "U", "I", "O",
    "", "J", "G", "H", "B", "C", "F", "D",
    " ", "\n", "X", "Z", "S", "T", "W", "V", 
    "", "K", "M", "L", "R", "Q", "N", "P"
};

char* lettres_tty[] = {
    "", "T", "\r", "O", "", "H", "N", "M",
    "\n", "L", "R", "G", "I", "P", "C", "V",
    "E", "Z", "D", "B", "S", "Y", "F", "X", 
    "A", "W", "J", "", "U", "Q", "K", ""
};

// Fonction pour convertir une séquence de 5 bits en entier
int bits_to_int(const char* bits) {
    int val = 0;
    for (int i = 0; i < 5; i++) {
        val = (val << 1) | (bits[i] - '0');
    }
    return val;
}

/**
 * Permet de convertir un flux binaire en string en encodage Baudot/Murray
 * Un paramètre de 0 à 2 permet de choisir l'encodage souhaité : 
 * 0 : ITA2
 * 1 : ITA1
 * 2 : TTY
 */
int main(int argc, char** argv) {
    char input[6];  // 5 bits + '\0'

    // Lecture du flux d'entrée 5 bits par 5 bits
    while (fscanf(stdin, "%5s", input) == 1) {
        int code = bits_to_int(input);

        // Vérification que le code est dans les limites valides (0 à 31)
        if (code >= 0 && code < 32) {
            // Affiche la lettre correspondante
            char* lettre = lettres[code];

            if (*argv[1] == '1'){
                lettre = lettres_ita1[code];
            }
            else if (*argv[1] == '2') {
                lettre = lettres_tty[code];
            }

            printf("%s", lettre);
        } 
    }

    return 0;
}
