#include <stdio.h>

/**
 * Transforme un fichier en flux binaire sous forme de string ('0' et '1')
 * 
 * Utilisation :
 * <pre>
 * echo "Hello" | binary
 * 010010000110010101101100011011000110111100001010
 * </pre>
 */
int main() {
    int byte;

    // Lire les octets depuis stdin
    while ((byte = getchar()) != EOF) {

        // Lecture des bits de gauche à droite (MSB vers LSB)
        for (int i = 7; i >= 0; --i) {
            putchar(((byte >> i) & 1) ? '1' : '0');
        }

    }

    return 0;
}
