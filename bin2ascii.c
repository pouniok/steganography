#include <stdio.h>

/**
 * Permet de convertir un flux binaire en string vers un flux binaire
 * 
 * Utilisation : 
 * <pre>
 * echo "010010000110010101101100011011000110111100001010" | bin2ascii
 * Hello
 * </pre>
 */
int main() {
    int bit; // Lecture d'un caractère correspondant à un bit ('0' ou '1')
    unsigned char byte = 0; // Caractère à afficher une fois les 8 'bits' lus
    int bit_count = 0;

    while ((bit = getchar()) != EOF) {
        // Sécurité pour ne pas lire autre chose que des 0 et 1
        if (bit == '0' || bit == '1') {
            // Décalage vers la gauche et ajout du bit
            byte = (byte << 1) | (bit - '0'); // Le - '0' petmet de convertir le caractères '0'/'1' en 0 ou 1
            bit_count++;

            // Si nous avons un octet complet (8 bits)
            if (bit_count == 8) {
                putchar(byte);  // Écrire l'octet vers stdout
                bit_count = 0;
                byte = 0;  // Réinitialiser l'octet
            }
        }
    }

    // Écrire les bits restants si le nombre total de bits n'est pas un multiple de 8
    if (bit_count > 0) {
        byte <<= (8 - bit_count);  // Compléter avec des zéros
        putchar(byte);
    }

    return 0;
}
